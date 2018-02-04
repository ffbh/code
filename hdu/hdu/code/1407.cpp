#include <iostream>
#include <fstream>
using namespace std;
void fun(int num){
	for (int i = 1; i*i <= num; ++i)
	for (int j = i; i*i + j*j <= num; ++j)
	for (int k = j; i*i + j*j + k*k <= num; ++k)
	if (i*i + j*j + k*k == num){
		printf("%d %d %d\n", i, j, k);
		return;
	}
}
int main(){
	ifstream in("C:\\temp.txt");
	int num;
	while (cin >> num)
		fun(num);
	

	return 0;
}