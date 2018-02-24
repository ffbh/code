#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	Node(int a, int b) :id(a), price(b){}
	Node(){}
	int id;
	int price;
	bool operator<(const Node& p)const{
		return price > p.price;
	}
};


int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	Node temp;
	priority_queue<Node> pn[51];
	while (T--){
		for (int i = 0; i < 51;++i)
		while (!pn[i].empty())
			pn[i].pop();
		int N;
		cin >> N;
		while (N--){
			int a, b, c;
			//in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			pn[b].push(Node(a, c));
		}
		cin >> N;
		int mmin;
		int u;
		while (N--){
			int m;
			//in >> m;
			scanf("%d", &m);
			mmin = INT_MAX;
			u = 0;
			for (int i = m; i < 51;++i)
			if (!pn[i].empty()&&pn[i].top().price < mmin){
				mmin = pn[i].top().price;
				u = i;
			}
			if (u == 0)
				cout << "sorry" << endl;
			else{
				temp = pn[u].top();
				pn[u].pop();
				cout << temp.id << endl;
				if (u - m>0)
					pn[u - m].push(temp);
			}
		}
	}
	return 0;
}