package ff;

import java.awt.Color;
import java.awt.event.*;
import java.sql.SQLException;

import javax.swing.*;

public class ButtonColorChange implements MouseListener {
	Register register = new Register();
	MainScreen ms = new MainScreen();
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		LoginActivity.message.setText("");
		if((JButton)e.getSource()==LoginActivity.but1){
			LoginActivity.message.setText("�������û���������,Ȼ����ȷ��");
			LoginActivity.but1.setText("ȷ��");
			LoginActivity.jb3.setVisible(true);
			LoginActivity.jtf3.setVisible(true);
			String name = LoginActivity.jtf1.getText();
			String password1 = new String(LoginActivity.jtf2.getPassword());
			String password2 = new String(LoginActivity.jtf3.getPassword());
			if(name.length()==0||password1.length()==0||password2.length()==0)
				return ;
			if(!password1.equals(password2)){
				LoginActivity.message.setText("���벻һ��!");
				LoginActivity.jtf2.setText("");
				LoginActivity.jtf3.setText("");
				return ;
			}
			LoginActivity.message.setText("����ע����...");
			int result = register.IsNoRepeated(name, "");
			if(result == -1 ){
				String sqlString = "insert into RECORD values("+"'"+name+"'"+","+"'"+password1+"'"+")";
				try {
					Main.stm.executeUpdate(sqlString);
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					LoginActivity.message.setText("SQLException");
				}
				LoginActivity.message.setText("ע��ɹ�");
				LoginActivity.but1.setText("ע��");
				LoginActivity.jtf3.setText("");
				LoginActivity.jb3.setVisible(false);
				LoginActivity.jtf3.setVisible(false);
			}
			else{
				LoginActivity.message.setText("�û����Ѵ���,����������");
				LoginActivity.jtf1.setText("");
				LoginActivity.jtf2.setText("");
				LoginActivity.jtf3.setText("");
			}
		}
		else{
			LoginActivity.but1.setText("ע��");
			LoginActivity.jb3.setVisible(false);
			LoginActivity.jtf3.setVisible(false);
			String name = LoginActivity.jtf1.getText();
			String password = new String(LoginActivity.jtf2.getPassword());
			if(name.length()==0){
				LoginActivity.message.setText("�û�������Ϊ��");
				return;
			}
			if(password.length()==0){
				LoginActivity.message.setText("���벻��Ϊ��");
				return;
			}
			if(register.IsNoRepeated(name, password) == 1){
				LoginActivity.message.setText("��½�ɹ�!");
				Main.username = name;
				ms.Init();
				
				
				
				
			}
			else {
				LoginActivity.message.setText("�˺Ż��������!");
			}
		}
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		((JButton)e.getSource()).setForeground(new Color(30,178,170));
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		((JButton)e.getSource()).setForeground(Color.blue);
	}

}
