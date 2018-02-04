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
using namespace std;

map<int, int> mmp;

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;


	int N;
	in >> N;
	for (int i = 0; i < N; ++i){
		int s, e;
		in >> s >> e;
		mmp[s]++;
		mmp[e]--;
	}
	int ans = 0, now = 0;
	map<int, int>::iterator it = mmp.begin();
	while (it != mmp.end()){
		now += it->second;
		ans = max(ans, now);
		it++;
	}

	cout << ans << endl;




	return 0;
}





