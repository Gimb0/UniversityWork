import java.net.*;
import java.io.*;
import java.util.*;

class SChatServer {
    public SChatServer (int port) throws IOException {
		ServerSocket server=new ServerSocket(port);
		while(true) {
	    	Socket client=server.accept();
	    	new SChatter(client).start();
		}
    }

    public static void main(String[] args) throws IOException {
		new SChatServer(Integer.parseInt(args[0]));
    }
}

class SChatter extends Thread {
    private static int count=0;
    private static Vector chatters=new Vector();
    private String id="#"+Integer.toString(++count);
    private Socket s;
    private BufferedReader in;
    private PrintWriter out;

    public SChatter(Socket socket) throws IOException {
		s=socket;
		in=new BufferedReader(new InputStreamReader(s.getInputStream()));
		out=new PrintWriter(s.getOutputStream(),true);
		broadcast("** user "+id+" has just joined in");
    }

    public void run() {
		try { 
	    	chatters.add(this);
	    	while(true) { broadcast(id+": "+in.readLine()); }
		} catch(IOException e) {}
		finally { try{ s.close(); } catch(IOException e) {} }
    }

    private void broadcast(String msg) {
		synchronized(chatters) {
	    	for(int i=0;i<chatters.size();i++) {
				SChatter c=(SChatter) chatters.get(i);
				synchronized(c.out) { c.out.println(msg); }
	    	}
		}
    }
}

