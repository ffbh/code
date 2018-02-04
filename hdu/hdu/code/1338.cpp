#include <iostream>
#include <fstream>
using namespace std;
bool data[1010];
int MyCard[1010];
int k1;
int EnemeyCard[1010];
int k2;
int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	int ans;
	int CASE = 1;
	while (cin >> N >> M){
		if (N == 0 && M == 0)break;
		ans = 0;
		memset(data, 0, sizeof(data));
		k1 = k2 = 0;
		for (int i = 0; i < M; ++i){
			int d;
		//	in >> d;
			scanf("%d", &d);
			data[d] = 1;
		}
		for (int i = N*M; i >= 1; --i)
		if (data[i])
			MyCard[k1++] = i;
		else
			EnemeyCard[k2++] = i;
		k1 = k2 = 0;
		for (int k1 = 0; k1 < M;++k1)
		if (MyCard[k1] < EnemeyCard[k2]){
			ans++;
			k2++;
		}
		printf("Case %d: %d\n", CASE++, M - ans);
	}



	return 0;
}