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
#define MMAX ((int)1e6)
int N;
int a[int(1e6) + 10];
long long b[int(1e6) + 10];
vector<pair<int, int> > all;






int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	//in >> N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	//		in >> a[i];
		scanf("%d", &a[i]);

	
	all.clear();
	long long ans = 0;
	b[0] = 0;
	for (int i = 1; i <= N; ++i){

		while (!all.empty() && all.back().first <= a[i])
			all.pop_back();

		if (all.empty()){
			b[i] = (long long)a[i] * i;
		}
		else{
			int idx = all.back().second;
			b[i] = (long long)a[i] * (i - idx) + b[idx];
		}
		ans += b[i];
		all.push_back(make_pair(a[i], i));
	}


	b[0] = 0;
	all.clear();
	for (int i = 1; i <= N; ++i){
		while (!all.empty() && all.back().first >= a[i])
			all.pop_back();


		if (all.empty()){
			b[i] = (long long)a[i] * i;
		}
		else{
			int idx = all.back().second;
			b[i] = (long long)a[i] * (i - idx) + b[idx];
		}
		ans -= b[i];
		all.push_back(make_pair(a[i], i));

	}


	cout << ans << endl;








	return 0;
}
