#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int num[2345];


int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i < 2345; i++)
	if (i % 2 == 0)
		num[i] = num[i - 1];
	else
		num[i] = num[i - 1] + i*i;
	int N;
	while (~scanf("%d", &N))
		printf("%d\n", num[N]);
	return 0;
}