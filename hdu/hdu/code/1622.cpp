#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
struct Node{
	string s;
	int num;
};
Node data[300];
int cnt;
bool fun(string& s){
	int len = s.length();
	for (int i = 0; i < len;++i)
	if (s[i] == '(' || s[i] == ')' || s[i] == ',')
		s[i] = ' ';
	return len != 2;
}

bool cmp(const Node& p1, const Node& p2){
	int len1 = p1.s.length();
	int len2 = p2.s.length();
	if (len1 != len2)return len1 < len2;
	return p1.s < p2.s;
}

int  OK(int n){
	int ans = 0;
	if (n < cnt){
		string s = data[n].s;
		string lson = s + "L";
		string rson = s + "R";
		for (int i = n; i<cnt;++i)
		if (data[i].s == lson ){
			ans++;
			ans += OK(i);
			break;
		}
		for (int i = n; i<cnt; ++i)
		if (data[i].s == rson){
			ans++;
			ans += OK(i);
			break;
		}
	}
	return ans;

}

int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	stringstream ss;
	while (cin >> s){
		cnt = 0;
		bool flag = 1;
		while (1){
			flag = fun(s);
			ss.clear();
			ss.str(s);
			ss >> data[cnt].num;
			data[cnt].s = "";
			ss >> data[cnt].s;
			cnt++;
			if (!flag)break;
			cin >> s;
		}
		cnt--;
		sort(data, data + cnt, cmp);
		if (data[0].s.length() > 0 || OK(0) != cnt - 1)
			cout << "not complete" << endl;
		else{
			for (int i = 0; i < cnt - 1; ++i)
				printf("%d ", data[i].num);
			printf("%d\n", data[cnt - 1].num);
		}
	}

	return 0;
}