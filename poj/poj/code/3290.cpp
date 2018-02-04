#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<char> wff, k,n;
int a, b, c;
string s;
void Init(){
	wff.clear();
	n.clear();
	k.clear();
	for (int i = 0; i < s.length();++i)
	if (s[i] == 'N')
		n.push_back(s[i]);
	else if (s[i] >= 'a'&&s[i] <= 'z')
		wff.push_back(s[i]);
	else
		k.push_back(s[i]);
}



int main(){
	ifstream in("C:\\input.txt");
	string ans;
	while (cin >> s&& s != "0"){
		Init();
		if (wff.size() == 0){
			cout << "no WFF possible" << endl;
			continue;
		}
		ans = "";
		a = b = 0;
		for (int i = 0; i < n.size(); ++i)
			ans = 'N' + ans;
		ans += wff[a++];
		while (a < wff.size() && b < k.size()){
			ans += wff[a++];
			ans = k[b++] + ans;
		}
		cout << ans <<endl;
	}



	return 0;
}