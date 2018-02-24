import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
	static int[] h = new int[70];
	static BigInteger[] ppp = new BigInteger[70];
	static int getaim(int a, int b) {
		if (a>b) {
			int t = a;
			a = b;
			b = t;
		}
		if (a == 1 && b == 2)
			return 3;
		else if (a == 1 && b == 3){
			return 2;
		}
		else
			return 1;


	}

	static BigInteger dfs(int pos, int aim) {
		BigInteger ret = BigInteger.ZERO;
		if (pos == 0)
			return ret;
		if (h[pos] == aim) {
			return dfs(pos - 1, aim);
		}
		else {
			return dfs(pos - 1, getaim(h[pos], aim)).add(ppp[pos - 1]);



		}


	}

	public static void main(String[] args)throws Exception{
		//   Scanner in = new Scanner(new File("C:\\input.txt"));
		Scanner in = new Scanner(System.in);
		ppp[0] = BigInteger.ONE;
		for (int i = 1; i<70; ++i)
			ppp[i] = ppp[i - 1].multiply(BigInteger.valueOf(2));


		int TEST_CASE = in.nextInt(), N, num;
		while (TEST_CASE-- > 0) {
			N = in.nextInt();

			num = in.nextInt();
			while (num-- > 0){
				int t = in.nextInt();

				h[t] = 1;
			}

			num = in.nextInt();
			while (num-- > 0){
				int t = in.nextInt();

				h[t] = 2;
			}

			num = in.nextInt();
			while (num-- > 0){
				int t = in.nextInt();

				h[t] = 3;
			}
			//   System.out.println(dfs(N,3));
			BigInteger back = dfs(N, 1);
			BigInteger then = dfs(N, 3);
			if (back.add(then).compareTo(ppp[N].subtract(BigInteger.ONE)) == 0) {
				System.out.println("true");
			}
			else {
				System.out.println("false");
			}






		}



	}
}


