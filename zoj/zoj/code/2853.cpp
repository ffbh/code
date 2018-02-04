#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;
struct Node{
	int to;
	double p;
};
double data[210], tmp[210];
vector<Node> vi[210];
bool vis[210];
int N, M, K;

void Evolution(){
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < vi[i].size(); ++j){
			double t = data[i]*vi[i][j].p;
			tmp[vi[i][j].to] += t;
			tmp[i] -= t;
		}
	}
	for (int i = 0; i < N; ++i){

		data[i] += tmp[i];
	}
}




int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N + M){
		for (int i = 0; i < N; ++i){
		//	scanf("%lf",&data[i] );
			cin >> data[i];
			vi[i].clear();
		}
		cin >> K;
		memset(vis, 0, sizeof(vis));
		while (K--){
			int a, b;
			double p;
			cin >> a >> b >> p;
		//	scanf("%d%d%lf", &a, &b, &p);
			if (p != 0){
				vi[a].push_back(Node{ b, p });
			}
		}
		int num = 0;
		while (M--){
			double pre = data[N - 1];
			Evolution();
			if (pre == data[N - 1]){
				num++;
				if (num > N)
					break;
			}
			else
				num = 0;
		}
		printf("%lld\n", (long long)(data[N - 1] + 0.5));
	}
	return 0;
}