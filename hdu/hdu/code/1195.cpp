#include <iostream>
#include <string>
#include <queue>
using namespace std;
string s1, s2;
bool vis[10010];
struct node{
	string s;
	int step;
};
void Change(string& s,int index,int v){
	if (v == 1){
		s[index]++;
		if (s[index] > '9') s[index] = '1';
	}
	else {
		s[index]--;
		if (s[index] < '1') s[index] = '9';
	}
}

void Swap(string& s, int i1, int i2){
	char c = s[i1];
	s[i1] = s[i2];
	s[i2] = c;
}
int getNum(const string& s){
	return atoi(s.c_str());
}


int bfs(){
	queue<node> qn;
	node nn;
	nn.s = s1;
	nn.step = 0;
	qn.push(nn);
	vis[getNum(s1)] = 1;
	node temp1, temp2;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.step++;
			Change(temp2.s, i, 1);
			if (temp2.s == s2) return temp2.step;
			if (!vis[getNum(temp2.s)]){
				vis[getNum(temp2.s)] = 1;
				qn.push(temp2);
			}
		}
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.step++;
			Change(temp2.s, i, -1);
			if (temp2.s == s2) return temp2.step;
			if (!vis[getNum(temp2.s)]){
				vis[getNum(temp2.s)] = 1;
				qn.push(temp2);
			}
		}
		for (int i = 0; i < 3; ++i){
			temp2 = temp1;
			temp2.step++;
			Swap(temp2.s, i, i + 1);
			if (temp2.s == s2) return temp2.step;
			if (!vis[getNum(temp2.s)]){
				vis[getNum(temp2.s)] = 1;
				qn.push(temp2);
			}
		}
	}



}
int main(){
	int N;
	cin >> N;
	while (N--){
		cin >> s1 >> s2;
		memset(vis, 0, sizeof(vis));
		cout << bfs() << endl;
	}


	return 0;
}