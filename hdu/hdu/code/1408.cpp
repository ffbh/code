#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	double V, D;
	int time;
	int num;
	while (cin >> V >> D){
		time = 0;
		num = 1;
		int kk = ceil(V / D);
		while (1){
			if (kk >= num){
				kk -= num;
				time += num;
			}
			else{
				time += kk;
				break;
			}
			if (kk <= 0)break;
			time++;
			num++;
		}
		cout << time << endl;
	
	}

	return 0;
}