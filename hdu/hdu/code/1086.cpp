#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	double x1, y1, x2, y2;
};

Node data[101];
bool ok(int i, int j){
	double k1 = (data[j].x1 - data[i].x1)*(data[i].y2 - data[i].y1)
		- (data[i].x2 - data[i].x1)*(data[j].y1 - data[i].y1);
	double k2 = (data[j].x2 - data[i].x1)*(data[i].y2 - data[i].y1)
		- (data[i].x2 - data[i].x1)*(data[j].y2 - data[i].y1);
	return k1*k2 <= 0;
}


int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i].x1 >> data[i].y1 >> data[i].x2 >> data[i].y2;
		int num = 0;
		for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N;++j)
		if (ok(i, j)&&ok(j,i))
			num++;
		cout << num << endl;
	}
	return 0;
}