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

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	long long N, Q;
	while (in >> N >> Q){
		long long ans = N;
		long long num = 1;
		int buildtime = 0;
		for (int i = 0; i < 60; ++i){
			long long time = N / num + buildtime;
			if (N%num != 0)
				time++;
			ans = min(ans, time);
			num *= 2;
			buildtime += Q;
		}
		cout << ans << endl;

	}






















	return 0;
}





