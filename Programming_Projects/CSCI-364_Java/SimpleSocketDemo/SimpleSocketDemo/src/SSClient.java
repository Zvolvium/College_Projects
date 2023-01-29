/**
 * SSClient.java
 *
 * Demonstrates how to use client-side sockets.
 *
 * Author: David Apostal
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/**
 * A client that compares a message sent to a server and the message returned
 * by the server. This class demonstrates classes from the Java Class
 * Library used to create a TCP connection with a server, set up communication
 * streams, and exchange a message with a server.
 */
public class SSClient {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 2) {
			System.err.println("Usage: java SSClient <hostname> <port number>");
			System.exit(1);
		}

		String hostName = args[0];
		int portNumber = -1;
		try {
			// convert command line argument to int
			portNumber = Integer.parseInt(args[1]);

			Socket socket = new Socket(hostName, portNumber);
			System.out.println("The client is running on host " +
					socket.getLocalAddress());
			System.out.println("The client is listening on port " +
					socket.getLocalPort());

			// set up i/o between client and server
			PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
			BufferedReader in = new BufferedReader(
					new InputStreamReader(socket.getInputStream()));

			// prompt user for input
			System.out.print("Enter a message to send: ");
			Scanner stdIn = new Scanner(System.in);
			String outMsg = stdIn.next();

			System.out.println("Sending: " + outMsg);
			out.println(outMsg);

			// read response from server
			String inMsg = in.readLine();
			System.out.println("Received: " + inMsg);

			if (inMsg.equals(outMsg)) {
				System.out.println("They match");
			} else {
				System.out.println("Incorrect");
			}

			stdIn.close();
			in.close();
			out.close();
			if (socket.isClosed()) {
				System.out.println("socket is closed");
			} else {
				System.out.println("socket is closing...");
				socket.close();
			}
		} catch (NumberFormatException nfe) {
			System.err.println("Invalid port number");
			System.exit(1);
		} catch (IOException ioe) {
			System.err.println(ioe.getMessage());
			System.exit(1);
		}
	}

}
