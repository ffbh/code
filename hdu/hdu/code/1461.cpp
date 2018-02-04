#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
bool map[15][15];
bool temp[15][15];
bool aim[15][15];
bool OK(){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N;++j)
	if (map[i][j] != aim[i][j])
		return 0;
	return 1;
}
void Rorate(){
	bool t[15][15];
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j)
		t[i][j] = map[N-j-1][i];
	memcpy(map, t, sizeof(map));
}


void Reflect(){
	bool t[15][15];
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j)
		t[i][j] = map[N - i - 1][j];
	memcpy(map, t, sizeof(map));
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i){
			string s1, s2;
			cin >> s1 >> s2;
			for (int j = 0; j < N; ++j){
				if (s1[j] == '.')
					map[i][j] = 0;
				else
					map[i][j] = 1;
				if (s2[j] == '.')
					aim[i][j] = 0;
				else
					aim[i][j] = 1;
			}
		}
		if (OK()){
			printf("Preserved\n");
			continue;
		}
		memcpy(temp, map, sizeof(temp));
		bool flag = 0;
		for (int k = 1; k <= 3; ++k){
			Rorate();
			if (OK()){
				printf("Rotated through %d degrees\n", 90 * k);
				flag = 1;
				break;
			}
		}
		if (flag)
			continue;
		memcpy(map, temp, sizeof(map));
		Reflect();
		if (OK()){
			printf("Reflected\n");
			continue;
		}
		for (int k = 1; k <= 3; ++k){
			Rorate();
			if (OK()){
				printf("Reflected and rotated through %d degrees\n", 90 * k);
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "Improper" << endl;
	}
	return 0;
}