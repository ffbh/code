#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
bool map[60][60];
string str = "NESW";
int N, M;
int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

bool IN(int x,int y){
	return x >= 0 && x <= N&y >= 0 && y <= M;
}

int getD(char c){
	for (int i = 0; i < 4;++i)
	if (str[i] == c)
		return i;
}

char getD(int c){
	return str[c];
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N >> M;
	int now_x, now_y, d;
	char c;
	string instruction;
	while (in >> now_x >> now_y >> c){
		bool lost = 0;
		in >> instruction;
		d = getD(c);
		for (int i = 0; i < instruction.length() && !lost; ++i){
			switch (instruction[i]){
			case 'L':
				d = (d + 3) % 4;
				break;
			case 'R':
				d = (d + 1) % 4;
				break;
			case 'F':
				int nx = now_x + dirs[d][0];
				int ny = now_y + dirs[d][1];
				if (IN(nx, ny)){
					now_x = nx;
					now_y = ny;
				}
				else {
					if (map[now_x][now_y]){
					}
					else{
						lost = 1;
						map[now_x][now_y] = 1;
					}
				}
				break;
			}


		}
		printf("%d %d ", now_x, now_y);
		cout << getD(d);
		if (lost)
			cout << " LOST";
		cout << endl;

	}

















	return 0;
}