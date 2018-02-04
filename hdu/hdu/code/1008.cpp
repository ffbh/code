#include <iostream>
using namespace std;

int Up(int now, int then){
	return (then - now) * 6 + 5;
}

int Down(int now, int then){
	return (now - then) * 4 + 5;
}

int main(){
	int count;
	while (cin >> count&&count){
		int* p = new int[count];
		if (!p) exit(0);
		int i = 0;
		while (count--){
			int n;
			cin >> n;
			p[i++] = n;
		}
		int j = 0;
		int now = 0;
		int then;
		int sum = 0;
		while (j < i){
			then = p[j++];
			sum += (now - then)>0 ? Down(now, then) : Up(now, then);
			now = then;
		}
		cout << sum << endl;
	}



	return 0;
}