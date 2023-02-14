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

public class Server extends Thread {

    static Scanner keyboard;
    static ServerSocket serverSocket;
    static int connections;

    
    public void run(){
        System.out.println("\n - Hi I'm " + this.getName());
        return;
    }

    public static int getOpenSpot (Server threads[]){
        for (int i = 0; i < threads.length; i++){
            if (threads[i] == null){
                return i;
            }
            else if (!threads[i].isAlive()){
                return i;
            }
        }
        return -1;
    }

    public static void main (String args[]){
        
        // Setup
        if (args.length < 2){
            System.out.println(" -- Error: Not Enough Arguments\n\n -- java Server <port_number> <max_queue_size>");
            System.exit(0);
        }
        System.out.println(" --- Setting Up...");

        // Socket
        try {
            serverSocket = new ServerSocket(Integer.parseInt(args[0]));
        } catch (Exception e) {
            System.out.println("-- Error: " + e);
            System.exit(0);
        }
        int maxConnections = 100, connections = 0;
        Server threads[] = new Server[maxConnections];
        System.out.println(" --- Finished Setting Up\n");

        while (true){

            try {
                System.out.println("\n --- Waiting for Connection...");
                Socket clientSocket = serverSocket.accept();
                System.out.println(" -- Connecting...");
                while (connections == maxConnections){
                    Thread.sleep(1000);
                }
                int open = getOpenSpot(threads);
                threads[open] = new Server();
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
