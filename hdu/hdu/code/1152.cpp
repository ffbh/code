#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int x, y;
};
Node data[200010];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i].x >> data[i].y;
		int X = data[N / 2].x;
		int Y = data[N / 2].y;
		int a, b;
		a = b = 0;
		for (int i = 0; i < N; ++i){
			if (X == data[i].x || Y == data[i].y)
				continue;
			if (data[i].x>X&&data[i].y>Y || data[i].x < X&&data[i].y < Y)
				a++;
			else
				b++;
		}
		printf("%d %d\n", a, b);



	}





	return 0;
}