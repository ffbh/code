#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;
vector<char> vi[266];
bool mark[266];
char Minor, These;
int K;
stringstream ss;
void Init(){
	for (int i = 0; i < 266; ++i){
		vi[i].clear();
		mark[i] = 0;
	}
}

void build(string& t){
	char a = t[0];
	for (int i = 2; i < t.length(); ++i){
		if (isupper(t[i]))
		vi[a].push_back(t[i]);
	}
}



int main(){
	//ifstream in("C:\\input.txt");
	ofstream ou("C:\\input2.txt");
	istream& in = cin;
	string s;
	while (in >> s&&s!="#"){
		Init();
		in >> Minor >> These >> K;

		for (int i = 0; i < s.length();++i)
		if (s[i] == ';')
			s[i] = ' ';

		ss.clear();
		ss.str(s);
		string tmp;
		while (ss >> tmp){
			build(tmp);
		}
		for (int i = 0; i < 266; ++i){
	//		sort(vi[i].begin(), vi[i].end());
		}


		char now = Minor, pre = These;
		int now_k = 1;
		while (1){
			bool trap = 1;
			for (int i = 0; i < vi[now].size(); ++i){
				char next = vi[now][i];
				if (next != pre && !mark[next]){
					trap = 0;
					if (now_k%K == 0){
						cout << now << " ";
						ou << now << " ";
						mark[now] = 1;
					}
					pre = now;
					now = next;
					now_k++;
					break;
				}
			}
			if (trap){
				cout << "/" << now << endl;
				ou << "/" << now << endl;
				break;
			}

			
		}
	}


	return 0;
}