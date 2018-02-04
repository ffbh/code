#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
struct Node{
	double x, y;
}data[110];
double d[110][110];
int limit[15010], size;
int N, M;
const double esp = 1e-8;
void cal_d(){
	for (int i = 1; i <= M;++i)
	for (int j = i + 1; j <= M; ++j){
		double tmp = sqrt(pow(data[i].x - data[j].x, 2.0) + pow(data[i].y - data[j].y, 2.0));
		d[i][j] = d[j][i] = tmp;
		limit[size++] = floor(tmp);
		limit[size++] = ceil(tmp);
		if (fabs(limit[size - 1] - tmp) < esp){
			limit[size] = limit[size - 1] + 1;
			size++;
		}
	}
}
bool judge(int center,int len){
	int num = 0;
	for (int i = 1; i <= M;++i)
	if (i == center)
		num++;
	else if (d[i][center] < len)
		num++;
	else if (fabs(d[i][center]-len)<esp)
		return 0;
	return N == num;
}

bool judgecenter(int len){
	for (int i = 1; i <= M;++i)
	if (judge(i, len))
		return 1;
	return 0;

}
int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> M >> N;
		size = 0;
		limit[size++] = 0;
		for (int i = 1; i <= M; ++i)
			cin >> data[i].x >> data[i].y;
		cal_d();
		sort(limit, limit + size);
		size = unique(limit, limit + size) - limit;
		bool f = 0;
		for (int i = 1; i < size; ++i){
			if (judgecenter(limit[i])){
				cout << limit[i] << endl;
				f = 1;
				break;
			}
		}
		if (!f)
			cout << -1 << endl;
		
	}
	return 0;
}