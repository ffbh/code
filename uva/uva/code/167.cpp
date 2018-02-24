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

vector<vector<int> > ans;
vector<int> tmp;
int mmp[8][8];
bool c[10], a[30], b[30];

void dfs(int pos){
	if (tmp.size() == 8){
		ans.push_back(tmp);
		return;
	}
	for (int i = 0; i < 8; ++i){
		if (!c[i] && !a[pos + i] && !b[pos - i + 10]){
			c[i] = 1;
			a[pos + i] = 1;
			b[pos - i + 10] = 1;
			tmp.push_back(i);
			dfs(pos+1);
			tmp.pop_back();
			c[i] = 0;
			a[pos + i] = 0;
			b[pos - i + 10] = 0;

		}

	}

}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	dfs(0);
	int N;
	in >> N;
	while (N-- > 0){
		for (int i = 0; i < 8;++i)
		for (int j = 0; j < 8; ++j)
			in >> mmp[i][j];
		int mmax = 0;
		for (int i = 0; i < ans.size(); ++i){
			int temp = 0;
			for (int j = 0; j < ans[i].size(); ++j){
				temp += mmp[j][ans[i][j]];
			}
			mmax = max(temp, mmax);
		}
		printf("%5d\n", mmax);


	}















	return 0;
}