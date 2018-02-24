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


int n;
LL a[200010];
vector<pii> A, B;



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

int vis[200010];


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		LL aim = n / 2;
		for (int i = 1; i <= n; ++i){
			LL sq = sqrt(a[i]);
			if (sq * sq == a[i]){
				aim--;
			}

		}
		if (aim >= 0){

			for (int i = 1; i <= n; ++i){
				LL sq = sqrt(a[i]);
				if (sq*sq == a[i]){
					A.push_back(mp(0, i));
					B.push_back(mp(0, i));
				}
				else{
					A.push_back(mp(a[i] - sq*sq, i));
					B.push_back(mp((sq + 1)*(sq + 1) - a[i], i));
				}
			}
		}
		else{
			for (int i = 1; i <= n; ++i){
				LL sq = sqrt(a[i]);
				if (sq * sq == a[i]){
					if (sq == 0){
						A.push_back(mp(2, i));
						B.push_back(mp(2, i));
					}
					else{
						A.push_back(mp(1, i));
						B.push_back(mp(1, i));
					}
				}
				else{
					A.push_back(mp(0, i));
					B.push_back(mp(0, i));

				}
			}


		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		LL ans = 0;
		int apos, bpos;
		apos = bpos = 0;
		int num = 0;
		while (num < n / 2){
			while (vis[A[apos].second])
				apos++;
			while (vis[B[bpos].second])
				bpos++;
			if (A[apos].first < B[bpos].first){
				ans += A[apos].first;
				vis[A[apos].second] = 1;
			}
			else{
				ans += B[bpos].first;
				vis[B[bpos].second] = 1;
			}
			num++;

		}

		
	

		cout << ans << endl;
		









	}


	return 0;
}





