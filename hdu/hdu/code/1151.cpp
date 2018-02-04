#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[125];
bool vis[125];
int link[125];
bool find(int v){
	int size = vi[v].size();
	for (int i = 0; i < size; ++i){
		int j = vi[v][i];
		if (!vis[j]){
			vis[j] = 1;
			if (link[j] == -1 || find(link[j])){
				link[j] = v;
				return 1;
			}
		}
	}
	return 0;

}
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	int num,k;
	while (N--){
		cin >> num>>k;
		int t1, t2;
		memset(link, -1, sizeof(link));
		for (int i = 0; i < k; ++i){
			//in >> t1 >> t2;
			scanf("%d%d", &t1, &t2);
			vi[t1].push_back(t2);
		}
		int ans = 0;
		for (int i = 1; i <= num;++i){
			memset(vis, 0, sizeof(vis));
			if (find(i))ans++;
		}
		cout <<num- ans << endl;
		for (int i = 0; i < 125; ++i)
			vi[i].clear();
			
	}

	return 0;
}

