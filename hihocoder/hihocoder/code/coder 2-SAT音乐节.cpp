#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, id;


vector<int> song[110][2];
vector<int> vi[2010];
bool mark[2010];
vector<int> idx;

void Init(){
	for (int i = 0; i < 110; ++i){
		song[i][0].clear();
		song[i][1].clear();
	}
	memset(mark, 0, sizeof(mark));
	idx.clear();
	id = 0;
}

void add(char c, int bianhao){
	song[bianhao][c != 'm'].push_back(id++);
}


bool dfs(int x){

	if (mark[x]){
		return 1;
	}
	if (mark[x ^ 1])
		return 0;
	mark[x] = 1;
	idx.push_back(x);

	for (int i = 0; i < vi[x].size(); ++i){
		int son = vi[x][i];
		if (!dfs(son)){
			return 0;
		}
	}

	return 1;
}


int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		Init();
		char c;
		int bianhao;
		for (int i = 0; i < M; ++i){
			string s;
			cin >> s;
			c = s[0];
			bianhao = 0;
			for (int j = 1; j < s.length(); ++j)
				bianhao = bianhao * 10 + s[j] - '0';
			add(c, bianhao);

			

			cin >> s;
			c = s[0];
			bianhao = 0;
			for (int j = 1; j < s.length(); ++j)
				bianhao = bianhao * 10 + s[j] - '0';
			add(c, bianhao);
		}

		for (int i = 1; i <= N; ++i){
			for (int j = 0; j < song[i][0].size();++j)
			for (int k = 0; k < song[i][1].size(); ++k){
				int a = song[i][0][j];
				int b = song[i][1][k];
				if (a/2 != b/2){
					vi[a].push_back(b ^ 1);
					vi[b].push_back(a ^ 1);

				}
			}
		}

		bool ans = 1;
		
		for (int i = 0; i < M; ++i){
			idx.clear();
			if (!dfs(2 * i)){
				for (int i = 0; i < idx.size(); ++i){
					mark[idx[i]] = 0;
				}
				idx.clear();
			
				if (!dfs(i * 2 + 1)){
					ans = 0;
					break;
				}
			}
		}

		if (ans)
			cout << "GOOD" << endl;
		else
			cout << "BAD" << endl;



	}
















	return 0;
}