#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
struct Node{
	int l, r;
	string ID;
	bool in;
	Node(){}
	Node(int _l, int _r, string _ID){
		l = _l;
		r = _r;
		ID = _ID;
		in = 1;
	}

	void show(){
		cout << l << " " << r << " " << ID <<" "<<in<< endl;
	}
};
struct Date{
	Node data[110];
	int len;

	void push_back(int _l, int _r, string& _ID){
		data[len].l = _l;
		data[len].r = _r;
		data[len].ID = _ID;
		data[len].in = 1;
		len++;
	}

	void push(Node& node){
		data[len++] = node;
	}

	void clear(){
		len = 0;
	}

	void display(){
		for (int i = 0; i < len; ++i)
			data[i].show();
		cout << endl;
	}
}queue[2];
int flag;
int S;
string id;
int w;

void push(){
	int nextflag = (flag + 1) % 2;
	queue[flag].clear();
	queue[flag].push_back(1, w, id);
	int s = w + 1;
	for (int i = 0; i < queue[nextflag].len; ++i){
		Node& tmp = queue[nextflag].data[i];
		if (!tmp.in)
			continue;
		int tw = tmp.r - tmp.l;
		tmp.l = s;
		tmp.r = s + tw;
		if (tmp.r > S)
			break;
		s = tmp.r + 1;
		queue[flag].push(tmp);
	}
	flag = nextflag;
}

void pop(){
	int nextflag = (flag + 1) % 2;
	for (int i = 0; i<queue[nextflag].len;++i)
	if (queue[nextflag].data[i].ID == id){
		queue[nextflag].data[i].in = 0;
		break;
	}
}
int main(){
	//ifstream in("C:\\input.txt");
	int CASE = 1;
	while (cin >> S&&S > 0){
	//	msi.clear();
		char c;
		flag = 0;
		queue[0].clear();
		queue[1].clear();
		while (cin >> c&&c != 'E'){
			if (c == 'A'){
				cin >> id >> w;
				push();
			}
			else{
				cin >> id;
				pop();
			}
	//		queue[flag].display();
		}
		printf("PROBLEM %d:", CASE++);
		int nextflag = (flag + 1) % 2;
		for (int i = 0; i<queue[nextflag].len; ++i)
		if (queue[nextflag].data[i].in){
			printf(" %s", queue[nextflag].data[i].ID.c_str());
		}
		cout << endl;

	}

	return 0;
}