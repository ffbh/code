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
string s;

void Init(){
	s = "";
	for (char c = 'a'; c <= 'z'; ++c)
		s += c;
	for (char c = '0'; c <= '9'; ++c)
		s += c;
	for (char c = 'A'; c <= 'Z'; ++c)
		s += c;

}
int dirs[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
char mmp[110][110];
int N, M, T;


int ans[110][110];
int dp[110], pace[110];
int now_id;
int l, r;
int dd[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };


bool IN(int x, int y){
	return x >= 1 && x <= N&&y >= 1 && y <= M;
}




void show(){
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= M; ++j){
			putchar(mmp[i][j]);
		}
		cout << endl;
	}
}

bool judge(int x,int y){
	vector<int> vc;
	vc.push_back(ans[x][y]);
	if (x < N){
		vc.push_back(ans[x + 1][y]);
	}
	if (y < M){
		vc.push_back(ans[x][y + 1]);
	}
	if (x < N&&y < M){
		vc.push_back(ans[x + 1][y + 1]);
	}
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()), vc.end());
	

	return vc.size() < 4;
}
/*bool judge(int x, int y){
	vector<char> vc;
	vc.push_back(mmp[x][y]);
	if (x < N){
		vc.push_back(mmp[x + 1][y]);
	}
	if (y < M){
		vc.push_back(mmp[x][y + 1]);
	}
	if (x < N&&y < M){
		vc.push_back(mmp[x + 1][y + 1]);
	}
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()), vc.end());


	return vc.size() < 4;
}*/

bool test(){
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j){
		if (i == 2 && j == 5){
			int t = 0;
		}
		if (!judge(i, j))
			return 0;
	}
	return 1;
}

bool dfs(int dept){
	int x = -1, y;
	for (int i = 1; i <= N && x == -1;++i)
	for (int j = 1; j <= M && x == -1; ++j){
		if (mmp[i][j] == '-'){
			x = i;
			y = j;
		}
	}
	if (x == -1){
		if (!test()){
			cout << "wrong answer" << endl;
		}
		else
		show();
		return 1;
	}
	char code = s[dept];
	//char code = char(dept);
	mmp[x][y] = code;
	if (x < N && mmp[x+1][y] =='-'){
		mmp[x + 1][y] = code;
		bool ok = 1;
		for (int i = 0; i < 8; ++i){
			int nx = x + dirs[i][0];
			int ny = y + dirs[i][1];
		
			if (IN(nx, ny) && !judge(nx, ny)){
				ok = 0;
				break;
			}
		}
		if (ok){
			if (dfs(dept + 1))
				return 1;
		}
		mmp[x + 1][y] = '-';
	}

	if (y < M && mmp[x][y+1] =='-'){
		mmp[x][y + 1] = code;
		bool ok = 1;
		for (int i = 0; i < 8; ++i){
			int nx = x + dirs[i][0];
			int ny = y + dirs[i][1];

			if (IN(nx, ny) && !judge(nx, ny)){
				ok = 0;
				break;
			}
		}
		if (ok){
			if (dfs(dept + 1))
				return 1;
		}
		mmp[x][y + 1] = '-';

	}


	mmp[x][y] = '-';
	return 0;
}

void ceshi(){
	Init();
	for (int i = 0; i < 110; ++i)
	for (int j = 0; j < 110; ++j)
		mmp[i][j] = '-';

	N = 6;
	M = 8;

	if (!dfs(0)){
		cout << "bukenneg" << endl;
	}
}


bool In(int x,int y){
	return x >= 1 && x <= N&&y >= l&&y <= r;
}



void con_frame(int _l,int _r,int d,int inc){
	l = _l;
	r = _r;
	int now_x, now_y, now_d, nx, ny, nnx, nny, inc_num = 0;
	now_x = 1;
	now_y = l;
	now_d = d;
	while (inc_num < 4){
		nx = now_x + dd[now_d][0];
		ny = now_y + dd[now_d][1];
		if (In(nx, ny) && ans[nx][ny] == 0){
			ans[now_x][now_y] = ans[nx][ny] = now_id++;

			nnx = now_x + 2 * dd[now_d][0];
			nny = now_y + 2 * dd[now_d][1];
			if (In(nnx, nny) && ans[nnx][nny] == 0){
				now_x = nnx;
				now_y = nny;
			}
			else{
				now_d = (now_d + inc + 4) % 4;
				inc_num++;
				now_x = nx + dd[now_d][0];
				now_y = ny + dd[now_d][1];
			}

		}
		else{
			now_d = (now_d + inc + 4) % 4;
			inc_num++;
		}
	}
}

