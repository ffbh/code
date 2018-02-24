#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int lx, ly, rx, ry;
}data[20];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i].lx >> data[i].ly >> data[i].rx >> data[i].ry;
		int M;
		cin >> M;
		while (M--){
			int  a, b;
			cin >> a >> b;
			bool flag = 0;
			for (int i = N - 1; i >= 0;--i)
			if (data[i].lx <= a&&data[i].rx >= a&&data[i].ly <= b&&data[i].ry >= b){
				cout << i << endl;
				flag = 1;
				break;
			}
			if (!flag)
				cout << -1 << endl;
		}
	}
	return 0;
}