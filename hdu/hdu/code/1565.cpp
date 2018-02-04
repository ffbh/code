#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int N;
int state[20000];//17711
int cnt;
int data[22][22];
int result[18000];
int temp[18000];

int lowbit(int x){
	return x&(-x);
}

void DP(int line){
	for (int i = 0; state[i] < (1 << N)&&i<cnt; ++i){
		temp[i] = 0;
		/*int sa = state[i];
		while (sa){
			int low = lowbit(sa);
			int dd = int(log2(low)) + 1;
			temp[i] += data[line][int(log2(low))+1];
			sa -= low;
		}*/
		for (int j = 0; j < N;++j)
		if ((state[i] >> j) & 1)
			temp[i] += data[line][j + 1];
		int mmax = 0;///初始化为0
		for (int j = 0; state[j] < (1 << N) && j < cnt;++j)
		if (!(state[i]&state[j])&&mmax < result[j])
			mmax = result[j];
		temp[i] += mmax;
	}
	memcpy(result, temp, sizeof(result));

}




int main(){
//	ifstream in("C:\\temp.txt");
	cnt = 0;
	for (int i = 1; i < 1 << 20;++i)
	if (!(i&(i >> 1)))//左移ac，右移wa，醉了
		state[cnt++] = i;
	while (cin >> N){
		memset(result, 0, sizeof(result));
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
		//	in >> data[i][j];
			scanf("%d", &data[i][j]);


		for (int k = 1; k <= N; ++k){
			DP(k);
		}
		int mmax = 0;
		for (int i = 0; state[i] < (1 << N) && i < cnt;++i)
		if (mmax < result[i])
			mmax = result[i];

		cout << mmax << endl;

	
	
	
	}
	

	return 0;
}




