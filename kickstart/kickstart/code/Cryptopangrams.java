import java.io.*;
import java.math.*;
import java.util.*;
public class Solution {
	
	public static BigInteger gcd(BigInteger a ,BigInteger b) {
		if(b.equals(BigInteger.ZERO)) {
			return a;
		}
		else {
			return gcd(b,a.mod(b));
		}
	}
	
    public static void main(String[] args)throws Exception {
   //  Scanner in = new Scanner(new File("C:\\input.txt"));
        Scanner in = new Scanner(System.in);
     int T = in.nextInt();
     for(int t=1;t<=T;++t) {
    	 BigInteger N = in.nextBigInteger();
    	 int L = in.nextInt();
    	 BigInteger[] a = new BigInteger[L];
    	 for(int i=0;i<L;++i) {
    		 a[i] = in.nextBigInteger();
    	 }
    	
    	 BigInteger[] ans = new BigInteger[L+1];
    	
    	 int pos = 0;
    	 while(a[pos].equals(a[pos+1])) {
    		 pos++;
    	 }
    	 
		 BigInteger g = gcd(a[pos],a[pos+1]);
		 ans[pos] = a[pos].divide(g);
		 for(int i=pos;i<L;++i) {
			 ans[i+1] = a[i].divide(ans[i]);
		 }
		 for(int i=pos;i>0;--i) {
			 ans[i-1] = a[i-1].divide(ans[i]);
		 }
		 
		 Set<BigInteger> S = new TreeSet<BigInteger>();
    	 for(int i=0;i<L+1;++i) {
    		 S.add(ans[i]);
    	 }
    	 
    	 Map<BigInteger,Character> M = new HashMap<BigInteger,Character>();
    	 char SSS = 'A';
    	 for(BigInteger b : S) {
    		 M.put(b, SSS++);
    	 }
    	 
    	 System.out.printf("Case #%d: ",t);
    	 for(int i=0;i<L+1;++i) {
    		 System.out.print(M.get(ans[i]));
    	 }
    	 System.out.println();
     }
     
     
     
     
     
     

    }
}
