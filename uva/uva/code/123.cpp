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
using namespace std;
struct Node{
	string s, key;
	int input_idx, inner_idx;

	bool operator<(const Node& p)const{
		if (key != p.key)
			return key < p.key;
		else if (input_idx != p.input_idx)
			return input_idx < p.input_idx;
		else
			return inner_idx < p.inner_idx;
	}
}data[40010];
int size;
unordered_set<string> usi;
string str;

void lower(string& s){
	for (int i = 0; i < s.length(); ++i){
		if (isupper(s[i]))
			s[i] += 32;
	}
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;

	size = 0;
	while (in >> str && str !="::"){
		lower(str);
		usi.insert(str);
	}
	getline(in, str);
	int idx = 0;
	while (getline(in, str)){
		idx++;
		lower(str);
		int a, b;
		a = 0;
		int inneridx = 0;
		while (a < str.length()){
			inneridx++;
			while (a<str.length() && str[a] == ' ')
				a++;
			b = a;
			while (b< str.length() &&  str[b] != ' ')
				b++;
			string tmp = str.substr(a, b-a);
			if (b != str.length())
					b--;
			if (!usi.count(tmp)){
				for (int k = a; k <= b; ++k)
					str[k] -= 32;
				
				data[size].key = tmp;
				data[size].s = str;
				data[size].input_idx = idx;
				data[size].inner_idx = inneridx;
				size++;
				for (int k = a; k <= b; ++k)
					str[k] += 32;
			}
			a = b + 1;
		}
		
	}
	sort(data, data + size);
	for (int i = 0; i < size; ++i)
		printf("%s\n", data[i].s.c_str());


	return 0;
}