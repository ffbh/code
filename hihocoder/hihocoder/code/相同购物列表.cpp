#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;
struct Node{
	string id;
	double price;
	bool operator==(const Node& p)const{
		return id == p.id&&price == p.price;
	}
	bool operator<(const Node& p)const{
		if (id != p.id)
			return id < p.id;
		return price < p.price;
	}
}input;

map<Node, int> mni;
multiset<string> mss;
bool mark[60];
string ans[60];
int size;
int main(){
//	ifstream in("C:\\input.txt");
	int N, M;
	cin >> N;

	mni.clear();
	memset(mark, 0, sizeof(mark));
	size = 1;
	mss.clear();

	cin >> M;
	for(int i=1;i<=M;++i){
		string tmp;
		cin >> input.id >> tmp >> input.price;
		if (mni[input] == 0){
			mni[input] = size;
			mark[size] = 1;
			ans[size] = input.id;
			size++;
		}
	}
	while (--N){
		cin >> M;
		bool tmark[60] = { 0 };
		while (M--){
			string tmp;
			cin >> input.id >> tmp >> input.price;
			for (int i = 0; i < input.id.length(); ++i){
				if (input.id[i]>'9' || input.id[i] < '0'){
					int a = 0;
					while (1){
						a++;
					}
				}
			}
			if (mni.count(input))
				tmark[mni[input]] = 1;
			
		}
		for (int i = 1; i < size; ++i)
				mark[i] = min(mark[i], tmark[i]);
	}
	for (int i = 1; i < size;++i)
	if (mark[i])
		mss.insert(ans[i]);
	multiset<string>::iterator it = mss.begin();
	while (it != mss.end()){
		cout << *it << endl;
		it++;
	}















	return 0;
}