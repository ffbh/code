#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int data[20];

int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	int min;
	while (cin >> N >> M&&N + M){
		min = INT_MAX;
		while (N--){
			int  t;
			cin >> t;
			if (t < min)
				min = t;
		}
		for (int i = 0; i < M; ++i)
			cin >> data[i];
		sort(data, data + M);
		if (min < data[1])
			putchar('Y');
		else
			putchar('N');
		putchar('\n');
	}
	return 0;
}