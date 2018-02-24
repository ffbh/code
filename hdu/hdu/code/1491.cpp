#include <iostream>
#include <fstream>
using namespace std;
int day[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	int N;
	cin >> N;
	while (N--){
		cin >> a >> b;
		if (a > 10 || a == 10 && b > 21)
			printf("What a pity, it has passed!\n");
		else if (a == 10 && b == 21)
			printf("It's today!!\n");
		else {
			if (a == 10)
				cout << 21 - b << endl;
			else{
				int sum = 0;
				for (int i = a + 1; i < 10; ++i)
					sum += day[i];
				sum += 21;
				sum += day[a] - b;
				cout << sum << endl;
			}
		
		
		}
	
	}


	return 0;
}