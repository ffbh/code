#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
long long N, M, V, K;
long long change(){
	return (M - V)*K;
}
int slove(){
	int time = 0;
	while (M < N){
		time++;
		long long  t = change();
		if (t <= M)
			return -1;
		M = t;
	}
	return time;

}




int main(){
	ifstream in("C:\\input.txt");
	int T;

	cin >> T;
	while (T--){
		cin >> N >> M >> V >> K;
		if (N <= M)
			cout << 0 << endl;
		else
			cout << slove() << endl;
	}
	return 0;
}