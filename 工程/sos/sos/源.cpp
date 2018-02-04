#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
int dirs[8][2] = { 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1 };
char zifu[] = { 'S', 'O' };
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
	Block(){}
	Block(int a, int b, char _c) :x(a), y(b), c(_c){}
	bool _IN()const{
		return x >= 1 && x <= N_SIZE&&y >= 1 && y <= M_SIZE;
	}
	void Print()const{
		cout << x << " " << y << " " << c << endl;
	}
};
class SOS{
	char map[N_SIZE + 10][M_SIZE + 10];
	double maxdepth;
	vector<Block> tmp[N_SIZE*M_SIZE * 20];
	Block good;
	int nowscore1, nowscore2;
	bool mark[N_SIZE + 10][M_SIZE + 10][2];
	bool flag;
public:
	int round;
	vector<Block> Arr[10];	
	vector<Block> tt;
	void Init();
	void DebugInput();
	void Print();
	int max_value(int, int, int, int, int, int);
	int min_value(int, int, int, int, int, int);
	void decision();
	bool PC_move();
	bool Play_move();
	int getScore(const Block&);
	void set(const Block&, bool);
	void GameOver();
	bool judge1(const Block&);//是否可放
	int _judge1(const Block&);
	int judge2(const Block&);//构造双s
	bool judge3();//送分
	int _judge3();
	bool judge4();//是否有好点
	bool getGG();
	void dArr();
	int dfs(const Block&);
}start;

int SOS::dfs(const Block& p){
	if (getScore(p) > 0){
		int mmax = -1;
		map[p.x][p.y] = p.c;
		for (int i = 1; i <= N_SIZE; ++i)
		for (int j = 1; j <= M_SIZE; ++j)
		if (map[i][j] == 0){
			int ret = dfs(Block(i, j, 'S'));
			if (ret > mmax)
				mmax = ret;
			ret = dfs(Block(i, j, 'O'));
			if (ret > mmax)
				mmax = ret;
		}
		map[p.x][p.y] = 0;
		return mmax + 1;
	}
	return 0;
}
bool SOS::getGG(){
	for (int i = 1; i <= N_SIZE; ++i)
	for (int j = 1; j <= M_SIZE; ++j)
	if (map[i][j] == 0)
	for (int k = 0; k < 2; ++k){
		if (getScore(Block(i, j, zifu[k])))
			return 1;
	}
	return 0;
}


void SOS::DebugInput(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i <= N_SIZE; ++i){
		for (int j = 1; j <= M_SIZE; ++j){
			while ((map[i][j] = in.get()) == '\n');
			if (map[i][j] == ' ')
				map[i][j] = 0;
		}
	}
}

bool SOS::judge3(){
	for (int i = 1; i <= N_SIZE; ++i)
	for (int j = 1; j <= M_SIZE; ++j)
	if (map[i][j] == 0)
	for (int k = 0; k < 2; ++k){
		if (judge1(Block(i, j, zifu[k]))){
			return 1;
		}
	}
	return 0;
}

int SOS::_judge3(){
	int num = 0;
	for (int i = 1; i <= N_SIZE; ++i)
	for (int j = 1; j <= M_SIZE; ++j)
	if (map[i][j] == 0)
	for (int k = 0; k < 2; ++k){
		if (judge1(Block(i, j, zifu[k])))
			num++;
	}
	return num;
}
bool SOS::judge4(){
	for (int i = 1; i <= N_SIZE;++i)
	for (int j = 1; j <= M_SIZE;++j)
	if (map[i][j] == 0){
		for (int k = 0; k < 2;++k)
		if (getScore(Block(i, j, zifu[k]))){
			good = Block(i, j, zifu[k]);
			return 1;
		}
	}
	return 0;
}

int SOS::judge2(const Block& p){
	int d = 0;
	Block temp[3];
	for (int k = 0; k < 8; ++k){
		int sum = 0;
		temp[0].x = p.x + dirs[k][0];
		temp[0].y = p.y + dirs[k][1];
		if (temp[0]._IN())
			sum += map[temp[0].x][temp[0].y];
		else
			sum = INF;
		for (int m = 1; m < 3; ++m){
			temp[m].x = temp[m - 1].x + dirs[k][0];
			temp[m].y = temp[m - 1].y + dirs[k][1];
			if (temp[m]._IN())
				sum += map[temp[m].x][temp[m].y];
			else
				sum = INF;
		}
		sum -= 'S';
		if (temp[2]._IN() && !sum&&map[temp[2].x][temp[2].y]=='S')
			d++;
	}
	return d;
}


void SOS::Init(){
	memset(map, 0, sizeof(map));
	memset(mark, 0, sizeof(mark));
	round = nowscore1 = nowscore2 = 0;
	maxdepth = 4;
	flag = 0;
}

