package test;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	public static void main(String[]args)throws IOException{
		ServerSocket server=new ServerSocket(8081);
		Socket socket=server.accept();
		InputStream is=socket.getInputStream();
		
		byte []bytes=new byte[1024];
		int len=0;
		while((len=is.read(bytes))!=-1){
			System.out.println(new String(bytes,0,len));
		}
		OutputStream os=socket.getOutputStream();
		os.write("已经接受到！！！\r\n".getBytes());
		server.close();
		socket.close();
	}
}
