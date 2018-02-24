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

int n;
vector<int> vi[1010];



void input(){
	in >> n;
	for (int i = 2; i <= n; ++i){
		int t;
		in >> t;
		vi[t].push_back(i);
	}


}

bool dfs(int p){
	if (vi[p].size() == 0)
		return 1;
	int num = 0;
	for (int son : vi[p]){
		if (!dfs(son))
			return 0;
		if (vi[son].size() == 0)
			num++;


	}

	return num >= 3;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();



		if (dfs(1)){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}











	}


	return 0;
}





