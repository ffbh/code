#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct Node{
	double A ,B, C;
	bool ISBAD;
};
Node data[50];
bool dp[8000010];

int main(){
	ifstream in("C:\\temp.txt");
	double MAX;
	int N;
	stringstream ss;
	while (cin >> MAX >> N&&N){
		memset(data, 0, sizeof(data));
		for (int i = 0; i < N; ++i){
			string s;
			int t;
			double d;
			char c;
			cin >> t;
			getline(cin, s);
			for (int k = 0; k < s.length();++k)
			if (s[k] == ':')
				s[k] = ' ';
			ss.clear();
			ss.str(s);
			while (ss >> c>>d)
			if (c == 'A')
				data[i].A += d;
			else if (c == 'B')
				data[i].B += d;
			else if (c == 'C')
				data[i].C += d;
			else
				data[i].ISBAD = 1;
		}
		for (int i = 0; i < N;++i)
		if (!data[i].ISBAD){
			if (data[i].A + data[i].B + data[i].C > 1000 || data[i].A > 600
				|| data[i].B > 600 || data[i].C > 600)
				data[i].ISBAD = 1;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int k = 0; k < N;++k)
		if (!data[k].ISBAD){
			int K = (data[k].A + data[k].B + data[k].C) * 100;
			for (int i = MAX*100; i >= K;--i)
			if (dp[i - K])
				dp[i] = 1;
		}
		for (int i = MAX*100; i >= 0;--i)
		if (dp[i]){
			printf("%.2f\n", double(i) / 100);
			break;
		}
	}
	return 0;
}