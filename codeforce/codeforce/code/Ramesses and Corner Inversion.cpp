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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int n, m;
int A[510][501];
int B[510][510];
int C[510][510];

void input(){
	in >> n >> m;
	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= m; ++j)
		in >> A[i][j];

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
		in >> B[i][j];
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			C[i][j] = A[i][j] ^ B[i][j];
		
		for (int i = 1; i < n;++i)
		for (int j = 1; j < m; ++j){
			if (C[i][j] == 1){
				C[i][j] = 0;
				C[i][j + 1] ^= 1;
				C[i + 1][j] ^= 1;
				C[i + 1][j + 1] ^= 1;
			}
		}


		int num = 0;
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			num += C[i][j];
		if (num == 0){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}









	}


	return 0;
}





