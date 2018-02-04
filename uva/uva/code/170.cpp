#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
string s;
vector<string> vs[13];
vector<string> data;
int h[266];
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	h['A'] = 0;
	for (char c = '2'; c <= '9'; ++c){
		h[c] = c - '0' - 1;
	}
	h['T'] = 9;
	h['J'] = 10;
	h['Q'] = 11;
	h['K'] = 12;
	while (in >> s&&s != "#"){
		for (int i = 0; i < 13; ++i)
			vs[i].clear();

		data.push_back(s);
		for (int i = 0; i < 51; ++i){
			in >> s;
			data.push_back(s);
		}
		reverse(data.begin(), data.end());
		for (int i = 0; i < 52; ++i){
			vs[i % 13].push_back(data[i]);
		}




		int now = 12;
		string pre;
		int num = 0;
		while (!vs[now].empty()){
			pre = vs[now].back();
			num++;
			vs[now].pop_back();
			now = h[pre[0]];
		}
		printf("%02d,", num);
		cout << pre << endl;




	}
















	return 0;
}