package ff;

import java.awt.Color;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JWindow;

public class MainScreen {
	static JButton[] but = new JButton[4];
	static JFrame frame = LoginActivity.frame;
	static JWindow jw = new JWindow();
	static JTextField jtf = new JTextField(100);
	static String[] mess = {"¼�붩����Ա��Ϣ������������Ϣ","������Ա���ı���",
		"����Ա��ѯ����������ѯ�������Ų�ѯ�йض�����Ϣ","������ͳ�ơ�����Աͳ�ơ�������ͳ��"};
	void Init(){
		jw.setVisible(false);
		jw.add(jtf);
		jtf.setVisible(true);
		LoginActivity.closeAll();
		but[0] = new JButton("¼��");
		but[0].setFont(new Font("����", Font.PLAIN, 60));
		but[0].setOpaque(true);
		but[0].setBounds(20, 20, 400, 90);
		but[0].setBackground(new Color(241,158,194));
		but[0].setForeground(Color.white);
		but[0].setBorder(null);
		but[0].addMouseListener(new MainScreenButtonHandle());
		frame.add(but[0]);
		
		but[1] = new JButton("����");
		but[1].setFont(new Font("����", Font.PLAIN, 60));
		but[1].setOpaque(true);
		but[1].setBounds(20, 110, 400, 90);
		but[1].setBackground(Color.yellow);
		but[1].setForeground(Color.white);
		but[1].setBorder(null);
		but[1].addMouseListener(new MainScreenButtonHandle());
		frame.add(but[1]);
		
		but[2] = new JButton("��ѯ");
		but[2].setFont(new Font("����", Font.PLAIN, 60));
		but[2].setOpaque(true);
		but[2].setBounds(20, 200, 400, 90);
		but[2].setBackground(Color.green);
		but[2].setForeground(Color.white);
		but[2].setBorder(null);
		but[2].addMouseListener(new MainScreenButtonHandle());
		frame.add(but[2]);
		
		but[3] = new JButton("ͳ��");
		but[3].setFont(new Font("����", Font.PLAIN, 60));
		but[3].setOpaque(true);
		but[3].setBounds(20, 290, 400, 90);
		but[3].setBackground(Color.blue);
		but[3].setForeground(Color.white);
		but[3].setBorder(null);
		but[3].addMouseListener(new MainScreenButtonHandle());
		frame.add(but[3]);
		
		frame.repaint();
		frame.setVisible(true);
	}
	
	
	

}
