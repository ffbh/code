#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
using namespace std;
ofstream out("C:\\output.txt");
struct Node{
	int num;
	char c;
}data[10];
int dig[] = { 0, 8, 88, 888, 8888, 88888, 888888, 8888888, 88888888 };

int aim;

string IntToString(int num){
	string tmp = "";
	if (num == 0)
		return "0";
	bool f = 0;
	if (num < 0){
		f = 1;
		num = -num;
	}
	while (num){
		tmp += num % 10 + '0';
		num /= 10;
	}
	if (!f)
		return string(tmp.rbegin(), tmp.rend());
	else
		return '-' + string(tmp.rbegin(), tmp.rend());
}

bool DFS(long long pre, int k, int d){
	/*if (k == 8){
		string s = "";
		for (int i = 0; i < d; ++i){
			if (s.length() != 0)
				s = '(' + s + ')' + data[i].c + IntToString(data[i].num);
			else{
				if (data[i].c == '-')
					s = data[i].c + IntToString(data[i].num);
				else
					s = IntToString(data[i].num);
			}
		}
		out << s+'='+ IntToString(pre) << endl;
	}*/
	if (pre == aim && k == 8){
		string s = "";
		for (int i = 0; i < d; ++i){
			if (s.length() != 0)
				s = '(' + s + ')' + data[i].c + IntToString(data[i].num);
			else{
				if (data[i].c == '-')
					s = data[i].c + IntToString(data[i].num);
				else
					s = IntToString(data[i].num);
			}
		}
		cout << s << endl;
		return 1;
	}
	
	for (int i = k + 1; i <= 8; ++i){
		if (d != 0){
			data[d].c = '*';
			data[d].num = dig[i - k];
			if (DFS(pre * dig[i - k], i, d + 1))
				return 1;

			data[d].c = '/';
			data[d].num = dig[i - k];
			if (DFS(pre / dig[i - k], i, d + 1))
				return 1;
		}
		data[d].c = '+';
		data[d].num = dig[i - k];
		if (DFS(pre + dig[i - k], i, d + 1))
			return 1;

		data[d].c = '-';
		data[d].num = dig[i - k];
		if (DFS(pre - dig[i - k], i, d + 1))
			return 1;
	}
	return 0;
}



int main(){
	ifstream in("C:\\input.txt");
	aim = 262080;
	long s = clock();
	if (!DFS(0, 0, 0))
		cout << -1 << endl;
	cout << clock() - s << endl;















	return 0;
}