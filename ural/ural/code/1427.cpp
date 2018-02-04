#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int N, M;
string s;
void Init(){
	int pre = 0;
	int ans = 0;
	bool flag = 1;
	for (int i = 0; i < s.length(); ++i){
		if (!(s[i] >= 'a'&&s[i] <= 'z' || s[i] == ' ' || s[i] >= 'A'&&s[i] <= 'Z'))
			flag = 0;
		if (pre == 0)
			ans++;
		pre++;
		if (!flag&&pre>N || flag&&pre > M){
			pre = 0;
			flag = 1;
			i--;
		}
	}
	cout << ans << endl;
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		cin.get();
		getline(cin, s);
		Init();
		
	}








	return 0;
}