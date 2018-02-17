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

void input(){
	in >> n;


}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		LL ans = 0;
		for (int i = 1; i <= n;++i)
		for (int j = i + 1; j <= n; ++j){
			if ((i^j)<=n&&(i^j) > j &&(i+j)>(i^j)){
				ans++;
		//		cout << i << " " << j << " " << (i^j) << endl;
				
			}
		}
		
		cout << ans << endl;












	}


	return 0;
}





