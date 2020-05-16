import java.net.*;
import java.io.*;

class ReadText extends Thread {
    private PrintWriter out;
    public ReadText(PrintWriter out) {
		this.out=out;
		setDaemon(true); // thread dies when no longer needed
		start();
    }

    public void run() { // send messages to the server
		try {
	    	BufferedReader console=new BufferedReader(
	        	new InputStreamReader(System.in));
	    	String line;
	    	while((line=console.readLine())!=null) {
				out.println(line);
	    	}
	    	console.close();
		} catch(IOException e) {
	    	e.printStackTrace();
		}
    }
}

class CloseSocket extends Thread {
    private Socket s;
    private PrintWriter out;
    public CloseSocket(Socket s, PrintWriter out) {
		this.s=s;
		this.out=out;
    }

    public void run() {
		// say bye to everyone before departure
		if(out!=null) out.println("/bye");
		try { if(s!=null) s.close();  // close socket if not already done
		} catch(IOException e) { e.printStackTrace(); }
			System.out.println("** terminated: "+s);
    	}
}

class TextClient {
    private BufferedReader in;
    private PrintWriter out;

    public TextClient(String host, int port) throws IOException {
		Socket s=null;
		try {
			s=new Socket(host, port);
			in=new BufferedReader(new InputStreamReader(s.getInputStream()));
			out=new PrintWriter(s.getOutputStream(),true);
			new ReadText(out);

			Runtime.getRuntime().addShutdownHook(new CloseSocket(s,out));
			String line;
			while((line=in.readLine())!=null) System.out.println(line);
		} finally { if(s!=null) s.close(); s=null; }
    }

    public static void main(String[] args) throws IOException {
		if(args.length!=2) {
			System.out.println("usage: java TextClient host port");
			System.exit(0);
		}
		new TextClient(args[0], Integer.parseInt(args[1]));
    }
}

