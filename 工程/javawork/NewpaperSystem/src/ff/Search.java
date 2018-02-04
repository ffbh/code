package ff;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.sql.rowset.JdbcRowSet;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;
import javax.swing.JWindow;





public class Search {
	Color color = new Color(192,192,192);
	MyJWindow jw = new MyJWindow(color);
	ButtonGroup bg = new ButtonGroup();
	JRadioButton jb1,jb2;
	JButton but = new JButton("确认");
	JLabel jl = new JLabel("~",JLabel.CENTER);
	JTextField jtf1,jtf2,jtf3;
	Show s = new Show();
	int flag;
	public Search(){
		jl.setVisible(true);
		jl.setBounds(240, 150, 40, 30);
		jl.setForeground(Color.red);
		jl.setFont(new Font("粗体", Font.PLAIN, 22));
		jw.add(jl);
		
		jtf1 = new JTextField(20);
		jtf1.setBounds(200, 50, 100, 30);
		jw.add(jtf1);
		
		jtf2 = new JTextField(10);
		jtf2.setBounds(200, 150, 40, 30);
		jw.add(jtf2);
		
		jtf3 = new JTextField(10);
		jtf3.setBounds(280, 150, 40, 30);
		jw.add(jtf3);
		
		jw.setVisible(false);
		
		jw.setBounds(400, 150,350, 300);
		jb1 = new JRadioButton("按报刊名");
		jb1.setBounds(50, 50, 100, 30);
		jb1.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				but.setVisible(true);
				jtf1.setText("");
				jtf2.setText("");
				jtf2.setText("");
				jtf1.setEditable(true);
				jtf2.setEditable(false);
				jtf3.setEditable(false);
				flag = 1;
				
				
			}
		});
		jb2 = new JRadioButton("按订阅人数");
		jb2.setBounds(50, 150, 100, 30);
		jb2.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				but.setVisible(true);
				jtf1.setText("");
				jtf2.setText("");
				jtf1.setEditable(false);
				jtf2.setEditable(true);
				jtf3.setEditable(true);
				flag = 2;
				
				
			}
		});
		bg.add(jb1);
		bg.add(jb2);
		jw.add(jb1);
		jw.add(jb2);
		
		but.setForeground(Color.red);
		but.setBounds(160, 200, 100, 60);
		but.setOpaque(true);
		but.setBackground(color);
		but.setFont(new Font("粗体", Font.PLAIN, 40));
		but.setBorder(null);
		but.addActionListener(new SearchButton());
		jw.add(but);
		
		
		
		
	}
	
	
	
	
	
	void show(int x,int y){
		jtf1.setEditable(false);
		jtf2.setEditable(false);
		jtf3.setEditable(false);
		jtf1.setText("");
		jtf2.setText("");
		jtf3.setText("");
		but.setVisible(false);
		bg.clearSelection();
		
		
		
		jw.setVisible(true);
		
		
		
		
	}





	

}
