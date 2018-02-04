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
#define DEBUG (0)
#define INF (1<<29)
struct Node{
	int b, e, y;
	bool operator<(const Node& p)const{
		return y < p.y;
	}
}data[50];
int N;
set<int> si;
map<int, int> pi;
int pp[50];
int dp[30][2050];
int minb, maxe;

int J[2048][2048], C[2048][2048], F[2048][2048];

int judge(int a, int b){

	for (int i = 0; i < 11; ++i){
		if (((1 << i)&b) && (!((1 << i)&a)))
			return  0;
	}
	return  1;
}

int COST(int a, int b){
	int num = 0;
	for (int i = 0; i < 11; ++i){
		if (((1 << i)&a) && (!((1 << i)&b)))
			num++;
	}
	return   num;

}



int flow(int a, int b){




	vector<int> t1(11, 0);
	vector<int> t2(11, 0);
	vector<int> t3(11, 0);
	int size = 10;
	while (a){
		t1[size--] = a % 2;
		a /= 2;
	}
	size = 10;
	while (b){
		t2[size--] = b % 2;
		b /= 2;
	}

	for (int i = 0; i < 11; ++i){
		if (t1[i] == 0 || i < minb || i >= maxe)
			continue;
		if (t2[i] == 0){
			t3[i] = 1;
		}
		else{
			int l, r;
			l = r = i;
			while (l >= minb && t2[l] == 1)
				l--;
			l++;
			while (r < maxe && t2[r] == 1)
				r++;
			if (i - l == r - i){

				t3[l] = 1;
				t3[r] = 1;

			}
			else if (i - l < r - i){

				t3[l] = 1;

			}
			else{

				t3[r] = 1;

			}
		}
	}
	int key = 0;
	for (int i = 0; i < 11; ++i)
		key = key * 2 + t3[i];
	return key;
}


class AcidRain {
public:
	int saveHarvest(vector <int> b, vector <int> e, vector <int> y) {
		for (int i = 0; i < 30; ++i)
		for (int j = 0; j < 2050; ++j)
			dp[i][j] = INF;
		

		
		si.clear();
		pi.clear();

		N = b.size();
		minb = 12;
		maxe = -1;
		for (int i = 0; i < N; ++i){
			minb = min(minb, b[i]);
			maxe = max(maxe, e[i]);
			data[i].b = b[i];
			data[i].e = e[i];
			data[i].y = y[i];
			si.insert(y[i]);
		}

		sort(data, data + N);
		int size = 1;
		for (int a : si){
			pi[a] = size++;
		}

		for (int i = 0; i < N; ++i){
			data[i].y = pi[data[i].y];
		}

		int pos = 0;
		size = 1;
		while (pos < N){
			int now = data[pos].y;
			vector<int> t(11, 0);
			while (pos < N  && data[pos].y == now){
				for (int i = data[pos].b; i < data[pos].e; ++i)
					t[i] = 1;
				pos++;
			}
			int key = 0;
			for (int i = 0; i < 11; ++i)
				key = key * 2 + t[i];
			pp[size++] = key;
		}
		


		for (int i = 0; i < 2048; ++i)
		for (int j = 0; j < 2048; ++j){
			J[i][j] = judge(i, j);
			C[i][j] = COST(i, j);
			F[i][j] = flow(i, j);
		}


		int K = si.size();
		dp[K][2047] = 0;
		for (int k = K; k >= 1; --k){

			for (int i = 0; i < 2048; ++i){
				if (dp[k][i] == INF)
					continue;
				
				for (int j = 0; j < 2048; ++j){


					if (J[j][ pp[k]]){


						int cost = C[j][pp[k]];
						int ne = F[i][j];

						if (dp[k - 1][ne] > dp[k][i] + cost){
							dp[k - 1][ne] = dp[k][i] + cost;
						}
					}
				}
			}
		}
		vector<int> ans(11, 0);
		for (int i = minb + 1; i < maxe; ++i)
			ans[i] = 1;
		int key = 0;
		for (int i = 0; i < 11; ++i)
			key = key * 2 + ans[i];
		int ret = INF;
		for (int i = 0; i < 2048; ++i)
		if (!(i & key)){
			ret = min(ret, dp[0][i]);

		}

		return ret;
	}
};



#if 0
int main(){
	vector<int> a({ 0, 1 });
	vector<int> b({ 2, 4 });
	vector<int> c({ 1, 2 });


	AcidRain so;
	cout << so.saveHarvest(a, b, c) << endl;
















	return 0;
}
#endif

