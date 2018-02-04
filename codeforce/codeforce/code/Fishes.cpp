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


LL n, m, r, k;


void input(){
	in >> n >> m >> r >> k;


}

LL ccc(LL len, LL now){
	LL a = now - r + 1;
	if (a <= 0)
		a = 1;
	LL b = a + r - 1;
	return min(len - b + 1, now - a + 1);
}


LL cale(LL x, LL y){

	return ccc(n, x)*ccc(m, y);

}

int dirs[8][2] = { 1, 0, 0, 1, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1 };
unordered_set<LL> mmp;
vector<LL> V;
bool IN(pii& p){
	return p.first >= 1 && p.first <= n&&p.second >= 1 && p.second <= m;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		//	cout << 36 * 32.8333333333 << endl;

		LL fenmu = (n - r + 1)*(m - r + 1);

		if (n*m <= 2000000){

			for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				V.push_back(cale(i, j));
		}
		else{
			double y = sqrt(1e5*m / n);
			double x = 1e5 / y;
			double fac = 4.5;
			int X = (int)(x*fac);
			int Y = (int)(y*fac);
		
			int midx = n / 2;
			int midy = m / 2;
			int sx = max(1, midx - X);
			int ex = min((int)n, midx + X);
			int sy = max(1, midy - Y);
			int ey = min((int)m, midy + Y);
			for (int i = sx; i <= ex;++i)
			for (int j = sy; j <= ey; ++j){
				V.push_back(cale(i, j));
			}
		}
		sort(V.begin(), V.end(), greater<LL>());
		LL fenzi = 0;
		for (int i = 0; i < k; ++i){

			fenzi += V[i];

		}
		printf("%.11f\n", double(fenzi) / fenmu);
















	}


	return 0;
}


