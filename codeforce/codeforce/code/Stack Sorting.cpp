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
#include <stack>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int n, k;
int a[200010];


void input(){
	in >> n >> k;
	for (int i = 1; i <= k; ++i)
		in >> a[i];


}

bool vis[200010];

bool stack_sort(){
	stack<int> S;
	int can = 1;
	for (int i = 1; i <= k; ++i){
		vis[a[i]] = 1;
		if (S.empty()){
			S.push(a[i]);
		}
		else{
			if (S.top() < a[i])
				return 0;
			S.push(a[i]);
		}
		while (!S.empty() &&S.top() == can){
			S.pop();
			can++;
		}
	}
	int len = k + 1, pos;
	while (!S.empty()){
		pos = S.top();
		while (pos >= can){
			if (!vis[pos]){
				vis[pos] = 1;
				a[len++] = pos;
			}
			pos--;
		}
		can = S.top() + 1;
		S.pop();
	}
	pos = n;
	while (pos >= can){
		if (!vis[pos]){
			vis[pos] = 1;
			a[len++] = pos;
		}
		pos--;
	}

	return 1;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (stack_sort()){
			for (int i = 1; i <= n; ++i)
				printf("%d ", a[i]);
			cout << endl; 
		}
		else{
			cout << -1 << endl;
		}












	}


	return 0;
}





