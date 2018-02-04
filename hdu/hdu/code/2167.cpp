#include <iostream>
#include <string>
#include <fstream>
#include <vector>?
using namespace std;
int data[20][20];
int dp[20][1550];
vector<int> state;
void Init(){
	for (int i = 0; i < (1 << 15); ++i){
		int l = (i << 1);
		int r = (i >> 1);
		if ((l|r)&i)
			continue;
		state.push_back(i);
	}
}
int size;
int getsum(int line, int s){
	int sum = 0;
	for (int i = 0; i < size;++i)
	if ((s >> i) & 1)
		sum += data[line][i];
	return sum;
}



int main(){
	//ifstream in("C:\\temp.txt");
	Init();
	while (cin >> data[0][0]){
		memset(dp, 0, sizeof(dp));
		size = 1;
		while (1){
			cin >> data[0][size++];
			if (getchar() == '\n')
		//	if (in.get() == '\n')
				break;
		}
		for (int i = 1; i < size;++i)
		for (int j = 0; j < size; ++j)
			cin >> data[i][j];
		for (int i = 0; state[i] < (1 << size); ++i)
			dp[0][i] = getsum(0, state[i]);
		for (int i = 1; i < size;++i)
		for (int j = 0; state[j] < (1 << size); ++j){
			int temp = getsum(i,state[j]);
			for (int k = 0; state[k] < (1 << size); ++k){
				int s1 = (state[j] << 1) | (state[j] >> 1) | state[j];
				int s2 = state[k];
				if (s1&s2) continue;
				if (dp[i][j] < dp[i - 1][k] + temp)
					dp[i][j] = dp[i - 1][k] + temp;
			}
		}
		int max = 0;
		for (int i = 0; state[i] < (1 << size);++i)
		if (max < dp[size - 1][i])
			max = dp[size - 1][i];
		cout << max << endl;
	}
	return 0;
}