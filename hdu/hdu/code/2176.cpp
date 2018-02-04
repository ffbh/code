#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[200001];


int main(){
	//ifstream in("C:\\temp.txt");
	int N;
//	while (in >> N&&N){
	while (scanf("%d",&N)&&N){
		int sum = 0;
		for (int i = 0; i < N; ++i){
			//in >> data[i];
			scanf("%d", &data[i]);
			sum ^= data[i];
		}
		if (sum == 0)
			cout << "No" << endl;
		else{
			cout << "Yes" << endl;
			for (int i = 0; i < N; ++i){
				if ((data[i]^sum) < data[i])
					printf("%d %d\n", data[i], (data[i]^sum));
			}
		}
	}
	return 0;
}