#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int sx, sy;
string map[20];

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i){
			in >> map[i];
			for (int j = 0; j < M; ++j){
				if (map[i][j] == '@'){
					map[i][j] = '.';

				}
			}
		}



	}





	return 0;
}