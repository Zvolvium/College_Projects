/*
 * Program Name: Server.java
 * 
 * Java Version: JDK 17.0.5.8 Microsoft
 * 
 * Author: Mason A. Motschke
*/
import java.net.ServerSocket;
import java.net.Socket;
import java.lang.Thread;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import hw2.xml.MessageBuilder;
import hw2.xml.MessageParser;

public class Server extends Thread {

    static ServerSocket serverSocket;
    static Socket clientSocket;
    static int connections;
    static ArrayList<String> Queue;
    static int maxQueue;

    static final int MAX_CONNECTIONS = 10;
    static final int SLEEP_TIME = 1000;
    static final int MIN_PORT = 1024;

    public Server (ArrayList<String> Queue, Socket client, int maxQueue){
        Server.Queue = Queue;
        Server.clientSocket = client;
        Server.maxQueue = maxQueue;
    }
    
    public void run(){
        try {
            MessageParser mp;
            PrintWriter writer = new PrintWriter(Server.clientSocket.getOutputStream(), true);
            BufferedReader reader = new BufferedReader(new InputStreamReader(Server.clientSocket.getInputStream()));
            String cmd;
            String data;

            mp = new MessageParser(reader.readLine());
            while (!mp.getCmd().strip().equals("close")){
                
                if (mp.getCmd().strip().equals("write")){
                    MessageBuilder mb = new MessageBuilder();
                    cmd = mp.getCmd().strip();
                    data = mp.getData().strip();

                    synchronized (Server.Queue){
                        if (Queue.size() < Server.maxQueue){
                            Server.Queue.add(data);
                            data = "ok";
                        } else {
                            data = "Error: Queue Full";
                        }
                    }
                    mb.setCmd(cmd);
                    mb.setData(data);
                    writer.println(mb.toString());
                }
                else if (mp.getCmd().strip().equals("read")){
                    MessageBuilder mb = new MessageBuilder();
                    cmd = mp.getCmd().strip();

                    synchronized (Server.Queue){
                        if (!Server.Queue.isEmpty()){
                            data = Server.Queue.remove(0);
                        } else {
                            data = "Error: Queue Empty";
                        }
                    }
                    mb.setCmd(cmd);
                    mb.setData(data);
                    writer.println(mb.toString());
                }
                else if (mp.getCmd().strip().equals("size")){
                    MessageBuilder mb = new MessageBuilder();
                    cmd = mp.getCmd().strip();

                    synchronized (Server.Queue){
                        int size = Server.Queue.size();
                        data = "".format("%d", size);
                    }

                    mb.setCmd(cmd);
                    mb.setData(data);
                    writer.println(mb.toString());
                } else {
                    MessageBuilder mb = new MessageBuilder();
                    cmd = "Error_No_Such_Command";
                    data = "Error";
                    mb.setCmd(cmd);
                    mb.setData(data);
                    writer.println(mb.toString());
                }
                mp = new MessageParser(reader.readLine());
            }

            MessageBuilder mb = new MessageBuilder();
            cmd = mp.getCmd().strip();
            data = "ok";
            mb.setCmd(cmd);
            mb.setData(data);
            writer.println(mb.toString());
            
            Server.clientSocket.close();
            return;
        } catch (Exception e){
            System.out.println(" --- Error: " + e);
        }
    }

    public static int getOpenSpot (Server threads[]){
        for (int i = 0; i < MAX_CONNECTIONS; i++){
            if ((threads[i] == null) || (!threads[i].isAlive())){
                return i;
            }
        }
        return -1;
    }

    public static void checkArgs (String args[]){
        try {
            int port = Integer.parseInt(args[0]);
            int maxQueueSize = Integer.parseInt(args[1]);
            if ((port < MIN_PORT) || (maxQueueSize < 0)){
                throw new Exception("Args not Valid");
            }
        } catch (Exception e){
            System.out.println(" --- Error: Args not Valid\n\n -- java Server <port_number> <max_queue_size>");
            System.out.println("    -- port_number > 1024\n    -- max_queue_size > 0");
            System.exit(0);
        }
        return;
    }

    public static void main (String args[]){
        
        // Setup
        if (args.length < 2){
            System.out.println(" --- Error: Not Enough Arguments\n\n -- java Server <port_number> <max_queue_size>");
            System.exit(0);
        }
        System.out.println(" --- Setting Up...");
        Server threads[] = new Server[MAX_CONNECTIONS];

        // Socket
        try {
            checkArgs(args);
            Queue = new ArrayList<String>();
            serverSocket = new ServerSocket(Integer.parseInt(args[0]));
            maxQueue = Integer.parseInt(args[1]);
        } catch (Exception e) {
            System.out.println("-- Error: " + e);
            System.exit(0);
        }
        System.out.println(" --- Finished Setting Up\n");

        int open;
        while (true){

            try {
                open = getOpenSpot(threads);
                if (open == -1){
                    System.out.println("\n --- Max Client Connections Made!\n     - Waiting for Client to Close...\n");
                    while (open == -1){
                        Thread.sleep(SLEEP_TIME);
                        open = getOpenSpot(threads);
                    }
                }
                System.out.println("\n --- Waiting for Connection...");
                clientSocket = serverSocket.accept();
                System.out.println("     -- Connecting...");
                threads[open] = new Server(Queue, clientSocket, maxQueue);
                threads[open].start();
                System.out.println("     -- Got Connection!");
            }
            catch (Exception e){
                System.out.println("\n --- Error: " + e + ". Exiting Program...");
                System.exit(0);
            }

        }

    }

}
