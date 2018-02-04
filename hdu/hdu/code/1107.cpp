#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct People{
	People(){
		dir = 1;
	}
	int x, y;
	int dir;
	char flag;
	int IF, ATK, HP;
	virtual int getATK() = 0;
	virtual void move() = 0;
};

struct SPeople : public People{
	int getATK(){
		return (0.5*IF + 0.5*ATK)*(HP + 10) / 100;
	}
	void move(){
		if (x == 1 || x == 12){
			if (x == 1)
				dir = 1;
			else
				dir = -1;
		}
		x += dir;
	}
};

struct WPeople : public People{
	int getATK(){
		return (0.8*IF + 0.2*ATK)*(HP + 10) / 100;
	}
	void move(){
		if (y == 1 || y == 12){
			if (y == 1)
				dir = 1;
			else
				dir = -1;
		}
		y += dir;
	}
};

struct EPeople : public People{
	int getATK(){
		return (0.2*IF + 0.8*ATK)*(HP + 10) / 100;
	}
	void move(){
		if (!(x == 12 &&y == 1 || x == 1 && y == 12)){
			if (y == 1 || x == 12 || x == 1 || y == 12){
				if (y == 1 || x == 1)
					dir = 1;
				else
					dir = -1;
			}
			x += dir;
			y += dir;
		}
	}
};

vector<People*> vp[13][13];
vector<People*> TEMP;

void Start(int time){
	People* temp;
	while (time--){
		for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 12; ++j){//战斗
			if (vp[i][j].size() == 2 && vp[i][j][0]->flag != vp[i][j][1]->flag){
				int oneATK = vp[i][j][0]->getATK();
				int twoATK = vp[i][j][1]->getATK();
				vp[i][j][0]->HP -= twoATK;
				vp[i][j][1]->HP -= oneATK;
			}
		}
		for (int i = 0; i <= 12;++i)
		for (int j = 0; j <= 12; ++j){
			while (!vp[i][j].empty()){//计算移动+去掉死人
				temp = vp[i][j].back();
				vp[i][j].pop_back();
				temp->move();
				if (temp->HP > 0)
					TEMP.push_back(temp);
				else
					delete temp;
			}
		}
		while (!TEMP.empty()){//移动
			temp = TEMP.back();
			TEMP.pop_back();
			vp[temp->x][temp->y].push_back(temp);
		}
	}
}

int main(){
//	ifstream in("C:\\temp.txt");
	int T;
	int N;
	cin >> T;
	char flag;
	while (T--){
		for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 12; ++j)
		if (!vp[i][j].empty()){
			for (int k = 0; k < vp[i][j].size(); ++k)
				delete vp[i][j][k];
			vp[i][j].clear();
		}
		cin >> N;
		while (cin >> flag&&flag != '0'){
			if (flag == 'S'){
				SPeople* sp = new SPeople();
				sp->flag = 'S';
				cin >> sp->x >> sp->y >> sp->IF >> sp->ATK >> sp->HP;
				vp[sp->x][sp->y].push_back(sp);
			}
			else if (flag == 'W'){
				WPeople* wp = new WPeople();
				wp->flag = 'W';
				cin >> wp->x >> wp->y >> wp->IF >> wp->ATK >> wp->HP;
				vp[wp->x][wp->y].push_back(wp);
			}
			else{
				EPeople* ep = new EPeople();
				ep->flag = 'E';
				cin >> ep->x >> ep->y >> ep->IF >> ep->ATK >> ep->HP;
				vp[ep->x][ep->y].push_back(ep);
			}
		}

		Start(N);
		int st, wt, et;
		int  sh, wh, eh;
		st = sh = wt = wh = et = eh = 0;
		for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 12; ++j)
		for (int k = 0; k < vp[i][j].size(); ++k){
			if (vp[i][j][k]->flag == 'S'){
				st++;
				sh += vp[i][j][k]->HP;
			}
			else if (vp[i][j][k]->flag == 'W'){
				wt++;
				wh += vp[i][j][k]->HP;
			}
			else{
				et++;
				eh += vp[i][j][k]->HP;
			}
		}
		printf("%d %d\n%d %d\n%d %d\n***\n", st, sh,
			wt, wh, et,eh);
	}
	return 0;
}