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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}


int N;
void input(){
	in >> N;
}


//pii d[1010 * 1010];
//unordered_map<int, int> M;
//int K;
//void get_snake(){
//
//	in >> K;
//	for (int i = 1; i <= K; ++i){
//		in >> d[i].first >> d[i].second;
//		int h = d[i].first * 1010 + d[i].second;
//		M[h] = i;
//	}
//}
//
//bool IN(int x1, int y1, int x2, int y2,int x,int y){
//	return x >= x1&&x <= x2&&y >= y1&&y <= y2;
//}

//int query(int x1, int y1, int x2, int y2){
//	int v = 0;
//	for (int i = x1; i <= x2;++i)
//	for (int j = y1; j <= y2; ++j){
//		int pos = -1;
//		int h = i * 1010 + j;
//		if (M.count(h)){
//			pos = M[h];
//		}
//		if (pos == -1)
//			continue;
//		if (pos - 1 >= 1){
//			if (!IN(x1, y1, x2, y2, d[pos - 1].first, d[pos - 1].second)){
//				v++;
//			}
//		}
//		if (pos + 1 <= K){
//			if (!IN(x1, y1, x2, y2, d[pos + 1].first, d[pos + 1].second)){
//				v++;
//			}
//		}
//	}
//	return v;
//}

int query(int x1,int y1,int x2,int y2){
	FFLUAHALL;
	cout << "?" << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	FFLUAHALL;
	int ttt;
	in >> ttt;
	FFLUAHALL;
	return ttt;
}

void print(int x1, int y1, int x2, int y2){
	FFLUAHALL;
	cout << "!" << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	FFLUAHALL;

}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

 //    	get_snake();

		vector<int> X, Y;
		for (int i = 1; i < N; ++i){
			int v = query(1, 1, i, N);
			if (v % 2 == 1){
				if (X.empty()){
					X.push_back(i);
				}
			}
			else{
				if (!X.empty()){
					X.push_back(i);
					break;
				}
			}
		}

		if (X.size() == 1){
			X.push_back(N);
		}

		for (int i = 1; i < N; ++i){
			int v = query(1, 1, N, i);
			if (v % 2 == 1){
				if (Y.empty()){
					Y.push_back(i);
				}
			}
			else{
				if (!Y.empty()){
					Y.push_back(i);
					break;
				}
			}
		}

		if (Y.size() == 1){
			Y.push_back(N);
		}

		assert(X.size() % 2 == 0 && Y.size() % 2 == 0 && (X.size() + Y.size() == 2 || X.size() + Y.size()==4));
		vector<pii> ans;
		if (X.size() == 2 && Y.size() == 2){
			for (int x : X)
			for (int y : Y){
				if (query(x, y, x, y) == 1){
					ans.push_back(mp(x, y));
				}
			}
		}
		else if (X.size() == 2){
			int x = X[0];
			int l = 1, r = N;
			while (l < r){
				int m = (l + r) / 2;
				int v = query(1, l, x, m);
				if (v % 2 == 1){
					r = m;
				}
				else{
					l = m + 1;
				}

			}
			assert(l == r);
			ans.push_back(mp(x, l));

			x = X[1];
			l = 1;
			r = N;
			while (l < r){
				int m = (l + r) / 2;
				int v = query(x, l, N, m);
				if (v % 2 == 1){
					r = m;
				}
				else{
					l = m + 1;
				}

			}
			assert(l == r);
			ans.push_back(mp(x, l));

		}
		else{
			int y = Y[0];
			int l = 1, r = N;
			while (l < r){
				int m = (l + r) / 2;
				int v = query(l, 1, m, y);
				if (v % 2 == 1){
					r = m;
				}
				else{
					l = m + 1;
				}

			}
			assert(l == r);
			ans.push_back(mp(l, y));

			y = Y[1];
			l = 1;
			r = N;
			while (l < r){
				int m = (l + r) / 2;
				int v = query(l, y, m, N);
				if (v % 2 == 1){
					r = m;
				}
				else{
					l = m + 1;
				}

			}
			assert(l == r);
			ans.push_back(mp(l, y));

		}

		print(ans[0].first, ans[0].second, ans[1].first, ans[1].second);








	}


	return 0;
}





