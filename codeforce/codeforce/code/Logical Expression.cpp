#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


string str;

string ans[300][3];

string MIN(string a,string b){
	if (a.length() == 0)
		return b;
	if (b.length() == 0){
		return a;
	}

	if (a.length() < b.length()){
		return a;
	}
	else if (a.length() == b.length()){
		if (a < b)
			return a;
		else
			return b;
	}
	else{
		return b;
	}

}

int X = 15, Y = 51, Z = 85;
queue<pii> Q;
void update(pii& pos,string s){
	if (ans[pos.first][pos.second].length() == 0){
		ans[pos.first][pos.second] = s;
		Q.push(pos);
	}
	else{
		string& aim = ans[pos.first][pos.second];

		if (s.length() < aim.length() || s.length() == aim.length() && s < aim){
			Q.push(pos);
			aim = s;
		}
		
	}

}

int NOT(unsigned int v){
	v = ~v;
	return v % 256;
}

void spfa(){
	ans[X][0] = "x";
	ans[Y][0] = "y";
	ans[Z][0] = "z";
	ans[NOT(X)][0] = "!x";
	ans[NOT(Y)][0] = "!y";
	ans[NOT(Z)][0] = "!z";

	Q.push(mp(15, 0));
	Q.push(mp(51, 0));
	Q.push(mp(85, 0));
	Q.push(mp(NOT(15), 0));
	Q.push(mp(NOT(51), 0));
	Q.push(mp(NOT(85), 0));
	while (!Q.empty()){
		pii u = Q.front(), v;
		Q.pop();
		string now = ans[u.first][u.second];
		string _now = "(" + now + ")";
		v.first = NOT(u.first);
		v.second = 0;
		if (u.second == 0)
			update(v, "!" + now);
		else
			update(v, "!" + _now);
	

		for (int i = 0; i < 256;++i)
		for (int j = 0; j < 3; ++j){
			string& aim = ans[i][j];
			if (aim.length() == 0)
				continue;


			

			string _aim = "(" + aim + ")";
			v.second = 1;
			v.first = i & u.first;
			string a, b;
			if (j <= 1){
				a = aim;
			}
			else{
				a = _aim;
			}
			
			if (u.second <= 1){
				b = now;
			}
			else{
				b = _now;
			}
			update(v, MIN(a + "&" + b, b + "&" + a));
			v.second = 2;
			v.first = i | u.first;
			update(v, MIN(now + "|" + aim, aim + "|" + now));
		}





	}



}

void input(){
	in >> str;


}


int main(){

	spfa();



	int TEST_CASE = 1;
	in >> TEST_CASE;



	while (TEST_CASE-- > 0){
		input();

		int code = 0;
		for (int i = 0; i < str.length(); ++i){
			code = code * 2 + str[i] - '0';
		}

		cout << MIN(MIN(ans[code][0], ans[code][1]), ans[code][2]) << endl;











	}


	return 0;
}





