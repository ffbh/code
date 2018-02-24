#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		int a, b;
		int sum = 0;
		while (N--){
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			sum ^= (abs(a - b) - 1);
		}
		if (sum)
			cout << "I WIN!" << endl;
		else
			cout << "BAD LUCK!" << endl;
	}

	return 0;
}