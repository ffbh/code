#include <iostream>
#include <limits>
using namespace std;
#define MAXSIZE 100000

int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	int count;
	int n;
	int num[MAXSIZE + 10];
	int index,ti,m;
	int z = 1;;
	cin >> count;
	while (count-- > 0){
		cin >> n;
		int i=1;
		m = -999999999;
		while (i <= n)
			cin >> num[i++];

		if (n == 1) {
			cout << "Case " << z++ << ":" << endl;
			cout << num[1] << " " << 1 << " " << 1 << endl;
			if (count) cout << endl;
			continue;
		}
		index = 1;
		int temp = 0;
		i = 1;
		while (i <= n){
			temp = max(temp + num[i], num[i]);
			if (m < temp) {
				m = temp;
				index = i;
			}
			i++;
		}
		temp = num[index];
		ti = index;
		i = index-1;
		while (i>0){
			temp += num[i];
			if (temp == m) ti = i;
			i--;
		}
		cout << "Case " << z++ << ":" << endl;
		cout << m << " " << ti << " " << index << endl ;
		if (count) cout << endl;
	
	}

	return 0;
}