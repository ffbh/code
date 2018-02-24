#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> msi;
unordered_map<int, int> usi;
int size = 1;
int f[500];
int fa[500];
int dept[510];
vector<int> vi[510];
void dfs(int p,int d){
	dept[p] = d;
	for (int i = 0; i < vi[p].size(); ++i){
		dfs(vi[p][i], d + 1);
	}
}




int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

int getId(string& s){
	if (msi.count(s))
		return msi[s];
	else{
		int ret = size++;
		msi[s] = ret;
		return ret;
	}
}

int judge(int a,int p){
	int num = 0;
	int tmp = a;
	while (f[tmp] != tmp){
		tmp = fa[tmp];
		num++;
		if (tmp == p)
			return num;
	}
	return -1;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	for (int i = 0; i < 500; ++i)
		f[i] = i;

	string s1, s2;
	while (in >> s1 >> s2){
		if (s1 == "no.child"){
			break;
		}
		int son = getId(s1);
		int father = getId(s2);
		fa[son] = father;
		vi[father].push_back(son);
		f[son] = father;
	}

	for (int i = 1; i < size; ++i){
		if (f[i] == i){
			dfs(i, 1);
		}
	}
	while (in >> s1 >> s2){
		int a = getId(s1);
		int b = getId(s2);
		if (find(a) != find(b)){
			printf("no relation\n");
		}
		else{
			int ret = judge(a, b);
			if (ret != -1){
				if (ret > 1){
					for (int i = 2; i < ret; ++i){
						printf("great ");
					}
					printf("grand ");
				}
			
					
				printf("child\n");
				continue;
			}
			ret = judge(b, a);
			if (ret != -1){
				if (ret > 1){
					for (int i = 2; i < ret; ++i){
						printf("great ");
					}
					printf("grand ");
				}
				printf("parent\n");
				continue;
			}

			if (fa[a] == fa[b]){
				printf("sibling\n");
				continue;
			}


			int da = dept[a];
			int db = dept[b];
			
			usi.clear();
			int tmp = a;
			int ddd = 0;
			int n, m;
			m = abs(da - db);
			while (f[tmp] != tmp){
				tmp = fa[tmp];
				usi[tmp] = ddd++;
			}

			tmp = b;
			ddd = 0;
			while (f[tmp] != tmp){
				tmp = fa[tmp];
				if (usi.count(tmp)){
					n = min(usi[tmp], ddd);
					break;
				}
				ddd++;
			}

			printf("%d cousin", n);
			if (m){
				printf(" removed %d", m);
			}
			printf("\n");

		}


	}


	return 0;
}