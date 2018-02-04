#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
struct node{
	char c;
	int step;
};
node p[11][11];//可以用string数组，更快
int i, j,n;
struct Point{
int x, y;
};

bool stop(const Point& po){
	return po.x == 0 && p[po.x][po.y].c == 'N' ||
		po.x == i - 1 && p[po.x][po.y].c == 'S' ||
		po.y == 0 && p[po.x][po.y].c == 'W' ||
		po.y == j - 1 && p[po.x][po.y].c == 'E';
}



int main(){
	Point po;
	int time;
	//ifstream in("C:\\temp.txt");
	while (cin >> i >> j){
		if (i == 0 || j == 0) break;
		
		cin >> n;
		
		string s;
		for (int a = 0; a < i; ++a){
			cin >> s;
			for (int b = 0; b < j; ++b){
				p[a][b].c = s[b];
				p[a][b].step = 0;
			}
		}
		
		po.x = 0;
		po.y = n - 1;
		time = 1;
		while (1){
			if (stop(po)){
				printf("%d step(s) to exit\n", time);
				break;
			}

			if (p[po.x][po.y].step ==0){
				char temp = p[po.x][po.y].c;
				p[po.x][po.y].step = time;
				if (temp == 'N')
					po.x--;
				else if (temp == 'S')
					po.x++;
				else if (temp == 'E')
					po.y++;
				else po.y--;
			}
			else {
				int now = p[po.x][po.y].step;
				int circle = time - now;
				printf("%d step(s) before a loop of %d step(s)\n", now - 1, circle);
				break;
			}
			time++;
		}
		

	}



	return 0;
}