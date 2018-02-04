#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int a, c;
}data[110];
bool dp[100010];
int num[100010];
int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N + M){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int sum = 0;
		for (int i = 0; i < N; ++i)
			//in >> data[i].a;
			scanf("%d", &data[i].a);
		for (int i = 0; i < N; ++i)
			//in >> data[i].c;
			scanf("%d", &data[i].c);
		for (int i = 0; i < N; ++i){
			memset(num, 0, sizeof(num));
			for (int j = data[i].a; j <= M;++j)
			if (!dp[j] && dp[j - data[i].a] && num[j - data[i].a] < data[i].c){
				dp[j] = 1;
				sum++;
				num[j] = num[j - data[i].a] + 1;
			}
	
		}
		cout << sum << endl;


	}
	



	return 0;
}