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
int data[100010];
bool vis[100010];

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	int N;
	in >> N;
	for (int i = 1; i <= N; ++i){
		in >> data[i];
	
	}
	int ans = N;
	int tar = N;
	for (int i = N; i >= 1; --i){
		if (vis[tar])
			break;
		if (data[i] == tar){
			tar--;
			ans--;
		}
		vis[data[i]] = 1;
	}
	
	cout << ans << endl;












	return 0;
}