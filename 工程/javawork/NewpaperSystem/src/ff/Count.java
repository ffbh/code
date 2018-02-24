package ff;

import java.awt.BorderLayout;
import java.awt.Color;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;

public class Count {
	Color color = new Color(216,191,216);
	MyJWindow jw = new MyJWindow(color);
	AbstractTableModel atm = new CountModel();
	JTable table = new JTable(atm);
	Vector<Vector<Object>> v = new Vector<Vector<Object>>();
	JScrollPane jsp;
	public Count(){
		jw.setBounds(400,100, 350, 500);
		
		jw.getContentPane().setLayout(new BorderLayout());
		table.setShowVerticalLines(true);
		table.setCellSelectionEnabled(false);
		table.setBounds(50, 40, 250,400);
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		table.setShowVerticalLines(true);//  
        table.setShowHorizontalLines(true);
        table.setToolTipText("显示全部查询结果");
		jsp = new JScrollPane(table);
		jw.getContentPane().add(jsp,BorderLayout.CENTER);
		
		
		
	}
	
	
	void show(int x,int y){
		v.clear();
		Vector<String> vs = new Vector<String>();
		atm.fireTableStructureChanged();
		try {
			ResultSet rs = Main.stm.executeQuery("select nname from New");
			while(rs.next()){
				vs.add(rs.getString(1));
			}
			for(int i=0;i<vs.size();++i){
				Vector<Object> vo = new Vector<Object>();
				String sql = "select Count(*) from Trade where papername = "+"'"+vs.get(i)+"'";
				ResultSet rss = Main.stm.executeQuery(sql);
				rss.next();
				vo.add(vs.get(i));
				vo.add(rss.getInt(1));
				System.out.println(rss.getInt(1));
				v.add(vo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		atm.fireTableStructureChanged();
		System.out.println(vs.size());
		
		
		
		
		
		
		jw.setVisible(true);
	}
	
	
	
	
	
}
