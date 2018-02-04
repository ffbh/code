package ff;

import java.awt.BorderLayout;
import java.awt.Color;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;

public class Show {
	Color color = new Color(216,191,216);
	MyJWindow jw = new MyJWindow(color);
	AbstractTableModel atm = new ShowModel();
	JTable table = new JTable(atm);
	Vector<Vector<Object>> v = new Vector<Vector<Object>>();
	JScrollPane jsp;
	//JLabel j1,j2,j3;
	public Show() {
		jw.setBounds(400,100, 350, 500);
		jw.getContentPane().setLayout(new BorderLayout());
		table.setShowVerticalLines(true);
		table.setCellSelectionEnabled(false);
		table.setBounds(50, 50, 250,400);
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		table.setShowVerticalLines(true);//  
        table.setShowHorizontalLines(true);
        table.setToolTipText("显示全部查询结果");
		jsp = new JScrollPane(table);
		jw.getContentPane().add(jsp,BorderLayout.CENTER);
		
		
		
		
		
		
	}
	void show(ResultSet rs){
		v.clear();
		atm.fireTableStructureChanged();
		try {
			while(rs.next()){
				Vector<Object> vo = new Vector<Object>();
				vo.add(rs.getString(1));
				vo.add(rs.getString(2));
				v.add(vo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		atm.fireTableStructureChanged();
		jw.setVisible(true);
	}
}
