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
#define EXP (1e-9)
int N;
vector<pair<int,int> > vi[110];

void print(int u,int v,double x){
	if (x - 1.0 > EXP){
		printf("%d %d %.10f\n", v, u, abs(x - 1.0));
	}
	else{
		printf("%d %d %.10f\n", u, v, abs(x));
	}
}

double getrev(double x){
	if (x - 1.0 > EXP){
		return x - 1.0;
	}
	else{
		return 1.0 + x;
	}
}

void dfs(int p,int f,double x){
	double delta = 2.0 / (double)vi[p].size();
	for(pair<int,int> son : vi[p]){
		if (son.first == f)
			continue;
		x += delta;
		if (x - 2.0 > EXP){
			x -= 2.0;
		}
		cout << 1 << " " << son.second << " ";
		print(p, son.first, x);
		dfs(son.first, p, getrev(x));
	}
}


int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;
	for (int i = 1; i < N; ++i){
		int a, b;
		in >> a >> b;
		vi[a].push_back(make_pair(b, i));
		vi[b].push_back(make_pair(a, i));
	}
	cout << N - 1 << endl;
	
	dfs(1, -1, 0);















	return 0;
}





