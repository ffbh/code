#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	int w, h;
}data[100010];
struct Flow{
	long long l, r, w, h, sum;
};
int N;
long long ans[100010];
bool higest[100010];

void InitHigest(){
	for (int i = 2; i < N;++i)
	if (data[i].h>data[i - 1].h&&data[i].h > data[i + 1].h)
		higest[i] = 1;

}
int findLowest(int k,int dir){
	int i;
	for (i = k; data[i].h > data[i + dir].h; i += dir);
	return i;
}

void DFS(Flow& pre,int s,int dir){
	Flow ret;
	ret.l = ret.r = s;
	ret.sum = data[s].w + pre.sum;
	ret.w = data[s].w;
	ret.h = data[s].h + 1;
	ans[s] = ret.sum;
	while (ret.l != 1 || ret.r != N){
		if (data[ret.l - 1].h < data[ret.r + 1].h){
			if (!higest[ret.l - 1]){
				ret.sum += (data[ret.l - 1].h + 1 - ret.h)*ret.w + data[ret.l - 1].w;
				ret.w += data[ret.l - 1].w;
				ret.h = data[ret.l - 1].h + 1;
				ret.l--;
				ans[ret.l] = ret.sum;
			}
			else{
				if (dir == 1){
					ret.sum += (data[ret.l - 1].h - ret.h)*ret.w;
					pre.sum = ret.sum + data[ret.l - 1].w + pre.w + ret.w;
					pre.h = data[ret.l - 1].h + 1;
					pre.w += data[ret.l - 1].w + ret.w;
					pre.r = ret.r;
					ans[ret.l - 1] = pre.sum;
					return;
				}
				else{
					ret.sum += (data[ret.l - 1].h - ret.h)*ret.w;
					ret.h = data[ret.l - 1].h;
					DFS(ret, findLowest(ret.l - 1, -1), -1);
				}


			}

		}
		else{
			if (!higest[ret.r + 1]){
				ret.sum += (data[ret.r + 1].h + 1 - ret.h)*ret.w + data[ret.r + 1].w;
				ret.w += data[ret.r + 1].w;
				ret.h = data[ret.r + 1].h + 1;
				ret.r++;
				ans[ret.r] = ret.sum;
			}
			else{
				if (dir == -1){
					ret.sum += (data[ret.r + 1].h - ret.h)*ret.w;
					pre.sum = ret.sum + data[ret.r + 1].w + pre.w + ret.w;
					pre.h = data[ret.r + 1].h + 1;
					pre.w += data[ret.r + 1].w + ret.w;
					pre.l = ret.l;
					ans[ret.r + 1] = pre.sum;
					return;

				}
				else{
					ret.sum += (data[ret.r + 1].h - ret.h)*ret.w;
					ret.h = data[ret.r + 1].h;
					DFS(ret, findLowest(ret.r + 1, 1), 1);
				}
			}
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	int mmin = 1;
	for (int i = 1; i <= N; ++i){
		//in >> data[i].w >> data[i].h;
		scanf("%d%d", &data[i].w, &data[i].h);
		if (data[i].h < data[mmin].h)
			mmin = i;
	}
	data[0].h = data[N + 1].h = INT_MAX;
	InitHigest();
	Flow flow;
	flow.l = flow.r = mmin;
	flow.sum = 0;
	flow.w = 0;
	DFS(flow, mmin, 0);
	for (int i = 1; i <= N; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}