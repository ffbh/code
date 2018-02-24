#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;
int Next[1000010];

void kmp(){
	int i, j;
	i = 0;
	j = -1;
	Next[0] = -1;
	while(i < s.length()){
		if (j == -1 || s[i] == s[j]){
			Next[++i] = ++j;
			if (i % (i - Next[i]) == 0 && (i / (i - Next[i])>1))
				printf("%d %d\n", i, i / (i - Next[i]));
		}
		else j = Next[j];
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	int N, CASE = 1;
	while (cin >> N&&N){
		cin >> s;
		printf("Test case #%d\n", CASE++);
		kmp();
		cout << endl;

	}






	return 0;
}