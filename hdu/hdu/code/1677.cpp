#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int x, y;
	bool operator<(const Node& p)const{
		if (x != p.x)
			return x > p.x;
		return y<p.y;
	}
};
Node data[20001];
int dp[20001];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int count;
	while (T--){
		count = 0;
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> data[i].x >> data[i].y;
		sort(data, data + N);
		dp[count++] = data[0].y;
		for (int i = 1; i < N;++i)
		if (data[i].y >= dp[count - 1])
			dp[count++] = data[i].y;
		else
			*upper_bound(dp, dp + count, data[i].y) = data[i].y;
		cout << count << endl;
	}





	return 0;
}