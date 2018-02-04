#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
char a[100], b[100];
int dp[100][100];
int pos, num;
void Print(int x,int y){
	if (x == 0 && y == 0)
		return;

	if (a[x] == b[y])
		Print(x - 1, y - 1);
	else if(x>0 && y>0){
		int mmin = min(min(dp[x - 1][y], dp[x][y - 1]), dp[x - 1][y - 1]);
		if (dp[x - 1][y] == mmin){	
			Print(x - 1, y);
			printf("%d Delete %d\n", num++, x+pos);
			pos--;
		
		}
		else if (dp[x - 1][y - 1] == mmin){
			Print(x - 1, y - 1);
			printf("%d Replace %d,%c\n", num++, x+pos, b[y]);
			
		}
		else{
			Print(x, y - 1);
			printf("%d Insert %d,%c\n", num++, y, b[y]);
			pos++;
			
		}
	}
	else if (x == 0){
		Print(x, y - 1);
		printf("%d Insert %d,%c\n", num++, y, b[y]);
		pos++;
		

	}
	else{
		Print(x - 1, y);
		printf("%d Delete %d\n",num++,  x+pos);
		pos--;
		

	}



}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> (a+1) >> (b+1)){
		int la = strlen(a + 1);
		int lb = strlen(b + 1);
		pos = 0;
		num = 1;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < 100; ++i)
			dp[0][i] = dp[i][0] = i;
		for (int i = 1; i <= la;++i)
		for (int j = 1; j <= lb; ++j){
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1];
			else{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
		cout << dp[la][lb] << endl;
		Print(la, lb);

	}

	return 0;
}