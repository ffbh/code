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

LL n, y[1010];



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> y[i];


}

bool judge(){
	vector<int> V;
	for (int i = 2; i <= n; ++i){
		V.clear();
		

		for (int j = 2; j <= n; ++j){
			if ((y[i] - y[1]) * (j - 1) != (y[j] - y[1]) *(i - 1)){
				V.push_back(j);
			}
		}
		if (V.size() == 0){
			continue;
		}
		if (V.size() == 1){
			return 1;
		}
		bool ok = 1;
		for (int j = 2; j < V.size(); ++j){
			if ((y[V[1]] - y[V[0]]) * (V[j] - V[0]) != (y[V[j]] - y[V[0]]) * (V[1] - V[0])){
				ok = 0;
				break;
			}
		}

		if (ok ){
			if ((y[i] - y[1])*(V[1] - V[0]) == (y[V[1]] - y[V[0]]) * (i-1))
				return 1;
		}

	}
	return 0;





}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
	
		if (judge()){
			cout << "YES" << endl;
		}
		else{
			int l = 1, r = n;
			while (l < r){
				swap(y[l], y[r]);
				l++;
				r--;
			}
			if (judge()){
				cout << "YES" << endl;
			}
			else
			cout << "NO" << endl;
		}











	}


	return 0;
}





