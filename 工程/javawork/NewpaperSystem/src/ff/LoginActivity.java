package ff;



import java.awt.Color;
import java.awt.Font;

import javax.swing.*;



public class LoginActivity {
	static JFrame frame = new JFrame();
	static JButton but1,but2;
	static JTextField jtf1;
	static JPasswordField jtf2,jtf3;
	static JLabel message = new JLabel(),jb1,jb2;
	static JLabel jb = new JLabel(),jb3 = new JLabel("È·ÈÏÃÜÂë");
	
	static void closeAll(){
		but1.setVisible(false);
		but2.setVisible(false);
		jtf1.setVisible(false);
		jtf2.setVisible(false);
		jtf3.setVisible(false);
		jb.setVisible(false);
		jb1.setVisible(false);
		jb2.setVisible(false);
		jb3.setVisible(false);
		message.setVisible(false);
	}
	
	void Init(){
		frame.setBounds(450, 150, 450, 450);
		frame.setLayout(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setBackground(new Color(200,200,200));
		jb.setBounds(0,390, 200, 11);
		jb.setOpaque(true);
		jb.setBackground(new Color(200,200,200));
		jb.setFont(new Font("ÑÅºÚ",Font.PLAIN,10));
		jb.setForeground(Color.black);
		frame.add(jb);
		message.setBounds(55, 170, 345, 20);
		message.setOpaque(true);
		message.setBackground(new Color(200,200,200));
		message.setFont(new Font("ÑÅºÚ",Font.PLAIN,13));
		message.setForeground(Color.red);
		message.setHorizontalAlignment(SwingConstants.CENTER);
		frame.add(message);
		jb1 = new JLabel("ÕË»§",JLabel.CENTER);
		jb1.setBounds(80, 200, 100, 30);
		jb1.setOpaque(true);
		jb1.setBackground(new Color(200,200,200));
		jb1.setFont(new Font("ËÎÌå", Font.PLAIN, 20));
		frame.add(jb1);
		jb2 = new JLabel("ÃÜÂë",JLabel.CENTER);
		jb2.setBounds(80, 250, 100, 30);
		jb2.setOpaque(true);
		jb2.setBackground(new Color(200,200,200));
		jb2.setFont(new Font("ËÎÌå", Font.PLAIN, 20));
		frame.add(jb2);
		jb3.setBounds(80, 300, 100, 30);
		jb3.setOpaque(true);
		jb3.setBackground(new Color(200,200,200));
		jb3.setFont(new Font("ËÎÌå", Font.PLAIN, 20));
		jb3.setVisible(false);
		frame.add(jb3);
		jtf1 = new JTextField(20);
		jtf1.setVisible(true);
		jtf1.setOpaque(true);
		jtf1.setBounds(180, 200, 100, 30);
		frame.add(jtf1);
		jtf2 = new JPasswordField(20);
		jtf2.setVisible(true);
		jtf2.setOpaque(true);
		jtf2.setBounds(180, 250, 100, 30);
		jtf2.setEchoChar('*');
		frame.add(jtf2);
		jtf3 = new JPasswordField(20);
		jtf3.setOpaque(true);
		jtf3.setVisible(false);
		jtf3.setBounds(180, 300, 100, 30);
		jtf3.setEchoChar('*');
		frame.add(jtf3);
		but1 = new JButton("×¢²á");
		but1.setBackground(new Color(200,200,200));
		but1.setBorder(null);
		but1.setBounds(290, 200, 80, 30);
		but1.setFont(new Font("ËÎÌå", Font.PLAIN, 20));
		but1.setForeground(Color.blue);
		but1.addMouseListener(new ButtonColorChange());
		frame.add(but1);
		but2 = new JButton("µÇÂ½");
		but2.setBackground(new Color(200,200,200));
		but2.setBorder(null);
		but2.setBounds(290, 250, 80, 30);
		but2.setFont(new Font("ËÎÌå", Font.PLAIN, 20));
		but2.setForeground(Color.blue);
		but2.addMouseListener(new ButtonColorChange());
		frame.add(but2);
		
		
		jtf1.setText("ffbh");
		jtf2.setText("123456");
		
		
		
		frame.setVisible(true);
	}
	public static void main(String[] args){
		LoginActivity lActivity = new LoginActivity();
		lActivity.Init();
		
		
	}
	
}
	
	

