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
long long val[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4 };
long long pw[20];
long long n, L, R;
vector<long long> digit;
void get(long long p){
	digit.clear();
	while (p){
		digit.push_back(p % 16);
		p /= 16;
	}
	reverse(digit.begin(), digit.end());
	
}

long long cale(int l,int r){
	long long ans = 0;
	for (int i = l; i <= r; ++i)
		ans = ans * 16 + digit[i];
	return ans;

}

long long slove(long long p){
	if (p < 0)
		return 0;
	if (p == 0){
		return 8 * val[0];
	}

	vector<long long> ans(16, 0);

	get(p);
	if (digit.size() == 1){
		for (int i = 1; i <= digit[0]; ++i)
			ans[i] = 1;
	}
	else{
		long long a, b;
		a = digit[0];
		b = cale(1, digit.size() - 1);
		for (int i = 1; i < a; ++i)
			ans[i] += pw[digit.size() - 1];
		ans[a] += b + 1;
		
		a = digit.back();
		b = cale(0, digit.size() - 2);
		for (int i = 1; i < 16; ++i){
			ans[i] += b;
			if (i <= a)
				ans[i]++;
		}


		for (int k = 1; k < digit.size() - 1; ++k){
			long long v = digit[k];
			long long l = cale(0, k - 1);
			long long r = cale(k + 1, digit.size() - 1);
			int len = digit.size() - k - 1;
			for (int i = 1; i < 16; ++i){
				if (i < v){
					ans[i] += (l + 1)*pw[len];
				}
				else if (i == v){
					ans[i] += l * pw[len];
					ans[i] += r + 1;

				}
				else{
					ans[i] += l*pw[len];
				}
			}
		}
	}

	ans[0] = (p + 1) * 8;
	for (int i = 1; i < 16; ++i)
		ans[0] -= ans[i];

	long long ret = 0;
	for (int i = 0; i < 16; ++i)
		ret += val[i] * ans[i];
	return ret;


}



int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	pw[0] = 1;
	for (int i = 1; i<20; ++i)
		pw[i] = pw[i - 1] * 16;
	long long MMAX = pw[8];
	int T;
	in >> T;
	while (T-- > 0){
		scanf("%d%x", &n, &L);
		//in >> n >> hex >> L;
		R = L + n - 1;

		if (R < MMAX){
			printf("%lld\n", slove(R) - slove(L - 1));

		}
		else{
			R -= MMAX;
			printf("%lld\n", slove(MMAX - 1) - slove(L - 1) + slove(R));
	
		}






	}
















	return 0;
}





