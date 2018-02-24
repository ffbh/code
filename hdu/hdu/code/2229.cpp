#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream in("C:\\temp.txt");
map<string, int> msi; 
vector<int> vi[300];
vector<int> V;
bool vis[300];
int cnt;
int getInput(){
	string s;
	in >> s;
	if (!msi[s])
		msi[s] = cnt++;
	return msi[s];
}


int main(){
	int N;
	while (cin >> N){
		




	}








	return 0;
}