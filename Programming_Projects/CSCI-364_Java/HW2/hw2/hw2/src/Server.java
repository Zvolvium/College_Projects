/*
 * Program Name: Server.java
 * 
 * Java Version: JDK 17.0.5.8 Microsoft
 * 
 * Author: Mason A. Motschke
*/
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.lang.Thread;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import hw2.xml.MessageBuilder;
import hw2.xml.MessageParser;

import java.io.IOException;

public class Server extends Thread {

    static ServerSocket serverSocket;
    static Socket clientSocket;
    static int connections;
    static ArrayList<String> Queue;
    static int maxQueue;

    public Server (ArrayList<String> Queue, Socket client, int maxQueue){
        this.Queue = Queue;
        this.clientSocket = client;
        this.maxQueue = maxQueue;
    }
    
    public void run(){
        System.out.println("\n - Hi I'm " + this.getName());
        try {
            //MessageBuilder mb = new MessageBuilder();
            //MessageParser mp = new MessageParser();
            PrintWriter writer = new PrintWriter(this.clientSocket.getOutputStream(), true);
            BufferedReader reader = new BufferedReader(new InputStreamReader(this.clientSocket.getInputStream()));

            // while (){

            // }
            
            this.clientSocket.close();
            return;
        } catch (Exception e){

        }
    }

    public static int getOpenSpot (Server threads[]){
        for (int i = 0; i < threads.length; i++){
            if ((threads[i] == null) || (!threads[i].isAlive())){
                return i;
            }
        }
        return -1;
    }

    public synchronized String queueRead (ArrayList<String> queue){
        if (!queue.isEmpty()){
            return queue.remove(0);
        } else {
            return "Error: Queue Empty";
        }
    }

    public synchronized int queueSize (ArrayList<String> queue){
        return queue.size();
    }

    public synchronized void queueWrite (ArrayList<String> queue, int maxSize){
        
    }

    public static void main (String args[]){
        
        // Setup
        if (args.length < 2){
            System.out.println(" -- Error: Not Enough Arguments\n\n -- java Server <port_number> <max_queue_size>");
            System.exit(0);
        }
        System.out.println(" --- Setting Up...");
        int maxConnections = 100, connections = 0;
        Server threads[] = new Server[maxConnections];

        // Socket
        try {
            Queue = new ArrayList<String>();
            serverSocket = new ServerSocket(Integer.parseInt(args[0]));
            maxQueue = Integer.parseInt(args[1]);
        } catch (Exception e) {
            System.out.println("-- Error: " + e);
            System.exit(0);
        }
        System.out.println(" --- Finished Setting Up\n");

        while (true){

            try {
                System.out.println("\n --- Waiting for Connection...");
                clientSocket = serverSocket.accept();
                System.out.println(" -- Connecting...");
                while (connections == maxConnections){
                    Thread.sleep(1000);
                }
                int open = getOpenSpot(threads);
                threads[open] = new Server(Queue, clientSocket, maxQueue);
                threads[open].start();
                System.out.println(" -- Got Connection!");
                connections++;
            }
            catch (Exception e){
                System.out.println("\n --- Error: " + e + ". Exiting Program...");
                System.exit(0);
            }

        }

    }

}
