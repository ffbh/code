#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;
struct mouse{
	int weight, speed;
	int index;
	bool operator<(const mouse& m){
		if (speed!=m.speed)
		return speed > m.speed;
		return weight < m.weight;
	}
};
mouse mice[1010];
int dp[1010];
struct{
	int index, pre;
}re[1010];
int main(){
	ifstream in("C:\\temp.txt");
	int k=0;
	//while (in >> mice[k].weight >> mice[k].speed){
	while (scanf("%d%d", &mice[k].weight, &mice[k].speed)!=EOF){
		mice[k].index = k;
		k++;
	}
	sort(mice, mice + k);
	memset(re, -1, sizeof(re));
	for (int i = 0; i < 1010; ++i)
		dp[i] = 1;
	re[0].index = mice[0].index;
	for (int i = 1; i < k; ++i){
		re[i].index = mice[i].index;
		for (int j = 0; j < i; ++j)	
		if (mice[i].weight>mice[j].weight && mice[i].speed < mice[j].speed&&dp[i] < dp[j] + 1){
			dp[i] = dp[j] + 1;
 			re[i].pre = j;
		//	re[i].pre = re[i].pre;
		}
	}
	int mmax = 0;
	int pos = 0;
	for (int i = 0; i < k; ++i)
	if (dp[i]>mmax){
		mmax = dp[i];
		pos = i;
	}
	cout << mmax << endl;
	stack<int> si;
	for (; pos != -1; pos = re[pos].pre)
		si.push(re[pos].index + 1);
	while (!si.empty()){
		cout << si.top() << endl;
		si.pop();
	}

	return 0;
}

