package zjz;


import java.util.*;

import org.omg.CosNaming.NamingContextExtPackage.AddressHelper;

public class LRTable{ 
    private static final int MaxTableSize = 500;
    ArrayList<Table> vTables;
    Character[][] map ;
    String[][] tableLink;
    public ArrayList<String> arrayList;
    String[][] analyTable;
    
    public char start;
    Set<Character> finality ;
    Set<Character> unfinality ;
    Map<Character, Integer> mci = new HashMap<>();
    
    public String[][] getAnalyTable(){
        return analyTable;
    }
    
    public LRTable() {
        // TODO Auto-generated constructor stub
        this.vTables = new ArrayList<>();
        arrayList = new ArrayList<>();
        this.map = new Character[MaxTableSize][MaxTableSize];
        finality = new HashSet<>();
        unfinality = new HashSet<>();
        for(int i=0;i<MaxTableSize;++i) 
            for(int j=0;j<MaxTableSize;++j)
                map[i][j]='-';

    }
    
    public ArrayList<Table> getTable(){
        return vTables;
    }
    
    public String[][] CaleTableDefine(){
        int row = 1;
        int col = vTables.size();
        Iterator<Table> iterator = vTables.iterator();
        while(iterator.hasNext()) {
            Table table = iterator.next();
            if(table.size() + 1 > row)
                row = table.size() + 1;
        }
        String[][] ret = new String[row][col];
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                ret[i][j] = "";
        for(int i=0;i<vTables.size();++i) {
            ret[0][i] = "T"+i;
            int index = 1;
            Iterator<Expression> it = vTables.get(i).iterator();
            while(it.hasNext()) {
                String string = it.next().showString();
                if(string.charAt(0) != '0')
                    ret[index++][i] = string;
                else
                    ret[index++][i] = start+"'"+string.substring(1);
            }
        }
        return ret;
    }
    
    public void InitAnalyTable() {
        int row = vTables.size()+1;
        int col = finality.size()+unfinality.size()+2;
        analyTable = new String[row][col];
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                analyTable[i][j] = "";
        
        Set<Character> sc = new TreeSet<>(finality);
        int index = 1;
        Iterator<Character> iterator = sc.iterator();
        while(iterator.hasNext()) {
            Character character = iterator.next();
            mci.put(character, index);
            analyTable[0][index++]=""+character;
        }
        mci.put('#', index);
        analyTable[0][index++]="#";
        sc = new TreeSet<>(unfinality);
        iterator = sc.iterator();
        while(iterator.hasNext()) {
            Character character = iterator.next();
            mci.put(character, index);
            analyTable[0][index++]=""+character;
        }
        for(int i=1;i<row;++i)
            analyTable[i][0] = ""+(i-1);
    }
    
    public void CaleAnalyTable() {
        InitAnalyTable();
    
        for(int i=0;i<MaxTableSize;++i) {
            for(int j=0;j<MaxTableSize;++j)
                if(map[i][j] != '-') {
                    try {
                    if(finality.contains(map[i][j]))
                        analyTable[i+1][mci.get(map[i][j])]="s"+j;
                    else
                        analyTable[i+1][mci.get(map[i][j])]=""+j;
                    }
                    catch(NullPointerException e) {
                        System.out.println(map[i][j]);
                    }
                        
                }
        }
        
        for(int i=0;i<vTables.size();++i) {
                Iterator<Expression> iterator = vTables.get(i).iterator();
                Expression src = null;
                while(iterator.hasNext()) {
                    Expression expression = iterator.next();
                    if(expression.Nextchar() == null) {
                        src = new Expression();
                        src.S = expression.S;
                        src.right = expression.right.substring(0,expression.length()-1);
                        break;
                    }  
                }
                if(src != null) {
                    String id = "r";
                    String aimString = src.toString();
                    for(int j=0;j<arrayList.size();++j) {
                        if(arrayList.get(j).equals(aimString)) {
                            id += j;
                            break;
                        }
                    }
                    if(id.charAt(1) == '0') {
                        analyTable[i+1][mci.get('#')]="acc";
                    }
                    else {
                        Iterator<Character> it = finality.iterator();
                        while(it.hasNext()) {
                            analyTable[i+1][mci.get(it.next())]=id;
                        }
                        analyTable[i+1][mci.get('#')]=id;
                    }
                    
                }
                
                
        }
        
       
 
    }
    
