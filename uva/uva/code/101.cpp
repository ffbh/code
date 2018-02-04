#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int N;
vector<int> vi[30];
int idx[30];

void Init(){
	for (int i = 0; i < 30; ++i)
		vi[i].clear();
}

void pop(int p){
	int idp = idx[p];
	while (vi[idp].back() != p){
		int top = vi[idp].back();
		vi[top].push_back(top);
		idx[top] = top;
		vi[idp].pop_back();
	}
}

vector<int> Get(int p){
	vector<int> ans;
	while (vi[idx[p]].back() != p){
		ans.push_back(vi[idx[p]].back());
		vi[idx[p]].pop_back();
	}
	vi[idx[p]].pop_back();
	ans.push_back(p);
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
//	ifstream in("C:\\input.txt");
	while (cin >> N){
		Init();
		for (int i = 0; i < N; ++i){
			vi[i].push_back(i);
			idx[i] = i;
		}
		string s;
		int a, b;
		while (1){
			cin >> s;
			if (s[0] == 'q')
				break;
			if (s[0] == 'm'){
				cin >> a >> s >> b;
				if (a == b || idx[a] == idx[b])
					continue;
				if (s == "onto"){
					pop(a);
					pop(b);
					vi[idx[b]].push_back(a);
					vi[idx[a]].pop_back();
					idx[a] = idx[b];
				}
				else{
					pop(a);
					vi[idx[a]].pop_back();
					vi[idx[b]].push_back(a);
					idx[a] = idx[b];
				}
			}
			else{
				cin >> a >> s >> b;
				if (a == b || idx[a] == idx[b])
					continue;
				if (s == "onto"){
					pop(b);
					vector<int> A = Get(a);
					for (int i = 0; i < A.size(); ++i){
						vi[idx[b]].push_back(A[i]);
						idx[A[i]] = idx[b];
					}
				}
				else{
					vector<int> A = Get(a);
					for (int i = 0; i < A.size(); ++i){
						vi[idx[b]].push_back(A[i]);
						idx[A[i]] = idx[b];
					}
				}


			}

		}
		for (int i = 0; i < N; ++i){
			printf("%d:", i);
			for (int j = 0; j < vi[i].size(); ++j)
				printf(" %d", vi[i][j]);
			printf("\n");
		}

	}


	return 0;
}