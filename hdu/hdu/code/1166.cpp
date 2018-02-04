/*#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int N, M;
struct tree{
	int left, right, value;
};
tree dp[150010];
int father[50010];
void build(int i,int left,int right){
	dp[i].left = left;
	dp[i].right = right;
	dp[i].value = 0;
	if (left == right){
		father[left] = i;
		return;
	}
	build(i * 2, left, (left + right) / 2);
	build(i * 2 + 1, (left + right) / 2 + 1, right);
}

void uperat(int i,int value){
	dp[i].value += value;
	if (i == 1)
		return;
	else
		uperat(i / 2, value);
}


int query(int i,int l, int r){
	int sum = 0;
	if (dp[i].left == l&&dp[i].right == r)
		return dp[i].value;
	int index = i * 2;
	if (l<=dp[index].right)
	if (r<=dp[index].right)
		sum += query(index, l, r);
	else
		sum += query(index, l, dp[index].right);

	index++;
	if (r>=dp[index].left)
	if (l>=dp[index].left)
		sum += query(index, l, r);
	else
		sum += query(index, dp[index].left, r);
	return sum;

}




/*int main(){
	//ifstream in("C:\\temp.txt");
	int N,M;
	cin >> N;
	int Case = 1;
	while (N--){
		printf("Case %d:\n", Case++);
		memset(dp, 0, sizeof(dp));
		memset(father, 0, sizeof(father));
		cin >> M;
		build(1, 1, M);
		for (int i = 1; i <= M; ++i){
			int t;
			//in >> t;
			scanf("%d", &t);
			uperat(father[i], t);
		}
		string s;
		while (cin >> s&&s != "End"){
			int a, b;
			if (s == "Add"){
			//	in >> a >> b;
				scanf("%d%d", &a, &b);
				uperat(father[a], b);
			}
			else if (s == "Sub"){
				//in>> a >> b;
				scanf("%d%d", &a, &b);
				uperat(father[a], -b);
			}
			else{
				//in >> a >> b;
				scanf("%d%d", &a, &b);
				printf("%d\n", query(1, a, b));
			}
		}
	
	}

	return 0;
}*/