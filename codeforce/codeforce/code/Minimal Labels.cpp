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
#define MMAX ((int)1e5 + 5)

vector<int> vi[MMAX];
int ans[MMAX];
int OU[MMAX];
int N, M;

void work(){
	priority_queue < int > pq;
	for (int i = 1; i <= N; ++i){
		if (OU[i] == 0){
			pq.push(i);
		}
	}

	int id = N;
	while (id >= 1){
		int u = pq.top();
		pq.pop();
		ans[u] = id--;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if ((--OU[v]) == 0){
				pq.push(v);
			}
		}
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";
	cout << endl;

}


int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N >> M;

	for (int i = 0; i < MMAX; ++i){
		vi[i].clear();
		OU[i] = 0;
	}

	for (int i = 0; i < M; ++i){
		int a, b;
		in >> a >> b;
		vi[b].push_back(a);
		OU[a]++;
	}

	work();










	return 0;
}





