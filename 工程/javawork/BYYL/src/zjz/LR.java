package zjz;
import java.io.*;
import java.util.*;




public class LR {

	/**
	 * @param args
	 */
	private static void DFS_Expression(LRTable lrTable,ArrayList<Expression> data,Table table, int index){
		Expression e = data.get(index);
		Iterator<Expression> it = table.iterator();
		while(it.hasNext()) {
		   Expression expression = it.next();
		   if(expression.equals(e))
		       return ; 
		}
		
		table.add(e);
		    int dian;
		    for(dian=0;dian<e.length();++dian){
            if(e.charAt(dian) == '*')
                break;
		    }
		    dian ++;
		    if(dian >= e.length() || lrTable.finality.contains(e.charAt(dian)))
		        return ;
		    for(int i=0;i<data.size();++i) {
		        Expression expression = data.get(i);
		        if(expression.S == e.charAt(dian) && expression.right.charAt(0) =='*')
		            DFS_Expression(lrTable,data, table, i);
            }
		}
	
	
	private static void DFS_Table(LRTable lrTable,Table table, ArrayList<Expression> array) {
	    ArrayList<Table> vTables = lrTable.vTables;
	    Iterator<Table> it = vTables.iterator();
	    while(it.hasNext()) {
	        Table table2 = it.next();
	        if(table2.equals(table)) {
	            table.name = table2.name;
	            return ;  
	        }
	    }
	    table.name = vTables.size();
	    vTables.add(table);
	    Set<Character> sc = new HashSet<Character>();
	    Iterator<Expression> iterator = table.iterator();
	    while(iterator.hasNext()) {
	        Expression expression = iterator.next();
	        Character character = expression.Nextchar();
	        if(character != null)
	            sc.add(character);
	    }
	    Iterator<Character> itc = sc.iterator();
	    while(itc.hasNext()) {
	        Table sontable = new Table();
	        Character c = itc.next();
	        iterator = table.iterator();
	        while(iterator.hasNext()) {
	            Expression expression = iterator.next();
	            if(c.equals(expression.Nextchar())) {
	                int index = array.indexOf(expression) + 1;
	                DFS_Expression(lrTable,array, sontable, index);
	            }
	        }
	        DFS_Table(lrTable, sontable, array);
	        lrTable.map[table.name][sontable.name]=c;
	    }    
	}
	
	
	private static void StartCaleTable(LRTable lrTable, ArrayList<Expression> array,int index){
		Table table = new Table();
		DFS_Expression(lrTable,array, table, index);
		DFS_Table(lrTable,table,array);
	}
	
	
	
	
	public static void lr(LRTable lrTable)  {
		// TODO Auto-generated method stub
		ArrayList<Expression> array = Table.pasteExpressionsArray(lrTable.arrayList);
		StartCaleTable(lrTable, array,0);
		
		lrTable.CaleAnalyTable();
		lrTable.CaleTableLink();
		
		
	}

}
