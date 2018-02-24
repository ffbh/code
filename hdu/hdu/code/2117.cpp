#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		int x = 1;
		int k;
		while (M--){
			x *= 10;
			k = x / N;
			x -= k*N;
		}
		cout << k%10 << endl;
	}





	return 0;
}