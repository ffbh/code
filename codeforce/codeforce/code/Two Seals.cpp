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
int n, a, b;
int x[110],y[110];

bool cale(int x1,int y1,int x2,int y2){
	bool ret = 0;
	if (x1 + x2 <= a ){
		ret = max(ret ,max(y1 , y2) <= b);
	}
	if (x1 + x2 <= b){
		ret = max(ret, max(y1 , y2) <= a);
	}

	if (x1 + y2 <= a){
		ret = max(ret,max( x2 , y1) <= b);
	}
	if (x1 + y2 <= b){
		ret = max(ret, max(x2 , y1) <= a);
	}
	if (x2 + y1 <= a){
		ret = max(ret,max( x1 , y2) <= b);
	}
	if (x2 + y1 <= b){
		ret = max(ret, max(x1 , y2) <= a);
	}
	if (y1 + y2 <= a){
		ret = max(ret, max(x1 , x2) <= b);
	}
	if (y1 + y2 <= b){
		ret = max(ret,max( x1 , x2) <= a);
	}
	return ret;
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
		in >> x[i] >> y[i];

	int ans = 0;
	for (int i = 1; i <= n;++i)
	for (int j = i + 1; j <= n; ++j){
		int ret = cale(x[i],y[i],x[j],y[j]);
		if (ret){
			ans = max(ans, x[i] * y[i] + x[j] * y[j]);
		}

	}

	cout << ans << endl;












	return 0;
}





