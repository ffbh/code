import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Writer;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;




public class Server {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
       
        System.out.println("start");
        try {
            ServerSocket serverSocket = new ServerSocket(9999);

            Socket socket = serverSocket.accept();
 
            final DataInputStream input = new DataInputStream(socket.getInputStream());
   //         Scanner in = new Scanner(socket.getInputStream());
            final DataOutputStream dataOutputStream= new DataOutputStream(socket.getOutputStream());
            
            
            final ChatModel chatModel = new ChatModel();
            final ButtonController buttonController = new ButtonController(chatModel,dataOutputStream);
            final MainFrame mainFrame = new MainFrame(chatModel, buttonController,"server");
            
            Thread thread = new Thread(new Runnable() {
                @Override
                public void run() {
                    // TODO Auto-generated method stub   
                    System.out.println("thread start");
                    while(true) {
                        try {
                            String string = input.readUTF();
                            chatModel.push(new OtherMessage(string.split("\n+"),Algorithms.getTime()));
                        } catch (IOException e) {
                            // TODO Auto-generated catch block 
                            break;
                      //      e.printStackTrace();
                          
                        }
                        
                   
                    }
                    
                }
            });
           thread.start();
  
            
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        System.out.println("end");
        
        
        
    }

}
