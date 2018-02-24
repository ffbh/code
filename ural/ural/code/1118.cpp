#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double ratio[1000010];
int num[1000010];
void Init(){
	for (int i = 1; i < 1000010; ++i){
		int now = i;
		while (now < 1000010){
			num[now] += i;
			now += i;
		}
		ratio[i] = double(num[i]) / i;
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	int L, R;
	cin >> L >> R;
	Init();
	int mmin = L;
	while (L <= R){
		if (ratio[mmin] > ratio[L])
			mmin = L;
		L++;
	}
	cout << mmin << endl;
	return 0;
}