#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, size;
struct Node{
	int l, r;
	int id;
	bool leaf;
	bool lazy;
}data[8001000];
struct Data{
	int x, y;
}num[10010];
int X[20010];
bool vis[10010];
int ans;

void Build(int root, int l, int r){
	data[root].l = l;
	data[root].r = r;
	data[root].lazy = 0;
	data[root].id = -1;
	data[root].leaf = 0;
	if (l == r){
		data[root].leaf = 1;
		return;
	}
	int mid = (l + r) / 2;
	Build(root * 2, l, mid);
	Build(root * 2 + 1, mid + 1, r);
}

void PushDown(int root){
	if (data[root].lazy){
		data[root].lazy = 0;
		data[root * 2].lazy = 1;
		data[root * 2].id = data[root].id;
		data[root * 2 + 1].lazy = 1;
		data[root * 2 + 1].id = data[root].id;
	}
}


void Update(int root, int l, int r, int id){
	if (data[root].leaf){
		data[root].id = id;
		return;
	}
	if (data[root].l == l&&data[root].r == r){
		data[root].lazy = 1;
		data[root].id = id;
		return;
	}
	PushDown(root);
	int mid = (data[root].l + data[root].r) / 2;
	if (l >= mid + 1)
		Update(root * 2 + 1, l, r, id);
	else if (r <= mid)
		Update(root * 2, l, r, id);
	else{
		Update(root * 2, l, mid, id);
		Update(root * 2 + 1, mid + 1, r, id);
	}
}


void Query(int root){
	if (data[root].lazy || data[root].leaf){
		if (data[root].id != -1){
			if (!vis[data[root].id]){
				vis[data[root].id] = 1;
				ans++;
			}
		}
		return;
	}
	Query(root * 2);
	Query(root * 2 + 1);
}



int mii[100000010];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		memset(vis, 0, sizeof(vis));
		cin >> N;
		size = 0;
		ans = 0;
		for (int i = 0; i < N; ++i){
			//in >> num[i].x >> num[i].y;
			scanf("%d%d", &num[i].x, &num[i].y);
			X[size++] = num[i].x;
			X[size++] = num[i].y;
		}
		sort(X, X + size);
		int cnt = 1;
		mii[X[0]] = cnt++;
		for (int i = 1; i<size; ++i)
		if (X[i] != X[i - 1])
			mii[X[i]] = cnt++;
		Build(1, 1, cnt - 1);
		for (int i = 0; i < N; ++i)
			Update(1, mii[num[i].x], mii[num[i].y], i);
		Query(1);
		cout << ans << endl;
	}
	return 0;
}