#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int map[20];
int temp[20];
int N, M;

int recv(int i, int state){
	int t = state;
	int ans = 0;
	for (int k = 1; k <= M;++k)
	if (t&(1 << k)){
		ans++;
		temp[i + 1] ^= (1 << k);
	}
	t ^= (state << 1);
	t ^= (state >> 1);
	temp[i] ^= t;
	return ans;
}

int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N + M){
		string s;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= N; ++i){
			cin >> s;
			for (int k = 0; k < M;++k)
			if (s[k] == 'X')
				map[i] ^= (1 << (k+1));
		}
		int ans = INT_MAX;
		for (int k = 0; k < (1 << M); ++k){
			int t = (k << 1);
			int dd = 0;
			memcpy(temp, map, sizeof(temp));
			dd = recv(1, t);
			temp[1] &= ~1;
			for (int i = 2; i <= N; ++i){
				temp[i-1] &= ~(1 << (M + 1));
				temp[i-1] &= ~1;
				dd += recv(i, temp[i - 1]);
				if (dd >= ans)
					break;
			}
			temp[N] &= ~(1 << (M + 1));
			if (temp[N] >> 1 == 0 && dd < ans)
				ans = dd;
		}
		if (ans != INT_MAX)
			printf("You have to tap %d tiles.\n", ans);
		else
			cout << "Damaged billboard." << endl;
	}
	return 0;
}