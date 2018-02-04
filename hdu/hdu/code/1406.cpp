#include <iostream>
#include <fstream>
using namespace std;

int GetNum(int n){
	int ans = 0;
	for (int i = 1; i < n;++i)
	if (n%i == 0)ans += i;
	return ans;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int a, b;
	int N;
	cin >> N;
	while (N--){
		cin >> a >> b;
		int res = 0;
		int mmin = a < b ? a : b;
		int mman = a>b ? a : b;
		for (int i = mmin; i <= mman;++i)
		if (GetNum(i) == i)res++;
		cout << res << endl;
		
		

	}

	return 0;
}