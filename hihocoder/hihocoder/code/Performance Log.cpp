#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
stack<int> si;
int size;
struct Log{
	string name, state;
	int time;
	bool operator<(const Log& p)const{
		return time < p.time;
	}
}g[20010];
struct Node{
	string name;
	int time;
}ans[20010];


int TimeToInt(string& s){
	int h,m, sec;
	h = (s[0]-'0') * 10 + s[1]-'0';
	m = (s[3]-'0') * 10 + s[4]-'0';
	sec = (s[6]-'0') * 10 + s[7]-'0';
	return h * 3600 + m * 60 + sec;

}

void PrintIntToTime(int t){
	int h = t / 3600;
	t %= 3600;
	int m = t / 60;
	t %= 60;
	int sec = t;
	printf("%02d:%02d:%02d", h, m, sec);
}


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	bool f = 1;
	for (int i = 0; i < N; ++i){
		string t;
		cin >> g[i].name >> t >> g[i].state;
		g[i].time = TimeToInt(t);
		if (i && g[i].time < g[i - 1].time){
			f = 0;
			break;
		}
	}

	size = 0;
	
	if (f){
		for (int i = 0; i < N; ++i){
			if (g[i].state == "START"){
				ans[size].name = g[i].name;
				ans[size].time = g[i].time;
				si.push(size);
				size++;
			}
			else if (g[i].state == "END"){
				int top = si.top();
				if (ans[top].name != g[i].name){
					f = 0;
					break;
				}
				si.pop();
				ans[top].time = g[i].time - ans[top].time;
			}
			else{
				f = 0;
				break;
			}
		}
	}

	if (!si.empty())
		f = 0;

	if (!f){
		cout << "Incorrect performance log" << endl;
	}
	else{
		for (int i = 0; i < size; ++i){
			printf("%s ", ans[i].name.c_str());
			PrintIntToTime(ans[i].time);
			putchar('\n');
		}
	}



	return 0;
}