#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	map<int, int> mii;
	while (T--){
		mii.clear();
		int M;
		cin >> M;
		int ans = 0;
		while (M--){
			int t;
			cin >> t;
			int temp = ++mii[t];
			if (temp > ans)
				ans = temp;
		}
		cout << ans << endl;
	}





	return 0;
}