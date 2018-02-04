#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int f[1001];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;

	while (cin >> N >> M){
		for (int i = 0; i < N; ++i)
			f[i] = i;
		int ans = 0;
		while (M--){
			int a, b;
			cin >> a >> b;
			int fa = find(a);
			int fb = find(b);
			if (fa == fb)
				ans++;
			else
				f[fa] = fb;
		}
		cout << ans << endl;

	}





	return 0;
}