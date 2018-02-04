#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;
int dirs[8][2] = { 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1 };
const static int  N_SIZE = 7;
const static int  M_SIZE = 7;
const int INF = (1 << 28);
int mmax(int a, int b){
	return a > b ? a : b;
}
int mmin(int a, int b){
	return a < b ? a : b;
}
struct Block{
	int x, y;
	char c;
	bool _IN(){
		return x >= 1 && x <= N_SIZE&&y >= 1 && y <= M_SIZE;
	}
	void Print(){
		cout << x << " " << y << " " << c << endl;
	}
};
class SOS{
	char map[N_SIZE + 10][M_SIZE + 10];
	const int maxdepth = 4;
	vector<Block> tmp[N_SIZE*M_SIZE * 20];
	int nowscore1, nowscore2;
	bool mark[N_SIZE + 10][M_SIZE + 10][2];
public:
	int round;
	void Init();
	void Print();
	int max_value(int, int, int, int, int, int);
	int min_value(int, int, int, int, int, int);
	void decision();
	bool PC_move();
	bool Play_move();
	int getScore(Block&);
	void set(Block&, bool);
	void GameOver();
	bool OK(Block&);
}start;
bool SOS::OK(Block& p){
	Block temp, t;
	if (p.c == 'O'){
		for (int i = 0; i < 8; ++i){
			temp.x = p.x + dirs[i][0];
			temp.y = p.y + dirs[i][1];
			if (temp._IN() && map[temp.x][temp.y] == 'S'){
				t.x = p.x - dirs[i][0];
				t.y = p.y - dirs[i][1];
				if (t._IN() && map[t.x][t.y] == 0)
					return 0;
			}
		}
	}
	else{
		for (int i = 0; i < 8; ++i){
			temp.x = p.x + dirs[i][0];
			temp.y = p.y + dirs[i][1];
			t.x = temp.x + dirs[i][0];
			t.y = temp.y + dirs[i][1];
			if (temp._IN() && map[temp.x][temp.y] == 'O'&&t._IN() && map[t.x][t.y] == 0
				|| temp._IN() && map[temp.x][temp.y] == 0 && t._IN() && map[t.x][t.y] == 'S')
				return 0;
		}
	}
	return 1;
}

void SOS::Init(){
	memset(map, 0, sizeof(map));
	memset(mark, 0, sizeof(mark));
	round = nowscore1 = nowscore2 = 0;
}

bool SOS::Play_move(){
	round++;
	if (round > N_SIZE*M_SIZE){
		GameOver();
		exit(0);
	}
	cout << "玩家回合..." << endl;
	Block p;
	cout << "请输入坐标xy和S或者O：";
	cin >> p.x >> p.y >> p.c;
	bool flag = 0;
	if (p.c == 'o' || p.c == 'O'){
		p.c = 'O';
		flag = 1;
	}
	else if (p.c == 's' || p.c == 'S'){
		p.c = 'S';
		flag = 1;
	}
	while (!flag || !p._IN() || map[p.x][p.y] != 0){
		flag = 0;
		cout << "输入格式错误！请输重新入坐标xy和S或者O：";
		cin >> p.x >> p.y >> p.c;
		if (p.c == 'o' || p.c == 'O'){
			p.c = 'O';
			flag = 1;
		}
		else if (p.c == 's' || p.c == 'S'){
			p.c = 'S';
			flag = 1;
		}
	}
	int score = getScore(p);
	nowscore2 += score;
	set(p, 1);
	Print();
	return score != 0;
}
void SOS::GameOver(){
	cout << endl;
	if (nowscore1 > nowscore2)
		cout << "you lose!" << endl;
	else if (nowscore1 == nowscore2)
		cout << "tie!" << endl;
	else
		cout << "you win!" << endl;
	cout << endl;
}

bool SOS::PC_move(){
	int score;
	round++;
	if (round > N_SIZE*M_SIZE){
		GameOver();
		exit(0);
	}
	else{
		cout << "电脑回合..." << endl;
		decision();
		for (int i = N_SIZE*M_SIZE * 20 - 1; i >= 0; --i)
		if (!tmp[i].empty()){
			int size = tmp[i].size();
			srand(time(0));
			int random = rand() % size;
			score = getScore(tmp[i][random]);
			nowscore1 += score;
			set(tmp[i][random], 0);
			Print();
			tmp[i][random].Print();
			break;
		}
	}
	return score != 0;
}

void SOS::set(Block& p, bool flag){
	if (!p._IN()){
		cout << "越界" << endl;
		p.Print();
		exit(0);
	}
	map[p.x][p.y] = p.c;
	Block temp, t;
	if (p.c == 'S'){
		for (int i = 0; i < 8; ++i){
			temp.x = p.x + dirs[i][0];
			temp.y = p.y + dirs[i][1];
			if (temp._IN() && start.map[temp.x][temp.y] == 'O'){
				t.x = temp.x + dirs[i][0];
				t.y = temp.y + dirs[i][1];
				if (t._IN() && start.map[t.x][t.y] == 'S')
					mark[p.x][p.y][flag] = mark[temp.x][temp.y][flag] = mark[t.x][t.y][flag] = 1;
			}
		}
	}
	else{
		for (int i = 0; i < 4; ++i){
			temp.x = p.x + dirs[i][0];
			temp.y = p.y + dirs[i][1];
			t.x = p.x - dirs[i][0];
			t.y = p.y - dirs[i][1];
			if (temp._IN() && t._IN() &&
				start.map[temp.x][temp.y] == 'S'&&start.map[t.x][t.y] == 'S')
				mark[p.x][p.y][flag] = mark[temp.x][temp.y][flag] = mark[t.x][t.y][flag] = 1;
		}
	}

}

