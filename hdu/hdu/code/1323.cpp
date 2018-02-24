#include <iostream>
#include <fstream>
using namespace std;
void Print(int n){
	printf("%5d  ", n);
	int sum = 0;
	for (int i = 1;i<=n/2;++i)
	if (n%i == 0)sum += i;

	if (sum == n)printf("PERFECT");
	else if (sum < n)printf("DEFICIENT");
	else printf("ABUNDANT");
	printf("\n");


}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	printf("PERFECTION OUTPUT\n");
	while (cin >> N&&N)
		Print(N);
	printf("END OF OUTPUT\n");

	return 0;
}