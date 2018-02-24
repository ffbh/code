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
#include <set>
using namespace std;
int N;
vector <int> vi[100010];
void input(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> N;
	for (int i = 1; i < N; ++i){
		int a, b;
		in >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}

}

double dfs(int p,int fa){
	double sum = 0;
	int poss = 0;
	for (int i = 0; i < vi[p].size(); ++i){
		int son = vi[p][i];
		if (son == fa)
			continue;
		poss++;
		sum += dfs(son, p) + 1.0;
	}
	if (poss != 0)
		return sum / poss;
	else{
		return 0;
	}
}

int main(){
	input();

	printf("%.10f\n", dfs(1,-1));


















	return 0;
}





