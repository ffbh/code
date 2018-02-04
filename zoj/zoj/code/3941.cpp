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
int T, N, K, M;
struct Node{
	int s, e;
	bool operator<(const Node& p)const{
		if (s != p.s)
			return s < p.s;
		return e < p.e;
	}
}data[20];
vector<Node> vi;
int ans = 0;
void Init(){
	vi.clear();
	ans = 0;
}

void dfs(int pos, int sum, int rest, int p){
	if (pos == vi.size() || rest == 0){
		ans = max(ans, sum);
		return;
	}
	int start = max(p + 1, vi[pos].s);
	int block = vi[pos].e - start + 1;
	if (block > 0){

		int num = block / K;
		if (num >= rest){
			dfs(pos + 1, sum + rest*K, 0, -1);
		}
		else{
			dfs(pos + 1, sum + num*K, rest - num, start + num*K - 1);
			if (rest >= num + 1 && block%K != 0){
				dfs(pos + 1, sum + (num + 1)*K, rest - num - 1, start + (num + 1)*K - 1);
				if (rest >= num + 2){
					int eend = vi[pos].e + K - 1;
					dfs(pos + 1, sum + eend - start + 1, rest - num - 2, eend);
				}
			}
			else{
				if (rest >= num + 1){
					int eend = vi[pos].e + K - 1;
					dfs(pos + 1, sum + eend - start + 1, rest - num - 1, eend);
				}
			}
		}
	}
	else{
		dfs(pos + 1, sum, rest, p);
		int eend = vi[pos].e + K - 1;
		dfs(pos + 1, sum + eend - p, rest - 1, eend);
	}
}

int main(){
	ifstream in("C:\\input.txt");
	in >> T;
	while (T-- > 0){
		Init();
		in >> N >> K >> M;
		for (int i = 0; i < N; ++i)
			in >> data[i].s >> data[i].e;

		sort(data, data + N);
		for (int i = 0; i < N; ++i){
			if (vi.empty() || vi.back().e + 1<data[i].s){
				vi.push_back(data[i]);
			}
			else{
				vi.back().e = max(vi.back().e, data[i].e);
			}
		}
		dfs(0, 0, M, 0);
		cout << ans << endl;
	}

	return 0;
}