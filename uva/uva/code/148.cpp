#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

struct Node{
	string str;
	int num[30];
}data[2010];
stringstream ss;
int size;
int h[30];
int tmp[30];
vector<int> ans;
string str;
int judge(){//-1 nolegal   0 not match   1  ok
	bool ok = 1;
	for (int i = 0; i < 30; ++i){
		if (h[i] != tmp[i]){
			ok = 0;
		}
		if (h[i] < tmp[i])
			return -1;
	}
	return ok;
}


bool ok_judge(){
	ss.clear();
	ss.str(str);
	string t;
	unordered_set<string> usi;
	for (int i = 0; i < ans.size(); ++i)
		usi.insert(data[ans[i]].str);
	while (ss >> t){
		if (usi.count(t))
			return 0;
	}
	
	return 1;

}
//ofstream ou("C:\\input2.txt");
void dfs(int pos){
	int ret = judge();
	if (ret == -1)
		return;
	else if (ret == 1){
		if (ok_judge()){
			printf("%s =", str.c_str());
		//	ou << str << " ";
			for (int i = 0; i < ans.size(); ++i){
				printf(" %s", data[ans[i]].str.c_str());
			//	ou << " " << data[ans[i]].str;
			}
			putchar('\n');
		//	ou << endl;
			


		}
		return;
	}
	if (pos == size)
		return ;
	
	for (int i = pos; i < size; ++i){
		for (int k = 0; k < 30; ++k)
			tmp[k] += data[i].num[k];
		ans.push_back(i);
		dfs(i + 1);
		ans.pop_back();
		for (int k = 0; k < 30; ++k)
			tmp[k] -= data[i].num[k];
		

	}
}



int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	size = 0;

	while (getline(in , data[size].str) && data[size].str != "#"){
	
		for (int i = 0; i < 30; ++i)
			data[size].num[i] = 0;
		string &s = data[size].str;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] != ' '){
				data[size].num[s[i] - 'A']++;
			}
		}
		size++;
	}
	//getline(in, str);
	while (getline(in,str) &&str != "#"){
		for (int i = 0; i < 30; ++i)
			h[i] = tmp[i] = 0;
		ans.clear();
		for (int i = 0; i < str.length(); ++i){
			if (str[i] != ' '){
				h[str[i] - 'A']++;
			}
		}

	
		dfs(0);

	}

	return 0;
}