#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int N, P, Q;

int Ps[1000010];
double dp[110];
bool vis[110];
double DP(int p){
	if (vis[p])
		return dp[p];
	vis[p] = 1;
	double ans = 0;
	int nowp = p;
	double gp = 1;
	for (int i = 1; i <= 100; ++i){
		ans += i*gp*(nowp*0.01);
		gp *= (1 - nowp*0.01);
		if (nowp == 100){
			break;
		}
		nowp += Q;
		if (nowp > 100)
			nowp = 100;
	}
	return dp[p] = ans;
}


int main(){
	ifstream in("C:\\input.txt");
	cin >> P >> Q >> N;
	int mul = 1;
	Ps[0] = P;
	for (int i = 1; i <= N; ++i){
		if (mul < 100){
			mul *= 2;
			Ps[i] = P / mul;
		}
		else{
			Ps[i] = 0;
		}
	}
	double ans = 0;
	for (int i = 0; i < N; ++i){
		ans += DP(Ps[i]);
	}

	printf("%.2lf\n", ans);

	return 0;
}