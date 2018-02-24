#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
bool p[1000010];
int fun(int n){
	int ans = 0;
	for (int i = 2; i <= n; ++i){
		if (!p[i]){
			ans++;
			for (int j = 2; j*i <= n; ++j)
				p[i*j] = 1;
		}
	}
	return ans;

}


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	cout << fun(N) << endl;

















	return 0;
}