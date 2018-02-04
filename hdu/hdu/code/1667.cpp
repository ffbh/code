#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <map>
using namespace std;
map<int, bool> mbi;
struct Node{
	int step;
	char map[7][7];
	string s;
	void fun();
};
void Node::fun(){
	char temp[7][7];
	memcpy(temp, map, sizeof(temp));
	for (int i = 0; i < 7;++i)
	for (int j = 0; j < 7; ++j)
		map[i][j] = temp[j][6-i];
}

Node start;
string pace = "ABCDEFGH";


int getHash(Node& p){
	int res = p.map[0][2];
	res = res * 3 + p.map[0][4];
	res = res * 3 + p.map[1][2];
	res = res * 3 + p.map[1][4];
	for (int i = 0; i < 7; ++i)
		res = res * 3 + p.map[2][i];
	res = res * 3 + p.map[3][2];
	res = res * 3 + p.map[3][4];
	for (int i = 0; i < 7; ++i)
		res = res * 3 + p.map[4][i];
	res = res * 3 + p.map[5][2];
	res = res * 3 + p.map[5][4];
	res = res * 3 + p.map[6][2];
	res = res * 3 + p.map[6][4];
	return res;
}

void Move(Node& p,int i){
	if (i == 0){
		int t = p.map[0][2];
		for (int i = 0; i < 6; ++ i)
			p.map[i][2] = p.map[i + 1][2];
		p.map[6][2] = t;
	}
	else if (i == 1){
		int t = p.map[0][4];
		for (int i = 0; i < 6; ++i)
			p.map[i][4] = p.map[i + 1][4];
		p.map[6][4] = t;
	}
	else if (i == 2){
		int t = p.map[2][6];
		for (int i = 6; i > 0; --i)
			p.map[2][i] = p.map[2][i - 1];
		p.map[2][0] = t;
	}
	else if (i == 3){
		int t = p.map[4][6];
		for (int i = 6; i > 0; --i)
			p.map[4][i] = p.map[4][i - 1];
		p.map[4][0] = t;
	}
	else if (i == 4){
		int t = p.map[6][4];
		for (int i = 6; i >0; --i)
			p.map[i][4] = p.map[i - 1][4];
		p.map[0][4] = t;
	}
	else if (i == 5){
		int t = p.map[6][2];
		for (int i = 6; i >0; --i)
			p.map[i][2] = p.map[i - 1][2];
		p.map[0][2] = t;
	}
	else if (i == 6){
		int t = p.map[4][0];
		for (int i = 0; i <6; ++i)
			p.map[4][i] = p.map[4][i + 1];
		p.map[4][6] = t;
	}
	else{
		int t = p.map[2][0];
		for (int i = 0; i <6; ++i)
			p.map[2][i] = p.map[2][i + 1];
		p.map[2][6] = t;
	}
}



bool OK(Node& p){
	int num = 0;
	int m = p.map[2][2];
	for (int i = 2; i < 5; ++i){
		if (m == p.map[2][i] && m == p.map[4][i])
			num += 2;
	}
	if (num != 6)return 0;
	return m == p.map[3][2] && m == p.map[3][4];
}





pair<string,int> bfs(){
	mbi.clear();
	queue<Node> qn;
	start.s = "";
	start.step = 0;
	Node temp1, temp2;
	int HH;
	for (int k = 0; k < 4; ++k){
		HH = getHash(start);
		start.fun();
		mbi[HH] = 1;
	}
	qn.push(start);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		temp1.step++;
		for (int i = 0; i < 8; ++i){
			temp2 = temp1;
			Move(temp2, i);
			temp2.s += pace[i];
			bool flag = 1;
			for (int k = 0; k < 4; ++k){
				HH = getHash(temp2);
				temp2.fun();
				if (!mbi[HH]){
					flag = 0;
					break;
				}
				mbi[HH] = 1;
			}
			if (flag){
				if (OK(temp2))
					return make_pair(temp2.s, temp2.map[2][2]+1);
				qn.push(temp2);
			}
		}
	}
	return make_pair("", -1);
}


int main(){
	ifstream in("C:\\temp.txt");
	pair<string, int> psi;
	while (in >> start.map[0][2] && start.map[0][2]!='0'){
		in >> start.map[0][4];
		in >> start.map[1][2];
		in >> start.map[1][4];
		for (int i = 0; i < 7; ++i)
			in >> start.map[2][i];
		in >> start.map[3][2];
		in >> start.map[3][4];
		for (int i = 0; i < 7; ++i)
			in >> start.map[4][i];
		in >> start.map[5][2];
		in >> start.map[5][4];
		in >> start.map[6][2];
		in >> start.map[6][4];
		for (int i = 0; i < 7;++i)
		for (int j = 0; j < 7; ++j)
			start.map[i][j]-='1';

		
		psi = bfs();
		if (psi.second == -1)
			cout << "No moves needed" << endl;
		else{
			cout << psi.first << endl;
			cout << psi.second << endl;
		}


	}
	return 0;
}