#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
map<char, int> mci;
char data[30];
int num[30];
void init(){
	for (char c = 'a'; c <= 'z'; ++c)
		data[c - 'a'] = c;
	data[26] = '+';
	data[27] = '*';
	data[28] = '/';
	data[29] = '?';
	for (int i = 0; i < 30; ++i)
		mci[data[i]] = i;
}

vector<int> vi, ans;
int mintime;

void dfs(int k){
	if (vi.size() == 12){
		vi.push_back(99999);
		int time = 0;
		int index = 1, i = 0;
		while (index <= 11&&i<30){
			if (i == vi[index]){
				index++;
			}
			time += num[i] * (i - vi[index - 1]);
			i++;
		}
		vi.pop_back();
		if (time < mintime){
			mintime = time;
			ans = vi;
		}
		return;
	}
	for (int i = k; i < 30; ++k){
		vi.push_back(i);
		dfs(i + 1);
		vi.pop_back();
	}
}



int main(){
	ifstream in("C:\\input.txt");
	int T;
	in >> T;
	while (T--){
		string s;
		memset(num, 0, sizeof(num));
		int M;
		in >> M;
		vi.clear();
		vi.push_back(0);
		mintime = INT_MAX;
		while (M--){
			in >> s;
			for (int i = 0; i < s.length(); ++i)
				num[mci[s[i]]]++;
		}
		dfs(1);
		for (int i = 1; i < 12; ++i)
			cout << data[ans[i]];
		cout << endl;









	}









	return 0;
}