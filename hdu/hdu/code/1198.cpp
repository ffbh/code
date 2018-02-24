#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int N, M;
struct node{;
	int up, down, left, right;
};
node dp[60][60];
int ans;
struct Point{
	int x, y;
	bool operator==(const Point& p)const{
		return x == p.x&&y == p.y;
	}
	bool operator<(const Point& p)const{
		return x*M + y < p.x*M + p.y;
	}
};
Point link[60][60];

Point find(Point& p){
	return p == link[p.x][p.y] ? p : p = find(link[p.x][p.y]);
}
void LinkV(){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M - 1; ++j)
		if (dp[i][j].right&&dp[i][j + 1].left){
			Point p1 = find(link[i][j]);
			Point p2 = find(link[i][j + 1]);
			if (!(p1 == p2)){
				//link[p1.x][p1.y].x = p2.x;
			//	link[p1.x][p1.y].y = p2.y;
				link[p1.x][p1.y] = p2;
				ans--;
			}//if
		}//if

}

void LinkH(){
	for (int i = 0; i < N - 1;++i)
	for (int j = 0; j < M; ++j)
		if (dp[i][j].down&&dp[i + 1][j].up){
			Point p1 = find(link[i][j]);
			Point p2 = find(link[i+1][j]);
			if(!(p1 == p2)){
				//link[p1.x][p1.y].x = p2.x;
				//link[p1.x][p1.y].y = p2.y;
				link[p1.x][p1.y] = p2;
				ans--;
			}//if
	}//if
}




int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (cin >> N >> M){
		if (N <= 0)break;
		ans = N*M;
		memset(dp, 0, sizeof(dp));
		memset(link, 0, sizeof(link));
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
			link[i][j].x = i;
			link[i][j].y = j;
		}
			
		
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < M; ++j)
				switch (s[j]){
				case 'A': 
					dp[i][j].up = 1;
					dp[i][j].left = 1;
					break;
				case 'B':
					dp[i][j].up = 1;
					dp[i][j].right = 1;
					break;
				case'C':
					dp[i][j].left = 1;
					dp[i][j].down = 1;
					break;
				case'D':
					dp[i][j].down = 1;
					dp[i][j].right = 1;
					break;
				case'E':
					dp[i][j].up = 1;		
					dp[i][j].down = 1;
					break;
				case'F':
					dp[i][j].left = 1;
					dp[i][j].right = 1;
					break;
				case'G':
					dp[i][j].up = 1;
					dp[i][j].left = 1;
					dp[i][j].right = 1;
					break;
				case'H':
					dp[i][j].up = 1;
					dp[i][j].left = 1;
					dp[i][j].down = 1;
					break;
				case'I':
					dp[i][j].left = 1;
					dp[i][j].down = 1;
					dp[i][j].right = 1;
					break;
				case'J':
					dp[i][j].up = 1;
					dp[i][j].down = 1;
					dp[i][j].right = 1;
					break;
				case'K':
					dp[i][j].up = 1;
					dp[i][j].left = 1;
					dp[i][j].down = 1;
					dp[i][j].right = 1;
					break;
				default:
					cout << "error" << endl;
					break;
				}//switch
		}//for
		LinkV();
		LinkH();
		cout <<ans << endl;
		
	
	}//while

	return 0;
}