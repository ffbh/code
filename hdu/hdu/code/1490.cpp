#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[1010][1010];
int N;

int main(){
	ifstream in("C:\\temp.txt");
	
	bool flag;
	while (cin >> N&&N){
		flag = 1;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j)
				//in >> data[i][j];
				scanf("%d", &data[i][j]);
		}
		
			


	}
	return 0;
}