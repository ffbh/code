import java.math.BigInteger;
import java.util.Scanner;

public class Main {
   static  BigInteger[] dp = new BigInteger[210];

   static  BigInteger dfs(int sum){
        if(dp[sum] != null){
            return dp[sum];
        }
        if(sum <= 1){
            return dp[sum] = BigInteger.ONE;
        }
        else{
            return dp[sum] = dfs(sum-1).add(dfs(sum-2));
        }


    }

    public static void main(String[] aaa){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int N = sc.nextInt();
            System.out.println(dfs(N));

        }





    }



}
