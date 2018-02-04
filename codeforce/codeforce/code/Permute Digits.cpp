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

string A, B;



void input(){
	in >> A >> B;


}

int num[266];
string ans;
bool dfs(int pos,bool ok){
	if (pos == B.length()){
		return 1;
	}
	if (ok){
		char p = '9';
		while (num[p] == 0)
			p--;
		num[p]--;
		ans[pos] = p;
		return dfs(pos + 1, ok);
	}
	else {
		for (char p = B[pos]; p >= '0'; p--){
			if (num[p] > 0){
				ans[pos] = p;
				num[p]--;
				if (dfs(pos + 1, p != B[pos]))
					return 1;
				num[p]++;
			}
		}
		return 0;
	}
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		assert(A.length() <= B.length());

		if (A.length() < B.length()){
			sort(A.begin(), A.end(), greater<char>());
			cout << A << endl;
		}
		else{
			for (char c : A)
				num[c]++;
			ans = B;
			dfs(0, 0);
			cout << ans << endl;
		}
		
	}
	return 0;
}





