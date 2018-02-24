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
using namespace std;
int Q, N, M, T, S;
int A[5][5];
vector<int> b, c;

struct Node{
	int idx, a;
	Node(int _idx, int _a){
		idx = _idx;
		a = _a;
	}
	bool operator<(const Node& p)const{
		return a<p.a;
	}
};
vector<Node> VA;

int main(){
	//ifstream in("C:\\input.txt");
	cin >> Q;
	while (Q-- > 0){
		cin >> N >> M >> T >> S;
		VA.clear();
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= M; ++j){
				cin >> A[i][j];
				VA.push_back(Node(i, A[i][j]));
			}
		}

		sort(VA.begin(), VA.end());

		b.clear();
		for (int i = 1; i <= T; ++i){
			int tmp;
			cin >> tmp;
			if (tmp > 0)
				b.push_back(tmp);
		}
		sort(b.begin(), b.end());

		c.clear();
		for (int i = 1; i <= T; ++i){
			int tmp;
			cin >> tmp;
			if (tmp > 0)
				c.push_back(tmp);
		}
		sort(c.begin(), c.end());


		int maxatk = -1;
		bool ok = 0;
		int num = 1 << (N*M);
		for (int i = 0; i < num; ++i){
			int bsum = 0, csum = 0, bidx = b.size() - 1, cidx = c.size() - 1;
			int mark = 0;
			for (int j = N*M - 1; j >= 0; --j){
				int dig = 1 << j;
				if (i&dig){//b
					if (bidx >= 0){
						bsum += VA[j].a*b[bidx];
						bidx--;
					}
				}
				else{//c
					if (cidx >= 0){
						csum += VA[j].a*c[cidx];
						cidx--;
						if (!(mark&(1 << (VA[j].idx-1)))){
							mark += 1 << (VA[j].idx - 1);
						}
					}
				}
			}
			if (bsum >= S){
				if (maxatk < csum){
					maxatk = csum;
					ok = 0;
				}
				if (maxatk == csum){
					if (mark + 1 == (1 << N))
						ok = 1;
				}
			}

		}
		if (maxatk == -1){
			cout << "Not Exist" << endl;
		}
		else{
			cout << maxatk << endl;
			if (ok){
				cout << "Yes" << endl;
			}
			else
				cout << "No" << endl;
		}
	}
















	return 0;
}