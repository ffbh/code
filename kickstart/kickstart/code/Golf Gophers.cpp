
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


int N, M;

void input(){
	fflush(stdin);
	fflush(stdout);
	in >> N >> M;
	fflush(stdin);
	fflush(stdout);

}

bool ans[7][1000310];
bool ooo[1000310];
int a[20];
int v[20];



int prime[7] = { 2, 3, 5, 7, 11, 13, 17 };

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < 1000310; ++i)
			ans[0][i] = 1;

	//	srand(time(0));
		for (int i = 1; i <= 7; ++i){
			fflush(stdin);
			fflush(stdout);
			set<int> P;
			P.insert(0);
			for (int j = 1; j <= 18; ++j){
			//	srand(time(0));
			//	int vv = abs(rand()) % 17;
				a[j] = prime[i - 1];
				cout << a[j] << " ";
				P.insert(a[j]);
			}
			cout << endl;
			fflush(stdin);
			fflush(stdout);
			for (int j = 1; j <= 18; ++j){
				in >> v[j];
				
			}
			fflush(stdin);
			fflush(stdout);
			int sum = 0;
			for (int j = 1; j <= 18; ++j){
				int k = v[j];
			//	k = (a[j] - k) % a[j];
				sum += k;
			}
			memset(ooo, 0, sizeof(ooo));
			ooo[0] = 1;
			for (int k = 0; k <= M; ++k){
				if (ooo[k]){
					for (int p : P){
						ooo[k + p] = 1;
					}
				}
			}
			for (int k = 0; k <= M; ++k){
				if (ans[i - 1][k] && ooo[k])
					ans[i][k] = 1;
			}
			
		}

		int num = 0;
		for (int i = 1; i <= M; ++i){
			if (ans[7][i]){
				fflush(stdin);
				fflush(stdout);
				cout << i << endl;
				fflush(stdin);
				fflush(stdout);
				num++;
			}
		}

	//	assert(num == 1);
		fflush(stdin);
		fflush(stdout);
		int cost;
		in >> cost;
		fflush(stdin);
		fflush(stdout);


	}


	return 0;
}





