#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		printf("Printing order for %d pages:\n", N);
		if (N == 1){
			printf("Sheet 1, front: Blank, 1\n");
			continue;
		}
		int R = N / 4;
		if (N % 4 != 0)
			R++;
		R *= 4;
		int L = 1;
		int num = 2;
		while (L<R){
			if (num % 2 == 0){
				printf("Sheet %d, front: ", (num++) / 2);
				if (R>N)
					printf("Blank");
				else
					printf("%d", R);
				printf(", ");
				printf("%d", L);
			}
			else{
				printf("Sheet %d, back : ", (num++) / 2);
				printf("%d", L);
				printf(", ");
				if (R>N)
					printf("Blank");
				else
					printf("%d", R);
			}
			cout << endl;
			R--;
			L++;
		}
	}



	return 0;
}

