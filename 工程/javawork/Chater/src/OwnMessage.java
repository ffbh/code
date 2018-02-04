import java.awt.Color;

import javax.swing.JTextPane;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;


public class OwnMessage extends Message {
    public OwnMessage(String[] s,String time) {
        this.messages = s; 
        this.time = time;
        attrSet = new SimpleAttributeSet(); 
        StyleConstants.setForeground(attrSet,new Color(106,90,205)); 
        StyleConstants.setBold(attrSet,true); 
    }

    @Override
    public void insert(JTextPane jtf) {
        // TODO Auto-generated method stub
       
        
        Document doc = jtf.getDocument(); 
        String starthide = "       ";
        String endhide = "\n";
        try   {  
            doc.insertString(doc.getLength(),starthide+time+"\n",   attrSet); 
        for(int i=0;i<messages.length;++i) {
             
           //     if(i==0)
      //              doc.insertString(doc.getLength(),"¡ñ   ", attrSet);
           //     else 
         //           doc.insertString(doc.getLength(),"       ", attrSet);
                
                String[] line = Algorithms.splitStringByViewlength(messages[i] ,16);
        //        doc.insertString(doc.getLength(), line[0] + endhide ,   attrSet);  
                for(int j=0;j<line.length;++j)
                    doc.insertString(doc.getLength(),starthide + line[j] + endhide,   attrSet);   
            } 
        doc.insertString(doc.getLength(),"\n",   attrSet);   
        
        
        jtf.setCaretPosition(doc.getLength());
        
        
        }catch   (BadLocationException   e)   {   
           System.out.println("BadLocationException:   "   +   e);   
            
           
         }
        
        

    }

}
