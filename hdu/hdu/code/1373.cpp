#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[30];
int mark[30];
bool Ok(int n){
	for (int i = 0; i < vi[n].size(); ++i){
		int son = vi[n][i];
		if (mark[son] == mark[n])
			return 0;
	}
	return 1;
}
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < 30; ++i)
			vi[i].clear();
		memset(mark, 0, sizeof(mark));
		int M = N;
		while (M--){
			string temp;
			cin >> temp;
			int now = temp[0] - 'A';
			for (int i = 2; i < temp.length(); ++i)
				vi[now].push_back(temp[i] - 'A');
		}
		int max = -1;
		for (int i = 0; i < N; ++i)
		for (int j = 1; j <= N; ++j){
			mark[i] = j;
			if (max < j)
				max = j;
			if (Ok(i))
				break;
		}
		if (max == 1)
			cout << "1 channel needed." << endl;
		else
			printf("%d channels needed.\n",max);

	}
	return 0;
}