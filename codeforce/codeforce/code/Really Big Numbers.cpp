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
long long n, s;

long long sum(long long p){
	long long ret = 0;
	while (p){
		ret += p % 10;
		p /= 10;
	}
	return ret;

}

long long ok(long long mid){
	return mid - sum(mid) >= s;
}


int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> s;

	long long L, R;
	L = 1;
	R = n;
	long long ans = n + 1;
	while (L <= R){
		long long mid = (L + R) / 2;
		if (ok(mid)){
			ans = mid;
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}

	if (ans > n)
		cout << 0 << endl;
	else{
		cout << n - ans + 1 << endl;
	}



	return 0;
}





