/**
 * SSServer.java
 *
 * Demonstrates server-side sockets.
 *
 * Author: David Apostal
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * A server that echos a single message from a client. This class demonstrates
 * classes from the Java Class Library used to create a TCP connection with
 * a client, set-up communication streams, and exchange a message between this
 * class's server socket and a client-side socket.
 */
public class SSServer {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// check command line args
		if (args.length != 1) {
			System.err.println("Usage: java SSServer <port number>");
			System.exit(1);
		}

		int portNumber = -1;
		try {
			// convert command line argument to int
			portNumber = Integer.parseInt(args[0]);

			ServerSocket serverSocket = new ServerSocket(portNumber);
			System.out.println("The server is listening at: " +
					serverSocket.getInetAddress() + " on port " +
					serverSocket.getLocalPort());
			Socket clientSocket = serverSocket.accept();

			// set up i/o between server and client
			PrintWriter out = new PrintWriter(
					clientSocket.getOutputStream(), true);
			BufferedReader in = new BufferedReader(
					new InputStreamReader(clientSocket.getInputStream()));

			// read message from client and echo it back to client
			String inputLine = in.readLine();
			out.println(inputLine);

			in.close();
			out.close();
			if (clientSocket.isClosed()) {
				System.out.println("clientSocket is closed");
			} else {
				clientSocket.close();
			}

			if (serverSocket.isClosed()) {
				System.out.println("serverSocket is closed");
			} else {
				System.out.println("serverSocket is closing...");
				serverSocket.close();
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
