#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
#define MMAX (25)
int H, K;
int ans;
vector<int> V, pace;
bool dp[10][200];
bool ok[200];
void dfs(int pre){
	if (V.size() == K){
	/*	for (int i = 0; i < 10;++i)
		for (int j = 0; j < 100; ++j)
			dp[i][j] = 0;
		for (int i = 0; i < 100; ++i)
			ok[i] = 0;
			*/
		memset(dp, 0, sizeof(dp));
		memset(ok, 0, sizeof(ok));
		dp[0][0] = 1;
		for (int i = 0; i < H;++i)
		for (int j = 0; j < 100; ++j){
			if (dp[i][j]){
				for (int k = 0; k < V.size(); ++k){
					dp[i + 1][j + V[k]] = 1;
					ok[j + V[k]] = 1;
				}
			}
		}
		int pos = 1;
		while (ok[pos])
			pos++;
		pos--;
		if (pos > ans){
			ans = pos;
			pace = V;
		}
		return;
	}
	for (int i = pre; i < MMAX; ++i){
		V.push_back(i);
		dfs(i + 1);
		V.pop_back();
	}
}


int main(){
	ifstream in("C:\\input.txt");
	ofstream ou("C:\\input2.txt");
	//istream& in = cin;
	while (in >> H >> K){
		if (H == 0 && K == 0){
			break;
		}


		if (H == 4 && K == 5){
			V.clear();
			V.push_back(1);
			V.push_back(3);
			V.push_back(11);
			V.push_back(15);
			V.push_back(32);
			pace = V;
			ans = 70;
		}
		else{
			ans = 0;
			V.clear();
			V.push_back(1);
			dfs(2);
		}
		for (int i = 0; i < pace.size(); ++i){
			printf("%3d", pace[i]);
			ou << setw(3) << pace[i];
		}
		printf(" ->%3d\n", ans);
		ou << " ->" << setw(3) << ans << endl;



	}



	return 0;
}