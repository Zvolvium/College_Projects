/*
 * Program Name: GuessClient.java
 * 
 * Java Version: JDK 17.0.5.8 Microsoft
 * 
 * Author: Mason A. Motschke
*/
import java.net.Socket;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.IOException;

public class GuessClient {
  static Socket client;
  static Scanner keyboard;
  public static void main(String[] args) throws IOException{
      checkArgs(args);

      // Setup ->
      if (args.length < 2){ System.out.println(" -- Error: Not Enough Arguments"); System.exit(0); }
      System.out.println(" --- Setting Up...");

      // -- Socket
      try { client = new Socket(args[0], Integer.parseInt(args[1])); }
      catch (NumberFormatException | IOException e) { e.printStackTrace(); System.exit(0); }

      // -- Readers / Writers
      PrintWriter out = new PrintWriter(client.getOutputStream(), true);
			BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));

      // -- Keyboard Input
      keyboard = new Scanner(System.in);
      System.out.println(" -- Complete\n");

      // Run Application
      String toServer = "", fromServer = "";
      while (true){
        fromServer = in.readLine(); System.out.println(fromServer);
        System.out.print("Message to send: "); toServer = keyboard.nextLine(); System.out.printf("\n");
        out.println(toServer);
        fromServer = in.readLine();

        while (fromServer.startsWith("Error") || fromServer.startsWith("Lower") || fromServer.startsWith("Higher")){
          System.out.println(fromServer);
          System.out.print("Message to send: "); toServer = keyboard.nextLine(); System.out.printf("\n");
          out.println(toServer); fromServer = in.readLine();
        }

        if (fromServer.startsWith("Correct")){ // -------------- IF Correct
          System.out.println(fromServer); fromServer = in.readLine();
        }

        if (fromServer.startsWith("Play")){    // -------------- IF Play Again
          System.out.println(fromServer);
          System.out.print("Message to send: "); toServer = keyboard.nextLine(); System.out.printf("\n");
          if (toServer.equals("y") || toServer.equals("Y")){
            out.println(toServer); fromServer = toServer = "";
          } else {
            out.println(toServer);

            // Close 'ALL' Opened Objects
            System.out.println(" --- Closing...");
            in.close(); out.close(); closeSocket(client); keyboard.close();
            System.out.println(" -- Complete\n"); System.exit(1);
          }
        }
      }
  }

  private static void checkArgs(String[] args){
    // Prints Length of Command Line Arguments and said Arguments to the Console
    int argLength = args.length;
    System.out.println(" -- Args Length: " + argLength); System.out.print(" -- Args: ");
    for (int i = 0; i < argLength; i++){ System.out.print("" + args[i] + " "); }
    System.out.printf("\n\n");
  }

  private static void closeSocket(Socket client){
    // Attempts to close socket
    try { client.close(); }
    catch (IOException e) { System.out.println(" -- Failed to close Socket"); }
  }
}
