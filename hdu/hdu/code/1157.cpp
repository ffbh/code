#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int num[10010];
int main(){
	ifstream in("C:\\temp.txt");
	int n;
	while (cin >> n){
		for (int i = 0; i < n; ++i)
			scanf("%d", &num[i]);
		sort(num, num + n);
		cout << num[n / 2] << endl;
		memset(num, 0, sizeof(num));
	}
	return 0;
}