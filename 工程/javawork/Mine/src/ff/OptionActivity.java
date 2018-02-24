package ff;


import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class OptionActivity extends JFrame{
	String text = "1.扫雷规模：N*N个网格，N的取值范围15~25\n2.雷数量的取值范围10~min(N*N/2,99)\n3.输入为正整数，不得输入数字以外的任何字符(比如空格)\n4.输入框不得为空";
	JLabel jLabel1,jLabel2;
	JTextField jtf1,jtf2;
	JButton jb = new JButton("确定");
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public OptionActivity() {
		// TODO Auto-generated constructor stub
		setVisible(false);
		//setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		setBounds(400, 150, 250, 250);
		jLabel1 = new JLabel("扫雷规模",JLabel.CENTER);
		jLabel1.setBounds(20, 35, 80, 30);
		jLabel1.setOpaque(true);
		add(jLabel1);
		jLabel2 = new JLabel("雷数量",JLabel.CENTER);
		jLabel2.setBounds(20, 90, 80, 30);
		jLabel2.setOpaque(true);
		add(jLabel2);
		jtf1 = new JTextField(5);
		jtf1.setBounds(110, 35, 80, 30);
		add(jtf1);
		jtf2 = new JTextField(5);
		jtf2.setBounds(110, 90, 80, 30);
		add(jtf2);
		
		jb.setBounds(80, 140, 60, 40);
		jb.setBorder(null);
		jb.setForeground(Color.red);
		jb.setFont(new Font("粗体", Font.PLAIN, 20));
		jb.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String s1 = jtf1.getText();
				String s2 = jtf2.getText();
				if(s1.length()==0||s2.length()==0){
					JOptionPane.showMessageDialog(null, text);
					jtf1.setText("");
					jtf2.setText("");
					return ;
				}
				boolean f = false;
				for(int i=0;i<s1.length();++i)
					if(s1.charAt(i)<'0'||s1.charAt(i)>'9'){
						f = true;
						break;
					}
				for(int i=0;i<s2.length();++i)
					if(s2.charAt(i)<'0'||s2.charAt(i)>'9'){
						f  = true;
						break;
					}
				if(f){
					JOptionPane.showMessageDialog(null, text);
					jtf1.setText("");
					jtf2.setText("");
					return ;
				}
				int num1 = 0,num2 = 0;
				try {
				    num1 =  Integer.valueOf(s1);
				    num2 = Integer.valueOf(s2);
                } catch (NumberFormatException e2) {
                    // TODO: handle exception
                    f = true;
                }
				if(f){
                    JOptionPane.showMessageDialog(null, text);
                    jtf1.setText("");
                    jtf2.setText("");
                    return ;
                }
				if(num1<15||num1>25||num2<10||num2>=(num1*num1)/2||num2>99)
					f = true;
				if(f){
					JOptionPane.showMessageDialog(null, text);
					jtf1.setText("");
					jtf2.setText("");
					return ;
				}
				Main.Mine_Map_size = num1;
				Main.Mine_num = num2;
				Main.message.setText("扫雷规模:"+num1+"  雷数量:"+num2);
				dispose();
				
			}
		});
		add(jb);
		

		
		
		
	}
	public void _show(boolean f){
		jtf1.setText("");
		jtf2.setText("");
		setVisible(f);
	}
	public static void main(String[] args){
		OptionActivity optionActivity = new OptionActivity();
		optionActivity._show(true);
	}
	
	
	
}
