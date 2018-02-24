#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int data[310];
int main(){
	//ifstream in("C:\\input.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 1; i <= N; ++i){
			int t;
			cin >> t;
			data[i] = data[i + N] = t;
		}
		int ans = 0, e;
		for (int i = 1; i <= N; ++i){
			e = i;
			while (data[e] < data[e+1])
				e++;
			if (e - i > ans)
				ans = e - i;

			e = i;
			while (data[e] > data[e+1])
				e++;
			if (e - i > ans)
				ans = e - i;



		}
		cout << ans << endl;
	}














	return 0;
}