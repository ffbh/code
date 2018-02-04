#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[51];
bool vis[51];


int main(){
	ifstream in("C:\\temp.txt");
	int N, K;
	while (cin >> N >> K&&N + K){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		sort(data, data + N);
		int count = 0;
		for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N;++j)
		if (!vis[i] && !vis[j] && data[i] * K == data[j]){
			vis[i] = 1;
			vis[j] = 1;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}