#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N;
char s[100010];
bool Filter[100010];
string data[1010];
int len;
int e[256];

int f[100010];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}


void InitS(string& str){
	memset(e, -1,sizeof(e));
	for (int i = 0; i < str.length(); ++i)
		e[str[i]] = i;
}
bool ok(string& str,int a){
	for (int i = 0; i < str.length(); ++i){
		if (a >= len || str[i] != s[a])
			return 0;
		a++;
	}
	return 1;
}

void filter(int a,int k){

	for (int i = 0; i < k; ++i){
		
		if (!Filter[a]&&a - 1 >= 0 && Filter[a - 1])
			f[a - 1] =  a;
			
		if (!Filter[a]&&a + 1<len&&Filter[a + 1])
			f[a] = a + 1;
		Filter[a] = 1;
		a++;
	}
}

void showF(int n){
	for (int i = 0; i < n; ++i)
		cout <<find( f[i]);
	cout << endl;
}

void text(){
	len = 100000000;
	for (int i = 0; i < 10; ++i)
		f[i] = i;
	showF(10);
	filter(1, 2);
	showF(10);
	filter(5, 3);
	showF(10);
	filter(3, 1);
	showF(10);
	filter(8, 2);
	showF(10);
}

void match(string& str){
	InitS(str);
	int epos = str.length() - 1;
	
	for (; epos  < len;epos++){


		if (e[s[epos]] == -1){
			epos += str.length() - 1;
			continue;
		}
		int spos = epos - e[s[epos]];

		int fspos = find(spos);
		if (fspos - spos + 1 > str.length()){
			epos = fspos;
			continue;
		}
			
		if (ok(str, spos)){
			filter(spos, str.length());
			epos = spos + str.length() - 1;
		}
		else{
			epos = spos + str.length() - 1;
		}
	}
}

int main(){

	//text();
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> data[i];
	cin >> s;
	len = 0;
	while (s[len]){
		f[len] = len;
		len++;
	}
	for (int i = 1; i <= N; ++i)
		match(data[i]);

	for (int i = 0; i < len; ++i){
		if (Filter[i])
			putchar('*');
		else
			putchar(s[i]);
	}
	cout << endl;
	return 0;
}