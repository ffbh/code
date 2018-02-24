#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int map[110][110];
const int MM = 9999999;
void floyd(){
	for (int k = 0; k < N;++k)
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N;++j)
	if (map[i][j]>map[i][k] + map[k][j])
		map[i][j] = map[i][k] + map[k][j];
}


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			map[i][j] = MM;
		while (M--){
			int a, b;
		//	in >> a >> b;
			scanf("%d%d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}
		for (int i = 0; i < N; ++i)
			map[i][i] = 0;
		floyd();
		bool flag = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N;++j)
		if (map[i][j]>7){
			flag = 1;
			break;
		}
		if (flag)
			cout << "No" << endl; 
		else
			cout << "Yes" << endl;
	}
	return 0;
}