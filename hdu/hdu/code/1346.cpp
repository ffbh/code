#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool OK(int n,int ttl){
	for (int i = 0; i < n; ++i){
		ttl--;
		if (ttl%n)
			return 0;
		ttl -= ttl / n;
	}
	return 1;
}



int main(){
	ifstream in("C:\\temp.txt");
	int num;
	while (cin >> num&&num>=0){
		int i;
		for (i = num-1; i >= 2;--i)
		if (OK(i, num)){
			printf("%d coconuts, %d people and 1 monkey\n", num, i);
			break;
		}
		if (i < 2)
			printf("%d coconuts, no solution\n", num);

	}

	return 0;
}