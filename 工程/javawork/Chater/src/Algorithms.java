
import java.util.*;


public class Algorithms {
    public static String[] splitStringByCharlength(String src,int limit) {
        ArrayList<String> arrayList = new ArrayList<String>();
        int nowindex = 0;
        while(nowindex < src.length()){
            if(limit + nowindex < src.length())
                arrayList.add(src.substring(nowindex, nowindex + limit));
            else 
                arrayList.add(src.substring(nowindex));
                
            nowindex += limit;
        }
        String[] res = new String[arrayList.size()];
        return arrayList.toArray(res);
    }
    
    public static String[] splitStringByViewlength(String src,int limit) {
        ArrayList<String> arrayList = new ArrayList<String>();
        int nowindex = 0,endindex;
        while(nowindex < src.length()){
           int len = 0;
           endindex = nowindex;
           while(len < limit && endindex < src.length()) {

               if(src.charAt(endindex) >= '\u4e00' && src.charAt(endindex) <='\u9fa5')
                   len += 2;
               else
                   len ++;
               endindex++;
           }
           arrayList.add(src.substring(nowindex, endindex));
           nowindex = endindex;
        }

        String[] res = new String[arrayList.size()];
        return arrayList.toArray(res);
    }
    
    public static int getViewlength(String s) {
        int count = 0;
        for(int i=0;i<s.length();++i) {
            if(s.charAt(i) >= '\u4e00' && s.charAt(i) <='\u9fa5')
                count += 2;
            else 
                count ++;
        }
        return count;
        
    }
    
    
    public static String getTime() {
        Calendar c = Calendar.getInstance();
        int hour = c.get(Calendar.HOUR_OF_DAY); 
        int minute = c.get(Calendar.MINUTE); 
        int second = c.get(Calendar.SECOND); 
        return String.format("%2d:%2d:%2d",hour,minute,second);
    }
    
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        String[] dec = splitStringByViewlength("sa1ÖÐrrÎÊdff", 3);
        for(int i=0;i<dec.length;++i)
            System.out.println(dec[i]);
        
        
    }

}
