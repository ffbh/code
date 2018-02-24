#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int f[2000010];
int id[2000010];
int num[2000010];

int find(int n){
	return n == f[n] ? n : f[n] = find(f[n]);
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int cnt;
	while (in >> N){
		for (int i = 1; i <= N; ++i){
			f[i] = i;
			id[i] = i;
			num[i] = 1;
		}
		cnt = N + 1;
		for (int i = 1; i <= N; ++i){
			int t;
			in >> t;
			//scanf("%d", &t);
			int fa = find(id[i]);
			int fb = find(id[t]);
			if (fa != fb){
				//if (num[fb] != 1){
					f[cnt] = cnt;
					num[cnt] = 1;
					id[t] = cnt++;
					f[id[t]] = fa;
					num[fa]++;
					num[fb]--;
			/*	}
				//else{
			    	f[fb] = fa;
					num[fa]++;
					num[fb]--;
				}*/
			}
		}
		cout << num[find(id[1])] - 1 << endl;
	}
	return 0;
}