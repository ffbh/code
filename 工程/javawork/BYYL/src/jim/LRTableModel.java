package jim;

import javax.swing.table.AbstractTableModel;

public class LRTableModel extends AbstractTableModel {
    /**
     * 
     */
    private static final long serialVersionUID = 1L;
    String[][] data;
    public LRTableModel(String[][] data) {
        // TODO Auto-generated constructor stub
        this.data =data;
    }
    @Override
    public int getRowCount() {
        // TODO Auto-generated method stub
        return data.length;

    }

    @Override
    public int getColumnCount() {
        // TODO Auto-generated method stub
        
        return data[0].length;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        // TODO Auto-generated method stub
        return data[rowIndex][columnIndex];
    }

}










