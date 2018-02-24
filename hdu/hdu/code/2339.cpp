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
using namespace std;
int N, M, D;
int mmp[510][510];
int dist[510][510];
struct Node{
	int val, idx;

	inline bool operator<(const Node& p)const{
		return val>p.val;
	}
}data[250010];
int size, ans;

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };


/*
struct PX{
int val, x, y;
inline bool operator<(const PX& p)const{
return val>p.val;
}
};


priority_queue<PX> pq;
void dijstra(){

while (!pq.empty()){
PX u = pq.top(), v;
pq.pop();

for (int i = 0; i < 4; ++i){
v.x = u.x + dirs[i][0];
v.y = u.y + dirs[i][1];
int mh = u.val + D;
if (IN(v) && mmp[v.x][v.y] < mh){
v.val = min(mmp[v.x][v.y], u.val);
if (dist[v.x][v.y] < v.val){
dist[v.x][v.y] = v.val;
pq.push(v);
}

}
}
}
}*/
struct PX{
	short  x, y;
};
//inline bool IN(PX& p){
//return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
//}


queue<PX> pq;
bool vis[510][510];
void spfa(){
	while (!pq.empty()){
		PX u = pq.front(), v;
		pq.pop();
		vis[u.x][u.y] = 0;
		for (int i = 0; i < 4; ++i){
			v.x = u.x + dirs[i][0];
			v.y = u.y + dirs[i][1];
			int mh = dist[u.x][u.y] + D;
			//    if (IN(v) && mmp[v.x][v.y] < mh){
			if (v.x >= 0 && v.x<N&&v.y >= 0 && v.y<M && mmp[v.x][v.y] < mh){
				int val = min(mmp[v.x][v.y], dist[u.x][u.y]);
				if (dist[v.x][v.y] < val){
					dist[v.x][v.y] = val;
					if (!vis[v.x][v.y]){
						vis[v.x][v.y] = 1;
						pq.push(v);
					}
				}

			}
		}
	}


}


inline bool judge(int x, int y){


	for (int i = 0; i < 4; ++i){
		short nx = x + dirs[i][0];
		short ny = y + dirs[i][1];
		if (nx >= 0 && nx < N&&ny >= 0 && ny < M && mmp[x][y] < mmp[nx][ny])
			return 0;
	}
	return 1;

}


void Init(int n, int m){
	size = 0;
	ans = 0;
	/*for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= m; ++j){
	vis[i][j] = 0;
	dist[i][j] = (-1);
	}*/
	//memset(vis, 0, sizeof(vis));
	while (!pq.empty())
		pq.pop();

}


/*bool p[510][510];
bool ok(int x,int y){
for (int i = 0; i < 510; ++i)
for (int j = 0; j < 510; ++j){
p[i][j] = 0;

}
queue<PX>  qn;
PX start;
start.x = x;
start.y = y;
qn.push(start);
int mminH = mmp[x][y] - D + 1;
p[x][y] = 1;
while (!qn.empty()){
PX u = qn.front(), v;
qn.pop();
if (mmp[u.x][u.y] > mmp[x][y]){
return 1;
}

for (int i = 0; i < 4; ++i){
v.x = u.x + dirs[i][0];
v.y = u.y + dirs[i][1];
if (IN(v) && mmp[v.x][v.y] >= mminH && !p[v.x][v.y]){
p[v.x][v.y] = 1;
qn.push(v);
}
}
}
return 0;
}
*/

int main(){
	//ifstream in("C:\\input.txt");
	//istream& in = cin;

	int T;
	//    in >> T;
	scanf("%d", &T);

	//T = 1;


	while (T-- > 0){
		//    long start = clock();
		scanf("%d%d%d", &N, &M, &D);
		Init(N, M);
		int mmin = 2000000000;
		//    int mmax = -1;
		//    in >> N >> M >> D;


		//    N = M = 11;
		//    D = 2;
		//    srand(time(0));
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			//    in >> mmp[i][j];
			scanf("%d", &mmp[i][j]);
			dist[i][j] = -1;
			//    mmp[i][j] = abs(rand()) % 10;
			//    mmin = min(mmin, mmp[i][j]);
			if (mmin > mmp[i][j])
				mmin = mmp[i][j];
			//    mmax = max(mmax, mmp[i][j]);
		}



		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			//    data[size].x = i;
			//    data[size].y = j;
			if ((mmp[i][j] == mmin) || !judge(i, j))
				continue;
			data[size].idx = i*M + j;
			data[size].val = mmp[i][j];
			size++;
		}

		sort(data, data + size);
		//    vector<pair<int, int> > A, B;

		//    int pos = 0;
		Node* p = &data[0];
		Node* e = &data[size];
		PX tmp;
		while (p < e){
			while (p < e && dist[p->idx / M][p->idx%M] != (-1))
				p++;
			if (p == e)
				break;
			int height = p->val;

			while (p < e && height == p->val){
				if (dist[p->idx / M][p->idx%M] != (-1)){
					p++;
					continue;
				}
				dist[p->idx / M][p->idx%M] = p->val;
				//        cout << data[pos].x << ' ' << data[pos].y << endl;
				//    pq.push(data[pos]);
				//    tmp.val = data[pos].val;
				tmp.x = p->idx / M;
				tmp.y = p->idx % M;
				vis[tmp.x][tmp.y] = 1;
				//    A.push_back(make_pair(tmp.x, tmp.y));
				pq.push(tmp);
				ans++;
				p++;
			}
			spfa();
			//    dijstra();
		}
		if (ans == 0)
			ans = N*M;
		printf("%d\n", ans);
		//cout << ans << endl;


		/*    int tans = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
		if (!ok(i, j)){
		B.push_back(make_pair(i, j));
		//        cout << i << " " << j << endl;
		tans++;
		}
		}
		cout << tans << endl;

		if (ans != tans){
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		ofstream ou("C:\\input2.txt");
		for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j)
		ou << mmp[i][j] << " ";
		ou << endl;
		}

		for (int i = 0; i < 3; ++i)
		ou << endl;

		for (int i = 0; i < A.size(); ++i)
		ou << A[i].first << " " << A[i].second << endl;
		for (int i = 0; i < 3; ++i)
		ou << endl;

		for (int i = 0; i < A.size(); ++i)
		ou << B[i].first << " " << B[i].second << endl;

		}*/


		//    cout << clock() - start << endl;

	}

	return 0;
}