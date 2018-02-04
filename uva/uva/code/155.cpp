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
struct Node{
	int x, y;


	void show(){
		//	printf("%.1f %.1f\n", x, y);
		printf("%d %d\n", x, y);
	}
};
int K, X, Y;
int ans;
void dfs(int k, int cx, int cy){

	if (k == 0)
		return;
	int len = k;
	Node lu, ru, ld, rd;
	lu.x = cx - len;
	lu.y = cy - len;

	ru.x = cx + len;
	ru.y = cy - len;

	ld.x = cx - len;
	ld.y = cy + len;

	rd.x = cx + len;
	rd.y = cy + len;

//	int width = rd.x - lu.x;


	ans++;
	if (X < lu.x || X > rd.x || Y < lu.y || Y > rd.y){
		ans--;
	}
	else{
		/*	cout << "K: " << k << endl;
			lu.show();
			ru.show();
			ld.show();
			rd.show();
			cout << endl;*/

	}


	if (X == cx || Y == cy){
		return;
	}

	if (X < cx&&Y < cy){
		dfs(k / 2, lu.x, lu.y);
	}
	else if (X>cx&&Y < cy){
		dfs(k / 2, ru.x, ru.y);
	}
	else if (X<cx&&Y>cy){
		dfs(k / 2, ld.x, ld.y);
	}
	else{
		dfs(k / 2, rd.x, rd.y);
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	while (in >> K >> X >> Y){
		if (K == 0 && X == 0 && Y == 0){
			break;
		}
	//	X *= 2;
	//	Y *= 2;
		//	swap(X, Y);
		//	K *= 2;
		ans = 0;
		dfs(K, 1024, 1024);

		printf("%3d\n", ans);

	}



	return 0;
}