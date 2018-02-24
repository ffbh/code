#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
struct Node{
	int _data[15];
	int index;
	bool operator<(const Node& p)const{
		for (int i = 0; i < M;++i)
		if (_data[i]>=p._data[i])
			return 0;
		return 1;
	}
}data[40];
bool cmp(int a, int b){
	return data[a]._data[0] < data[b]._data[0];
}
bool G[40][40];
int pace[40], dist[40];

void Print(int x){
	if (pace[x] != -1)
		Print(pace[x]);
	printf("%d ", data[x].index);
}



int main(){
//	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		memset(G, 0, sizeof(G));
		for (int i = 0; i < 40; ++i)
			dist[i] = 1;
		memset(pace, -1, sizeof(pace));
		for (int i = 0; i < N; ++i){
			data[i].index = i+1;
			for (int j = 0; j < M; ++j)
				cin >> data[i]._data[j];
			sort(data[i]._data, data[i]._data + M);
		}
		sort(data, data + N);
		for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N;++j)
		if (data[i] < data[j])
			G[i][j] = 1;
		for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N;++j)
		if (G[i][j]){
			if (dist[j] < dist[i] + 1){
				dist[j] = dist[i] + 1;
				pace[j] = i;
			}
		}
		int u, max;
		max = 0;
		for (int i = 0; i < N;++i)
		if (max < dist[i]){
			max = dist[i];
			u = i;
		}
		cout << max << endl;
		Print(u);
		cout << endl;
	}
	return 0;
}