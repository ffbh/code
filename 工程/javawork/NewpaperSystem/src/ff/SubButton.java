package ff;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;


public class SubButton implements MouseListener{

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		MainScreenButtonHandle.subscribe.atm.fireTableStructureChanged();
		Vector<Vector<Object>> v = MainScreenButtonHandle.subscribe.v;
		try {
			Main.stm.executeUpdate("delete from trade where name = "+"'"+Main.username+"'");
		} catch (SQLException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		for(int i=0;i<v.size();++i){
			if(!(v.get(i).get(3)).toString().equals("false")){
				String name =v.get(i).get(0).toString();
				String sql = "insert into Trade values("+"'"+name+"',"+"'"+Main.username+"')";
				try {
					ResultSet rs = Main.stm.executeQuery("select * from Trade where papername = "
							+"'"+name+"' and name = "+"'"+Main.username+"'");
					if(!rs.next())
						Main.stm.executeUpdate(sql);
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}
		MainScreenButtonHandle.subscribe.atm.fireTableStructureChanged();
		MainScreenButtonHandle.subscribe.jw.setVisible(true);
		
		
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
		int x = e.getXOnScreen();
		int y = e.getYOnScreen();
		MainScreenButtonHandle.subscribe.jtmp.setBounds(x, y, 60, 20);
		MainScreenButtonHandle.subscribe.jtmp.setVisible(true);
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		MainScreenButtonHandle.subscribe.jtmp.setVisible(false);
	}

}
