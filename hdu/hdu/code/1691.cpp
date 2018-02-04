#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
//ifstream in("C:\\input.txt");
struct Point {
	int x, y;
};
class ChineseChess{
	int map[11][10];
	bool end;
public:
	bool IN(Point& p){
		return p.x >= 1 && p.x <= 10 && p.y >= 1 && p.y <= 9;
	}
	void showMap(){
		for (int i = 1; i <= 10; ++i){
			for (int j = 1; j <= 9; ++j)
				cout << map[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	bool isRed(Point& p){
		return map[p.x][p.y] >= 1 && map[p.x][p.y] <= 7;
	}
	bool isBlack(Point& p){
		return map[p.x][p.y] >= 8 && map[p.x][p.y] <= 14;
	}
	void InitMap(){
		end = 0;
		for (int i = 1; i <= 10;++i)
		for (int j = 1; j <= 9; ++j)
			cin >> map[i][j];
	}
	bool moveable(Point& src, Point& dec, int flag){
		if (!IN(src) || !IN(dec)||end)
			return 0;
		if (src.x == dec.x&&src.y == dec.y)
			return 0;
		if (!flag){
			if (!isRed(src) || isRed(dec))
				return 0;

			if (map[src.x][src.y] == 1){
				if (src.x<8 || src.x>10 || src.y<4 || src.y>6)
					return 0;
				if (dec.x<8 || dec.x>10 || dec.y<4 || dec.y>6)
					return 0;
				if (abs(src.x - dec.x) + abs(src.y - dec.y) != 1)
					return 0;
				for (int i = dec.x-1; i >= 1; --i){
					if (map[i][dec.y] == 8)
						return 0;
					if (map[i][dec.y] != 0)
						break;
				}
			}
			else if (map[src.x][src.y] == 2){
				if (dec.x<8 || dec.x>10 || dec.y<4 || dec.y>6)
					return 0;
				if (src.x<8 || src.x>10 || src.y<4 || src.y>6)
					return 0;
				if ((dec.x + dec.y) % 2 == 1)
					return 0;
				if ((src.x + src.y) % 2 == 1)
					return 0;
				if (abs(src.x - dec.x) != 1 || abs(src.x - dec.x) != 1)
					return 0;
			}
			else if (map[src.x][src.y] == 3){
				bool f = 0;
				int x = src.x;
				int y = src.y;
				if (x == 6 && (y == 3 || y == 7))
					f = 1;
				if (x == 8 && (y == 1 || y == 5 || y == 9))
					f = 1;
				if ((x == 10 && (y == 3 || y == 7)))
					f = 1;
				if (!f)
					return 0;
				Point clash;
				if (dec.x<6 || dec.x>10 || dec.y<1 || dec.y>9)
					return 0;
				if (abs(src.x - dec.x) != 2 || abs(src.x - dec.x) != 2)
					return 0;
				clash.x = (src.x + dec.x) / 2;
				clash.y = (src.y + dec.y) / 2;
				if (map[clash.x][clash.y] != 0)
					return 0;
			}
			else if (map[src.x][src.y] == 4){
				Point clash;
				if (abs(src.x - dec.x) == 1 && abs(src.y - dec.y) == 2){
					clash.x = src.x;
					clash.y = (src.y + dec.y) / 2;
					if (map[clash.x][clash.y] != 0)
						return 0;
				}
				else if (abs(src.y - dec.y) == 1 && abs(src.x - dec.x) == 2){
					clash.y = src.y;
					clash.x = (src.x + dec.x) / 2;
					if (map[clash.x][clash.y] != 0)
						return 0;
				}
				else
					return 0;
			}
			else if (map[src.x][src.y] == 5){
				if (src.x != dec.x && src.y != dec.y)
					return 0;
				int mmin, mmax;
				if (src.x == dec.x){
					mmin = min(src.y, dec.y) + 1;
					mmax = max(src.y, dec.y) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[src.x][i] != 0)
						return 0;
				}
				else{
					mmin = min(src.x, dec.x) + 1;
					mmax = max(src.x, dec.x) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[i][src.y] != 0)
						return 0;
				}
			}
			else if (map[src.x][src.y] == 6){
				int mmin, mmax, num = 0;
				if (src.x == dec.x){
					mmin = min(src.y, dec.y) + 1;
					mmax = max(src.y, dec.y) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[src.x][i] != 0)
						num++;
				}
				else{
					mmin = min(src.x, dec.x) + 1;
					mmax = max(src.x, dec.x) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[i][src.y] != 0)
						num++;
				}
				if (num == 0){
					if (map[dec.x][dec.y] != 0)
						return 0;
				}
				else if (num == 1){
					if (!isBlack(dec))
						return 0;
				}
				else
					return 0;
			}
			else{
				if (abs(src.x - dec.x) + abs(src.y - dec.y) != 1)
					return 0;
				if (src.x >= 6){
					if (dec.x != src.x - 1)
						return 0;
				}
				else{
					if (src.x < dec.x)
						return 0;
				}
			}

		}
		else{
			if (!isBlack(src) || isBlack(dec))
				return 0;
			if (map[src.x][src.y] == 8){
				if (dec.x<1 || dec.x>3 || dec.y<4 || dec.y>6)
					return 0;
				if (src.x<1 || src.x>3 || src.y<4 || src.y>6)
					return 0;
				if (abs(src.x - dec.x) + abs(src.y - dec.y) != 1)
					return 0;
				for (int i = dec.x+1; i <= 10; ++i){
					if (map[i][dec.y] == 1)
						return 0;
					if (map[i][dec.y] != 0)
						break;
				}
			}
			else if (map[src.x][src.y] == 9){
				if (dec.x<1 || dec.x>3 || dec.y<4 || dec.y>6)
					return 0;
				if (src.x<1 || src.x>3 || src.y<4 || src.y>6)
					return 0;
				if ((dec.x + dec.y) % 2 != 1)
					return 0;
				if ((src.x + src.y) % 2 != 1)
					return 0;
				if (abs(src.x - dec.x) != 1 || abs(src.x - dec.x) != 1)
					return 0;

			}
			else if (map[src.x][src.y] == 10){
				bool f = 0;
				int x = src.x;
				int y = src.y;
				if (x == 1 && (y == 3 || y == 7))
					f = 1;
				if (x == 3 && (y == 1 || y == 5 || y == 9))
					f = 1;
				if ((x == 5 && (y == 3 || y == 7)))
					f = 1;
				if (!f)
					return 0;
				Point clash;
				if (dec.x<1 || dec.x>5 || dec.y<1 || dec.y>9)
					return 0;
				if (abs(src.x - dec.x) != 2 || abs(src.x - dec.x) != 2)
					return 0;
				clash.x = (src.x + dec.x) / 2;
				clash.y = (src.y + dec.y) / 2;
				if (map[clash.x][clash.y] != 0)
					return 0;

			}
			else if (map[src.x][src.y] == 11){
				Point clash;
				if (abs(src.x - dec.x) == 1 && abs(src.y - dec.y) == 2){
					clash.x = src.x;
					clash.y = (src.y + dec.y) / 2;
					if (map[clash.x][clash.y] != 0)
						return 0;
				}
				else if (abs(src.y - dec.y) == 1 && abs(src.x - dec.x) == 2){
					clash.y = src.y;
					clash.x = (src.x + dec.x) / 2;
					if (map[clash.x][clash.y] != 0)
						return 0;
				}
				else
					return 0;

			}
			else if (map[src.x][src.y] == 12){
				if (src.x != dec.x && src.y != dec.y)
					return 0;
				int mmin, mmax;
				if (src.x == dec.x){
					mmin = min(src.y, dec.y) + 1;
					mmax = max(src.y, dec.y) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[src.x][i] != 0)
						return 0;
				}
				else{
					mmin = min(src.x, dec.x) + 1;
					mmax = max(src.x, dec.x) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[i][src.y] != 0)
						return 0;
				}


			}
			else if (map[src.x][src.y] == 13){
				int mmin, mmax, num = 0;
				if (src.x == dec.x){
					mmin = min(src.y, dec.y) + 1;
					mmax = max(src.y, dec.y) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[src.x][i] != 0)
						num++;
				}
				else{
					mmin = min(src.x, dec.x) + 1;
					mmax = max(src.x, dec.x) - 1;
					for (int i = mmin; i <= mmax; ++i)
					if (map[i][src.y] != 0)
						num++;
				}
				if (num == 0){
					if (map[dec.x][dec.y] != 0)
						return 0;
				}
				else if (num == 1){
					if (!isRed(dec))
						return 0;
				}
				else
					return 0;
			}
			else{
				if (abs(src.x - dec.x) + abs(src.y - dec.y) != 1)
					return 0;
				if (src.x <= 5){
					if (dec.x != src.x + 1)
						return 0;
				}
				else{
					if (src.x > dec.x)
						return 0;
				}

			}

		}
		if (src.y >= 4 && src.y <= 6&&src.y!=dec.y){
			int num = 0;
			bool f1, f2;
			f1 = f2 = 0;
			for (int i = src.x + 1; i <= 10; ++i){
				if (map[i][src.y] == 1){
					f1 = 1;
					break;
				}
				if (map[i][src.y] != 0)
					num++;
			}
			for (int i = src.x - 1; i >= 1; --i){
				if (map[i][src.y] == 8){
					f2 = 1;
					break;
				}
				if (map[i][src.y] != 0)
					num++;
			}
			if (f1&&f2&&num == 0)
				return 0;

		}


		if (map[dec.x][dec.y] == 1 || map[dec.x][dec.y] == 8)
			end = 1;
		map[dec.x][dec.y] = map[src.x][src.y];
		map[src.x][src.y] = 0;
		return 1;
	}
};




int main(){
	int T, M, flag, wrong;
	cin >> T;
	int CASE = 1;
	while (T--){
		ChineseChess chess;
		chess.InitMap();
		wrong = -1;
		cin >> M >> flag;
		for(int i=1;i<=M;++i){
			Point src, dec;
		//	chess.showMap();
			cin >> src.x >> src.y;
			cin >> dec.x >> dec.y;
			if (wrong == -1&&!chess.moveable(src, dec,flag))
				wrong = i;
			flag = (flag + 1) % 2;
		}
		if (wrong == -1)
			printf("Case %d: Legal move\n", CASE++);
		else
			printf("Case %d: Illegal move on step %d\n", CASE++, wrong);
	}
	


	return 0;
}
