package ff;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.jar.JarOutputStream;

import javax.swing.JOptionPane;

public class SearchButton implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(MainScreenButtonHandle.search.flag == 1){
			String text = MainScreenButtonHandle.search.jtf1.getText();
			if(text.length() == 0){
				MainScreenButtonHandle.search.jtf1.setText("«Î ‰»Î");
				return ;
			}
			String sql = "select count(*) from Trade where papername = "+"'"+text+"'";
			try {
				ResultSet rs = Main.stm.executeQuery(sql);
				rs.next();
				JOptionPane.showMessageDialog(MainScreenButtonHandle.search.jw,text+" ∂©‘ƒ¡ø : "+ rs.getString(1));
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		else{
			String text1 = MainScreenButtonHandle.search.jtf2.getText();
			if(text1.length() == 0){
				MainScreenButtonHandle.search.jtf2.setText("«Î ‰»Î");
				return ;
			}
			String text2 = MainScreenButtonHandle.search.jtf3.getText();
			if(text2.length() == 0){
				MainScreenButtonHandle.search.jtf3.setText("«Î ‰»Î");
				return ;
			}
			String sql = "select papername ,count(*) from Trade "
					+" group by papername having count(*) between "
					+ text1 + " and "+ text2;
			try {
				ResultSet rs = Main.stm.executeQuery(sql);
				MainScreenButtonHandle.search.s.show(rs);
				
				
				
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
			
			
			
			
		}
	}

}
