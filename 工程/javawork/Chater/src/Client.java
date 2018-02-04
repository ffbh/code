import java.io.DataInputStream;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class Client {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
       
        System.out.println("start");
        try {

            Socket socket = new Socket("127.0.0.1", 9999);
 
            final DataInputStream input = new DataInputStream(socket.getInputStream());
   //         Scanner in = new Scanner(socket.getInputStream());
            final DataOutputStream dataOutputStream= new DataOutputStream(socket.getOutputStream());
            
            
            final ChatModel chatModel = new ChatModel();
            final ButtonController buttonController = new ButtonController(chatModel,dataOutputStream);
            final MainFrame mainFrame = new MainFrame(chatModel, buttonController,"client");
            
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