void fill(int x,int y,int d,int inc){
	int now_x, now_y, now_d, nx, ny, nnx, nny, inc_num = 0;
	now_x = x;
	now_y = y;
	now_d = d;
	while (ans[now_x][now_y] ==0 && inc_num < 4){
		nx = now_x + dd[now_d][0];
		ny = now_y + dd[now_d][1];
		if (ans[nx][ny] == 0){
			ans[now_x][now_y] = ans[nx][ny] = now_id++;

			nnx = now_x + 2 * dd[now_d][0];
			nny = now_y + 2 * dd[now_d][1];
			if ( ans[nnx][nny] == 0){
				now_x = nnx;
				now_y = nny;
			}
			else{
				now_d = (now_d + inc + 4) % 4;
				inc_num++;
				now_x = nx + dd[now_d][0];
				now_y = ny + dd[now_d][1];
			}

		}
		else{
			now_d = (now_d + inc + 4) % 4;
			inc_num++;
		}
	}

}




void spj(){
	if (N == 1){
		printf("%d %d", 1, 1);
		for (int i = 2; i <= M / 2; ++i){
			printf(" %d %d", i, i);
		}
		cout << endl;
	}
	else if (M == 1){
		for (int i = 1; i <= N / 2; ++i){
			printf("%d\n%d\n", i, i);
		}
	}
	else if (N == 2){
		printf("%d", 1);
		for (int i = 2; i <= M; ++i)
			printf(" %d", i);
		printf("\n");

		printf("%d", 1);
		for (int i = 2; i <= M; ++i)
			printf(" %d", i);
		printf("\n");
	}
	else{
		for (int i = 1; i <= N; ++i){
			printf("%d %d\n", i, i);
		}
		printf("\n");
	}


}

void show_ans(bool chan){
	if (!chan){
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j < M; ++j){
				printf("%d ", ans[i][j]);
			}
			printf("%d\n", ans[i][M]);
		}
	}
	else{
		for (int i = 1; i <= M; ++i){
			for (int j = 1; j < N; ++j){
				printf("%d ", ans[j][i]);

			}
			printf("%d\n", ans[N][i]);
		}


	}


}



void fill_frame(){
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j){
		if (ans[i][j] == 0){
			if ( ans[i][j - 1] != ans[i+1][j - 1]){
				fill(i, j, 0, 1);
			}
			else{
				fill(i, j, 1, -1);
			}

		}

	}

}

void tle(){
	double p = 1.4;
	for (int i = 0; i < 1e10; ++i)
		p = pow(p, p);
	p *= 10;

}
ofstream waout("C:\\wa.txt");
void frame_test(vector<int>& v,bool chan){
	/*vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);*/
//	N = 4;
	now_id = 1;
	int sum_l = 1;
	for (int k = 0; k < v.size(); ++k){
		int width = v[k];
		if (sum_l == 1 || ans[1][sum_l - 1] == ans[2][sum_l - 1]){
			con_frame(sum_l, sum_l + width - 1, 1, -1);
		}
		else{
			con_frame(sum_l, sum_l + width - 1, 0, 1);

		}
		sum_l += width;
	}
//	M = sum_l - 1;
	fill_frame();
	show_ans(chan);
	if (!test()){
		tle();
	//	cout << "WA:" << N << " " << M << endl;
	//	waout << "WA:" << N << " " << M << endl;
	
	}
	
}

void getInput(){
	ofstream out("C:\\input.txt");
	out << 10000 << endl;
	for (int i = 3; i <= 100;++i)
	for (int j = 3; j <= 100; ++j)
		out << i << " " << j << endl;

}

int main(){
	ifstream in("C:\\input.txt");
//	getInput();
//	return 0;

//	ceshi();
//	frame_test();

	cin >> T;
	while (T-- > 0){
	
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		
		cin >> N >> M;
		if (N*M % 2 == 1){
			printf("Impossible!\n");
			continue;
		}

		if (N == 1 || N == 2 || M == 1 || M == 2){

			spj();
			continue;
		}

		bool chan = 0;
		if (N > M){
			chan = 1;
			swap(N, M);
		}
		vector<int> v;
		if (N % 2 == 1){
			v.push_back(N - 1);
			v.push_back(N + 1);
		}
		else{
			for (int i = N - 1; i <= N + 1; i++)
				v.push_back(i);
		}
		dp[0] = 1;
		for (int k = 0; k < v.size();++k)
		for (int i = v[k]; i <= M; ++i){
			if (!dp[i] &&dp[i - v[k]]){
				dp[i] = 1;
				pace[i] = v[k];
			}
		}

		if (!dp[M]){
			printf("Impossible!\n");
			continue;
		}

		vector<int> block;
		int pos = M;
		while (pos > 0){
			block.push_back(pace[pos]);
			pos -= pace[pos];
		}
		sort(block.begin(), block.end());
		frame_test(block,chan);
	}
	return 0;
}