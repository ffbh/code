#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int N, M;
map<string, int> msi;
struct Problem{
	int wrongtime;
	bool ac;
	int actime;
	int penalty;
};
struct Node{
	vector<int> vi;
	Problem data[20];
	string name;
	int rank;
	int sumpenalty;
	bool operator<(const Node& p)const{
		if (vi.size() != p.vi.size())
			return vi.size()>p.vi.size();
		if (sumpenalty != p.sumpenalty)
			return sumpenalty < p.sumpenalty;
		for (int i = vi.size() - 1; i >= 0; --i){
			int a = vi[i];
			int b = p.vi[i];
			if (data[a].actime != p.data[b].actime)
				return data[a].actime < p.data[b].actime;
			if (data[a].penalty != p.data[b].penalty)
				return data[a].penalty>p.data[b].penalty;
		}
		return name < p.name;
	}
	bool operator==(const Node& p)const{
		if (vi.size() != p.vi.size())
			return 0;
		if (sumpenalty != p.sumpenalty)
			return 0;
		for (int i = vi.size() - 1; i >= 0; --i){
			int a = vi[i];
			int b = p.vi[i];
			if (data[a].actime != p.data[b].actime)
				return 0;
			if (data[a].penalty != p.data[b].penalty)
				return 0;
		}
		return 1;
	}
}stu[60];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		msi.clear();
		cin >> N >> M;
		int ID = 0;
		memset(stu, 0, sizeof(stu));
		for (int i = 0; i < N; ++i){
			cin >> stu[i].name;
			msi[stu[i].name] = ID++;
		}
		while (M--){
			int time;
			string name, state;
			char pid;
			cin >> time >> name >> pid >> state;
			int num = msi[name];
			pid -= 'A';
			if (state[0] == 'a'){
				if (stu[num].data[pid].ac)
					continue;
				if (num == 1){
					int t = 0;

				}
				stu[num].data[pid].ac = 1;
				stu[num].data[pid].actime = time;
				stu[num].vi.push_back(pid);
				stu[num].data[pid].penalty = stu[num].data[pid].actime +
					stu[num].data[pid].wrongtime * 20;
				stu[num].sumpenalty += stu[num].data[pid].penalty;
			}
			else{
			//	if (stu[num].data[pid].ac)
			//		continue;
				stu[num].data[pid].wrongtime++;
			}
		}
		sort(stu, stu + N);
		stu[0].rank = 1;
		for (int i = 1; i < N;++i)
		if (stu[i] == stu[i - 1])
			stu[i].rank = stu[i - 1].rank;
		else
			stu[i].rank = i + 1;
		for (int i = 0; i < N; ++i)
			printf("%d %s %d %d\n", stu[i].rank,stu[i].name.c_str(), stu[i].vi.size(), stu[i].sumpenalty);
	}
	return 0;
}