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
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

int N, M;

double dp[110][610];

void input(){

	in >> N >> M;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		dp[0][0] = 100;
		for (int i = 0; i <= N;++i)
		for (int j = 0; j <= M;++j)
		for (int k = 1; k <= 6; ++k)
			dp[i + 1][j + k] += dp[i][j] * (1.0 / 6);

		printf("%.2f\n", dp[N][M]);
	}


	return 0;
}





