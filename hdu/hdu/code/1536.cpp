#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
int SG[10001];
int data[101];

void InitSG(int x){
	bool vis[10001];
	SG[0] = 0;
	for (int i = 1; i <= 10000; ++i){
		memset(vis, 0, sizeof(vis));
		for (int k = 0; k < N&&i - data[k] >= 0; ++k)
			vis[SG[i - data[k]]] = 1;
		for (int k = 0; k <= 10000;++k)
		if (!vis[k]){
			SG[i] = k;
			break;
		}
	}
}


int main(){
//c	ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		int mmax = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			if (mmax < data[i])
				mmax = data[i];
		}
		sort(data, data + N);
		InitSG(mmax);
		cin >> M;
		int sum ;
		while (M--){
			sum = 0;
			int K;
		//	cin >> K;
			scanf("%d", &K);
			while (K--){
				int a;
			//	cin >> a;
				scanf("%d", &a);
				sum ^= SG[a];
			}
			if (sum)
				putchar('W');
			else
				putchar('L');
		}
		putchar('\n');
	}
	return 0;
}