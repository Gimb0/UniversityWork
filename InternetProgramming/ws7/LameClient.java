import java.io.*;
import java.net.*;

public class LameClient {
    public static void main(String[] args) throws IOException {
		String remoteHost=args.length>0? args[0]:"127.0.0.1";
		Socket socket=new Socket(remoteHost, 5678);
		System.out.println(socket);
		
		try {
	    	BufferedReader in=new BufferedReader(new InputStreamReader(
			      socket.getInputStream()));
	    	PrintWriter out=new PrintWriter(
			    socket.getOutputStream(),true);
	    	out.println("client sends greetings");
	    	String str=in.readLine(); // blocks for a message
	    	System.out.println(str);
	    	out.println("END");
		} finally { socket.close(); }
    }
}
