#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[200010];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 0; i < N; ++i){
			int  a, b;
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			data[i] = data[i + N] = a - b;
		}
		int max = 0;
		int num = 0;
		int money = 0;
		for (int i = 0; i < 2*N; ++i){
			money += data[i];
			if (money >= 0)
				num++;
			else{
				money = 0;
				if (num>max)
					max = num;
				num = 0;
			}
		}
		if (max<num)
			max = num;
		if (max > N)
			max = N;
		cout << max << endl;
	}
	return 0;
}