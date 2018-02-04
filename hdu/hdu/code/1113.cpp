#include <iostream>
#include <string>
#include <set>
#include <map>
//#include <fstream>
using namespace std;
multiset<char> fun(const string& s){
	int len = s.length();
	multiset<char> mc;
	for (int i = 0; i < len; ++i)
		mc.insert(s[i]);
	return mc;
}
int main(){
	//ifstream in("C:temp.txt");
	string s;
	multimap<multiset<char>, string> mcs;
	multiset<char> mcc;
	while (cin >> s&&s != "XXXXXX"){
		mcc = fun(s);
		mcs.insert(make_pair(mcc, s));
	}
	multimap<multiset<char>, string>::iterator it1;
	multimap<multiset<char>, string>::iterator it2;
	set<string> ss;
	while (cin >> s&&s != "XXXXXX"){
		mcc = fun(s);
		it1 = mcs.lower_bound(mcc);
		it2 = mcs.upper_bound(mcc);
		if (it1 == it2)
			cout << "NOT A VALID WORD" << endl;
		else{
			while (it1 != it2){
				ss.insert(it1->second);
				it1++;
			}
			copy(ss.begin(), ss.end(),ostream_iterator<string>(cout, "\n"));
			ss.clear();
		}
		cout << "******" << endl;
	}
	return 0;
}