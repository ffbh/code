#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s1, s2;
int Next[10010];

void Init(){
	int i, j;
	Next[0] = -1;
	i = 0;
	j = -1;
	while (i < s1.length()){
		if (j == -1 || s1[i] == s1[j])
			Next[++i] = ++j;
		else
			j = Next[j];
	}
}

int kmp(){
	int i, j;
	int cnt = 0;
	i = j = 0;
	while (i < s2.length()){
		if (j == -1 || s1[j] == s2[i]){
			++i;
			++j;
		}
		else
			j = Next[j];
		if (j == s1.length())
			cnt++;
	}
	return cnt;


}


int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while(T--){
		cin >> s1 >> s2;
		Init();
		cout << kmp() << endl;
	}





	return 0;
}