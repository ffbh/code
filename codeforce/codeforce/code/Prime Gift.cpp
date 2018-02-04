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
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
/istream& in = cin;


typedef unsigned long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int n, k;
LL P[20];
struct Node{
	LL p[10];//index 1
	int idx[10];
	int n;
	vector<LL> ans;
	void Init(){
		for (int i = 0; i < 10; ++i)
			idx[i] = 1;
		ans.clear();
	}

	void cale(){
		Init();
		
		ans.push_back(0);
		ans.push_back(1);
		if (n == 0)
			return;
		for (int i = 2; ans[i-1] < 1e18; ++i){
			int mmin = 1;
			for (int j = 2; j <= n; ++j){
				if (ans[idx[j]] * p[j] < ans[idx[mmin]] * p[mmin])
					mmin = j;
			}
			ans.push_back(ans[idx[mmin]] * p[mmin]);
			LL val = ans[idx[mmin]] * p[mmin];
			for (int j = 1; j <= n; ++j){
				if (ans[idx[j]] * p[j] == val)
					idx[j]++;
			}
		}

	}


}A, B;


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> P[i];
	in >> k;

}

bool judge(LL x){
	
	LL num = 0;
	int pos = B.ans.size() - 1;
	for (int i = 1; i < A.ans.size(); ++i){
		while (pos > 1 && ( A.ans[i] * B.ans[pos] > x)){
			pos--;
		}
		if (A.ans[i] * B.ans[pos] <= x)
			num += pos;
		if (num >= k)
			return 1;
	}
	return 0;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		A.n = B.n = 1;
		for (int i = 1; i <=n; ++i){
			if (i <= n / 2){
				if (i % 2 == 0){
					A.p[A.n++] = P[i];
				}
				else{
					B.p[B.n++] = P[i];
				}
			}
			else{
				if (i % 2 != 0){
					A.p[A.n++] = P[i];
				}
				else{
					B.p[B.n++] = P[i];
				}
			}
		}
		
		A.n--;
		B.n--;
		A.cale();
		B.cale();

		LL L = 1, R = LL(1e18) + 10;
		LL ans;
		while (L <= R){
			LL mid = (L + R) / 2;
			if (judge(mid)){
				ans = mid;
				R = mid - 1;
			}
			else{
				L = mid + 1;
			}
		}

		cout << ans << endl;










	}


	return 0;
}





