/**
 * Client.java
 *
 * A client to test MOM server for HW2.
 *
 * @author David Apostal
 *
 */ 
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.Socket;

import java.util.Scanner;

import hw2.xml.MessageBuilder;

/**
 * A client for testing the MOM server for HW2. This client can help 
 * you test the implementations of your "regular" and administration 
 * servers.  
 */
public class Client {
    public Client() {
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            StringBuilder sb = new StringBuilder();
            sb.append("Usage: java Client <hostname> <port number>\n");
            sb.append("where\n");
            sb.append("    hostname is server's hostname or IP address\n");
            sb.append("    port number is the server's listening port");
            System.err.println(sb.toString());
            System.exit(1);
        }

  	String hostName = args[0];
        int portNumber = -1;
        try {
            portNumber = Integer.parseInt(args[1]);
        
            Socket socket = new Socket(hostName, portNumber);
            System.out.println("client host: " + socket.getLocalAddress());
            System.out.println("local port: " + socket.getLocalPort());

            PrintWriter writer;
            BufferedReader reader;
            writer = new PrintWriter(socket.getOutputStream(), true);
            reader = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));

            Scanner scanner = new Scanner(System.in);
            String cmd = "";
            String data = "";

            do {
                System.out.print("Enter cmd: ");
                cmd = scanner.next();
                System.out.print("Enter data: ");
                data = scanner.next();

                MessageBuilder mb = new MessageBuilder();
                mb.setCmd(cmd);
                mb.setData(data);
                System.out.println(
                        "  Client: " + mb.toString());
            
                writer.println(mb.toString());
                String inputLine = reader.readLine();
                System.out.println("  Server: " + inputLine);
            } while (!"close".equalsIgnoreCase(cmd));
        } catch (NumberFormatException nfe) {
            nfe.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
