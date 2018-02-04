#include <iostream>
//#include <fstream>
#include <string>
#include <queue>
using namespace std;
int K[3];
struct node{
	int start;
	int end;
	bool operator<(const node& nn)const{
		return start > nn.start;
	}
};
priority_queue<node> qn[3];
int fun(int n){
	return (n - 1) / 2;
}
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	node nn;
	while (cin >> K[0] >> K[1] >> K[2]){
		if (K[0] == 0 && K[1] == 0 && K[2] == 0)
			break;
		int ans=0;
		while (cin >> s&&s != "#"){
			nn.start = 60*((s[0]-'0') * 10 + s[1]-'0')+(s[3]-'0') * 10 +s[4]-'0';
			nn.end = nn.start + 30;
			int num;
			cin >> num;
			while (!qn[fun(num)].empty() && nn.start >= qn[fun(num)].top().end)//pop出所有已吃完的人
				qn[fun(num)].pop();
			if (qn[fun(num)].size() < K[fun(num)]){//若还有空桌子，坐上去
				qn[fun(num)].push(nn);
				ans += num;
			}
			else if (qn[fun(num)].size() == K[fun(num)]&&K[fun(num)]!=0)//没有空桌子
				if (nn.end >= qn[fun(num)].top().end){//并且没有等待该桌子的人
				    nn.start = qn[fun(num)].top().end;
					nn.end = nn.start + 30;
					qn[fun(num)].push(nn);
					qn[fun(num)].pop();
					ans += num;
				}
		}
		cout << ans << endl;
		for (int i = 0; i < 3; ++i)
		while (!qn[i].empty()) qn[i].pop();
	}
	return 0;
}