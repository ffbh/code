#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
string s;
#define MAXSIZE 10
struct Node{
	int fail;
	int id;
	int next[MAXSIZE];
};
Node data[600010];
int root;
int cnt;
string s2;
int k;
bool ok;
int MALLOC(){
	for (int i = 0; i < MAXSIZE; ++i)
		data[cnt].next[i] = -1;
	data[cnt].fail = data[cnt].id = 0;
	return cnt++;
}

void insert(int n){
	int p = root;
	int len = s2.length();
	for (int i = k; i < len; ++i){
		if (data[p].next[s2[i] - '0'] == -1)
			data[p].next[s2[i] - '0'] = MALLOC();
		p = data[p].next[s2[i] - '0'];
	}
	data[p].id = n;
}

void setfail(){
	queue<int> qi;
	qi.push(root);
	while (!qi.empty()){
		int p = qi.front();
		qi.pop();
		for (int i = 0; i < MAXSIZE; ++i){
			if (data[p].next[i] == -1)
				data[p].next[i] = (p == root) ? root : data[data[p].fail].next[i];
			else{
				data[data[p].next[i]].fail = (p == root) ? root : data[data[p].fail].next[i];
				qi.push(data[p].next[i]);
			}
		}
	}
}


void Query(){
	int len = s.length();
	int p = root;
	for (int i = 0; i < len; ++i){
		p = data[p].next[s[i] - '0'];
		int temp = p;
		while (temp != root){
			if (data[temp].id){
				if (ok)
					printf(" [Key No. %d]", data[temp].id);
				else{
					ok = 1;
					printf("Found key:");
					printf(" [Key No. %d]", data[temp].id);
				}
				data[temp].id = 0;
			}
			temp = data[temp].fail;
		}
	}
}


int main(){
	//	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		ok = 0;
		cnt = 0;
		root = MALLOC();////
		s = "";
		cin.get();
		while (N--){
			string temp;
			getline(cin, temp);
			s += temp;
		}
		cin.get();
		for (int i = 1; i <= M; ++i){
			getline(cin, s2);
			k = 0;
			while (s2[k] != ']')k++;
			k++;
			insert(i);
		}
		setfail();
		Query();
		if (!ok)
			cout << "No key can be found !" << endl;
		else
			cout << endl;
	}
	return 0;
}