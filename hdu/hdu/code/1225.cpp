#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
struct Soccer{
	string name;
	int point;
	int winpoint;
	int failpoint;
	bool operator<(const Soccer& p)const{
		if (point != p.point)
			return point>p.point;
		else if (winpoint - failpoint != p.winpoint - p.failpoint)
			return winpoint - failpoint > p.winpoint - p.failpoint;
		else if (winpoint != p.winpoint)
			return winpoint > p.winpoint;
		else
			return name < p.name;
	}
};
Soccer pp[100];


int main(){
	//ifstream in("C:\\temp.txt");
	string s1, s2;
	map<string, int> msi;
	int N;
	int a, b;
	while (cin >> N){
		int cnt = 1;//排序开始下标为1
		msi.clear();
		memset(pp, 0, sizeof(pp));
		int M = N*(N - 1);
		while (M--){
			cin >> s1 >> s2 >> s2;
			if (msi[s1] == 0){
				pp[cnt].name = s1;
				msi[s1] = cnt++;
			}
			if (msi[s2] == 0){
				pp[cnt].name = s2;
				msi[s2] = cnt++;
			}
			//in >> a >> b;
			scanf("%d:%d", &a, &b);
			pp[msi[s1]].winpoint += a;
			pp[msi[s1]].failpoint += b;
			pp[msi[s2]].winpoint += b;
			pp[msi[s2]].failpoint +=a;
			if (a == b){
				pp[msi[s1]].point++;
				pp[msi[s2]].point++;
			}
			else if (a > b)
				pp[msi[s1]].point+=3;
			else
				pp[msi[s2]].point+=3;
		}
		sort(pp + 1, pp + 1 + N);
		for (int i = 1; i <= N; ++i)
			printf("%s %d\n", pp[i].name.c_str(), pp[i].point);
		cout << endl;

	}
	return 0;
}