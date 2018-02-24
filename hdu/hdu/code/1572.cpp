#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int num[10];
int map[35][35];

int Gettime(int k){
	int ans = map[0][num[0]];
	for (int i = 0; i < k - 1; ++i)
		ans += map[num[i]][num[i + 1]];
	return ans;

}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &map[i][j]);

		int K;
		cin >> K;
		for (int i = 0; i < K; ++i){
			cin >> num[i];
			if (num[i] == 0){
				i--;
				K--;
			}
		}
		sort(num, num + K);
		K = unique(num, num + K)-num;
		int ans = Gettime(K);
		while (next_permutation(num, num + K))
			ans = min(ans, Gettime(K));
		cout << ans << endl;




	}




	return 0;
}