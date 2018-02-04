#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	string name;
	int id;
	bool operator<(const Node& p)const{
		if (name != p.name)
			return name < p.name;
		else
			return id < p.id;

	}
}data[110];


int main(){
	//ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		string s;
		cin >> s;
		int j;
		for (j = 0; j < s.length();++j)
		if (s[j] >= '0' && s[j] <= '9')
			break;
		data[i].name = s.substr(0, j);
		data[i].id = 0;
		for (; j < s.length(); ++j)
			data[i].id = data[i].id * 10 + s[j] - '0';
	}
	sort(data, data + N);
	for (int i = 0; i < N; ++i)
		cout << data[i].name<< data[i].id << endl;














	return 0;
}