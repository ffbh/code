#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int num[3];
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		for (int i = 0; i < 3; ++i)
			cin >> num[i];
		sort(num, num + 3);
		printf("Scenario #%d:\n", CASE++);
		if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2])
			printf("yes\n");
		else
			printf("no\n");
		cout << endl;


	}



	return 0;
}