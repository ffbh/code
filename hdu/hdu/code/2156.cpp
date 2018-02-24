#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
double GetRU(){
	double ans = 0;
	int k = 2;
	int M = N;
	while (M--)
		ans += double(M) / k++;
	return ans;


}


int main(){
	ifstream in("C:\\temp.txt");
	
	while (cin >> N&&N){
		printf("%.2f\n", 2 * GetRU() + N);
	}
	return 0;
}