package ff;

import javax.swing.table.AbstractTableModel;

import java.util.*;

public class SubscribeModel extends AbstractTableModel {
	  final String title[] = { "报刊名","发行周期","价格","购买"};
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
	public int getRowCount() {
		// TODO Auto-generated method stub
		return MainScreenButtonHandle.subscribe.v.size();
	}

	@Override
	public int getColumnCount() {
		// TODO Auto-generated method stub
		return 4;
	}

	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		// TODO Auto-generated method stub
		if(!MainScreenButtonHandle.subscribe.v.isEmpty())
			return	((Vector<Object>)(MainScreenButtonHandle.subscribe.v.elementAt(rowIndex))).elementAt(columnIndex);
		else 
			return null;
	}
	 @Override
     public Class<?> getColumnClass(int columnIndex) {
         return MainScreenButtonHandle.subscribe.v.get(0).get(columnIndex).getClass();

     }
	@Override
	 public String getColumnName(int column) {
         return title[column];
     }// 设置表格列名
	
	 @Override
     public boolean isCellEditable(int rowIndex, int columnIndex) {
         // return columnIndex == 0;
         return (getValueAt(rowIndex, columnIndex) instanceof Boolean);
     }
	 @Override
     public void setValueAt(Object value, int rowIndex, int columnIndex) {
         MainScreenButtonHandle.subscribe.v.get(rowIndex).set(columnIndex, value);
         fireTableCellUpdated(rowIndex, columnIndex);
     }

}
