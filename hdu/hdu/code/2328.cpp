#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
string data[4010];
int Next[4010];

vector<string> temp;
bool cmp(string& s1, string& s2){
	if (s1.length() != s2.length())
		return s1.length()< s2.length();
	return s1 < s2;
}

void GetNext(string& s){
	int i, j;
	i = 0;
	j = -1;
	Next[0] = -1;
	while (i < s.length()){
		if (j == -1 || s[i] == s[j])
			Next[++i] = ++j;
		else
			j = Next[j];
	}
}

bool kmp(int u,string& s){
	int i, j;
	i = j = 0;
	while (i < data[u].length()){
		if (j == -1 || data[u][i] == s[j]){
			++i;
			++j;
		}
		else
			j = Next[j];
		if (j == s.length())
			return 1;
	}
	return 0;
}



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		sort(data, data + N, cmp);
		string ans = "";
		int MAXLEN;
		for (MAXLEN = data[0].length(); MAXLEN > 0; --MAXLEN){
			temp.clear();
			for (int i = 0; i <= data[0].length() - MAXLEN; ++i)
				temp.push_back(data[0].substr(i, MAXLEN));
			sort(temp.begin(), temp.end(), cmp);
			bool flag = 0;
			for (int k = 0; k < temp.size(); ++k){
				GetNext(temp[k]);
				bool FLAG = 1;
				for (int j = 1; j < N; ++j){
					if (!kmp(j, temp[k])){
						FLAG = 0;
						break;
					}
				}
				if (FLAG){
					ans = temp[k];
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (ans.length())
			cout << ans << endl;
		else
			cout << "IDENTITY LOST" << endl;
	}
	return 0;
}