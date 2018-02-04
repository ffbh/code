#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[601];
int L, M;
bool cmp(int a, int b){
	return a > b;
}




int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> L >> M){
		for (int i = 0; i < M; ++i)
			//cin >> data[i];
			scanf("%d", &data[i]);
		sort(data, data + M, cmp);
		int sum = 0;
		int res = 0;
		for (int i = 0; i < M; ++i){
			sum += data[i];
			if (sum >= L){
				res = i + 1;
				break;
			}
		}
		if (res)
			cout << res << endl;
		else
			cout << "impossible" << endl;
		
	}
	return 0;
}