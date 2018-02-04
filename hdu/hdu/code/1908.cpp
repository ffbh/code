#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
struct Node{
	int id, p;
	bool operator<(const Node& pp)const{
		return p < pp.p;
	}
};


int main(){
	ifstream in("C:\\temp.txt");
	string s;
	Node temp;
	set<Node> sq;
	while (cin >> s&&s[0] !='0'){
		if(s[0]=='1'){
		//	cin >> temp.id >> temp.p;
			scanf("%d%d", &temp.id, &temp.p);
			sq.insert(temp);
		}
		else if (s[0] == '2'){
			if (sq.empty())
				cout << 0 << endl;
			else{
				cout << (--sq.end())->id << endl;
				sq.erase(--sq.end());
			}
		}
		else{
			if (sq.empty())
				cout << 0 << endl;
			else{
				cout << (sq.begin())->id << endl;
				sq.erase(sq.begin());
			}

		}
	}
	return 0;
}

