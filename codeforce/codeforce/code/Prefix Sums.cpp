#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
#define INF (0)
int n;
unsigned long long k;
unsigned long long a[200010];

bool judge(unsigned long long m){
	unsigned long long need = k;
	unsigned long long pre = 1;
	unsigned long long fenzi = m;
	unsigned long long fenmu = 1;
	need -= a[n];
	for (int i = n-1; i >= 1 && need > 0; --i){
		if (pre == INF){
			
		}
		else{
			double p = log(pre) + log(fenzi) - log(fenmu);
			if (log10(pre) + log10(fenzi) - log10(fenmu) > 19.0){
				pre = INF;
			}
			else{
				pre = pre *fenzi/fenmu;
				fenmu++;
				fenzi++;
			}
		}

		if (pre == INF){
			if (a[i] != 0)
				return 1;
		}
		else{
			if (a[i] == 0)
				continue;

			if (need <= pre * a[i])
				return 1;
			need -= pre * a[i];
		}
	}
	return 0;

}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	in >> n >> k;
	bool ok = 0;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
		if (a[i] >= k){
			ok = 1;
		}
	}

	if (ok){
		cout << 0 << endl;
		return 0;
	}

	unsigned long long L = 1, R = k, ans = k;
	while (L <= R){
		unsigned long long mid = (L + R) / 2;
		if (mid <= 3776){
			int t = 0;
		}
		if (judge(mid)){
			ans = min(ans, mid);
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}


	cout << ans << endl;



	return 0;
}

/*import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static int n;
	static long k;
	static long[] a = new long[200010];
	
	static boolean judge(long m) {
		BigInteger M = BigInteger.valueOf(k);
		BigInteger pre = BigInteger.ONE;
		BigInteger fenzi = BigInteger.valueOf(m);
		BigInteger fenmu = BigInteger.ONE;
		M = M.subtract(BigInteger.valueOf(a[n]));
		for(int i=n-1;i>=1 &&  M.compareTo(BigInteger.ZERO) > 0;--i) {
			if(pre.compareTo(M) < 0 ) {
				pre = pre.multiply(fenzi);
				pre = pre.divide(fenmu);
				fenzi = fenzi.add(BigInteger.ONE);
				fenmu = fenmu.add(BigInteger.ONE);
			}
			
			M = M.subtract(pre.multiply(BigInteger.valueOf(a[i])));
			
		}
		
		
		
		return M.compareTo(BigInteger.ZERO) <= 0;
	}
	
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		k = in.nextLong();
		boolean ok = false;
		for(int i=1;i<=n;++i) {
			a[i] = in.nextLong();
			if(a[i] >= k) {
				ok=true;
			}
		}
		
		if(ok) {
			System.out.print(0);
			return ;
		}
		
		long L = 1,R = k,ans=k;
		while(L<=R) {
			long mid = (L+R)/2;
			if(judge(mid)) {
				if(ans > mid) {
					ans = mid;
				}
				R = mid-1;
			}
			else {
				L = mid+1;
			}
			
		}
		
		System.out.println(ans);
		
	}
	
	

}
*/



