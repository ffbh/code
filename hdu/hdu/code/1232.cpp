#include <iostream>
#include <fstream>
using namespace std;
int father[1010];

int find(int n){
	return n == father[n] ? n : father[n] = find(father[n]);
}
int main(){
//	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N){
		int ans = N - 1;
		for (int i = 1; i <= N; ++i)
			father[i] = i;
		int a, b;
		for (int i = 0; i < M; ++i){
		//	in >> a >> b;
			scanf("%d%d", &a, &b);
			int c = find(a);
			int d = find(b);
			if (c != d){
				father[c] = d;
				ans--;
			}
		
		}
		cout << ans << endl;
	
	
	
	}



	return 0;
}