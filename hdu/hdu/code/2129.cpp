#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
struct Contest{
	int g, s, c;
	string name;
	bool operator<(const Contest& p)const{
		if (name != p.name)
			return name < p.name;
		else if (g != p.g)
			return g < p.g;
		else if (s != p.s)
			return s < p.s;
		else
			return c < p.c;
	}
};

struct Team{
	string name;
	int g, s, c;
	int rank;
	bool operator<(const Team& p)const{
		if (g != p.g)
			return g>p.g;
		else if (s != p.s)
			return s > p.s;
		else if (c != p.c)
			return c > p.c;

		return name < p.name;

	}
	bool operator==(const Team& p)const{
		return g == p.g&&s == p.s&&c == p.c;
	}
};

struct School{
	int g, s, c;
	vector<Team> V;
	string name;
	int rank;
	bool operator<(const School& p)const{
		if (g != p.g)
			return g>p.g;
		else if (s != p.s)
			return s > p.s;
		else if (c != p.c)
			return c > p.c;
		return name < p.name;
	}
	bool operator==(const School& p)const{
		return g == p.g&&s == p.s&&c == p.c;
	}
};

Contest C[20001];
School S[201];

int main(){
	//ifstream in("C:\\temp.txt");
	istream& in = cin;
	map<string, int> msiC;
	map<string, int> msiS;
	Team temp;
	int CASE;
	in >> CASE;
	int Case = 1;
	int c, s;
	while (CASE--){
		int N;
		in >> N;
		memset(C, 0, sizeof(C));
		memset(S, 0, sizeof(S));
		c = s = 1;//排序起始下标为1
		msiC.clear();
		msiS.clear();
		while (N--){
			string s1, s2, s3, s4;
			in >> s1 >> s2 >> s3 >> s4;
			if (!msiS[s1]){
				S[s].name = s1;
				msiS[s1] = s++;
			}
			if (!msiC[s4]){
				C[c].name = s4;
				msiC[s4] = c++;
			}
			int Ss = msiS[s1];
			int Cc = msiC[s4];
			temp.name = s2;
			temp.c = temp.g = temp.s = 0;
			if (s3[0] == 'g'){
				temp.g++;
				C[Cc].g++;
				S[Ss].g++;
			}
			else if (s3[0] == 's'){
				temp.s++;
				C[Cc].s++;
				S[Ss].s++;
			}
			else if (s3[0] == 'c'){
				temp.c++;
				C[Cc].c++;
				S[Ss].c++;
			}
			S[Ss].V.push_back(temp);
		}
		sort(S + 1, S + s);
		S[1].rank = 1;
		for (int i = 2; i < s; ++i)
		if (S[i] == S[i - 1])
			S[i].rank = S[i - 1].rank;
		else
			S[i].rank = i;
		
		for (int i = 1; i < s; ++i){
			sort(S[i].V.begin(), S[i].V.end());
			S[i].V[0].rank = 1;
			for (int j = 1; j < S[i].V.size(); ++j)
			if (S[i].V[j] == S[i].V[j-1])
				S[i].V[j].rank = S[i].V[j - 1].rank;
			else
				S[i].V[j].rank = j + 1;
		}
		sort(C + 1, C + c);
		printf("Case %d:\n", Case++);
		printf("****************\n");
		printf("school number: %d\n", s - 1);
		for (int i = 1; i < s; ++i){
			printf("%s %d %d %d %d\n", S[i].name.c_str(), S[i].rank, S[i].g, S[i].s, S[i].c);
			printf("     team number: %d\n", S[i].V.size());
			for (int j = 0; j < S[i].V.size(); ++j)
				printf("     %s %d %d %d %d\n", S[i].V[j].name.c_str(), S[i].V[j].rank, S[i].V[j].g, S[i].V[j].s, S[i].V[j].c);
		}
		printf("****************\n\n");
		printf("contest number: %d\n", c - 1);
		for (int i = 1; i < c; ++i)
			printf("%s %d %d %d\n", C[i].name.c_str(), C[i].g, C[i].s, C[i].c);
		printf("****************\n");
	}
	return 0;
}