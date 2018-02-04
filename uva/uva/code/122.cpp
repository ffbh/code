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
struct Node{
	int val;
	string pace;
	bool operator<(const Node& p){
		if (pace.length() != p.pace.length())
			return pace.length() < p.pace.length();
		return pace < p.pace;
	}
}data[300];
int size;

stringstream ss;

bool build(string& s){
	if (s == "()")
		return 0;

	for (int i = 0; i < s.length();++i)
	if (s[i] == '(' || s[i] == ')' || s[i] == ','){
		s[i] = ' ';
	}

	ss.clear();
	ss.str(s);

	ss >> data[size].val;
	data[size].pace = "";
	ss >> data[size].pace;
	size++;
	return 1;
}

bool judge(){
	if (size && data[0].pace.length() != 0)
		return 0;
	for (int i = 0; i < size;++i)
	for (int j = 0; j < size; ++j){
			if (i != j &&data[i].pace == data[j].pace)
				return 0;
		}
	for (int i = 1; i < size; ++i){
		
		string str = data[i].pace.substr(0, data[i].pace.length() - 1);
		bool ok = 0;
		for (int j = 0; j < i; ++j){
			if (data[j].pace == str){
				ok = 1;
				break;
			}

		}
		if (!ok)
			return 0;


	}
	return 1;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	string s;
	while (in >> s){
		size = 0;
		while (build(s)){
			in >> s;
		}
		sort(data, data + size);
		if (judge()){
			for (int i = 0; i < size - 1; ++i)
				cout << data[i].val << " ";
			if (size)
				cout << data[size - 1].val;
			cout << endl;
		}
		else{
			cout << "not complete" << endl;
		}
		
	}
	return 0;
}