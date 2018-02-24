import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
	static BigInteger[][] dig = new BigInteger[81][81];
	static int len;
	//static int[][][] dp = new int[81][81][81];// end_start   pre_start  pre_end
	static boolean mark[] = new boolean[81];
	static int dfs(int a, int b, int c) {

		if (c > a){
			return 1;
		}
		if (b == c) {
			for (int i = a; i >= 0; --i) {
				mark[i] = true;
				if (i == 2 && a == 5) {
					int t = 0;
				}
				if (dig[0][i].compareTo(dig[a + 1][len]) < 0) {
					if (dfs(a, 0, i + 1) == 1) {
						return 1;
					}
				}
				mark[i] = false;
			}
		}
		else {
			for (int i = a; i >= c; --i) {
				mark[i] = true;
				if (dig[c][i].compareTo(dig[a + 1][len]) < 0 && dig[b][c - 1].compareTo(dig[c][i]) < 0) {
					if (dfs(a, c, i + 1) == 1) {
						return 1;
					}
				}
				mark[i] = false;
			}
		}

		return 0;

	}

	public static void main(String[] args)throws Exception{
		//    Scanner in = new Scanner(new File("C:\\input.txt"));
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			String str = in.nextLine();
			len = str.length() - 1;
			if (str.equals("0"))
				break;
			for (int i = 0; i<str.length(); ++i) {
				for (int j = i; j<str.length(); ++j) {
					dig[i][j] = new BigInteger(str.substring(i, j + 1));
				}
			}


			BigInteger mmin = dig[0][len];

			boolean ans[] = new boolean[81];
			for (int i = str.length() - 1; i>0; --i) {
				Arrays.fill(mark, false);
				if (dfs(i - 1, 0, 0) == 1) {

					if (dig[i][len].compareTo(mmin) < 0) {
						mmin = dig[i][len];

						for (int k = 0; k<81; ++k) {
							ans[k] = mark[k];
						}
					}
					else if (dig[i][len].compareTo(mmin) == 0) {
						boolean change = false;
						for (int k = 0; k<81; ++k) {
							if (mark[k] != ans[k]) {
								if (ans[k]) {
									change = true;

								}
								break;

							}
						}

						if (change) {
							for (int k = 0; k<81; ++k) {
								ans[k] = mark[k];
							}
						}

					}

				}
			}
			// System.out.println(str);
			if (mmin.equals(dig[0][len])) {
				System.out.println(str);
			}
			else {
				for (int i = 0; i<str.length(); ++i) {
					System.out.print(str.charAt(i));
					if (ans[i])
						System.out.print(',');
				}
				System.out.println();
			}
		}








	}
}


