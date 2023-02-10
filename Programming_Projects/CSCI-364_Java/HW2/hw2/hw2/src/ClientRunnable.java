/**
 * Server.java
 *
 * A Runnable for a MOM client.
 *
 * @author David Apostal
 */
import java.net.Socket;
import java.net.InetSocketAddress;

public class ClientRunnable implements Runnable {
    private Socket socket;

    public ClientRunnable(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        //String s1 = socket.getInetAddress().getCanonicalHostName();
        //String s2 = socket.getInetAddress().getHostAddress();//*
        //String s3 = socket.getInetAddress().getHostName();
        //String s1 = socket.getLocalAddress().getCanonicalHostName();
        //String s2 = socket.getLocalAddress().getHostAddress();
        //String s3 = socket.getLocalAddress().getHostName(); 
        InetSocketAddress isa = 
                (InetSocketAddress) socket.getRemoteSocketAddress(); 
        String s3 = isa.getAddress().getHostAddress();

        //System.out.println("S1: " + s1);
        //System.out.println("S2: " + s2);
        System.out.println("S3: " + s3);
        int port = socket.getPort();
        int localPort = socket.getLocalPort();
        System.out.println("port: " + port);
        System.out.println("local port: " + localPort);
    }

}

