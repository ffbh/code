#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[100010];
struct Node{
	int v, num;
}D[100010];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; ++i)
			//in >> data[i];
			scanf("%d", &data[i]);
		sort(data, data + N);
		int size = 0;
		D[0].v = data[0];
		D[0].num = 1;
		for (int i = 1; i < N;++i)
		if (data[i] == D[size].v)
			D[size].num++;
		else{
			size++;
			D[size].num = 1;
			D[size].v = data[i];
		}
		int num = 0;
		for (int i = 0; i <= size;++i)
		for (int j = i + 1; j <= size;++j)
		if ((D[i].v^D[j].v) > max(D[i].v, D[j].v))
			num += D[i].num*D[j].num;
		cout << num << endl;




	}






	return 0;
}