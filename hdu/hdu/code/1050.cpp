#include<iostream>
//#include <fstream>
using namespace std;

int num[201];
int room(int n){
	if (n % 2) return (n + 1) / 2;
	else return n / 2;

}
void Swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
int main(){
	int n,m;
	int start, end;
	//ifstream in("C:\\temp.txt");
	cin >> n;
	while (n--){
		cin >> m;
		memset(num, 0, sizeof(int)* 201);
		for (int i = 0; i < m; ++i){
			cin >> start >> end;
			start = room(start);
			end = room(end);
			if (start>end)Swap(&start, &end);
			while (end >= start)
				num[start++]++;
		}
		int mm=0;
		for (int i = 0; i < 201;++i)
		if (mm < num[i])
			mm = num[i];
		cout << mm * 10 << endl;
		
	}


	return 0;
}