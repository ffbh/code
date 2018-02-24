#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, M, L;
struct Node{
	int v, index;
	bool operator<(const Node& p)const{
		return v < p.v;
	}
}data[1010];
struct T{
	int s, e;
	bool in(int x){
		if (s > e)
			return x >= s || x <= e;
		else
			return x >= s && x <= e;
	}

	bool in(int _s, int _e){
		for (int i = _s; i <= _e;++i)
		if (in(i%N))
			return 1;
		return 0;
	}

}seg[1010];
int size;
int h[1010];
int ans;

int findmin(int s){
	for (int i = s; i < N; ++i){
		bool f = 0;
		for (int j = 0; j < size;++j)
		if (seg[j].in(data[i].index)){
			f = 1;
			break;
		}
		if (!f)
			return data[i].index;
	}
}

void dfs(int m){
	int index = findmin(m);
	if (m == M){
		int mmin = h[index];
		if (ans < mmin)
			ans = mmin;
		return;
	}
	int start = (index - L + 1 + N) % N;
	int time = L;
	while (time--){
		bool f = 0;
		for (int i = 0; i < size;++i)
		if (seg[i].in(start, start + L - 1)){
			f = 1;
			break;
		}
		if (f){
			start = (start + 1) % N;
			continue;
		}
		seg[size].s = start;
		seg[size].e = (start + L - 1) % N;
		size++;
		dfs(m + 1);
		size--;
		start = (start + 1) % N;
	}
}

int main(){
	ifstream in("C:\\input.txt");
	size = 0;
	cin >> N >> M >> L;
	for (int i = 0; i < N; ++i){
		cin >> h[i];
		data[i].index = i;
		data[i].v = h[i];
	}
	sort(data, data + N);
	ans = data[0].v;
	dfs(0);
	cout << ans << endl;
	return 0;
}