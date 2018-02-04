#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Tree{
	bool count;
	int next[15];
};
int root;
Tree tree[150010];
int cnt;
int MALLOC(){
	tree[cnt].count = 0;
	for (int i = 0; i < 15; ++i)
		tree[cnt].next[i] = 0;
	return cnt++;
}

bool Insert(string& s){
	int len = s.length();
	int index = root;
	bool flag = 1;
	for (int i = 0; i < len; ++i){
		if (tree[index].next[s[i] - '0'] == 0){
			tree[index].next[s[i] - '0'] = MALLOC();
			index = tree[index].next[s[i] - '0'];
		}
		else
			index = tree[index].next[s[i] - '0'];

		if (tree[index].count)
			flag = 0;
	}
	tree[index].count = 1;
	for (int i = 0; i < 15;++i)
	if (tree[index].next[i])
		flag = 0;
	return flag;
}





int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	string s;
	cin >> T;
	int K;
	while (T--){
		cnt = 1;
		root = MALLOC();
		cin >> K;
		bool ans = 1;
		while (K--){
			cin >> s;
			if (ans)
				ans = Insert(s);
		}
		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;




	}

	return 0;
}