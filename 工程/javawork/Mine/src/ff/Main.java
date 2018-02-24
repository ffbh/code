package ff;
import java.awt.Color;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;


public class Main {
	static JFrame frame;
	static JFrame mainactivity = new JFrame("扫雷");
	static Mine game;
	static Thread thread = null;
	static int Mine_Map_size = 16;/////
	static int Mine_num = 40;/////////
	static JButton jb1,jb2,jb3;
	static OptionActivity optionActivity = new OptionActivity();
	static Color color = new Color(169,169,169);
	static JLabel message = new JLabel("扫雷规模："+Mine_Map_size+"  雷数量："+Mine_num,JLabel.CENTER);
	public static void main(String[] args){
		
		message.setBounds(40, 20, 260, 40);
		message.setBackground(color);
		message.setOpaque(true);
		message.setFont(new java.awt.Font("宋体", 1, 20));
		mainactivity.add(message);
		mainactivity.setUndecorated(true);
		mainactivity.setBounds(400,150,330,420);
		mainactivity.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		mainactivity.setLayout(null);
		mainactivity.getContentPane().setBackground(color);

		jb1 = new JButton("开始");
		jb1.setBackground(color);
		jb1.setBorder(null);
		jb1.addActionListener(new Start());
		jb1.setBounds(90, 60, 140, 80);
		jb1.setFont(new java.awt.Font("宋体", 1, 50));
		jb1.setForeground(Color.BLUE);
		mainactivity.add(jb1);
		
		jb2 = new JButton("设置");
		jb2.setBackground(color);
		jb2.setBorder(null);
		jb2.addActionListener(new Option());
		jb2.setBounds(90, 160, 140, 80);
		jb2.setFont(new java.awt.Font("宋体", 1, 50));
		mainactivity.add(jb2);
		
		jb3 = new JButton("退出");
		jb3.setBackground(color);
		jb3.setBorder(null);
		jb3.addActionListener(new MenuExit());
		jb3.setBounds(90, 260, 140, 80);
		jb3.setFont(new java.awt.Font("宋体", 1, 50));
		jb3.setForeground(Color.red);
		mainactivity.add(jb3);
		

		mainactivity.setVisible(true);
		
	}
	
	
}
