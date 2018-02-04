#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;
bool pace[1010];
int size;
string s1, s2;
stack<char> sc;
void dfs(int p1, int p2,int p){

	if (p == size&&sc.empty()){
		for (int i = 0; i < size-1;++i)
			if (pace[i])
				printf("i ");
			else
				printf("o ");
		if (pace[size-1])
			printf("i ");
		else
			printf("o ");
		cout << endl;
		return;
	}
	if ((sc.empty()||sc.top() != s2[p2])&&p1<size/2){
		sc.push(s1[p1]);
		pace[p] = 1;
		dfs(p1 + 1, p2, p + 1);
		sc.pop();
	}
	else if (!sc.empty() && sc.top() == s2[p2]){
		if (p1 < size / 2){
			sc.push(s1[p1]);
			pace[p] = 1;
			dfs(p1 + 1, p2, p + 1);
			sc.pop();
		}

		char t = sc.top();
		sc.pop();
		pace[p] = 0;
		dfs(p1, p2 + 1, p + 1);
		sc.push(t);
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	
	string ts1, ts2;
	while (getline(cin,s1)){
		getline(cin, s2);
		cout << "[" << endl;
		//while (!sc.empty())
		//	sc.pop();
		ts1 = s1;
		ts2 = s2;
		sort(ts1.begin(), ts1.end());
		sort(ts2.begin(), ts2.end());
		if (ts1 == ts2){
			size = s1.size() * 2;
			dfs(0, 0, 0);
		}
		cout << "]" << endl;


	}
	return 0;
}