package ff;

import java.awt.event.*;
import java.sql.ResultSet;
import java.sql.SQLException;

public class TypingButton implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		MainScreenButtonHandle.typing.message.setText("");
		String nname = MainScreenButtonHandle.typing.jtf1.getText();
		String cycletime = MainScreenButtonHandle.typing.jtf2.getText();
		String price = MainScreenButtonHandle.typing.jtf3.getText();
		if(nname.length()*cycletime.length()*price.length()==0){
			MainScreenButtonHandle.typing.message.setText("�����������ı�����Ϣ");
			return ;
		}
		MainScreenButtonHandle.typing.message.setText("���ڴ�������Ϣ...");
		try{
			int time = Integer.parseInt(cycletime);
			float p = Float.parseFloat(price);
			String sql = "select * from New where nname = "+"'"+nname+"'";
			ResultSet rs = Main.stm.executeQuery(sql);
			if(rs.next()){
				MainScreenButtonHandle.typing.message.setText("�ñ�������¼�Ѵ���");	
				return;
			}
			sql = "insert into New values("+"'"+nname+"',"+cycletime+
					","+price+")";
			System.out.println(sql);
			Main.stm.executeUpdate(sql);
			MainScreenButtonHandle.typing.message.setText("���");	
		}catch(NumberFormatException e1){
			MainScreenButtonHandle.typing.message.setText("���ڻ�۸��������ݸ�ʽ����");
			return;
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		MainScreenButtonHandle.typing.jtf1.setText("");
		MainScreenButtonHandle.typing.jtf2.setText("");
		MainScreenButtonHandle.typing.jtf3.setText("");
	}

}
