#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <map>
using namespace std;
map<int, string> mis;
struct node{
	char data[2][4];
	string pace;
};
bool vis[8];
int GetHash(const node& p){
	int res = 0;
	for (int i = 0; i < 2;++i)
	for (int j = 0; j < 4; ++j)
		res = res * 8 + p.data[i][j]-'0';
	return res;
}

void ChangeA(node& p){
	node Q = p;
	for (int i = 0; i < 4; ++i)
		p.data[0][i] = Q.data[1][i];
	for (int i = 0; i < 4; ++i)
		p.data[1][i] = Q.data[0][i];
}
void ChangeB(node& p){
	node Q = p;
	for (int i = 0; i < 2; ++i)
		p.data[i][0] = Q.data[i][3];
	for (int i = 0; i < 2; ++i)
		p.data[i][3] = Q.data[i][2];
	for (int i = 0; i < 2; ++i)
		p.data[i][2] = Q.data[i][1];
	for (int i = 0; i < 2; ++i)
		p.data[i][1] = Q.data[i][0];
}


void ChangeC(node& p){
	char c = p.data[0][1];
	p.data[0][1] = p.data[1][1];
	p.data[1][1] = p.data[1][2];
	p.data[1][2] = p.data[0][2];
	p.data[0][2] = c;
}


void bfs(node& S){
	queue<node> qn;
	node temp1, temp2;
	int HH;
	HH = GetHash(S);
	mis[HH] = "-";
	S.pace = "";
	qn.push(S);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 3; ++i){
			temp2 = temp1;
			if (i == 0){
				ChangeA(temp2);
				temp2.pace += "A";
			}
			else if (i == 1){
				ChangeB(temp2);
				temp2.pace += "B";
			}
			else{
				ChangeC(temp2);
				temp2.pace += "C";
			}
			HH = GetHash(temp2);
			if (mis[HH] == ""){
				mis[HH] = temp2.pace;
				qn.push(temp2);
			}
			else if (temp2.pace < mis[HH]&&temp2.pace.length()<=mis[HH].length()&&mis[HH]!="-"){
				mis[HH] = temp2.pace;
				qn.push(temp2);
			}
		}
	}
}


int main(){
	//ifstream in("C:\\temp.txt");
	string ss, es;
	ss = "01234567";
	node Start, End;
	for (int i = 0; i < 4; ++i)
		Start.data[0][i] = ss[i];
	for (int i = 0; i < 4; ++i)
		Start.data[1][i] = ss[7 - i];
	bfs(Start);
	while (cin >> ss >> es){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 8; ++i)
		for (int j=0;j<8;++j)
		if (ss[i] == es[j]&&!vis[j]){
			es[j] = '0' + i;
			vis[j] = 1;
			break;
		}

		for (int i = 0; i < 4; ++i)
			End.data[0][i] = es[i];
		for (int i = 0; i < 4; ++i)
			End.data[1][i] = es[7 - i];
		int ans = GetHash(End);
		if (mis[ans] == "-")
			cout << endl;
		else
			cout << mis[ans] << endl;
		
	
	}

	return 0;
}