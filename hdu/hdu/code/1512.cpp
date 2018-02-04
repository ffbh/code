#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int f[100010];
priority_queue<int> qi[100010];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
	ifstream in("C:\\temp.txt");
	
	int N;
	while (cin >> N){
		for (int i = 1; i <= N; ++i){
			int t;
			cin >> t;
			f[i] = i;
			while (!qi[i].empty())
				qi[i].pop();
			qi[i].push(t);
		}
		int M;
		cin >> M;
		while (M--){
			int a, b;
			cin >> a >> b;
			int fa = find(a);
			int fb = find(b);
			if (fa == fb)
				printf("-1\n");
			else{
				qi[fa].top() /= 2;
				qi[fb].top() /= 2;
				while (!qi[fa].empty()){
					qi[fb].push(qi[fa].top());
					qi[fa].pop();
				}
				f[fa] = fb;
				printf("%d\n", qi[fb].top());
			}
		}
	}
	return 0;
}