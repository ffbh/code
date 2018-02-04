#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MMAX 100005
int num[MMAX];
bool mark[MMAX];
int data[MMAX];
int N, M;

int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i)
			//cin >> data[i];
			scanf("%d", &data[i]);
		int K;
		while (M--){
			int ans = N;
			int Q;
			cin >> Q;
			K = 0;
			memset(mark, 0, sizeof(mark));
			memset(num, 0, sizeof(num));
			while (Q--){//Q¿ÉÄÜÎª0
				int t;
			//	cin >> t;
				scanf("%d", &t);
				if (mark[t] == 0){
					mark[t] = 1;
					K++;
				}
			}
			if (K){
				int R = 0;
				for (int L = 0; L < N; ++L){
					while (K&&R<N){
						if (num[data[R]] == 0 && mark[data[R]])
							K--;
						num[data[R]]++;
						R++;
					}
					if (!K&&ans>R - L)
						ans = R - L;
					if (mark[data[L]] && num[data[L]] == 1)
						K++;
					num[data[L]]--;
				}
				cout << ans << endl;
			}
			else
				cout << 0 << endl;
		}
	}
	return 0;
}