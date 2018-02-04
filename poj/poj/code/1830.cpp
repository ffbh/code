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
#include <set>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;





void input(){
	


}


int K, N;
bool mmp[40][40];
int A[40], B[40];
LL hbit[40];


void add(LL k){
	for (LL i = 32; i >= 0; --i){
		if (((LL)1 << i)&k){
			if (hbit[i] == -1){
				hbit[i] = k;
				break;
			}
			else{
				k ^= hbit[i];
			}

		}

	}
}

int main(){
	input();

	in >> K;
	while (K-- > 0){
		memset(mmp, 0, sizeof(mmp));
		memset(hbit, -1, sizeof(hbit));
		in >> N;
		for (int i = 0; i < 40; ++i)
			mmp[i][i] = 1;

		for (int i = 0; i < N; ++i){
			in >> A[i];
		}

		for (int i = 0; i < N; ++i){
			in >> B[i];
		}

		for (int i = 0; i < 40; ++i){
			if (A[i] == 1){
				B[i] = 1 - B[i];
			}
		}

		while (1){
			int a, b;
			in >> a >> b;
			if (a == 0 && b == 0)
				break;
			a--;
			b--;
			mmp[a][b] = 1;
		}



		for (int i = 0; i < N; ++i){
			LL key = 0;
			for (int j = 0; j < N; ++j)
				key = key * 2 + mmp[i][j];

			add(key);

		}

		LL aim = 0;
		for (int i = 0; i < N; ++i)
			aim = aim * 2 + B[i];
		int num[40] = { 0 };
		LL ans = 1;
		for (int i = N - 1; i >= 0; --i){
			if (hbit[i] == -1){
				if (num[i] == 1 && !(aim & ((LL)1 << i)) || num[i] != 1 && (aim & ((LL)1 << i))){
					ans = 0;
					break;
				}
				else{
					ans *= 2;

				}
			}
			else{
				if (aim & ((LL)1 << i)){
					for (int j = 0; j < 40; ++j){
						if (hbit[i] & ((LL)1 << j))
							num[j] = 1 - num[j];
					}

				}
			}


		}
		if (ans == 0){
			cout << "Oh,it's impossible~!!" << endl;
		}
		else{
			cout << ans << endl;
		}


	}

	

	return 0;
}





