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
struct Node{
	int val;
	char op;
}data[10];
int size, aim;
int st[10], en[10], f[10];
bool vis[10];
char oper[] = { '+', '-', '*', '/' };
string s;

void PrintExpress(){
	for (int i = 0; i < size - 1; ++i){
		for (int j = 0; j < st[i];++j)
			putchar('(');
		printf("%d", data[i].val);
		for (int j = 0; j < en[i]; ++j)
			putchar(')');
		putchar(data[i].op);
	}
	printf("%d", data[size - 1].val);
	for (int j = 0; j < en[size-1]; ++j)
		putchar(')');
	putchar('\n');
}

bool cale(int rest){
	if (rest == 1){
		if (data[size - 1].val == aim){
			return 1;
		}
		return 0;
	}
	int next;
	for (int i = 0; i < size-1; ++i){
		if (vis[i])
			continue;
		next = i + 1;
		while (next < size &&vis[next]) 
			next++;
		if (next >= size)
			continue;

		int olddata = data[next].val;
		int pref = f[next];
		st[f[i]]++;
		en[next]++;
		f[next] = f[i];
		bool ok = 1;

		switch (data[i].op){
		case '+':
			data[next].val = data[i].val + data[next].val;
			break;
		case '-':
			data[next].val = data[i].val - data[next].val;
			break;
		case '*':
			data[next].val = data[i].val * data[next].val;
			break;
		case '/':
			if (data[next].val == 0){
				ok = 0;
			}
			else{
				data[next].val = data[i].val / data[next].val;
			}
			break;
		}
		if (ok){
			vis[i] = 1;
			if (cale(rest - 1)){
				data[next].val = olddata;
				return 1;
			}
			f[next] = pref;
			data[next].val = olddata;
			st[f[i]]--;
			en[next]--;
			vis[i] = 0;
		}
	}

	return 0;

}



bool dfs(int spos,int dpos){
	if (spos == s.length()){
		size = dpos;
		for (int i = 0; i < 10; ++i){
			vis[i] = st[i] = en[i] = 0;
			f[i] = i;
		}
		if (cale(size)){
			PrintExpress();
			return 1;
		}
	/*	cout << num++ << ":  ";
		for (int i = 0; i < size; ++i){
			cout << data[i].val << " " << data[i].op << " ";
		}
		cout << endl;
		num++;*/

		return 0;
	}
	int val = 0;
	for (int i = spos; i < s.length(); ++i){
		val = val * 10 + s[i] - '0';
		data[dpos].val = val;
		for (int k = 0; k < 4; ++k){
			data[dpos].op = oper[k];
			if (dfs(i + 1, dpos + 1))
				return 1;
		}
	}
	return 0;
}




int main(){
	ifstream in("C:\\input.txt");
	
	s = "8888888";
	aim = 9999999;
	long sd = clock();
	if (dfs(0, 0)){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	cout << clock() - sd << endl;

	return 0;
}

/*
4444 15
3684 16
8888888 9999999
*/