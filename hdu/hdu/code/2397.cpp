#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
string s, t;
set<string> si;
void Insert(){
	t = "";
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == '\'')continue;
		if (s[i] == '-'){
			if (t.length())
				si.insert(t);
			t = "";
			continue;
		}
		if (s[i] >= 'a'&&s[i] <= 'z')
			t += char(s[i] - 32);
		else if (s[i] >= 'A'&&s[i] <= 'Z')
			t += s[i];
	}
	if (t.length())
		si.insert(t);
}


int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (1){
		si.clear();
		while (in >> s&&s != "EOD"&&s != "EOT")
			Insert();
		printf("WORDS IN DOCUMENT #%d\n", CASE++);
		set<string>::iterator it = si.begin();
		while (it != si.end())
			printf("%s\n", (*it++).c_str());
		if (s == "EOT")
			break;
	}

	return 0;
}