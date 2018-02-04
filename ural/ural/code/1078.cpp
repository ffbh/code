#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int a, b;
	int num;
	bool operator<(const Node& p)const{
		return b < p.b;
	}
}data[510];
int dp[510];
int pace[510];

void Print(int u){
	if (pace[u] != -1)
		Print(pace[u]);
	printf("%d ", data[u].num);
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 0; i < N; ++i){
			cin >> data[i].a >> data[i].b;
			data[i].num = i + 1;
			dp[i] = 1;
			pace[i] = -1;
		}
		sort(data, data + N);
		for (int i = 1; i < N; ++i)
		for (int j = 0; j < i; ++j)
		if (data[i].b>data[j].b&&data[i].a < data[j].a&&dp[i] < dp[j] + 1){
			dp[i] = dp[j] + 1;
			pace[i] = j;
		}
		int mmax, u;
		mmax = 0;
		for (int i = 0; i < N; ++i)
		if (dp[i]>mmax){
			mmax = dp[i];
			u = i;
		}
		cout << mmax << endl;
		Print(u);
		cout << endl;
	}





	return 0;
}