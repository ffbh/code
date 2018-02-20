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

int n, a[5010];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		vector<int> vi;
		for (int i = 1; i <= n; ++i){
			vi.clear();
			vi.push_back(i);
			vi.push_back(a[vi.back()]);
			vi.push_back(a[vi.back()]);
			if (a[vi.back()] == i){
				cout << "YES" << endl;
				return 0;
			}
		}

		cout << "NO" << endl;












	}


	return 0;
}





