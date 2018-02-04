#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
int N, index, K;
int pre[1010], ino[1010];
struct Node{
	int l, r;
}data[1010];
map<int, int> mii;
int build(int L,int R){
	if (L > R){
		index--;
		return -1;
	}
	int ret = mii[pre[index]];
	index++;
	data[ret].l = build(L, ret - 1);
	index++;
	data[ret].r = build(ret + 1, R);
	return ret;
}

void Print(int root){
	if (root == -1)
		return;
	Print(data[root].l);
	Print(data[root].r);
	if (K == 0){
		printf("%d", ino[root]);
		K = 1;
	}
	else
		printf(" %d", ino[root]);
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin>>N){
		mii.clear();
		index = 0;
		K = 0;
		for (int i = 1; i <= N; ++i)
			cin >> pre[i];
		for (int i = 1; i <= N; ++i){
			cin >> ino[i];
			mii[ino[i]] = i;
		}
		index++;
		Print(build(1, N));
		cout << endl;
	}
	return 0;
}