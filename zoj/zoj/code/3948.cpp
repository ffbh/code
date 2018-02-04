#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int T;
int x, y, a, b;


int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T-- > 0){
		cin >> x >> y >> a >> b;
		if (x == 1 || y == 1){
			cout << "INF" << endl;
			continue;
		}

		if (x == 2 && y == 2 && (a >= 2 || b >= 2)){
			cout << "INF" << endl;
		}
		else{
			int ans = 0, num;
			while (1){
				if (a < x&&b < y)
					break;
				num = a / x;
				a %= x;
				ans += num;;
				a += num;
				b += num;

				num = b / y;
				b %= y;
				ans += num;
				a += num;
				b += num;
			}
			cout << ans << endl;

		}


		

	}
















	return 0;
}