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
int  N;
map<int, int> mii;

long long C(long long n,long long m){
	long long ans = 1;
	for (int i = 0; i < m; ++i)
		ans *= (n - i);
	for (int i = 1; i <= m; ++i)
		ans /= i;
	return ans;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	
	in >> N;
	for (int i = 0; i < N; ++i){
		int a;
		in >> a;
		mii[a]++;
	}
	map<int, int>::iterator it = mii.begin();
	long long need = 3;
	while (1){
		long long num = it->second;
		if (num >= need){
			cout << C(num, need) << endl;
			break;
		}
		need -= num;
		it++;
	}
	


	
	return 0;
}





