#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, M;
struct Node{
	int a, b;
}data[100010];
struct Dp{
	int h, maxh, w;
	bool start;
	int nexth;
}dp[100010];
int mmaxh;
bool vis[100010];

void init(){
	int h = 0, maxh = 0, w = N;
	dp[0].start = 1;
	for (int i = 0; i < M; ++i){
		dp[i].h = h;
		dp[i].maxh = maxh;
		dp[i].w = w;
		if (data[i].a <= w){
			w -= data[i].a;
			if (maxh < data[i].b)
				maxh = data[i].b;
		}
		else{
			int newb = ceil((double)w * data[i].b / data[i].a);
			w = 0;
			if (maxh < newb)
				maxh = newb;
		}

		if (w == 0){
			dp[i + 1].start = 1;
			h += maxh;
			maxh = 0;
			w = N;
		}
	}
	mmaxh = maxh + h;

}

int geth(int n){
	int h = dp[n].h, maxh = dp[n].maxh, w = dp[n].w;
	for (int i = n+1; i < M; ++i){
		if (data[i].a <= w){
			w -= data[i].a;
			if (maxh < data[i].b)
				maxh = data[i].b;
		}
		else{
			int newb = ceil((double)w * data[i].b / data[i].a);
			w = 0;
			if (maxh < newb)
				maxh = newb;
		}

		if (w == 0){
			h += maxh;
			maxh = 0;
			w = N;
			if (i + 1 < M && dp[i + 1].start)
				return h + dp[i + 1].nexth;

		}
	}
	return maxh + h ;

}


int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	
	for (int i = 0; i < M; ++i){
		cin >> data[i].a >> data[i].b;
	}

	init();
	dp[0].nexth = mmaxh;
	for (int i = 1; i < M; ++i)
	if (dp[i].start)
		dp[i].nexth = mmaxh - dp[i].h;

	int minh = 1 << 30;
	for (int i = 0; i < M; ++i){
		if (i == 3)
			int t = 0;
		int h = geth(i);
		if (minh > h){
			minh = h;
		}
	}
	cout << minh << endl;
	return 0;
}