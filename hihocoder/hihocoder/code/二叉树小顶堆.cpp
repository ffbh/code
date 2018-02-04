#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
int data[110], N;
struct Node{
	int l, r;
}tree[110];
int build(int L,int R){
	if (L > R)
		return -1;
	int ret = L;
	for (int i = L; i <= R; ++i){
		if (data[ret] > data[i])
			ret = i;
	}
	tree[ret].l = build(L, ret - 1);
	tree[ret].r = build(ret + 1, R);
	return ret;
}

void Print(int root){
	if (root == -1)
		return;	
	printf("%d ", data[root]);
	Print(tree[root].l);
	Print(tree[root].r);

}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> data[i];
	Print(build(1, N));
	
	return 0;
}