#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		int sum = 0;
		while (N--){
			int t;
			//in >> t;
			scanf("%d", &t);
			sum ^= t;
		}
		if (sum)
			cout << "Rabbit Win!" << endl;
		else
			cout << "Grass Win!" << endl;
	}
	return 0;
}