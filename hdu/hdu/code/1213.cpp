#include <iostream>
#include <set>
using namespace std;

int father[1010];
int N, M;
int find(int x){
	return x == father[x] ? x : father[x] = find(father[x]);
}
int main(){
	int n;
	cin >> n;
	int a, b;
	set<int> si;
	while(n--){
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			father[i] = i;
		si.clear();
		for (int i = 0; i < M; ++i){
			scanf("%d%d", &a, &b);
			int k1 = find(a);
			int k2 = find(b);
			if (k1 != k2)
				father[k2] = k1;
		}
		for (int i = 1; i <= N; ++i)
			find(i);
		for (int i = 1; i <= N; ++i)
			si.insert(father[i]);
		cout << si.size()<< endl;
	}


	return 0;
}