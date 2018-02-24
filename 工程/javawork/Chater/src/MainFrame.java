import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedOutputStream;
import java.util.Observable;
import java.util.Observer;

import javax.management.modelmbean.ModelMBean;
import javax.print.attribute.standard.JobPriority;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextPane;


public class MainFrame implements Observer{
    ChatModel chatModel;
    ButtonController buttonController;
    
    JFrame mainFrame;
    JTextArea jta1;
    JTextPane jtp;
    JButton submit;
    JScrollPane scroll1,scroll2;
    
    BufferedOutputStream bufferedOutputStream;


    
    
    public MainFrame(ChatModel chatModel,ButtonController buttonController,String title) {
        this.chatModel = chatModel;
        this.buttonController = buttonController;
         mainFrame = new JFrame(title);
        chatModel.addObserver(this);
        
        Init();
    }
    
    private void Init() {
       
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);;
        mainFrame.setBounds(400,150,500,350);
        mainFrame.getContentPane().setLayout(null);
        mainFrame.setVisible(true);
        


        jta1 = new JTextArea(10,10);
     //   jta1.setBounds(10, 10, 170, 170);;
      jta1.setBackground(new Color(169,169,169));
        jta1.setVisible(true);
        
        scroll1 = new JScrollPane(jta1);
        scroll1.setVisible(true);
        scroll1.setBounds(10, 10, 170, 170);
        scroll1.setHorizontalScrollBarPolicy( 
              JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS); 
        scroll1.setVerticalScrollBarPolicy( 
                JScrollPane.VERTICAL_SCROLLBAR_ALWAYS); 
        mainFrame.getContentPane().add(scroll1);

        
        submit =  new JButton("∑¢ÀÕ");
      //  submit.setBackground(Color.BLACK);
        submit.setVisible(true);
        submit.setBounds(50, 200, 80, 50);
        submit.setBorder(null);
        submit.setBorder(BorderFactory.createLineBorder(Color.PINK));
        submit.addActionListener(new ActionListener() {
            
            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO Auto-generated method stub
                String input = jta1.getText();
                jta1.setText("");
                buttonController.press(input);
            }
        });
        mainFrame.getContentPane().add(submit);
        
       
        jtp = new JTextPane();
        jtp.setFont(new Font("¥÷ÃÂ", Font.PLAIN, 12));
        jtp.setEditable(false);
        jtp.setBackground(new Color(240,230,140));
        jtp.setVisible(true);
     //   jta2.setBounds(200, 10, 250, 250);
        scroll2 = new JScrollPane(jtp);
        scroll2.setBounds(200, 10, 250, 250);
        scroll2.setHorizontalScrollBarPolicy( 
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED); 
        scroll2.setVerticalScrollBarPolicy( 
                JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED); 
  
        mainFrame.getContentPane().add(scroll2);
        
        
        mainFrame.validate();
        mainFrame.repaint();
        
        
    }

    @Override
    public void update(Observable o, Object arg) {
        // TODO Auto-generated method stub
        while(true) {
            Message message = chatModel.getMessage();
            if(message == null)
                break;
            message.insert(jtp);
        }
        
    }
    

}