bool SOS::judge1(const Block& p){
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

int SOS::_judge1(const Block& p){
	Block temp, t;
	int num = 0;
	if (p.c == 'O'){
		for (int i = 0; i < 8; ++i){
			temp.x = p.x + dirs[i][0];
			temp.y = p.y + dirs[i][1];
			if (temp._IN() && map[temp.x][temp.y] == 'S'){
				t.x = p.x - dirs[i][0];
				t.y = p.y - dirs[i][1];
				if (t._IN() && map[t.x][t.y] == 0)
					num++;
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
				num++;
		}
	}
	return num;
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
	while (!flag || !p._IN()||map[p.x][p.y]!=0){
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

void SOS::dArr(){
	for (int i = 0; i < 10; ++i)
		Arr[i].clear();
	for (int i = 1; i <= N_SIZE;++i)
	for (int j = 1; j <= M_SIZE;++j)
	if (map[i][j] == 0){
		if (judge1(Block(i, j, 'S')))
			Arr[judge2(Block(i, j, 'S'))].push_back(Block(i, j, 'S'));
	}
	tt.clear();
	for (int i = 1; i <= 7;i+=3)
	for (int j = 1; j <= 7;j+=3)
	if (map[i][j]==0&&judge1(Block(i, j, 'S')))
		tt.push_back(Block(i, j, 'S'));
}

bool SOS::PC_move(){
	int score;
	round++;	
	bool  b4;
	Block computer;
	if (round > 34)
		maxdepth+=1.5;
	if (round > N_SIZE*M_SIZE){
		GameOver();
		exit(0);
	}
	else{
		cout << "电脑回合..." << endl;
		dArr();
		b4 = judge4();
		if (b4&&dfs(good) >= 2){
			computer = good;
		}
		else if (!tt.empty()&&!b4){
			int size = tt.size();
			srand(time(0));
			int random = rand() % size;
			computer = tt[random];
		}
		else{
			int k;
			for (k = 7; k >= 0; --k)
			if (!Arr[k].empty())
				break;
			if (k >= 0&&!b4){
				int size = Arr[k].size();
				srand(time(0));
				int random = rand() % size;
				computer = Arr[k][random];
			}
			else{
				decision();
				for (int i = N_SIZE*M_SIZE * 20 - 1; i >= 0; --i)
				if (!tmp[i].empty()){
					int size = tmp[i].size();
					srand(time(0));
					int random = rand() % size;
					computer = tmp[i][random];
					break;
				}
			}
		}
	}
	set(computer, 0);
	score = getScore(computer);
	Print();
	computer.Print();
	nowscore1 += score;
	return score != 0;
}

void SOS::set(const Block& p, bool flag){
	if (!p._IN()){
		cout << "越界" << endl;
		p.Print();
		exit(0);
	}
	map[p.x][p.y] = p.c;
}

int SOS::getScore(const Block& p){
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
		score = getScore(Block( i, j, 'S' ));
		map[i][j] = 'S';
		if (score==0)
			v = mmax(v, min_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		else
			v = mmax(v, max_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		map[i][j] = 0;
		if (v >= beat) return v;
		alpha = mmax(alpha, v);
		score = getScore(Block( i, j, 'O' ));
		map[i][j] = 'O';
		if (score==0)
			v = mmax(v, min_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		else
			v = mmax(v, max_value(nowdep + 1, dep + 1, score1 + score, score2, alpha, beat));
		map[i][j] = 0;
		if (v >= beat) return v;
		alpha = mmax(alpha, v);
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
		score = getScore(Block( i, j, 'S' ));
		map[i][j] = 'S';
		if (score==0)
			v = mmin(v, max_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		else
			v = mmin(v, min_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		map[i][j] = 0;
		if (v <= alpha)return v;
		beat = mmin(beat, v);
		score = getScore(Block( i, j, 'O' ));
		map[i][j] = 'O';
		if (score==0)
			v = mmin(v, max_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		else
			v = mmin(v, min_value(nowdep + 1, dep + 1, score1, score2 + score, alpha, beat));
		map[i][j] = 0;
		if (v <= alpha)return v;
		beat = mmin(beat, v);
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
		score = getScore(Block( i, j, 'S' ));
		map[i][j] = 'S';
		if (score==0)
			tmp[N_SIZE*M_SIZE * 10 + min_value(round, 1, nowscore1 + score, nowscore2, -INF, INF)].push_back(Block{ i, j, 'S' });
		else
			tmp[N_SIZE*M_SIZE * 10 + max_value(round, 1, nowscore1 + score, nowscore2, -INF, INF)].push_back(Block{ i, j, 'S' });
		map[i][j] = 0;
		score = getScore(Block( i, j, 'O' ));
		map[i][j] = 'O';
		if (score==0)
			tmp[N_SIZE*M_SIZE * 10 + min_value(round, 1, nowscore1 + score, nowscore2, -INF, INF)].push_back(Block{ i, j, 'O' });
		else
			tmp[N_SIZE*M_SIZE * 10 + max_value(round, 1, nowscore1 + score, nowscore2, -INF, INF)].push_back(Block{ i, j, 'O' });
		map[i][j] = 0;
	}
}

void SOS::Print(){
	for (int i = 0; i <= M_SIZE; ++i)
		cout << i << " ";
	cout << endl;
	for (int i = 1; i <= N_SIZE; ++i){
		cout << i << " ";
		for (int j = 1; j <= M_SIZE; ++j){
			if (map[i][j]){
				printf("%c", map[i][j]);
				cout << " ";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "PC得分: " << nowscore1;
	cout << "  ,  ";
	cout << "玩家得分: " << nowscore2;
	cout << endl;
}

int main(){
	start.Init();
	start.Print();
	while (start.round <= N_SIZE*M_SIZE){	
		
		while (start.PC_move());
		while (start.Play_move());
	}

	return 0;
}