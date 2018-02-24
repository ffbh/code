#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int rem[100010];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	int t;
	while (cin >> N >> M&&N + M){
		memset(rem, -1, sizeof(rem));
		rem[0] = 0;
		int sum = 0;
		int L, R;
		bool flag = 1;
		for (int i = 1; i <= M; ++i){
			//cin >> t;
			scanf("%d", &t);
			if (flag){
				sum = (sum+t)%N;
				if (rem[sum] == -1)
					rem[sum] = i;
				else{
					L = rem[sum] + 1;
					R = i;
					flag = 0;
				}
			}
		}
		while (L < R)
			printf("%d ", L++);
		printf("%d\n", R);
	}
	return 0;
}



