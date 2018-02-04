#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int M, K;
	while (cin >> M >> K&&M + K){
		int day = 0;
		int ans = 0;
		while (M){
			day++;
			ans++;
			M--;
			if (day == K){
				M++;
				day = 0;
			}
		
			

		}
		cout << ans << endl;
	
	
	
	
	}

	return 0;
}