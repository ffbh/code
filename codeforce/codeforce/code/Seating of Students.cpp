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



int n, m;


void input(){

	in >> n >> m;

}
vector<int> vi[100010];
int mmp[2][100010];
int MP[100010];

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

int cslelll(int x,int y){
	return (x - 1)*m + y;
}

bool cale(){
	for (int i = 1; i <= n; ++i){
		vi[i].push_back(-1);
		for (int j = 1; j <= m; ++j){
			vi[i].push_back((i - 1)*m + j);
		}
	}
	if (n*m == 1){
		return 1;
	}

	if (n == 3 && m == 3){
		vector<int> arr;
		bool ok[10][10] = { 0 };
		for (int i = 0; i < 9; ++i)
			arr.push_back(i + 1);
		for (int i = 1; i <= 3;++i)
		for (int j = 1; j <= 3; ++j){
			for (int k = 0; k < 4; ++k){
				int x = i + dirs[k][0];
				int y = j + dirs[k][1];
				if (x >= 1 && x <= 3 && y >= 1 && y <= 3){
					ok[vi[i][j]][vi[x][y]] = 1;
				}
			}

		}

		while (next_permutation(arr.begin(), arr.end())){
			int pos = 0;
			for (int i = 1; i <= 3;++i)
			for (int j = 1; j <= 3; ++j)
				vi[i][j] = arr[pos++];
			bool end = 1;
			for (int i = 1; i <= 3; ++i)
			for (int j = 1; j <= 3; ++j){
				for (int k = 0; k < 4; ++k){
					int x = i + dirs[k][0];
					int y = j + dirs[k][1];
					if (x >= 1 && x <= 3 && y >= 1 && y <= 3){
						if (ok[vi[i][j]][vi[x][y]]){
							end = 0;
						}
					}
				}
			}
			if (end){
				return 1;
			}
			
		}


	}

	if (n <= m){

		if (m <= 3){
			return 0;
		}

		int pos = 1;
		int st = m;
		if (st % 2 == 0)
			st--;

		for (int i = st; i >= 1; i -= 2){
			MP[pos++] = i;
		}
		for (int i = m / 2 * 2; i >= 1; i -= 2){
			MP[pos++] = i;
		}
		if (m % 2 == 0){
			for (int i = 1; i <= m; ++i)
				mmp[0][i] = MP[i];
			for (int i = 1; i <= m; ++i){
				mmp[1][i] = MP[m - i + 1];
			}
		}
		else{

			for (int i = 1; i < m; ++i)
				mmp[0][i] = MP[i + 1];
			mmp[0][m] = MP[1];
			for (int i = 2; i <= m; ++i)
				mmp[1][i] = MP[i - 1];
			mmp[1][1] = MP[m];

		}
		for (int i = 1; i <= n; ++i){
			int f = i % 2;
			for (int j = 1; j <= m; ++j){
				vi[i][j] = cslelll(i, mmp[f][j]);
			}
		}
	}
	else{
		if (n <= 3){
			return 0;
		}
		int pos = 1;
		int st = n;
		if (st % 2 == 0)
			st--;

		for (int i = st; i >= 1; i -= 2){
			MP[pos++] = i;
		}
		for (int i = n / 2 * 2; i >= 1; i -= 2){
			MP[pos++] = i;
		}
		if (n % 2 == 0){
			for (int i = 1; i <= n; ++i)
				mmp[0][i] = MP[i];
			for (int i = 1; i <= n; ++i){
				mmp[1][i] = MP[n - i + 1];
			}
		}
		else{

			for (int i = 1; i < n; ++i)
				mmp[0][i] = MP[i + 1];
			mmp[0][n] = MP[1];
			for (int i = 2; i <= n; ++i)
				mmp[1][i] = MP[i - 1];
			mmp[1][1] = MP[n];

		}

		for (int i = 1; i <= m; ++i){
			int f = i % 2;
			for (int j = 1; j <= n; ++j){
				vi[j][i] = cslelll(mmp[f][j],i);
			}
		}


	}
	return 1;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		

		if (cale()){
			cout << "YES" << endl;





			for (int i = 1; i <= n; ++i){
				for (int j = 1; j <= m; ++j){
					printf("%d ", vi[i][j]);
				}
				printf("\n");
			}



		}
		else{
			cout << "NO" << endl;
		}












	}


	return 0;
}





