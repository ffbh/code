import java.awt.Color;

import javax.swing.JTextPane;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;


public class OtherMessage extends Message {
    public static String blankString = "                                            "
            + "                                                                 ";
    public OtherMessage(String[] s,String time) {
        // TODO Auto-generated constructor stub
        this.messages = s;
        this.time = time;
        attrSet = new SimpleAttributeSet(); 
        StyleConstants.setForeground(attrSet,new Color( 255,20,147)); 
        StyleConstants.setBold(attrSet,true); 
    }


    @Override
    public void insert(JTextPane jtf) {
        // TODO Auto-generated method stub
        
        
        Document doc = jtf.getDocument(); 
        String starthide = "                                  ";
        String endhide = "\n";
        try   {  
            doc.insertString(doc.getLength(),starthide+time+"\n",   attrSet); 
        for(int i=0;i<messages.length;++i) {
             
                
                String[] line = Algorithms.splitStringByViewlength(messages[i] ,16);
          //      doc.insertString(doc.getLength(), starthide + line[0] ,   attrSet); 
          //      if(i==0) {
                    
        //            doc.insertString(doc.getLength(),"     ¡ñ\n", attrSet); 
                    
           //     }
          //      else 
           //         doc.insertString(doc.getLength(),"\n", attrSet);
                
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
