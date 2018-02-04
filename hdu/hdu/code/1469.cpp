#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	double x, y;
}data[110];
int N;
bool OK(int a, int b, int c){
	return ((data[c].x - data[a].x)*(data[b].y - data[a].y)
		- (data[c].y - data[a].y)*(data[b].x - data[a].x)) >= 0;
}

bool slove(){
	for (int i = 0; i < N; ++i){
		int k1 = (i + 1) % N;
		int k2 = (i + 2) % N;
		if (!OK(i, k1, k2))
			return 0;
	}
	return 1;

}

int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i].x >> data[i].y;
		printf("Floor #%d\n", CASE++);
		if (!slove())
			printf("Surveillance is impossible.\n");
		else
			printf("Surveillance is possible.\n");
		cout << endl;


	}



	return 0;
}