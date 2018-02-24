#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
int N;
bool cmp(int a, int b){
	return a > b;
}
int C[32][32];
int lowbit(int x){
	return x&(-x);
}
void update(int x, int y, int v){
	for (int i = x; i <= N; i += lowbit(i))
	for (int j = y; j <= N; j += lowbit(j))
		C[i][j] += v;
}
int getsum(int x, int y){
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
	for (int j = y; j > 0; j -= lowbit(j))
		sum += C[i][j];
	return sum;
}


void Init(){
	memset(C, 0, sizeof(C));
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N;++j)
	for (int k = 0; i+k<=N&&j+k<=N; ++k){
		update(i, j, 1);
		update(i + k + 1, j, -1);
		update(i, j + k + 1, -1);
		update(i + k + 1, j + k + 1, 1);
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	priority_queue<int> qi, Q;
	while (T--){
		while (!qi.empty())qi.pop();
		cin >> N;
		Init();
		for (int i = 1; i <= N; ++i)////////
		for (int j = 1; j <= N; ++j){
			int t;
			//in >> t;
			scanf("%d", &t);
			if (t == 0)
				Q.push(getsum(i,j));
		}
		int M;
		cin >> M;
		while (M--){
			int t;
			//in >> t;
			scanf("%d", &t);
			qi.push(t);
		}
		_int64 res = 0;
		while (!Q.empty()){
                                                             			res += Q.top()*qi.top();
			Q.pop();
			qi.pop();
		}
		cout << res << endl;
	}
	return 0;
}