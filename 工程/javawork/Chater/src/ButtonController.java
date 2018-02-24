import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamCorruptedException;


public class ButtonController{
    ChatModel chatModel;
    DataOutputStream dataOutputStream;
    public ButtonController(ChatModel chatModel,DataOutputStream dataOutputStream) {
        this.chatModel = chatModel;
        this.dataOutputStream = dataOutputStream;
    }
   
    void press(String s) { 
        s = s.trim();
        if(s.length() == 0)
            return ;
        chatModel.push(new OwnMessage(s.split("\n+"),Algorithms.getTime()));
        try {
            dataOutputStream.writeUTF(s);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
           System.exit(0);
        }
       
    } 
   
}
