#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include<algorithm>
using namespace std;
map<string, int> msi;
//ifstream in("C:\\temp.txt");
struct Node{
	string name;
	set<int> P, Q;
	void clear(){
		P.clear();
		Q.clear();
	}
}data[110];
int id;
int getNext(){
	string temp;
	cin >> temp;
	if (!msi[temp]){
		data[id].name = temp;
		return msi[temp] = id++;
	}
	return msi[temp];
}

int ans[110];
bool cmp(int a, int b){
	return data[a].name < data[b].name;
}


int main(){
	int N, M, T;
	set<int> si;
	while(cin >> N >> T){
		id = 1;
		msi.clear();
		si.clear();
		for (int i = 0; i < 110; ++i)
			data[i].clear();
		while (N--){
			int index = getNext();
			int K;
			cin >> K;
			while (K--){
				data[index].P.insert(getNext());
			}
			cin >> K;
			while (K--){
				data[index].Q.insert(getNext());
			}
		}
		cin >> M;
		while (M--)
			si.insert(getNext());
		set<int>::iterator it;
		while (T--){
			int temp[110];
			int cnt = 0;
			for (int i = 1; i < id; ++i){
				int p, q;
				p = q = 0;
				for (it = si.begin(); it != si.end(); ++it){
					if (data[i].P.count(*it))
						p++;
					else if (data[i].Q.count(*it))
						q++;
				}
				if (q&&p || !p&&!q)
					continue;
				else if (p)
					temp[cnt++] = i;
				else{
					it = si.find(i);
					if (it != si.end())
						si.erase(it);
				}
				
			}
			for (int k = 0; k < cnt; ++k)
				si.insert(temp[k]);
		}
		int num = 0;
		for (it = si.begin(); it != si.end(); ++it)
			ans[num++] = *it;
		sort(ans, ans + si.size(),cmp);
		for (int i = 0; i < si.size() - 1; ++i)
			printf("%s ", data[ans[i]].name.c_str());
		printf("%s\n", data[ans[si.size()-1]].name.c_str());
	}
	return 0;
}