    public String ArrayToString(ArrayList arr,String b){
    	StringBuilder ret = new StringBuilder();
    	for(int i=0;i<arr.size();++i)
    		ret.append(arr.get(i).toString()+b);
    	return ret.toString();
    }
    
    public String[][] SyntaxAnaly(String s){
    	String data = s + '#';
    	ArrayList<String[]> As = new ArrayList<>();
    	String [] item = new String[5];
    	item[0] = "state";
    	item[1] = "operator";
    	item[2] = "rest input";
    	item[3] = "action";
    	item[4] = "next state";
    	As.add(item);
    	
    	ArrayList<Integer> stateStack = new ArrayList<>();
    	ArrayList<Character> analyStack = new ArrayList<>();
    	int index = 0;
    	stateStack.add(0);
    	analyStack.add('#');
    	boolean f = true;
    	while(f){
    		item = new String[5];   
    		item[4] = "";
    		item[0] = ArrayToString(stateStack," ");
    		item[1] = ArrayToString(analyStack,"");
    		item[2] = data.substring(index);
    		int top = stateStack.get(stateStack.size() - 1) + 1;
    		char next = data.charAt(index);
    		int col = mci.get(next);
    		String text = analyTable[top][col];
    		if(text.equals("acc")){
    			item[3] = text;
    			f = false;
    		}
    		else if(text.length() == 0){
    			item[3] = "error";
    			f = false;
    		}
    		else if(text.charAt(0) == 'r'){
    			int xiabiao = 0;
    			for(int i=1;i<text.length();++i)
    				xiabiao = xiabiao * 10 + text.charAt(i) - '0';
    			Expression expression = Expression.pasteExpression(arrayList.get(xiabiao));
    			int len = expression.length();
    			for(int i=0;i<len;++i){
    				stateStack.remove(stateStack.size() - 1);
    				analyStack.remove(analyStack.size() - 1);
    			}
    			analyStack.add(expression.S);
    			item[3] = text;
    			top = stateStack.get(stateStack.size() - 1) + 1;
    			next = expression.S;
    			col = mci.get(next);
    			text = analyTable[top][col];
    	//		System.out.println(top +"  "+next+"   "+text);
    			item[4] = text;
    			stateStack.add(Integer.valueOf(text));
    		}
    		else{
    			item[3] = text;
    			item[4] = text.substring(1);
    			stateStack.add(Integer.valueOf(item[4]));
    			analyStack.add(data.charAt(index));
    			index++;
    		}
    		As.add(item);
    	}
    	
    	String[][] ans = new String[As.size()][5];
    	for(int i=0;i<As.size();++i){
    		ans[i] = As.get(i);
    	//	for(int j=0;j<5;++j)
    	//		System.out.print(ans[i][j]+"   ");
    //		System.out.println();
    	}
    	return ans;
    }
    
    
    public void CaleTableLink() {
        int row = vTables.size()+1;
        int col = vTables.size()+1;
        tableLink = new String[row][col];
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                tableLink[i][j] = "";
        for(int i=1;i<row;++i)//square
            tableLink[i][0] = tableLink[0][i] = "T"+(i-1);
        for(int i=0;i<MaxTableSize;++i)
            for(int j=0;j<MaxTableSize;++j)
                if(map[i][j] != '-') {
                    tableLink[i+1][j+1] = map[i][j]+"";
                }
    }
    
    public String[][] getTableLink(){
        return tableLink;
    }
    
    
    void PrintAnalyTable() {
        for(int i=0;i<analyTable.length;++i) {
            for(int j=0;j<analyTable[i].length;++j)
                System.out.print(analyTable[i][j]);
            System.out.println();
        }
    }
    
    public void setfinality(String data) {
        for(int i=0;i<data.length();++i)
            finality.add(data.charAt(i));
            
    }
    
    public void setunfinality(String data) {
        for(int i=0;i<data.length();++i)
            unfinality.add(data.charAt(i));
    }
    
    public void PrintPath() {
        System.out.println();
        System.out.println();
        for(int i=0;i<MaxTableSize;++i) {
            for(int j=0;j<MaxTableSize;++j)
                if(map[i][j] != '-') {
                    System.out.println("T"+i+"--"+map[i][j]+"-->"+"T"+j);
                }
        }
        System.out.println();
        System.out.println();
        
    }
    
    public void PrintTable() {
        Iterator<Table> iterator = vTables.iterator();
        while(iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}



