#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N;
vector<int> vi;
bool map[60][60];
int max;
bool OK(int n){
	for (int i = 0; i<vi.size(); ++i)
	if (!map[n][vi[i]])
		return 0;
	return 1;
}

void dfs(int pos, int sum){
	if (sum > max)
		max = sum;
	if (N - pos + sum <= max)
		return;
	for (int i = pos; i < N; ++i){
		if (OK(i)){
			vi.push_back(i);
			dfs(i + 1, sum + 1);
			vi.pop_back();
		}
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			//in >> map[i][j];
			scanf("%1d", &map[i][j]);
		max = 0;
		vi.clear();
		for (int i = 0; i < N; ++i){
			vi.push_back(i);
			dfs(i + 1, 1);
			vi.pop_back();
		}
		cout << max << endl;

	}
	return 0;
}