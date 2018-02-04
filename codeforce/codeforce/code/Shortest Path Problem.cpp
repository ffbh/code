#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
#define MAXN ((int)1e5+10)
#define pii pair<int,int>
#define mp make_pair
int n, m;///m bianshu
int x[MAXN], y[MAXN], w[MAXN];
bool vis[MAXN],edgemark[MAXN];
int d[MAXN];
vector<pii> vi[MAXN];
void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> m;
	for (int i = 1; i <= m; ++i){
		in >> x[i] >> y[i] >> w[i];
		if (x[i] != y[i]){
			vi[x[i]].push_back(mp(y[i], i));
			vi[y[i]].push_back(mp(x[i], i));
		}
	}
}

void bfs(){
	queue<int> qi;
	d[1] = 0;
	vis[1] = 1;
	qi.push(1);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		for (pii p : vi[u]){
			if (!vis[p.first]){
				vis[p.first] = 1;
				edgemark[p.second] = 1;
				d[p.first] = (d[u] ^ w[p.second]);
				qi.push(p.first);
			}
		}
	}
}

vector<int> base;
int W[31], mat[31];
bool gauss(int k){
	if (k == 0)
		return 0;

	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < base.size(); ++i){
		for (int j = 0; j < 30; ++j){
			if (base[i] & W[j]){
				mat[j] += W[i];
			}
		}
	}
	for (int j = 0; j < 30; ++j){
		if (k & W[j]){
			mat[j] += W[30];
		}
	}
	int col = 0;
	for (int i = 0; i < 30 && col < 30; ++i){
		int pos = -1;
		for (int j = i; j < 30;++j)
		if (mat[j] & W[col]){
			pos = j;
			break;
		}
		if (pos == -1){
			if (mat[col] & W[30])
				return 1;

			col++;
			i--;
			continue;
		}
		swap(mat[i], mat[pos]);
		for (int j = i + 1; j < 30; ++j){
			if (mat[j] & W[col]){
				mat[j] ^= mat[i];
			}
		}
		col++;
	}
	return 0;

}

int GS(int P){
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < base.size(); ++i){
		mat[i] = base[i];
	}



	int col = 30;
	for (int i = 0; i < 30 && col >= 0; ++i){
		int pos = -1;
		for (int j = i; j < 30; ++j)
		if (mat[j] & W[col]){
			pos = j;
			break;
		}
		if (pos == -1){
		//	ret += (mat[col] & W[30])*0;
		//	ret += ((P & W[col]) ? 1 : 0) * W[col];
			col--;
			i--;
			continue;
		}
		swap(mat[i], mat[pos]);
		for (int j = i + 1; j < 30; ++j){
			if (mat[j] & W[col]){
				mat[j] ^= mat[i];
			}
		}
	//	ret += ((mat[col] & W[30])?1:0) * W[col];
		if (P & (W[col]))
			P = (P^mat[i]);
		col--;
	}
//	while (col >= 0){
//		ret += ((P & W[col]) ? 1 : 0) * W[col]; 
//		col--;
//}
	return P;

}

int main(){
	input();

	bfs();

	for (int i = 0; i < 31; ++i)
		W[i] = (1 << i);

	for (int k = 1; k <= m; ++k){
		if (edgemark[k])
			continue;
		int xy = d[x[k]] ^ d[y[k]] ^ w[k];
		if (gauss(xy))
			base.push_back(xy);
	}

	if (base.size() > 50){

		cout << "WA" << endl;
	}


	int ans = GS(d[n]);

	cout << ans << endl;










	return 0;
}



