#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, M;
int A[110];

int step[110];

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N >> M){
		for (int i = 1; i <= N; ++i)
			cin >> A[i];
		step[0] = 0;
		for (int i = 1; i <= N; ++i){
			step[i] = (2 * step[i - 1] + A[i]) % M;
		}
		int ans = 0;
		bool r = 0;
		
		for (int i = N; i >= 1; --i){
			int move;
			if (A[i] == 1){
				move = step[i - 1] + 1;
				r = 1;
			}
			else if (r){
				move = step[i - 1] + A[i];
			}
			else if(i == 1){
				move = 2 * A[i] - 1;
			}
			else{
				move = 2 * step[i - 1] + 2 * A[i];
			}
			ans = (ans + move) % M;
		}
		cout << ans << endl;
		
	}

	return 0;
}