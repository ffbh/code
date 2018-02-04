#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;
vector<string> vs;
stringstream ss;
int num[1010][30];
bool ok[1010];


bool equal(int a,int b){
	for (int i = 0; i < 30;++i)
	if (num[a][i] != num[b][i])
		return 0;
	return 1;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string s;
	while (getline(in, s) && s != "#"){
		ss.clear();
		ss.str(s);
		while (ss >> s){
			vs.push_back(s);
		}
	}

	sort(vs.begin(), vs.end());
	for (int i = 0; i < vs.size(); ++i){
		for (int j = 0; j < vs[i].length(); ++j){
			char code = vs[i][j];
			if (isupper(code)){
				code += 32;
			}
			num[i][code - 'a']++;
		}
	}


	for (int i = 0;i<vs.size();++i)
	for (int j = i + 1; j < vs.size(); ++j){
		if (equal(i,j)){
			ok[i]=ok[j] = 1;
		}
	}

	for (int i = 0; i < vs.size(); ++i){
		if (!ok[i]){
			cout << vs[i] << endl;
		}
	}



	return 0;
}