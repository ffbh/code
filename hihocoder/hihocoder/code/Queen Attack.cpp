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
unordered_map<int, long long> a, b, c, d;
int N;


long long cale(unordered_map<int,long long>& p){
	long long sum = 0;
	unordered_map<int, long long>::iterator it = p.begin();
	while (it != p.end()){
		sum += it->second*(it->second - 1) / 2;
		it++;
	}
	return sum;
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;
	for (int i = 0; i < N; ++i){
		int x, y;
		in >> x >> y;
		a[x]++;
		b[y]++;
		c[x + y]++;
		d[x - y]++;
	}

	long long ans = 0;
	ans += cale(a);
	ans += cale(b);
	ans += cale(c);
	ans += cale(d);



	cout << ans << endl;










	return 0;
}





