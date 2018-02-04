#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
int f[2000100];
int id[2000100];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}


int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	int cnt;
	int CASE = 1;
	set<int> si;
	while (cin >> N >> M&&N+M){
		si.clear();
		for (int i = 0; i < N; ++i){
			f[i] = i;
			id[i] = i;
		//	pre[i] = i;
		}
		cnt = N;
		while (M--){
			char c;
			int a, b;
			cin >> c;
			if (c == 'M'){
				//in >> a >> b;
				scanf("%d%d", &a, &b);
				int fa = find(id[a]);
				int fb = find(id[b]);
				if (fa != fb){
					if (fa > fb)
						f[fa] = fb;
					else
						f[fb] = fa;
				}
			}
			else{
				//in >> a;
				scanf("%d", &a);
				f[cnt] = cnt;
				id[a] = cnt++;
			}
		}
		printf("Case #%d: ", CASE++);
		for (int i = 0; i < N; ++i)
			si.insert(find(id[i]));
		cout << si.size() << endl;
	}
	return 0;
}