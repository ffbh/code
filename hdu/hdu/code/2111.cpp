#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[11];


int main(){
//	ifstream in("C:\\temp.txt");
	int V, N;
	while (cin >> V >> N&&V){
		memset(data, 0, sizeof(data));
		for (int i = 0; i < N; ++i){
			int a, b;
			cin >> a >> b;
			data[a] += b;
		}
		int ans = 0;
		for (int i = 9; i>0; --i)
		if (data[i]){
			if (V > data[i]){
				ans += data[i] * i;
				V -= data[i];
			}
			else {
				ans += V * i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}