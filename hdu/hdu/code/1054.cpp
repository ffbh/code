#include <iostream>
#include <vector>
//#include <fstream>
using namespace std;

vector<int> vi[1510];
bool vis[1510];
int link[1510];
int N;

bool find(int n){
	int size = vi[n].size();
	for (int i = 0; i < size; ++i){
		int j = vi[n][i];
		if (!vis[j]){
			vis[j] = 1;
			if (link[j] == -1 || find(link[j])){
				link[j] = n;
				return 1;
			
			}
		}
	}
	return 0;
}


int main(){
	//ifstream in("C:\\temp.txt");
	int t, k,m;
	while(cin >> N){
		for (int i = 0; i < 1510; ++i)
			vi[i].clear();
		memset(link, -1, sizeof(link));
		for (int i = 0; i < N; ++i){
			scanf("%d:(%d)", &t, &k);
		//	in >> t >> k;
			for (int j = 0; j < k; ++j){
			//	in >> m;
				scanf("%d", &m);
				vi[t].push_back(m);
				vi[m].push_back(t);
			}
		}
		int ans = 0;
		for (int i = 0; i < N; ++i){
			memset(vis, 0, sizeof(vis));
			if (find(i))
				ans++;
		}
		cout << ans / 2 << endl;
	
	
	}



	return 0;
}

