#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace  std;
string s;
int N;
struct ZDTree{
	struct Node{
		int len,sdex;
		int next[26];

	}data[100010];
	int size, root;
	void Init(){
		size = 0;
		root = getNext();
	}
	int getNext(){
		++size;
		data[size].len = 0;
		data[size].sdex = -1;
		memset(data[size].next, -1, sizeof(data[size].next));
		return size;
	}
	void Insert(string& s){
		int p = root;
		for (int i = 0; i < s.length(); ++i){
			int ne = s[i] - 'a';
			if (data[p].next[ne] == -1){
				data[p].next[ne] = getNext();
			}
			p = data[p].next[ne];
		}
		data[p].len = s.length();
	}

	int getAns(){
		int ans = 0;
		queue<int> qi;
		qi.push(root);
		while (!qi.empty()){
			int u = qi.front();
			qi.pop();
			if (data[u].len > ans){
				ans = data[u].len;
			}
			for (int i = 0; i < 26;++i)
			if (data[u].next[i] != -1){
				int v = data[u].next[i];
				int now_dex = data[u].sdex + 1;
				while (now_dex < s.length()){
					if (s[now_dex] == i + 'a')
						break;
					now_dex++;
				}
				if (now_dex < s.length()){
					data[v].sdex = now_dex;
					qi.push(v);
				}
			}
		}
		return ans;
	}

}zdTree;






int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	zdTree.Init();
	for (int i = 0; i < N; ++i){
		string str;
		cin >> str;
		zdTree.Insert(str);
	}
	cin >> s;

	cout << zdTree.getAns() << endl;

	



	return 0;
}