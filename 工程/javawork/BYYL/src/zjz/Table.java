package zjz;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

import javax.print.attribute.Size2DSyntax;

public class Table {
    int name;
    Set<Expression> data;
    public Table(){
        data = new TreeSet<Expression>();
    }
    public void add(Expression e){
        data.add(e);
    }
    
    public int size(){
        return data.size();
    }
    
    @Override
    public String toString(){
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("T"+name+"\n");
        Iterator<Expression> iterable = data.iterator();
        while(iterable.hasNext()) {
            stringBuilder.append(iterable.next().toString()+"\n");
        }
        return stringBuilder.toString();
    }
    
    public static ArrayList<Expression> pasteExpressionsArray(ArrayList<String> s){
        ArrayList<Expression> array = new ArrayList<Expression>();
        for(int i=0;i<s.size();++i){
            Expression e = Expression.pasteExpression(s.get(i));
            
            Expression tmp = new Expression();
            tmp.S = e.S;
            tmp.right = "*"+e.right;
            array.add(tmp);
            
            for(int j=0;j<e.length();++j){
                tmp = new Expression();
                tmp.S = e.S;
                if(j+1<e.length())
                    tmp.right = e.right.substring(0,j+1)+"*"+e.right.substring(j+1);
                else 
                    tmp.right = e.right.substring(0,j+1)+"*";
                
                array.add(tmp);
                
            }
        }
        return array;
    }
    public Iterator<Expression> iterator(){
        return data.iterator();
    }

    @Override
    public boolean equals(Object object) {
        Table table = (Table)object;
        if(data.size() != table.data.size())
            return false;
        Iterator<Expression> it1 = data.iterator();
        Iterator<Expression> it2 = table.data.iterator();
        while(it1.hasNext()) {
            Expression e1 = it1.next();
            Expression e2 = it2.next();
            if(!e1.equals(e2))
                return false;
            
        }
        return true;
        
    }
    
}