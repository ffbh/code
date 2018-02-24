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

long long N, K, a[10010];
int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N >> K;
	for (int i = 1; i <= N; ++i)
		in >> a[i];
	sort(a + 1, a + N + 1);
	int ans = 0;
	for (int i = 1; i <= N; ++i){
		while (K * 2 < a[i]){
			K *= 2;
			ans++;
		}

		K = max(K, a[i]);
	}

	cout << ans << endl;
















	return 0;
}





