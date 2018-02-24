#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	int id;
	int h;
	bool operator<(const Node& p)const{
		if (h != p.h)
			return h < p.h;
		return id>p.id;
	}
};


int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	int ID;
	priority_queue<Node> pn[4];
	while (cin >> N){
		for (int i = 1; i <= 3;++i)
		while (!pn[i].empty())
			pn[i].pop();
		ID = 1;
		string cmd;
		while (N--){
			Node temp;
			int a, b;
			cin >> cmd;
			if (cmd == "IN"){
				cin >> a >> b;
				temp.id = ID++;
				temp.h = b;
				pn[a].push(temp);
			}
			else{
				cin >> a;
				if (pn[a].empty())
					cout << "EMPTY" << endl;
				else{
					cout << pn[a].top().id << endl;
					pn[a].pop();
				}

			}
		}
	}
	return 0;
}