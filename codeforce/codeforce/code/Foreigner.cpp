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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)
#define INF (111111)

string str;

int M[11][11];

inline int get_m(int a, int b){
	int sum = 0;
	while (a != b){
		sum += a;
		a = (a + 1) % 11;
	}
	return sum % 11;
}

void input(){
	in >> str;


}

int dp[100010][11][11][11];

inline int cale(int pos, int st, int mid, int en){

	int& ref = dp[pos][st][mid][en];
	if (ref != INF)
		return ref;
	pos++;
	if (pos == str.length()){
		return 0;
	}



	int now_m = mid;
	int st_m = st;
	int en_m = en;
	int small = (mid - st + 11) % 11;
	int large = (en - mid + 11) % 11;


	int c = str[pos] - '0';
	if (c >= now_m)
		return ref = 0;

	int small_1 = M[st_m][(st_m + small) % 11];
	int small_2 = c;

	small = (small_1 + small_2) % 11;

	int next_m = (en_m + small + 1) % 11;

	int large_1 = now_m - 1 - c;
	int large_2 = M[(now_m + 1) % 11][(now_m + 1 + large) % 11];
	large = (large_1 + large_2) % 11;

	now_m = next_m;
	st_m = (en_m + 1) % 11;
	en_m = (en_m + small + 1 + large) % 11;

	return ref = 1 + cale(pos,st_m,now_m,en_m);
}



int main(){
	//set<int> S;
	//for (int i = 1; i <= 9; ++i)
	//	S.insert(i);

	//auto p = S.begin();
	//int m = 1;
	//while (true){
	//	int k = *S.begin();
	//	if (k > 10000){
	//		break;
	//	}
	//	S.erase(S.begin());
	//	for (int i = 0; i < m; ++i){
	//		S.insert(k * 10 + i);
	//	}
	//	cout << k << " " << m << endl;
	//	m = (m + 1) % 11;
	//}


/*
	return 0;*/



	for (int i = 0; i<11; ++i) {
		for (int j = 0; j < 11; ++j) {
			M[i][j] = get_m(i, j);
		}
	}
	
	int TEST_CASE = 1;
	// in >> TEST_CASE;
	for (int i = 0; i<100010;++i)
	for (int j = 0; j<11;++j)
	for (int k = 0; k<11; ++k)
	for (int e = 0; e<11; ++e)
		dp[i][j][k][e] = INF;

	while (TEST_CASE-- > 0){
		input();

		LL ans = 0;
		for (int i = str.length()-1; i>=0; --i) {
			if (str[i] == '0')
				continue;
			ans += cale(i,1,str[i]-'0',9);
			ans++;
	//		cout << cale(i, 1, str[i] - '0', 9) << endl;
			//        cout<<cale(i)<<endl;
		}
		cout << ans << endl;




	}


	return 0;
}