package zjz;

public class Expression implements Comparable<Expression>{
    Character S;
    String right;
    @Override
    public String toString(){
        return S+"->"+right;
    }
    
    public String showString() {
        return S+"→"+right;
    }
    public static  Expression pasteExpression(String s){
        String[] temp = s.split("->");
        Expression expression = new Expression();
        expression.S=temp[0].charAt(0);
        expression.right = temp[1];
        return expression;
    
    }
    @Override
    public boolean equals(Object t){
        Expression expression = (Expression)t;
        return S.equals(expression.S) && right.equals(expression.right);
    }
    public int length(){
        return right.length();
    }
    public char charAt(int i){
        return right.charAt(i);
    }
    public Character Nextchar() {
      int dian;
      for(dian = 0;dian<right.length();++dian)
          if(right.charAt(dian) == '*')
              break;
      if(dian >= right.length() - 1)
          return null;
      else 
          return right.charAt(dian + 1);
        
    }
    @Override
    public int compareTo(Expression o) {
        // TODO Auto-generated method stub
        if(S != o.S)
            return S.compareTo(o.S);
        else
           return right.compareTo(o.right);
    }
    
    
    
    
}