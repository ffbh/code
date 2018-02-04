#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include<vector>
using namespace std;
vector<int> vi[1010];
int N, R;
bool vis[1010];
int C[1010], fa[1010], size[1010];
double w[1010];
void Init(){
	for (int i = 0; i < 1010; ++i){
		vi[i].clear();
	}
	memset(vis, 0,sizeof(vis));
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N >> R){
		if (N == 0 && R == 0)
			break;
		Init();
		for (int i = 1; i <= N; ++i){
			cin >> C[i];
			w[i] = C[i];
			size[i] = 1;
		}
		for (int i = 1; i < N; ++i){
			int a, b;
			cin >> a >> b;
			vi[a].push_back(b);
			fa[b] = a;
		}
		int ans = 0;
		vis[R] = 1;
		for (int i = 1; i < N; ++i){
			double maxvalue = 0;
			int idx;
			for (int j = 1; j <= N; ++j){
				if (vis[j])
					continue;
				if (maxvalue < w[j]){
					maxvalue = w[j];
					idx = j;
				}
			}
			vis[idx] = 1;
			int f = fa[idx];
			ans += C[idx] * size[f];
			C[f] += C[idx];
			size[f] += size[idx];
			w[f] = (double)C[f] / size[f];
			for (int k = 0; k < vi[idx].size(); ++k){
				fa[vi[idx][k]] = f;
				if (!vis[vi[idx][k]])
					vi[f].push_back(vi[idx][k]);
			}
			//cout << "IDX:" << idx << endl;
			//cout << "test ans:" << ans << endl;


		}

		ans += C[R];
		cout << ans << endl;



	}
	return 0;
}