#include <iostream>
#include <cmath>
using namespace std;


bool p[9][9] = { 0 };
int n, m, t;
int sx, sy, dx, dy;
int block;

bool move(int x,int y,int time){
	if (x==dx&&y==dy) return time==0;
	if (((time - abs(dx - x) - abs(dy - y))<0)) return false;
	if ((time - (n*m - block)) > 0) return false;
	if (time == 0) return false;
	
	p[x][y] =0;
	block++;
	if ( p[x + 1][y] ==true )
		if (move(x + 1, y, time - 1))
			return true;

	if (p[x - 1][y] ==true)
		if (move(x - 1, y, time - 1))
			return true;

	if (p[x ][y+ 1] ==true)
		if (move(x, y + 1, time - 1))
			return true;

	if (p[x ][y- 1] ==true)
		if (move(x, y - 1, time - 1))
			return true;

	block--;
	p[x][y] =1;
	return false;

}
int main(){
	while (cin >> n >> m >> t){
		if (n == 0 && m == 0 && &t == 0) break;
		block = 0;
		char c;
		for (int i = 1; i <= n; ++i){
			int j;
			for (j = 1; j <=m; ++j){
				cin >> c;
				if ('.' == c)
					p[i][j] = true;
				else if ('X' == c)
					block++;
				else if ('S' == c){
					p[i][j] = true;
					sx = i;
					sy = j;
				}
				else if ('D' == c){
					p[i][j] = true;
					dx = i;
					dy = j;
				}
			}
		}

		if ((abs(t+sx+sy+dx+dy) % 2)!=1)
			if(move(sx,sy,t))
				cout << "YES"<<endl;
			else
				cout << "NO"<<endl;
		else
			cout << "NO" << endl;
		for (int i = 0; i < 9;++i)
		for (int j = 0; j < 9;++j)
			p[i][j] = false;
	
	}
	return 0;
}