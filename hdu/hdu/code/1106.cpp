#include <iostream>
#include <string>
#include <set>
using namespace std;
string s;
int len;
int fun(int pos1){
	while (pos1<len&&s[pos1] == '5')pos1++;
	return pos1;
}
int LEN(int a){
	int le=0;
	while (a<len&&s[a] != '5'){
		a++;
		le++;
	}
	return le;


}
int main(){
	int pos1, pos2;
	multiset<int> ms;
	while (cin >> s){
		ms.clear();
		pos1 = 0;
		len= s.length();
		int i;
		for (i = len - 1; i >= 0;--i)//È¥µôÎ²²¿µÄ5
		if (s[i] !='5')break;
		if (i != len - 1){
			s = s.substr(0, i + 1);
			len = s.length();
		}
		while (pos1 < len){
			pos1 = fun(pos1);
			pos2 = LEN(pos1);
			string t = s.substr(pos1, pos2);
			ms.insert(atoi(t.c_str()));
			pos1 += pos2;
		}
		multiset<int>::iterator it = ms.begin();
		int size = ms.size();
		int k = 0;
		while (k<size-1){
			cout << *it++ << " ";
			k++;
		}
		cout << *it++ << endl;
	}
	


	return 0;
}