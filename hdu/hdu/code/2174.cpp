#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
string s;
struct Node{
	bool map[26];
	int num;
	int step;
	bool operator<(const Node& p)const{
		if (step != p.step)
			return step>p.step;
		return num < p.num;
	}
};
bool vis[1 << 26];
bool set(Node& p){
	int num = 0;
	int size = 0;
	for (int i = 0; i < 13; ++i){
		num = num * 2 + p.map[i];
		if (p.map[i])
			size++;
	}
	for (int i = 13; i < 26; ++i){
		num = num * 2 + p.map[i];
	}
	p.num = size;
	if (vis[num])
		return 0;
	vis[num] = 1;
	return 1;
}
void change(Node& p,int i,int j){
	i += 2;
	bool t;

	i %= 13;
	t = p.map[i];
	p.map[i] = p.map[j];
	p.map[j] = t;

	i = (i + 12) % 13;
	j = (j + 1) % 13 + 13;
	t = p.map[i];
	p.map[i] = p.map[j];
	p.map[j] = t;

	i = (i + 12) % 13;
	j = (j + 1) % 13 + 13;
	t = p.map[i];
	p.map[i] = p.map[j];
	p.map[j] = t;
}

int Astar(){
	memset(vis, 0, sizeof(vis));
	Node temp1, temp2;
	temp1.num = 0;
	temp1.step = 0;
	priority_queue<Node> qn;
	for (int i = 0; i < 13; ++i)
	if (s[i] == 'g'){
		temp1.num++;
		temp1.map[i] = 1;
	}
	else
		temp1.map[i] = 0;
	for (int i = 13; i < 26; ++i)
	if (s[i] == 'g')
		temp1.map[i] = 1;
	else
		temp1.map[i] = 0;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.top();
		qn.pop();
		if (temp1.num == 13)
			return temp1.step;
		temp1.step++;
		for (int i = 0; i < 13; ++i){
			if (temp1.map[i] && temp1.map[(i + 1) % 13] && temp1.map[(i + 2) % 13])
				continue;
			for (int j = 13; j < 26; ++j){
				if (!temp1.map[j] && !temp1.map[(j + 1) % 13+13] && !temp1.map[(j + 2) % 13+13])
					continue;
				temp2 = temp1;
				change(temp2, i, j);
				if (set(temp2))
					qn.push(temp2);
			}
		}
	}
	return -1;
}


int main(){
	ifstream in("C:\\temp.txt");
	while (in >> s){
		cout << Astar() << endl;
	}
	return 0;
}