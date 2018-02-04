#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
map<char, int> mci;
char data[20];
bool vis[5010];
int N, C, M;

struct Node{
	string ans;
	int mod;
};


bool cmp(char c1, char c2){
	return mci[c1] < mci[c2];
}



bool bfs(){
	memset(vis, 0, sizeof(vis));
	queue<Node> pq;
	Node temp1, temp2;
	for (int i = 0; i < M; ++i)
	if (data[i] != '0'){
		temp1.ans = "";
		temp1.ans += data[i];
		temp1.mod = mci[data[i]] % N;
		vis[temp1.mod] = 1;
		pq.push(temp1);
	}
	while (!pq.empty()){
		temp1 = pq.front();
		pq.pop();	
		if (temp1.mod == 0){
			cout << temp1.ans << endl;
			return 1;
		}
		for (int i = 0; i < M; ++i){
			temp2 = temp1;
			temp2.ans += data[i];
			temp2.mod = (temp2.mod*C + mci[data[i]]) % N;
			if (!vis[temp2.mod]&&temp2.ans.length()<=500){
				vis[temp2.mod] = 1;
				pq.push(temp2);
			}
		}
	}
	return 0;
}





int main(){
	//ifstream in("C:\\temp.txt");
	for (char c = '0'; c <= '9'; ++c)
		mci[c] = c - '0';
	for (char c = 'A'; c <= 'F'; ++c)
		mci[c] = c - 'A' + 10;


	int T;
	cin >> T;
	while (T--){
		cin >> N >> C >> M;
		for (int i = 0; i < M; ++i){
			getchar();
			scanf("%c", &data[i]);
			// in >> data[i];
		}
		sort(data, data + M, cmp);
		M = unique(data, data + M) - data;
		if (N == 0){
			if (data[0] == '0')
				cout << 0 << endl;
			else
				printf("give me the bomb please\n");
		}
		else{
			if (!bfs())
				printf("give me the bomb please\n");
		}
	}
	return 0;
}

