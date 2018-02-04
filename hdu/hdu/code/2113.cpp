#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int ok = 0;
	while (cin >> N){
		if (ok)cout << endl;
		ok = 1;
		int ans = 0;
		while (N){
			ans += (N % 10) % 2==0 ? N % 10 : 0;
			N /= 10;
		}
		cout << ans << endl;

	}





	return 0;
}