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
using namespace std;
#define pii pair<int,int>
int n;
map<int, int> tv;
void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	for (int i = 1; i <= n; ++i){
		int l, r;
		in >> l >> r;
		tv[l]++;
		tv[r + 1]--;
	}

}

bool judge(){
	int sim = 0;
	for (pii p : tv){
		sim += p.second;
		if (sim > 2){
			return 0;
		}

	}
	return 1;
}

int main(){
	input();
	

	if (judge()){
		cout << "YES" << endl;
	}

	else
		cout << "NO" << endl;













	return 0;
}





