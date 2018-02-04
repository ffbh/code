#include <iostream>
#include <fstream>
#include <set>
using namespace std;
bool vis[2010];
set<int> si;
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	int a, b;
	while (cin >> N){     
		int m = N / 2;
		bool flag = 1;
		bool bflag = 1;
		for (int k = 0; k < N - 1; ++k){	
			memset(vis, 0, sizeof(vis));
			si.clear();
			for (int j = 0; j < m; ++j){
				scanf("%d-%d", &a, &b);
				getchar();
			//	in >> a >> b;
				if (bflag&&(a == 1 || b == 1)){//只需选取与1匹配的对手放入集合进行判重
					if (a == 1){
						if (si.count(b))bflag = 0;
						si.insert(b);
					}
					else {
						if (si.count(a))bflag = 0;
						si.insert(a);
					}
					
				}
				if (flag&&bflag&&!vis[a] && !vis[b]&&a!=b){
					vis[a] = vis[b] = 1;
				}
				else flag = 0;
			}
		}
		if (flag&&bflag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}