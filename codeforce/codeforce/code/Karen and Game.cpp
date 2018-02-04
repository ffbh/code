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
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;

int mmp[110][110], N, M, anstime;
struct Node{
	 int id, time;
	 string type;
	 Node(int _id,int _time,string s){
		 id = _id;
		 time = _time;
		 type = s;
	 }
	
};
vector<Node> ans;

void row(){
	for (int i = 1; i <= N; ++i){
		int p = 555;
		for (int j = 1; j <= M; ++j){
			p = min(mmp[i][j], p);
		}
		if (p){
			anstime += p;
			ans.push_back(Node(i, p, "row"));
		}
		for (int j = 1; j <= M; ++j){
			mmp[i][j] -= p;
		}
	}
}

void column(){
	for (int i = 1; i <= M; ++i){
		int p = 555;
		for (int j = 1; j <= N; ++j)
			p = min(mmp[j][i], p);
		if (p){
			anstime += p;
			ans.push_back(Node(i, p, "col"));
		}
		for (int j = 1; j <= N; ++j)
			mmp[j][i] -= p;
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> N >> M;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j)
		in >> mmp[i][j];

	ans.clear();
	anstime = 0;
	if (N < M){
		row();
		column();
	}
	else{
		column();
		row();
	}


	
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= M; ++j){
		if (mmp[i][j]){
			cout << -1 << endl;
			return 0;
		}
	}

	
	cout << anstime << endl;
	for (Node& p : ans){
		for (int i = 0; i < p.time; ++i)
			cout << p.type << " " << p.id << endl;
	}





	return 0;
}





