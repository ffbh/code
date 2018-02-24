#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int sum;
	int min;
	while (cin >> N){
		sum = 0;
		min = 100;
		for (int i = 0; i < N; ++i){
			int a, b;
			cin >> a >> b;
			sum += a;
			if (min>b)
				min = b;
		}
		printf("%.2f\n", double(sum) / min);



	}




	return 0;
}