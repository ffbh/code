#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
#define MMAX (1000000000)
struct DP{
	long long V, N, CAP, sum;
}dp[2][1010][2][6][6][4];

struct Node{
	string s;
	int v, c;
}data[510];
int L;

void Init(){
	memset(dp, 0, sizeof(dp));
}

void upd(DP& p1, DP& p2){

	if (p1.sum > p2.sum){
		p2 = p1;
	}
	else if (p1.sum == p2.sum){
		p2.N += p1.N;
		if (p2.N > MMAX)
			p2.N = MMAX;
	}
}
string str[] = { "Defender", "Midfielder", "Forward", "Goalkeeper" };

void getInput(){
	ofstream out("C:\\input.txt");
	out << 1 << endl;
	out << 500 << endl;
	srand(time(0));
	for (int i = 0; i < 500; ++i){
		out << str[abs(rand()) % 4] << " " << 5 << " " << abs(rand()) % 100 << endl;

	}
	out << 1000 << endl;


}

int main(){
	//	getInput();

	ifstream in("C:\\input.txt");
	int T, M;
	cin >> T;
	while (T-- > 0){
		Init();
		cin >> M;
		//scanf("%d", &M);
		dp[1][0][0][0][0][0].N = 1;
		for (int i = 0; i < M; ++i){
			cin >> data[i].s >> data[i].v >> data[i].c;
			//	cin >> data[i].s;
			//	scanf("%d%d", &data[i].v, &data[i].c);
		}
		cin >> L;
		//	scanf("%d", &L);
		for (int k = 0; k < M; ++k){
			int f = k % 2;
			int pf = 1 - f;
			for (int i = 0; i <= L; ++i)
			for (int k1 = 0; k1 <= 1; ++k1)
			for (int k2 = 0; k2 <= 5; ++k2)
			for (int k3 = 0; k3 <= 5; ++k3)
			for (int k4 = 0; k4 <= 3; ++k4)
				dp[f][i][k1][k2][k3][k4] = dp[pf][i][k1][k2][k3][k4];
			char s = data[k].s[0];
			long long v = data[k].v, c = data[k].c;

			if (s == 'G'){
				for (int i = L; i >= c; --i){
					for (int k1 = 1; k1 <= 1; ++k1)
					for (int k2 = 0; k2 <= 5; ++k2)
					for (int k3 = 0; k3 <= 5; ++k3)
					for (int k4 = 0; k4 <= 3; ++k4){
						if (k1 + k2 + k3 + k4 > 11)
							break;
						if (dp[pf][i - c][k1 - 1][k2][k3][k4].N == 0)
							continue;
						DP p1 = dp[pf][i - c][k1 - 1][k2][k3][k4];
						p1.V += v;
						p1.CAP = max(p1.CAP, v);
						p1.sum = p1.V + p1.CAP;
						DP& p2 = dp[f][i][k1][k2][k3][k4];
						if (p1.sum > p2.sum){
							p2 = p1;
						}
						else if (p1.sum == p2.sum){
							p2.N += p1.N;
							if (p2.N > MMAX)
								p2.N = MMAX;
						}
					}
				}
			}
			else if (s == 'D'){
				for (int i = L; i >= c; --i){
					for (int k1 = 0; k1 <= 1; ++k1)
					for (int k2 = 1; k2 <= 5; ++k2)
					for (int k3 = 0; k3 <= 5; ++k3)
					for (int k4 = 0; k4 <= 3; ++k4){
						if (dp[pf][i - c][k1][k2 - 1][k3][k4].N == 0)
							continue;
						DP p1 = dp[pf][i - c][k1][k2-1][k3][k4];
						p1.V += v;
						p1.CAP = max(p1.CAP, v);
						p1.sum = p1.V + p1.CAP;
						DP& p2 = dp[f][i][k1][k2][k3][k4];
						if (p1.sum > p2.sum){
							p2 = p1;
						}
						else if (p1.sum == p2.sum){
							p2.N += p1.N;
							if (p2.N > MMAX)
								p2.N = MMAX;
						}
					}
				}
			}
			else if (s == 'M'){
				for (int i = L; i >= c; --i){
					for (int k1 = 0; k1 <= 1; ++k1)
					for (int k2 = 0; k2 <= 5; ++k2)
					for (int k3 = 1; k3 <= 5; ++k3)
					for (int k4 = 0; k4 <= 3; ++k4){
						if (dp[pf][i - c][k1][k2][k3 - 1][k4].N == 0)
							continue;
						DP p1 = dp[pf][i - c][k1 ][k2][k3-1][k4];
						p1.V += v;
						p1.CAP = max(p1.CAP, v);
						p1.sum = p1.V + p1.CAP;
						DP& p2 = dp[f][i][k1][k2][k3][k4];
						if (p1.sum > p2.sum){
							p2 = p1;
						}
						else if (p1.sum == p2.sum){
							p2.N += p1.N;
							if (p2.N > MMAX)
								p2.N = MMAX;
						}
					}
				}
			}
			else{
				for (int i = L; i >= c; --i){
					for (int k1 = 0; k1 <= 1; ++k1)
					for (int k2 = 0; k2 <= 5; ++k2)
					for (int k3 = 0; k3 <= 5; ++k3)
					for (int k4 = 1; k4 <= 3; ++k4){
						if (dp[pf][i - c][k1][k2][k3][k4 - 1].N == 0)
							continue;
						DP p1 = dp[pf][i - c][k1 ][k2][k3][k4-1];
						p1.V += v;
						p1.CAP = max(p1.CAP, v);
						p1.sum = p1.V + p1.CAP;
						DP& p2 = dp[f][i][k1][k2][k3][k4];
						if (p1.sum > p2.sum){
							p2 = p1;
						}
						else if (p1.sum == p2.sum){
							p2.N += p1.N;
							if (p2.N > MMAX)
								p2.N = MMAX;
						}
					}
				}
			}
		}
		long long ansV = -1, ansC = 0, ansN = 0;
		int ak = M % 2;
		ak = 1 - ak;
		for (int i = 0; i <= L; ++i)
		for (int k1 = 1; k1 <= 1; ++k1)
		for (int k2 = 3; k2 <= 5; ++k2)
		for (int k3 = 2; k3 <= 5; ++k3)
		for (int k4 = 1; k4 <= 3; ++k4){
			if (k1 + k2 + k3 + k4 == 11 && dp[ak][i][k1][k2][k3][k4].N != 0){
				if (ansV < dp[ak][i][k1][k2][k3][k4].sum){
					ansV = dp[ak][i][k1][k2][k3][k4].sum;
					ansC = i;
					ansN = dp[ak][i][k1][k2][k3][k4].N;
				}
				else if (ansV == dp[ak][i][k1][k2][k3][k4].sum &&ansC == i){
					ansN += dp[ak][i][k1][k2][k3][k4].N;
					if (ansN > MMAX)
						ansN = MMAX;
				}
			}
		}
		if (ansN > MMAX)
			ansN = MMAX;
		cout << ansV << "¡¡" << ansC << "¡¡" << ansN << endl;
	}
	return 0;
}