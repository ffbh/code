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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;


int n;
struct Node{
	LL d[5];
}data[1010];

bool judge(Node& A,Node& B,Node& C){
	LL sum = 0;
	for (int i = 0; i < 5; ++i){
		sum += (B.d[i] - A.d[i])*(C.d[i] - A.d[i]);
	}
	return sum <= 0;

}


void input(){
	in >> n;
	for (int i = 1; i <= n;++i)
	for (int j = 0; j < 5; ++j)
		in >> data[i].d[j];
}

bool test(int p){
	for (int i = 1; i <= n;++i)
	for (int j = i + 1; j <= n; ++j){
		if (i != p&&j != p&&!judge(data[p], data[i], data[j])){
			return 0;
		}


	}
	return 1;


}

int cale(){
	queue<int> qi;
	for (int i = 1; i <= n; ++i){
		qi.push(i);
	}

	while (qi.size()>2){
		int a = qi.front();
		qi.pop();
		int b = qi.front();
		qi.pop();
		int c = qi.front();
		qi.pop();
		if (judge(data[a], data[b], data[c])){
			qi.push(a);
		}
		else if (judge(data[b], data[a], data[c])){
			qi.push(b);
		}
		else if (judge(data[c], data[b], data[a])){
			qi.push(c);
		}
	}
	while (!qi.empty()){
		int top = qi.front();
		qi.pop();
		if (test(top))
			return top;
	}




	return -1;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (n <= 2){
			cout << n << endl;
			for (int i = 1; i <= n; ++i)
				cout << i << endl;
		}
		else{
			int ans = cale();
			if (ans != -1){
				cout << 1 << endl;
				cout << ans << endl;
			}
			else
				cout << 0 << endl;

		}













	}


	return 0;
}





