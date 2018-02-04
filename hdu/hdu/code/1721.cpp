#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int num[9];


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> num[1] && num[1] >= 0){
		int sum = num[1];
		for (int i = 2; i <= 8; ++i){
			cin >> num[i];
			sum += num[i];
		}
		int ss = num[1] + num[3] + num[8] + num[6];
		sum -= ss;
		if (ss == sum)
			printf("All the seeds can be cleared away!\n");
		else
			printf("Sorry,it can't be cleared away!\n");
	}
	return 0;
}