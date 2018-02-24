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
#define lson (root<<1)  
#define rson (root<<1|1)  


int n;
double x[5], y[5], r[5], Max_x, Min_x, Max_y, Min_y;
int xx[5], yy[5], rr[5];
void input(){
	Max_x = Max_y = -30;
	Min_x = Min_y = 30;
	in >> n;
	for (int i = 1; i <= n; ++i){
		in >> xx[i] >> yy[i] >> rr[i];
		x[i] = xx[i];
		y[i] = yy[i];
		r[i] = rr[i];
		Max_x = max(Max_x, x[i]);
		Max_y = max(Max_y, y[i]);
		Min_x = min(Min_x, x[i]);
		Min_y = min(Min_y, y[i]);
	}
	for (int i = n + 1; i <= 3; ++i){
		x[i] = x[i - 1];
		y[i] = y[i - 1];
		r[i] = r[i - 1];
	}

}

bool out_connect(int a,int b){
	return pow(xx[a] - xx[b], 2) + pow(yy[a] - yy[b], 2) == (pow(rr[a] + rr[b], 2));
}

bool IN(int pos,double X,double Y){
	double R = r[pos] * r[pos];
	double S = (x[pos] - X)*(x[pos] - X) + (y[pos] - Y)*(y[pos] - Y);
	return S < R;

}




int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		set<int> si;
		double delta = 1.0 / 200;
		for (double a = -21; a < 21;a += delta)
		for (double b = -21; b < 21; b += delta){
			int key = 0;
			for (int i = 1; i <= 3; ++i){
				key = key * 2 + IN(i, a, b);
			}
			if (key == 0){
				if (a>Min_x&&a<Max_x&&b>Min_y&&b < Max_y){
					key += 10;
				}
			}
			si.insert(key);
		}
		cout << si.size() << endl;













	}


	return 0;
}





