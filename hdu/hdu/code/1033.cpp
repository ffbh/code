#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dirs[4][2] = { 10, 0, 0, -10, -10, 0, 0, 10 };
int main(){
	ifstream in("C:\\temp.txt");
	string s;
	while(cin >> s){
		printf("300 420 moveto\n");
		printf("310 420 lineto\n");
		int nowx, nowy, nextx, nexty;
		nowx = 310;
		nowy = 420;
		int nowd = 0;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == 'A')
				nowd = (nowd + 1) % 4;
			else
				nowd = (nowd + 3) % 4;
			nextx = nowx + dirs[nowd][0];
			nexty = nowy + dirs[nowd][1];
			printf("%d %d lineto\n", nextx, nexty);
			nowx = nextx;
			nowy = nexty;
		}
		printf("stroke\n");
		printf("showpage\n");
	}
	return 0;
}