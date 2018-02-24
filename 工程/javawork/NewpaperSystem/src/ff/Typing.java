package ff;


import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;

import javax.swing.*;



@SuppressWarnings("unused")
public class Typing {
	Color color = new Color(144,238,144);
	MyJWindow jw = new MyJWindow(color);
	JLabel jb1,jb2,jb3,jmb1,jmb2,jmb3;
	JTextField jtf1,jtf2,jtf3;
	JButton but = new JButton("确认");
	JLabel message = new JLabel();
 	public Typing(){
 		message.setBounds(160, 25, 180, 20);
		message.setOpaque(true);
		message.setBackground(color);
		message.setFont(new Font("雅黑",Font.PLAIN,13));
		message.setForeground(Color.red);
		message.setHorizontalAlignment(SwingConstants.CENTER);
		jw.add(message);
		jb1 = new JLabel("报刊名");
		jb1.setOpaque(true);
		jb1.setFont(new Font("宋体", Font.PLAIN, 20));
		jb1.setBackground(color);
		jb1.setBounds(80, 50, 80, 30);
		jw.add(jb1);
		jb2 = new JLabel("发行周期");
		jb2.setOpaque(true);
		jb2.setFont(new Font("宋体", Font.PLAIN, 20));
		jb2.setBackground(color);
		jb2.setBounds(80, 100, 80, 30);
		jw.add(jb2);
		jb3 = new JLabel("价格");
		jb3.setOpaque(true);
		jb3.setFont(new Font("宋体", Font.PLAIN, 20));
		jb3.setBackground(color);
		jb3.setBounds(80, 150, 80, 30);
 		jw.add(jb3);
		
 		jmb1 = new JLabel("名称:示例 abc");
		jmb1.setOpaque(true);
		jmb1.setFont(new Font("宋体", Font.PLAIN, 10));
		jmb1.setBackground(color);
		jmb1.setBounds(160, 85, 80, 15);
		jw.add(jmb1);
		jmb2 = new JLabel("天数:示例 1");
		jmb2.setOpaque(true);
		jmb2.setFont(new Font("宋体", Font.PLAIN, 10));
		jmb2.setBackground(color);
		jmb2.setBounds(160, 135, 80, 15);
		jw.add(jmb2);
		jmb3 = new JLabel("价格:示例 1.00");
		jmb3.setOpaque(true);
		jmb3.setFont(new Font("宋体", Font.PLAIN, 10));
		jmb3.setBackground(color);
		jmb3.setBounds(160, 185, 80, 15);
 		jw.add(jmb3);
 		
 		jtf1 = new JTextField(20);
		jtf1.setVisible(true);
		jtf1.setOpaque(true);
		jtf1.setBounds(160, 50, 180, 30);
		jw.add(jtf1);
		jtf2 = new JTextField(20);
		jtf2.setVisible(true);
		jtf2.setOpaque(true);
		jtf2.setBounds(160, 100, 180, 30);
		jw.add(jtf2);
		jtf3 = new JTextField(20);
		jtf3.setOpaque(true);
		jtf3.setBounds(160, 150, 180, 30);
		jw.add(jtf3);
 		
 		but.setForeground(Color.red);
		but.setBounds(160, 200, 100, 60);
		but.setOpaque(true);
		but.setBackground(color);
		but.setFont(new Font("粗体", Font.PLAIN, 40));
		but.setBorder(null);
		but.addActionListener(new TypingButton());
		jw.add(but);

		
	}
	void show(int x,int y){
		message.setText("");
		jw.setBounds(x, y,350, 300);
		jtf1.setText("");
		jtf2.setText("");
		jtf3.setText("");
		jw.setVisible(true);
		
		
	}
	
	
	
	
}
