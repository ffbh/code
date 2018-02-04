#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	_int64 N, M;
	while (cin >> N >> M&&N + M){
		int ans = 1;
		while (M % 2 == 0){
			M /= 2;
			ans++;
		}
		cout << ans << endl;
	}





	return 0;
}