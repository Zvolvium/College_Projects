/**
 * Server.java
 *
 * My message-oriented middleware (MOM) server.
 *
 * @author David Apostal
 */ 

import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private static ServerSocket clientServerSocket;
    //private final ServerSocket adminServerSocket;
    private static final int MIN_PORT = 1024;
    private static final int MIN_QUEUE_SIZE = 1;
    public static void main(String[] args) throws Exception {
        Server my_s = new Server();

        if (args.length != 2) {
            my_s.usage();
            System.exit(1);
        }
        System.out.println("That's right");

        // setup data structures
        
        // process command line args
        int clientPort = Integer.parseInt(args[0]);
        int maxSize = Integer.parseInt(args[1]);
        //int adminPort = Integer.parseInt(args[2]);

        // set up server.
        clientServerSocket = new ServerSocket(clientPort);
        //adminServerSocket = new ServerSocket(adminPort);

        while (true) {
            System.out.println("***** waiting for next client****");
            Socket socket = clientServerSocket.accept();
            Runnable cr = new ClientRunnable(socket);
            Thread thread = new Thread(cr);
            thread.start();
        }
    }

    private void usage() {
        System.err.println("Usage: java Server <client port> <max queue size>");
        System.err.println("where");
        System.err.println("\tclient port >= " + MIN_PORT);
        System.err.println("\tmax queue size >= " + MIN_QUEUE_SIZE);
    }

}

