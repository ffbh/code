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
	while (b > 0){
		sum += a;
		a = (a + 1) % 11;
		b--;
	}
	return sum % 11;
}

void input(){
	in >> str;


}

int dp[2][11][11][11];

inline int cale(int pos, int st_m, int now_m, int en_m){

	
	pos++;
	if (pos == str.length()){
		return 0;
	}

	

	int np = pos % 2;
	int fp = 1 - np;
	int& ref = dp[np][st_m][now_m][en_m];

	int c = str[pos] - '0';
	if (c >= now_m)
		return ref = 0;

	int small = (now_m - st_m + 11) % 11;
	int large = (en_m - now_m + 11) % 11;



	small = M[st_m][small] + c;
	large = now_m - 1 + 11  - c + M[(now_m + 1) % 11][large];

	now_m = (en_m + small + 1) % 11;
	st_m = (en_m + 1) % 11;
	en_m = (en_m + small + 1 + large) % 11;

	return ref = 1 + dp[fp][st_m][now_m][en_m];
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
	//for (int i = 0; i<100010;++i)
	//for (int j = 0; j<11;++j)
	//for (int k = 0; k<11; ++k)
	//for (int e = 0; e<11; ++e)
	//	dp[i][j][k][e] = INF;

	while (TEST_CASE-- > 0){
		input();

		LL ans = 0;
		for (int i = str.length()-1; i>=0; --i) {
			for (int j = 0; j < 11;++j)
			for (int k = 0; k < 11;++k)
			for (int e = 0; e < 11; ++e){
				cale(i, j, k, e);
			}
		//	cout << dp[(i % 2)][1][str[i] - '0'][9] << endl;
			if (str[i] != '0'){
				ans++;
				ans += dp[1-(i % 2)][1][str[i] - '0'][9];
			}
		//	cout << cale(i, 1, str[i] - '0', 9) << endl;
			//        cout<<cale(i)<<endl;
		}
		cout << ans << endl;




	}


	return 0;
}