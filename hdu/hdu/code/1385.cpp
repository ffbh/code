#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define MMAX 510
#define INF 99999999
int N;
int extra[MMAX];
int pace[MMAX][MMAX];
int dist[MMAX][MMAX];
void floyd(){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j){
			pace[i][j] = j;
	}
	for (int k = 0; k < N; ++k)
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j)
	{
		int	temp = dist[i][k] + dist[k][j] + extra[k];
		if (dist[i][j]>temp ){
			pace[i][j] = pace[i][k];
			dist[i][j] = temp;
		}
		else if (dist[i][j] == temp)
			pace[i][j] = min(pace[i][k],pace[i][j]);
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j){
			cin >> dist[i][j];
			if (dist[i][j] < 0)
				dist[i][j] = INF;
		}
		for (int i = 0; i < N; ++i)
			cin >> extra[i];
		int a, b;
		int temp;
		floyd();
		while (cin >> a >> b&&a + b >= 0){
			printf("From %d to %d :\n", a, b);
			a--;
			b--;
			temp = dist[a][b];
			printf("Path: ");
			while (a != b){
				printf("%d-->", a + 1);
				a = pace[a][b];
			}
			printf("%d\n", b + 1);
			printf("Total cost : %d\n", temp);
			cout << endl;
		}
		
	}
	return 0;
}



