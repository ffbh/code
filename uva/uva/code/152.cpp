#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int x[5010], y[5010], z[5010], size;
int d[5010], h[110], ans[12];
int main(){
	//ifstream in("C:\\input.txt");
	ios::sync_with_stdio(true);
	istream& in = cin;
	size = 0;
	//while (in >> x[size] >> y[size] >> z[size]){
	while (scanf("%d%d%d",&x[size],&y[size],&z[size])){
		d[size] = 19999999;
		if (x[size] == 0 && y[size] == 0 && z[size] == 0)
			break;
		size++;
	}
	for (int i = 0; i <= 10; ++i)
		h[i*i] = i;
	for (int i = 1; i < 110; ++i){
		if (h[i] == 0){
			h[i] = h[i - 1];
		}
	}

	
	for (int i = 0; i < size;++i)
	for (int j = i + 1; j < size; ++j){
		int now_d = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) +
			(z[i] - z[j])*(z[i] - z[j]);
		d[i] = min(d[i], now_d);
		d[j] = min(d[j], now_d);
	}



	for (int i = 0; i < size; ++i){
		if (d[i] < 100)
			ans[h[d[i]]]++;
	}

	for (int i = 0; i < 10; ++i){
		printf("%4d", ans[i]);
	}
	cout << endl;







	return 0;
}