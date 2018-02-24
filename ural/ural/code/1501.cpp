#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
int N;
string s1, s2;
vector<int> pace;
bool vis[1010][1010];
bool dfs(int p1, int p2, int pre1, int pre2){
	if (abs(pre1 - pre2) > 1 || vis[p1][p2])
		return 0;
	if (p1 == N&&p2 == N)
		return 1;
	vis[p1][p2] = 1;
	if (pre1 == pre2){
		if (p1 < N){
			if (s1[p1] == '0'){
				pace.push_back(1);
				if (dfs(p1 + 1, p2, pre1 + 1, pre2))
					return 1;
				pace.pop_back();
			}
			else {
				pace.push_back(1);
				if (dfs(p1 + 1, p2, pre1, pre2 + 1))
					return 1;
				pace.pop_back();
			}
		}
		if (p2 < N){
			if (s2[p2] == '0'){
				pace.push_back(2);
				if (dfs(p1, p2 + 1, pre1 + 1, pre2))
					return 1;
				pace.pop_back();
			}
			else {
				pace.push_back(2);
				if (dfs(p1, p2 + 1, pre1, pre2 + 1))
					return 1;
				pace.pop_back();
			}
		}
	}
	if (pre1 < pre2){
		if (p1 < N&&s1[p1] == '0'){
			pace.push_back(1);
			if (dfs(p1 + 1, p2, pre1 + 1, pre2))
				return 1;
			pace.pop_back();
		}
		if (p2 < N&&s2[p2] == '0'){
			pace.push_back(2);
			if (dfs(p1, p2 + 1, pre1 + 1, pre2))
				return 1;
			pace.pop_back();
		}
	}
	else{
		if (p1 < N&&s1[p1] == '1'){
			pace.push_back(1);
			if (dfs(p1 + 1, p2, pre1, pre2 + 1))
				return 1;
			pace.pop_back();
		}

		if (p2 < N&&s2[p2] == '1'){
			pace.push_back(2);
			if (dfs(p1, p2 + 1, pre1, pre2 + 1))
				return 1;
			pace.pop_back();
		}

	}
	return 0;
}



int main(){
	ifstream in("C:\\temp.txt"); 
	cin >> N >> s1 >> s2;
	if (dfs(0, 0, 0, 0)){
		for (int i = 0; i < pace.size(); ++i)
			printf("%d", pace[i]);
		cout << endl;
	}
	else
		cout << "Impossible" << endl;
	return 0;
}