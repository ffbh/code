#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	double x, y;
};
Node data[101];


int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (in >> N){
		for (int i = 0; i < N; ++i)
			in >> data[i].x >> data[i].y;
		in >> M;
		while (M--){
			double x, y;
			bool flag = 1;
			in >> x >> y;
			for (int i = 0; i < N; ++i){
				int j = (i + 1) % N;
				if ((data[j].x - data[i].x)*(y - data[i].y)
					- (data[j].y - data[i].y)*(x - data[i].x) > 0){
					flag = 0;
					break;
				}
			}
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}