#include <iostream>
#include <fstream>
using namespace std;
#define MAXN 100010
struct Tree{
	int left, right;
	_int64 v;
};
Tree tree[100010];





int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 1; i <= N; ++i){
			scanf("%I64d", &tree[i].v);
			//in >> tree[i].v;
			tree[i].left = i;
			tree[i].right = i;
		}
		tree[0].v = tree[N + 1].v = -1;
		for (int i = 2; i <= N;++i)
		while (tree[i].v <= tree[tree[i].left - 1].v)
			tree[i].left = tree[tree[i].left - 1].left;
		for (int i = N - 1; i >= 1;--i)
		while (tree[i].v <= tree[tree[i].right + 1].v)
			tree[i].right = tree[tree[i].right + 1].right;


		_int64 mmax = 0;
		for (int i = 1; i <= N; ++i){
			_int64 dd = tree[i].v*(tree[i].right - tree[i].left + 1);
			if (dd > mmax)mmax = dd;
		}
		cout << mmax << endl;



	
	
	
	}

	return 0;
}