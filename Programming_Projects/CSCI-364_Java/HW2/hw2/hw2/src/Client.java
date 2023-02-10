/**
 * Client.java
 *
 * A client to 
 *
 * @author David Apostal
 *
 */ 
import java.net.Socket;

import hw2.xml.MessageBuilder;

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
  		int portNumber = Integer.parseInt(args[1]);

        //Socket socket = new Socket(hostName, portNumber);
        //System.out.println("client host: " + socket.getLocalAddress());
        //System.out.println("local port: " + socket.getLocalPort());

        MessageBuilder message = new MessageBuilder();
        message.setCmd("read");
        System.out.println(message.toString());
        message.setData("here we are");
        System.out.println(message.toString());
    }
}

