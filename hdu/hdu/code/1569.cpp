#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N, M;
#define ID(i,j) (i*M+j+1)
vector<int> vi[2510];
int data[51][51];
int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		vi[0].clear();
		vi[N*M + 1].clear();
		int sum = 0;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			vi[ID(i,j)].clear();
			in >> data[i][j];
			sum += data[i][j];
			if ((i + j) % 2){
				vi[0].push()
				for (int k = 0; k < 4; ++k){
					int tx, ty;
					tx = i + dirs[i][0];
					ty = j + dirs[i][1];
					if (IN(tx, ty))
						vi[ID(i, j)].push_back(ID(tx, ty));
				}
			}
		}




	}



	return 0;
}