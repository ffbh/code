#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <stack>
using namespace std;
int N, val;
struct Node{
	int idx, lval, maxval;
	Node(int a,int b,int c){
		idx = a;
		lval = b;
		maxval = c;
	}
	Node(){}
};

int main(){
	ifstream in("C:\\input.txt");

	while (~scanf("%d",&N)){
		stack<Node> sn;
		int ans = -1;
		for (int i = 1; i <= N; ++i){
			//cin >> val;
			scanf("%d", &val);
			while (!sn.empty() && sn.top().lval > val){
					sn.pop();
			}

			if (sn.empty() || sn.top().maxval > val){
				sn.push(Node(i, val, val));
			}
			else{
				Node tmp;
				while (!sn.empty() && sn.top().maxval < val){
					tmp = sn.top();
					sn.pop();
					ans = max(ans, i - tmp.idx);
					tmp.maxval = val;
				}
				sn.push(tmp);
			}
		}
		cout << ans << endl;
	}


	return 0;
}