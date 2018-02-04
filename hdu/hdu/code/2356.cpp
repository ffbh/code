#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, I;
struct Node{
	int D, J, S;
	bool operator<(const Node& p)const{
		return D < p.D;
	}
}data[30];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> data[i].D >> data[i].J >> data[i].S;
		sort(data, data + N);
		for (int i = N - 1; i >0; --i)
			data[i].D -= data[i - 1].D;
		cin >> I;
		bool flag = 1;
		for (int i = 0; i < N; ++i){
			int F = I*data[i].D;
			int B = data[i].J*data[i].S*data[i].S;
			if (F <= B){
				flag = 0;
				break;
			}
			else{
				I = int(double(I)*(1.0 - double(B) / F)+0.999999999);
			}
		}
		if (flag)
			cout << "ROUT!" << endl;
		else
			cout << "RETREAT!" << endl;
	}
	return 0;
}