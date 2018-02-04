#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
const long long mod = (long long)(1e9) + 7;
int T;
struct Node{
	int val, index;

}tmp[1010];

long long p[1010];
bool cmp1(Node& p1, Node& p2){
	return p1.val < p2.val;
}

bool cmp2(Node& p1, Node& p2){
	return p1.val > p2.val;
}
int A[1010][1010], N, M;
int col[1010][1010], row[1010][1010];
int main(){
	ifstream in("C:\\input.txt");
	p[1] = 2;
	p[0] = 1;
	for (int i = 2; i<1010; ++i)
		p[i] = p[i - 1] * 2 % mod;
	cin >> T;
	while (T-- > 0){
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> A[i][j];

		for (int i = 0; i < N; ++i){
			for (int j = 0; j < M; ++j){
				tmp[j].index = j;
				tmp[j].val = A[i][j];
			}
			sort(tmp, tmp + M, cmp2);
			int pre = 0;
			col[i][tmp[0].index] = 0;
			for (int j = 1; j < M; ++j){
				if (A[i][tmp[j].index] != A[i][tmp[j - 1].index]){
					pre = j;
				}
				col[i][tmp[j].index] = pre;
			}
		}

		for (int i = 0; i < M; ++i){
			for (int j = 0; j < N; ++j){
				tmp[j].index = j;
				tmp[j].val = A[j][i];
			}

			sort(tmp, tmp + N, cmp1);
			int pre = 0;
			row[tmp[0].index][i] = 0;
			for (int j = 1; j < N; ++j){
				if (A[tmp[j].index][i] != A[tmp[j - 1].index][i]){
					pre = j;
				}
				row[tmp[j].index][i] = pre;
			}
		}
		long long ans = 0;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			ans = (ans + (p[col[i][j]])*(p[row[i][j]])) % mod;

		}
		cout << ans << endl;
	}
	

	



	return 0;
}