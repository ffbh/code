#include <iostream>
#include <fstream>
using namespace std;
int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	int a, b;
	cin >> N;
	int ans;
	while (N--){
		cin >> a >> b;
		if (a == b){
			if (a % 2 == 1)
				ans = 2 * a - 1;
			else ans = a * 2;
			cout << ans << endl;
		}
		else if (a == b + 2){
			if (a % 2 == 1)
				ans = 2 * a - 1;
			else ans = a * 2;
			cout << ans - 2 << endl;
		}
		else
			printf("No Number\n");
	
	}

	return 0;
}