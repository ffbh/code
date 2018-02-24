#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int Hash[500];

int main(){
	ifstream in("C:\\temp.txt");
	int M;
	string s;
	while (cin >> M&&M){
		cin.get();
		getline(cin, s);
		int L, R;
		L = R = 0;
		int num = 0;
		memset(Hash, 0, sizeof(Hash));
		int ans = 0;
		for (; L < s.length()&&R<s.length();++L){
			for (; R < s.length() && num <= M;++R){
				if (Hash[s[R]] == 0)
					num++;
				Hash[s[R]]++;
			}
			if (num>M){
				R--;
				Hash[s[R]]--;
				num--;
			}
			if (R - L>ans)
				ans = R - L;
			if (Hash[s[L]] == 1)
				num--;
			Hash[s[L]]--;
		}
		cout << ans << endl;
	}
	return 0;
}