int SOS::getScore(Block& p){
	Block temp, t;
	int score = 0;
	if (p.c == 'S'){
		for (int i = 0; i < 8; ++i){
			temp.x = p.x + dirs[i][0];
			temp.y = p.y + dirs[i][1];
			if (temp._IN() && start.map[temp.x][temp.y] == 'O'){
				temp.x += dirs[i][0];
				temp.y += dirs[i][1];
				if (temp._IN() && start.map[temp.x][temp.y] == 'S')
					score++;
			}
		}
	}
	else{
		for (int i = 0; i < 4; ++i){
			temp.x = p.x + dirs[i][0];
			temp.y = p.y + dirs[i][1];
			t.x = p.x - dirs[i][0];
			t.y = p.y - dirs[i][1];
			if (temp._IN() && t._IN() &&
				start.map[temp.x][temp.y] == 'S'&&start.map[t.x][t.y] == 'S')
				score++;
		}
	}
	return score;
}

int SOS::max_value(int nowdep, int dep, int score1, int score2, int alpha, int beat){
	if (nowdep >= N_SIZE*M_SIZE || dep == maxdepth)
		return score1 - score2;
	int v = -INF, score;
	for (int i = 1; i <= N_SIZE; ++i)
	for (int j = 1; j <= M_SIZE; ++j)
	if (!map[i][j]){
		score = getScore(Block{ i, j, 'S' });
		map[i][j] = 'S';
		if (score == 0)
			v = mmax(v, min_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		else
			v = mmax(v, max_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		map[i][j] = 0;
		score = getScore(Block{ i, j, 'O' });
		map[i][j] = 'O';
		if (score == 0)
			v = mmax(v, min_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		else
			v = mmax(v, max_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		map[i][j] = 0;
	}
	return v;
}

int SOS::min_value(int nowdep, int dep, int score1, int score2, int alpha, int beat){
	if (nowdep >= N_SIZE*M_SIZE || dep == maxdepth)
		return score1 - score2;
	int v = INF, score;
	for (int i = 1; i <= N_SIZE; ++i)
	for (int j = 1; j <= M_SIZE; ++j)
	if (!map[i][j]){
		score = getScore(Block{ i, j, 'S' });
		map[i][j] = 'S';
		if (score == 0)
			v = mmin(v, max_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		else
			v = mmin(v, min_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		map[i][j] = 0;
		score = getScore(Block{ i, j, 'O' });
		map[i][j] = 'O';
		if (score == 0)
			v = mmin(v, max_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		else
			v = mmin(v, min_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		map[i][j] = 0;
	}
	return v;
}

void SOS::decision(){
	for (int i = 0; i < N_SIZE*M_SIZE * 20; ++i)
		tmp[i].clear();
	int score;
	for (int i = 1; i <= N_SIZE; ++i)
	for (int j = 1; j <= M_SIZE; ++j)
	if (!map[i][j]){
		score = getScore(Block{ i, j, 'S' });
		if (score)
			tmp[N_SIZE*M_SIZE * 20 - 1].push_back(Block{ i, j, 'S' });
		else if (!OK(Block{ i, j, 'S' }))
			tmp[0].push_back(Block{ i, j, 'S' });
		else{
			map[i][j] = 'S';
			tmp[N_SIZE*M_SIZE * 10 + min_value(round, 1, nowscore1 + score, nowscore2, -INF, INF)].push_back(Block{ i, j, 'S' });
			map[i][j] = 0;
		}
		score = getScore(Block{ i, j, 'O' });
		if (score)
			tmp[N_SIZE*M_SIZE * 20 - 1].push_back(Block{ i, j, 'O' });
		else if (!OK(Block{ i, j, 'O' }))
			tmp[0].push_back(Block{ i, j, 'O' });
		else{
			map[i][j] = 'O';
			tmp[N_SIZE*M_SIZE * 10 + min_value(round, 1, nowscore1 + score, nowscore2, -INF, INF)].push_back(Block{ i, j, 'O' });
			map[i][j] = 0;
		}
	}
}

void SOS::Print(){
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 0; i <= M_SIZE; ++i)
		cout << i << " ";
	cout << endl;
	for (int i = 1; i <= N_SIZE; ++i){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << i << " ";
		for (int j = 1; j <= M_SIZE; ++j){
			if (map[i][j]){
				if (!mark[i][j][0] && !mark[i][j][1])
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				else if (mark[i][j][0] && !mark[i][j][1])
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				else if (mark[i][j][0] && mark[i][j][1])
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c", map[i][j]);
				cout << " ";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	cout << "PC得分: " << nowscore1;
	cout << "  ,  ";
	cout << "玩家得分: " << nowscore2;
	cout << endl;
}



int main(){
	ifstream in("C:\\temp.txt");
	start.Init();
	start.Print();
	while (start.round <= N_SIZE*M_SIZE){
		while (start.PC_move());
		while (start.Play_move());

	}
	return 0;
}