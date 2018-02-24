#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool map[110][110];


int main(){
	//ifstream in("C:\\temp.txt");
	int a, b, c, d;
	while (1){
		memset(map, 0, sizeof(map));
		int ans = 0;
		while (cin >> a >> b >> c >> d&&a+b+c+d>=0){
			if (a > c)
				swap(a, c);
			if (b > d)
				swap(b, d);
			for (int i = a; i < c;++i)
			for (int j = b; j < d;++j)
			if (map[i][j] == 0){
				ans++;
				map[i][j] = 1;
			}
		}
		cout << ans << endl;
		if (a + b + c + d == -8)
			break;
	}





	return 0;
}