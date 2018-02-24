#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <unordered_map>
using namespace std;
int T, N, M, Q;
unordered_map<string, int> msi;
string name[60010];
int data[60010];
int size;
int vis[60010], mark[60010];
vector<int> vi[60010];
string t;

void Init(){
	msi.clear();
	memset(vis, -1, sizeof(vis));
	memset(mark, -1, sizeof(mark));
	for (int i = 0; i < 60010; ++i)
		vi[i].clear();
	size = 1;
}

int getID(string& s){
	if (msi.count(s))
		return msi[s];
	else{
		name[size] = s;
		return msi[s] = size++;
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	cin >> T;
	while (T-- > 0){
		Init();
		cin >> N >> M >> Q;
		for (int i = 1; i <= N + M; ++i){
		
			cin >> t;
			int id = getID(t);
			int num;
			cin >> num;
			while (num-- > 0){
				cin >> t;
				vi[id].push_back(getID(t));
			}
		}
		for(int k=1;k<=Q;++k){
			
			int p_num, rest_num;
			cin >> p_num;
			rest_num = p_num;
			for (int i = 0; i < p_num; ++i){
				cin >> t;
				data[i] = getID(t);
				vis[data[i]] = k;
			}
			if (k == 3){
				int t = 0;
			}
			for (int i = 0; i < p_num; ++i){
				int id = data[i];
				for (int j = 0; j < vi[id].size(); ++j){
					int p = vi[id][j];
					if (vis[p] == k){
						if (mark[p] != k){
							rest_num--;
							mark[p] = k;
						}
					}

				}
			}
			if (rest_num == 0)
				printf("0\n");
			else{
				int ans = -1, love_num = 0;
				for (int i = 0; i < p_num; ++i){
					if (mark[data[i]] == k)
						continue;
					love_num = 0;
					for (int j = 0; j < vi[data[i]].size(); ++j){
						if (vis[vi[data[i]][j]] == k){
							love_num++;
						}
					}
					if (love_num == p_num - 1){
						ans = data[i];
						break;
					}
				}
				if (ans == -1)
					printf("0\n");
				else{
					printf("1 %s\n",name[ans].c_str());
				}
			}
		}
		putchar('\n');

	}



	return 0;
}