#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
#define MAXSIZE 26
struct Node{
	int count;
	int fail;
	int next[MAXSIZE];
};
Node data[600010];
//char s[1000010];
string s;
int size;
int root;
int MALLOC(){
	data[size].count = 0;
	data[size].fail = 0;
	for (int i = 0; i < MAXSIZE; ++i)
		data[size].next[i] = -1;
	return size++;
}

void insert(){
	int len = s.length();
	int p = root;
	for (int i = 0; i < len; ++i){
		if (data[p].next[s[i] - 'a'] == -1)
			data[p].next[s[i] - 'a'] = MALLOC();
		p = data[p].next[s[i] - 'a'];
	}
	data[p].count++;
}

void setfail(){
	queue<int> qi;
	qi.push(root);
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		for (int i = 0; i < 26; ++i){
			if (data[temp].next[i]!=-1){
				data[data[temp].next[i]].fail = (temp == root) ? root : data[data[temp].fail].next[i];
				qi.push(data[temp].next[i]);
			}
			else
				data[temp].next[i] = (temp == root) ? root : data[data[temp].fail].next[i];
		}
	}
}

int query(){
	int len = s.length();
	int cnt = 0;
	int p = root;
	for (int i = 0; i < len; ++i){
		p = data[p].next[s[i] - 'a'];
		int temp = p;
		while (data[temp].count){
			cnt += data[temp].count;
			data[temp].count = 0;
			temp = data[temp].fail;
		}
	}
	return cnt;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		size = 0;
		root = MALLOC();
		int M;
		cin >> M;
		while (M--){
			cin >> s;
			//scanf("%s", s);
			insert();
		}
		setfail();
		cin >> s;
		//scanf("%s", s);
		cout << query() << endl;
	}
	return 0;
}