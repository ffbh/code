#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	char c;
	int num;
}d1, d2, d3;
char data[11485760];



int main(){
	ifstream in("C:\\input.txt");
	int T, pos;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cin >> data;
		d1.c = '0';
		d2.c = '0';
		pos = 0;
		bool f = 0;
		while (pos < N){
			d3.c = data[pos];
			d3.num = 0;
			while (pos < N && d3.c == data[pos]){
				pos++;
				d3.num++;
			}
			if (d1.c + 1 == d2.c && d1.c + 2 == d3.c && d1.num >= d2.num && d3.num >= d2.num){
				f = 1;
				break;
			}
			d1 = d2;
			d2 = d3;
		}
		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}


	return 0;
}