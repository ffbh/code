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
int N, M, K;
bool leaf[110];
int A[110];
vector<int> vi[110];
vector<int> lf;
int d[110][110];
int f[110];

void Init(){
	for (int i = 0; i < 110; ++i)
		vi[i].clear();
	lf.clear();
	memset(leaf, 0, sizeof(leaf));
	memset(f, -1, sizeof(f));
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N >> M >> K){
		Init();
		for (int i = 1; i <= M; ++i)
			cin >> A[i];

		for (int i = 1; i <= M; ++i){
			for (int j = 0; j < A[i]; ++j){
				int t;
				cin >> t;
				vi[i].push_back(t);
			}

		}

		for (int i = 1; i <= K; ++i){
			int t;
			cin >> t;
			lf.push_back(t);
			leaf[t] = 1;
		}

		for (int i = 0; i < K; ++i)
		for (int j = 0; j < K; ++j){
			int t;
			cin >> t;
			d[lf[i]][lf[j]] = t;
		}

		f[vi[1][0]] = 0;
	

		

		for (int k = M; k >= 2; --k){
			int pos = 0;
			int fpos = 0;
			
			while (pos < vi[k].size()){
				int p = vi[k - 1][fpos];
				while (fpos < vi[k - 1].size() && leaf[vi[k - 1][fpos]])
					fpos++;
				int fa = vi[k - 1][fpos];
				int lson = vi[k][pos];
				f[lson] = fa;
				pos++;
				while (pos < vi[k].size() && d[vi[k][pos]][lson] == 2){
					f[vi[k][pos]] = fa;
					pos++;
				}
				for (int e = 1; e <= N; ++e){
					if (leaf[e]){
						d[e][fa] = d[fa][e] = d[lson][e] - 1;
					}
				}
				leaf[fa] = 1;
				fpos++;
			}
		}


		for (int i = 1; i <= N; ++i){
			printf("%d ", f[i]);
			
		}
		cout << endl;
	/*	for (int i = 1; i <= N; ++i){
			printf("%d ", son[i]);

		}*/
		
	}

	return 0;
}
