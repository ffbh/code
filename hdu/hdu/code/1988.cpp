#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
queue<int> qi;
int N;
int data[50];
int GetIndex(int n){
	for (int i = 1; i <= N;++i)
	if (abs(data[i]) == n)
		return i;
}

void filp(int t){
	qi.push(t);
	int s = 1;
	while (s <= t){
		swap(data[s], data[t]);
		data[s] = -data[s];
		data[t] = -data[t];
		if (s == t)
			data[s] = -data[s];
		s++;
		t--;
	}
}

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		printf("%d ", CASE++);
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		for(int i=N;i>=2;--i){
			int u = GetIndex(i);
            if (u == i&&data[u]==i)
				continue;
			if (u!=1)
				filp(u);
			if (data[1] > 0)
				filp(1);
			filp(i);
		}
		if (data[1] < 0)
			filp(1);
		printf("%d", qi.size());
		while (!qi.empty()){
			printf(" %d", qi.front());
			qi.pop();
		}
		printf("\n");
	}
	return 0;
}