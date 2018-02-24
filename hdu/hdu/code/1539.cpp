#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N;
int ans;
int time;
int len;
char S[110];
vector<int> pace;
vector<int> temp;

void dfs(int pos, int sum){
	if (sum > N)
		return;
	if (pos == len){
		if (sum >= ans&&sum <= N){
			if (sum == ans)
				time = 2;
			else{
				ans = sum;
				time = 1;
				pace = temp;
			}
		}
		return;
	}
	int now = 0;
	for (int i = pos; i < len; ++i){
		now = now * 10 + S[i] - '0';
		temp.push_back(now);
		dfs(i + 1, sum + now);
		temp.pop_back();
	}
}




int main(){
	ifstream in("C:\\temp.txt");
	//while (cin >> N >> S){
	while (scanf("%d",&N)&&cin>>S){
		if (N == 0 && S[0] =='0')
			break;
		len = strlen(S);
		temp.clear();
		ans = time =0;
		dfs(0, 0);
		if (time == 0)
			printf("error\n");
		else if (time == 1){
			cout << ans;
			for (int i = 0; i < pace.size(); ++i)
				printf(" %d", pace[i]);
			cout << endl;
		}
		else
			cout << "rejected" << endl;
	}
	return 0;
}

