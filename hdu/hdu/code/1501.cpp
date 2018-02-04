#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s1, s2, s3;
int len1, len2, len3;
bool vis[300][300];
bool dfs(int a, int b, int c){
	if (c >= len3)return 1;
	if (vis[a][b])return 0;
	vis[a][b] = 1;
	if (s1[a] == s3[c]&&a<len1)
	if (dfs(a + 1, b, c + 1))
		return 1;
	if (s2[b] == s3[c]&&b<len2)
	if (dfs(a, b + 1, c + 1))
		return 1;
	return 0;


}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	int CASE = 1;
	while (N--){
		memset(vis, 0, sizeof(vis));
		cin >> s1 >> s2 >> s3;
		len1 = s1.length();
		len2 = s2.length();
		len3 = s3.length();
		if (len1 + len2 == len3){
			if (dfs(0, 0, 0))
				printf("Data set %d: yes\n", CASE++);
			else
				printf("Data set %d: no\n", CASE++);
		
		}
		else
		
			printf("Data set %d: no\n", CASE++);
	
	
	}

	return 0;
}