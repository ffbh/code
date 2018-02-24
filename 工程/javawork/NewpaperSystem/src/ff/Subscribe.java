package ff;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

import javax.swing.*;
import javax.swing.table.*;



public class Subscribe  {
	Color color = new Color(216,191,216);
	MyJWindow jw = new MyJWindow(color);
	JButton sub = new JButton();
	AbstractTableModel atm = new SubscribeModel();
	JTable table = new JTable(atm);
	Vector<Vector<Object>> v = new Vector<Vector<Object>>();
	JScrollPane jsp;
	JWindow jtmp = new JWindow();
	//JLabel j1,j2,j3;
	public Subscribe() {
		jtmp.setVisible(false);
		jtmp.add(new JLabel("点击订阅"));
		
		jw.setBounds(400,100, 350, 500);
		sub.setBounds(300, 0, 30, 23);
		sub.setBackground(Color.red);
		sub.addMouseListener(new SubButton());
		jw.add(sub);
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
	void show(int x,int y){
		v.clear();
		atm.fireTableStructureChanged();
		try {
			ResultSet rs = Main.stm.executeQuery("select * from New");
			while(rs.next()){
				Vector<Object> vs = new Vector<Object>();
				for(int i=1;i<=3;++i)
					vs.addElement(rs.getString(i));
				v.add(vs);
			}
			for(int i=0;i<v.size();++i){
				ResultSet rss = Main.stm.executeQuery("select * from Trade where papername = "
						+"'"+v.get(i).get(0)+"' and name = "+"'"+Main.username+"'");
				if(!rss.next())
					v.get(i).add(new Boolean(false));
				else 
					v.get(i).add(new Boolean(true));	
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		atm.fireTableStructureChanged();
		jw.setVisible(true);
	}
}
