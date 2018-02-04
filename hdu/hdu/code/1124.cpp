#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	while (N--){
		int m;
		cin >> m;
		int ans = 0;
		while (m >= 5){
			ans += m / 5;
			m /= 5;
		}
		cout << ans << endl;

	}





	return 0;
}