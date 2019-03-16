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
#define pdd pair<double,double>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  

LL n, K;
double v[20010];



void input(){
	in >> n >> K;
	for (int i = 1; i <= n; ++i){
		LL tmp;
		in >> tmp;
		v[i] = tmp;
	}


}


double dp[50010];
double SUM[20010];
double SV[20010];
double P[20010];
int N;
inline double getSV(int pp){
	if (pp<0){
		pp = 0;
	}
	assert(pp<=N);

	

	if (pp == 0){
		return SV[N];
	}
	else{
		return SV[N] - SV[pp - 1];
	}
}

inline double getSUM(int pp){
	if (pp<0)
		pp = 0;
	assert(pp<=N);
	if (pp == 0){
		return SUM[N];
	}
	else{
		return SUM[N] - SUM[pp - 1];
	}
}
double Exp = 1e-10;
inline bool equal(double a,double b){
	return fabs(a - b) < Exp;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	int CPP = 1;
	while (TEST_CASE-- > 0){
		input();


		sort(v + 1, v + n + 1);
		vector<pdd> V;
		for (int i = 1; i <= n; ++i){
			if (V.empty() || V.back().second != v[i]){
				V.push_back(mp(1, v[i]));
			}
			else{
				V.back().first++;
			}
		}
		N = V.size() - 1;
		SUM[0] = V[0].first;
		SV[0] = V[0].second * V[0].first;
		for (int i = 1; i <= N; ++i){
			SUM[i] = SUM[i - 1] + V[i].first;
			SV[i] = SV[i - 1] + V[i].second * V[i].first;
		}


		double S = 0;
		for (int i = 0; i <= N; ++i){
			S += V[i].first  * V[i].second;
			P[i] = S / n;
		}



		dp[0] = P[N];
		int pos = 0;
		for (int k = 1; k <= K; ++k){
			while (pos < V.size() && (V[pos].second < dp[k - 1] )){
				pos++;
			}
			pos--;
			double rechoose = 0;
			if (pos >= 0){
				rechoose = SUM[pos] / n;
			}
			double a = getSV(pos + 1);
			double b = getSUM(pos + 1);
			double end = getSV(pos + 1) / getSUM(pos + 1);
			if (equal(b, 0)){
				end = 0;
			}
			dp[k] = rechoose* dp[k - 1] + (1 - rechoose) *end ;
		}

		printf("Case #%d: %.8f\n",CPP++, dp[K]);







	}


	return 0;
}





