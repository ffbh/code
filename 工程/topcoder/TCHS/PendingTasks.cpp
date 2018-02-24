#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;


vector<int> vi[100];
struct Node{
	int noexcute,excute, num;
	Node(int a, int b, int c){
		noexcute = a;
		excute = b;
		num = c;
	}
};
int size[100];
int dp[100][2];//0 noexcute     1 excute

int dfs(int p){
	size[p] = 1;	
	for (int i = 0; i < vi[p].size(); ++i){
		size[p] += dfs(vi[p][i]);
	}
	return size[p];
}

void slove(int p){
	if (vi[p].size() == 0){
		dp[p][0] = 0;
		dp[p][1] = 1;
		return;
	}
	else{
		vector<Node> tmp;
		for (int i = 0; i < vi[p].size(); ++i){
			int son = vi[p][i];
			slove(son);
			tmp.push_back(Node(dp[son][0], dp[son][1], size[son]));
		}
		int sum = 0;
		for (int i = 0; i < tmp.size(); ++i){
			sum += tmp[i].noexcute;
		}
		dp[p][0] = sum;
		for (int i = 0; i < tmp.size(); ++i){
			dp[p][0] = max(dp[p][0], sum - tmp[i].noexcute + tmp[i].num);
		}

		dp[p][1] = 0;
		if (tmp.size() == 1){
			dp[p][1] = tmp[0].num;
		}
		else{
			for (int i = 0;i<tmp.size();++i)
			for (int j = 0; j < tmp.size(); ++j){
				if (i == j)
					continue;
				dp[p][1] = max(dp[p][1], sum - tmp[i].noexcute - tmp[j].noexcute + tmp[i].num + tmp[j].excute);
			}
		}
		dp[p][1]++;
	}
}

class PendingTasks {
	public:
	int latestProcess(vector <int> supertasks) {
		for (int i = 0; i < 100; ++i)
			vi[i].clear();

		for (int i = 0; i < supertasks.size(); ++i){
			vi[supertasks[i]].push_back(i);
		}

		dfs(supertasks.size() - 1);
		
		slove(supertasks.size() - 1);

		return dp[supertasks.size() - 1][1] - 1;
	}
};



/*int main(){
	
	PendingTasks so;
	//cout<<so.latestProcess()<<endl;
















	return 0;
}


*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
