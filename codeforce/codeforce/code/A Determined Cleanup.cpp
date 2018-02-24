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

vector<LL> ce;
LL p, k;

void input(){
	in >> p >> k;


}

bool cale(){
	ce.clear();
	LL f = p;
	while (f != 1 && f != 0){
		LL c = -f / k;

		if (f%k != 0 && f < 0){
			ce.push_back(++c);
		}
		else{
	//		if (c == 0)
	//			return 0;
			ce.push_back(c);
		}
		f = c;
	}
	return 1;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (p < k){
			cout << 1 << endl;
			cout << p << endl;
			return 0;
		}

		if (!cale()){
			cout << -1 << endl;
			return 0;
		}

		map<LL, LL> M;
		for (int i = 0; i < ce.size(); ++i){
			M[i + 1] += ce[i];
			M[i] += k*ce[i];
		}
		M[0] += p;
		while ((--M.end())->second == 0)
			M.erase(--M.end());
		cout << M.size() << endl;
		for (pll p : M){
			cout << p.second << " ";
		}
		cout << endl;










	}


	return 0;
}





