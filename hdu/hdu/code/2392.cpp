#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int h, a, c;
	bool operator<(const Node& p)const{
		return a < p.a;
	}
}data[410];
bool dp[40010];
int num[40010];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		int M = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i].h >> data[i].a >> data[i].c;
			if (M < data[i].a)
				M = data[i].a;
		}
		sort(data, data + N);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < N; ++i){
			memset(num, 0, sizeof(num));
			for (int j = data[i].h; j <= data[i].a;++j)
			if (!dp[j] && dp[j - data[i].h] && num[j - data[i].h] < data[i].c){
				dp[j] = 1;
				num[j] = num[j - data[i].h] + 1;
			}
		}
		for (int i = M; i >= 0;--i)
		if (dp[i]){
			cout << i << endl;
			break;
		}
	}
	return 0;
}