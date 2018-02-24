package jim;




import java.awt.*;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;

import zjz.*;
public class ShowJTable{
    static int Count = 0;
    static final int x=250,y=150;
    public  ShowJTable(String[][] data,String title) {
        JFrame frame = new JFrame(title);
        frame.setVisible(true);
        frame.setSize(600, 400);
        
        frame.setLocation(x+Count*20, y+Count*20);
        Count++;

        JTable jTable = new JTable(new LRTableModel(data));
        DefaultTableCellRenderer  r   =   new   DefaultTableCellRenderer();   
        r.setHorizontalAlignment(JLabel.CENTER);   
        
        jTable.setDefaultRenderer(Object.class,   r);
        jTable.setFont(new Font("粗体", Font.BOLD, 18));
        jTable.getTableHeader().setVisible(false);
        jTable.setBorder(BorderFactory.createLineBorder(Color.black));
        jTable.setEnabled(false);
        
		for(int i=0;i<data[0].length;++i){
        	int maxlen = 0;
        	for(int j=0;j<data.length;++j){
        		if(maxlen < data[j][i].length())
        			maxlen = data[j][i].length();
        	}
        	jTable.getColumnModel().getColumn(i).setMinWidth(maxlen * 15);
		}
        JScrollPane jScrollPane = new JScrollPane(jTable);
        jScrollPane.setBounds(0, 0, 600, 400);
        jTable.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
        jScrollPane.setHorizontalScrollBarPolicy( 
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED); 
        jScrollPane.setVerticalScrollBarPolicy( 
                  JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED); 
//        jScrollPane.setMaximumSize(new Dimension(6, 6));
//        jTable.setMaximumSize(new Dimension(6, 6));
        frame.getContentPane().add(jScrollPane);
        
  
    }
    
    
    
   

}
