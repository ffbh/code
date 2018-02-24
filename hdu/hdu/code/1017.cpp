#include <iostream>
using namespace std;


int main(){
	int blocks;
	cin >> blocks;
	int n, m,c,count;
	for(int k=1;k<=blocks;++k){
		c = 1;
		while (cin >> n >> m){
			if (n == 0 && m == 0) break;//m可以为0，故不能写在while循环内
			count = 0;
			for (int i = 1; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j){
				if ((i*i + j*j + m) % (i*j) == 0) count++;
			}
			cout << "Case " << c++ << ": " << count << endl;
		
		}
		if (k<blocks)
			cout << endl;
		
	}
	return 0;
}