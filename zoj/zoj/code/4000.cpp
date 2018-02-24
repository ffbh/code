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
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

int N, R;
int x[100010], y[100010];

const double PI = acos(-1.0);
const double EXP = 1e-7;
void input(){
	in >> N >> R;
	for (int i = 1; i <= N; ++i)
		in >> x[i] >> y[i];
}

bool equal(double a, double b){

	return fabs(a - b) < EXP;
}

void JDZH(double& A){
	while (A < 0){
		A += 360;
	}
	while (A > 360){
		A -= 360;
	}
	if (equal(A, 360)){
		A = 0;
	}
}


bool IN(pair<double, double> P, double m){
	if (equal(P.first, m) || equal(P.second, m))
		return 0;
	if (P.first < P.second){

		return P.first < m && m < P.second;
	}
	else{

		return m < P.second || m > P.first;
	}
}

int main(){

	//	double arc = atan2(-1, -1);
	//	cout << arc *360 / 2 / PI<< endl;

	//	cout << arc << endl;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		vector<pair<double, double> > all;
		int add = 0;
		for (int i = 1; i <= N; ++i){
			if (x[i] * x[i] + y[i] * y[i] <= R * R){
				add++;
			}
			else{
				double ppp = atan2(y[i], x[i]);
				double mid = ppp * 180 / PI;

				JDZH(mid);

				double large = sqrt((double)x[i] * x[i] + y[i] * y[i]);
				double ppppp = acos(double(R) / large);
				double delta = ppppp * 180 / PI;
				double kl = mid - delta;
				double kr = mid + delta;
				JDZH(kl);
				JDZH(kr);
				all.push_back(mp(kl, kr));



			}
		}

		vector<pair<double, int> > KKK;
		for (pair<double, double> p : all){
			assert(p.first >= 0 && p.first <= 360 && p.second >= 0 && p.second <= 360);
			KKK.push_back(mp(p.first, -1));
			KKK.push_back(mp(p.second, 1));
		}

		sort(KKK.begin(), KKK.end());


		int now = N - add;

		for (pair<double, double> p : all){
			if (IN(p, 0)){
				now--;
			}
		}
		int mmax = now;

		int pos = 0;
		while (pos < KKK.size()){
			
			double v = KKK[pos].first;
			if (equal(v, 0)){
				if (KKK[pos].second == 1){
					pos++;
					continue;
				}
				else{
					now--;
					pos++;
					continue;
				}
			}
			int del = 0;
			while (pos < KKK.size() && equal(v, KKK[pos].first)){
				if (KKK[pos].second == 1){
					now++;
				}
				else{
					del++;
				}
				pos++;
			}
			mmax = max(mmax, now);
			if (mmax == 6){
				int t = 0;
			}
			now -= del;

		}

		cout << mmax + add << endl;



	}


	return 0;
}




