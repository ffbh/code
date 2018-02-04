#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node{
	_int64 x, y;
}data[100010];
struct XY{
	_int64 val, id;
	bool operator<(const XY& p)const{
		return val < p.val;
	}
}x[100010], y[100010];

struct Ans{
	_int64 x, y;
}ans[100010];


int main(){
	ifstream in("C:\\temp.txt");
	int T, N;
	cin >> T;
	while (T--){
		cin >> N;
		_int64 sumx, sumy, sum;
		sumx = sumy = 0;
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= N; ++i){
			cin >> data[i].x >> data[i].y;
			x[i].val = data[i].x;
			y[i].val = data[i].y;
			x[i].id = y[i].id = i;
			sumx += data[i].x;
			sumy += data[i].y;
		}
		sort(x + 1, x + N + 1);
		sort(y + 1, y + N + 1);
		sum = 0;
		for (int i = 2; i <= N; ++i){
			sum += (i-1)*(x[i].val - x[i - 1].val);
			ans[x[i].id].x += sum;
		}
		sum = 0;
		for (int i = N-1; i >=1; --i){
			sum += (N - i)*(x[i + 1].val - x[i].val);
			ans[x[i].id].x += sum;
		}
		sum = 0;
		for (int i = 2; i <= N; ++i){
			sum += (i - 1)*(y[i].val - y[i - 1].val);
			ans[y[i].id].y += sum;
		}
		sum = 0;
		for (int i = N-1; i>=1; --i){
			sum += (N - i)*(y[i + 1].val - y[i].val);
			ans[y[i].id].y += sum;
		}
		_int64 mmin = (1e18);
		for (int i = 1; i <= N;++i)
		if (mmin > ans[i].x + ans[i].y)
			mmin = ans[i].x + ans[i].y;
		cout << mmin << endl;
	}
	return 0;
}