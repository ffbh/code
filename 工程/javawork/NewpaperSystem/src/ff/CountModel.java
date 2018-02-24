package ff;

import java.util.Vector;

import javax.swing.table.AbstractTableModel;

public class CountModel extends AbstractTableModel{
	  /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	final String title[] = { "报刊名","订阅数"};
		/**
		 * 
		 */

		@Override
		public int getRowCount() {
			// TODO Auto-generated method stub
			return MainScreenButtonHandle.count.v.size();
		}

		@Override
		public int getColumnCount() {
			// TODO Auto-generated method stub
			return 2;
		}

		@Override
		public Object getValueAt(int rowIndex, int columnIndex) {
			// TODO Auto-generated method stub
			if(!MainScreenButtonHandle.count.v.isEmpty())
				return	((Vector<Object>)(MainScreenButtonHandle.count.v.elementAt(rowIndex))).elementAt(columnIndex);
			else 
				return null;
		}
		 @Override
	     public Class<?> getColumnClass(int columnIndex) {
	         return MainScreenButtonHandle.count.v.get(0).get(columnIndex).getClass();

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
	         MainScreenButtonHandle.count.v.get(rowIndex).set(columnIndex, value);
	         fireTableCellUpdated(rowIndex, columnIndex);
	     }
}
