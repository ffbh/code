#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>
#include <queue>
using namespace std;
struct Node{
	int to, d;
	Node(int a,int b){
		to = a;
		d = b;
	}
};
vector<Node> vi[800];
vector<int> V[800];
bool vis[800];
int dist[800], pace[800];
int getID(char d, char s){
	return (d - 'A') * 26 + s - 'a';
}

char getDesign(int p){
	return 'A' + (p / 26);
}

char getStation(int p){
	return 'a' + (p % 26);
}
int N;
string s;
stringstream ss;

int spfa(int st,int en){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 800; ++i)
		dist[i] = (1 << 29);
	dist[st] = 0;
	queue<int> qi;
	vis[st] = 1;
	pace[st] = -1;
	qi.push(st);
	while (!qi.empty()){
		int u = qi.front(),v;
		qi.pop();
		vis[u] = 0;
		for (int i = 0; i < vi[u].size(); ++i){
			v = vi[u][i].to;
			int d = vi[u][i].d;
			if (dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pace[v] = u;
				if (!vis[v]){
					vis[v] = 1;
					qi.push(v);
				}

			}
		}
	}
	return dist[en];

}
//ofstream ou("C:\\input2.txt");

char dfs(int p){
	char de = getDesign(p); 
	char sa = getStation(p);
	if (pace[p] == -1){
		cout << de << sa;
		//ou << de << sa;
	}
	else{
		char c = dfs(pace[p]);
		if (de == c){
			cout << sa;
		//	ou << sa;
		}
		else{
			cout << "=" << de << sa;
		//	ou << "=" << de << sa;
		}
	}
	return de;
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;
	getline(in, s);
	char design;
	for (int i = 0; i < N; ++i){
		getline(in, s);
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == ':')
				s[i] = ' ';
		}
		ss.clear();
		ss.str(s);
		ss >> design >> s;
		

		int pos = 0;
		int pre = -1;
		while (pos < s.length()){
			if (islower(s[pos])){
				int id = getID(design, s[pos]);
				if (pre != -1){
					vi[pre].push_back(Node(id,1));
					vi[id].push_back(Node(pre,1));
				}
				pre = id;
			}
			else if(s[pos]=='='){
				pos++;
				int id = getID(s[pos], s[pos+1]);
				pos++;
				V[id].push_back(pre);
				V[pre].push_back(id);
			//	vi[pre].push_back(Node(id, 3));
			//	vi[id].push_back(Node(pre, 3));
			}
			else{
				int p = 1.7;
				for (int i = 0; i < 1e10; ++i){
					p = pow(p, p);
				}
				cout << p*p << endl;
			}
			pos++;
		}

		for (int i = 0; i < 800; ++i){
			for (int j = 0; j < V[i].size(); ++j){
				int p = V[i][j];
				vi[i].push_back(Node(p, 3));
				vi[p].push_back(Node(i, 3));
				for (int k = 0; k < V[i].size(); ++k){
					int a = V[i][j];
					int b = V[i][k];
					if (a != b){
						vi[a].push_back(Node(b, 3));
						vi[b].push_back(Node(a, 3));
					}
				}
			}

		}



	}
	
	
	while (getline(in, s) && s != "#"){
		

		int st = getID(s[0], s[1]);
		int en = getID(s[2], s[3]);
		int ret = spfa(st, en);
		printf("%3d: ", ret);
		//	ou << setw(3) << ret << ": ";
		dfs(en);
		cout << endl;
		//	ou << endl;
	}















	return 0;
}