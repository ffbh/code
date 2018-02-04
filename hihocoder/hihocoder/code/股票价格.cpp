#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int size;
bool mark[500010];
struct Node{
	int timestamp, price, id;
	bool operator<(const Node& p)const{
		if (price != p.price)
			return price < p.price;
		else{
			return timestamp < p.timestamp;
		}
	}
	Node(int a, int b, int c){
		timestamp = a;
		price = b;
		id = c;
	}
};

queue<Node> qi;
set<Node> si;

void del(int time){
	while (!qi.empty() && qi.front().timestamp <= time){
		mark[qi.front().id] = 1;
		qi.pop();
	}
}


void adjust(){
	while (!si.empty() && mark[si.begin()->id]){
		si.erase(si.begin());
	}

	while (!si.empty() && mark[si.rbegin()->id]){
		si.erase(--si.end());
	}
}

void getInput(int n){
	ofstream ou("C:\\input.txt");
	ou << n << endl;
	srand(time(0));
	int ts = 1;
	for (int i = 0; i < n-2; ++i){
		int p = abs(rand()) % 5;
		ou << "P" << " " << ts + p << " " << abs(rand()) % 100000000 << endl;
		ts += p;
	}
	ou << "R" << " " << abs(rand())%ts << endl;
	ou << "Q" << endl;
}

int max_stamp;

int main(){

	//getInput(500000);
//	return 0;

	ifstream in("C:\\input.txt");
	//istream& in = cin;

	int K;
	in >> K;
	char c;
	int timestamp, price, id, recentprice;
	size = 0;
	max_stamp = -(1 << 29);
	while (K-- > 0){
		in >> c;
		if (c == 'P'){
			in >> timestamp >> price;
			recentprice = price;
			id = size++;
			qi.push(Node(timestamp, price, id));
			si.insert(Node(timestamp, price, id));
			if (timestamp == 7){
				int t = 0;
			}
		}
		else if (c == 'R'){
			in >> timestamp;
			//max_stamp = max(max_stamp, timestamp);
			del(timestamp);
			adjust();
		}
		else{

			printf("%d %d %d\n", si.rbegin()->price, si.begin()->price, recentprice);

		}


	}




	return 0;
}