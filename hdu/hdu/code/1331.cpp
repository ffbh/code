#include <iostream>
#include <fstream>
using namespace std;
int dp[30][30][30];
int dfs(int x, int y, int z){
	
	if (x <= 0 || y <= 0 || z <= 0)return 1;
	if (x > 20 || y > 20 || z > 20)return dp[20][20][20]=dfs(20, 20, 20);
	if (dp[x][y][z])return dp[x][y][z];

	if (x < y&&y < z)return dp[x][y][z] = (dp[x][y][z-1]=dfs(x, y, z-1))+
		(dp[x][y-1][z-1]=dfs(x,y-1,z-1))-
		(dp[x][y-1][z]=dfs(x,y-1,z));

	return dp[x][y][z]=(dp[x - 1][y][z] = dfs(x - 1, y, z)) +
		(dp[x - 1][y - 1][z] = dfs(x - 1, y - 1, z)) +
		(dp[x - 1][y][z - 1] = dfs(x - 1, y, z - 1)) -
		(dp[x - 1][y - 1][z - 1] = dfs(x - 1, y - 1, z - 1));
}
int main(){
	ifstream in("C:\\temp.txt");
	int X, Y, Z;
	while (cin >> X >> Y >> Z){
		if (X == -1 && Y == -1 && Z == -1)break;
		printf("w(%d, %d, %d) = %d\n", X, Y, Z, dfs(X,Y,Z));
	
	
	}

	return 0;
}