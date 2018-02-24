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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

int D, R;
int n;



void input(){
	in >> R >> D;
	in >> n;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = 0;
		
		for (int i = 1; i <= n; ++i){
			int x, y, r;
			in >> x >> y >> r;
			int dist = x*x + y*y;
			if (x == 0 && y == 6){
				int t = 0;
			}
			if (dist >= (R - D + r)*(R - D + r) && dist <= (R - r)*(R - r)){
				ans++;
		//		cout << x << " " << y << " " << r << endl;
			}

		}
		cout << ans << endl;












	}


	return 0;
}





