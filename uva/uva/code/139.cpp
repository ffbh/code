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
stringstream ss;
struct Node{
	string name;
	double price;
	Node(string str){
		int pos;
		for (int i = 0; i < str.length(); ++i){
			if (str[i] == '$'){
				pos = i;
				str[pos] = ' ';
			}
		}
		ss.clear();
		name = str.substr(0, pos);
		ss.str(str.substr(pos+1));
		ss  >> price;
		price /= 100.0;
	}
};

struct ZDTree{
	int next[11];
	bool ok;
	Node* p;
}data[1000010];
int size, root;

void tle(){
	double p = 1.70;
	for (int i = 0; i < 1e10; ++i)
		p = pow(p, p);
	p *= p;
}

int MALLOC(){
	data[size].ok = 0;
	for (int i = 0; i < 11; ++i)
		data[size].next[i] = -1;
	data[size].p = 0;
	return size++;
}


void Insert(string& s, string& str){
	int p = root;
	for (int i = 0; i < s.length(); ++i){
		

		int id = s[i]-'0' ;
		
		if (data[p].next[id] == -1){
			data[p].next[id] = MALLOC();
		}
		p = data[p].next[id];
	}
	data[p].ok = 1;
	data[p].p = new Node(str);
}
int sublen;

Node* query(string& s){
	int p = root;
	sublen = 0;
	for (int i = 0; i < s.length(); ++i){
		
		if (data[p].ok){
			bool ok = 0;
			if (s[1] == '0'){
				if (s.length() - sublen >= 4 && s.length() - sublen <= 10)
					ok = 1;
			}
			else{
				if (s.length() - sublen >= 4 && s.length() - sublen <= 7)
					ok = 1;
			}

			if (ok){
		//		cout << s.length() - sublen << endl;
				return data[p].p;
			}
		}
		int id = s[i] -'0';
		if (data[p].next[id] == -1){
			return NULL;
		}
		p = data[p].next[id];
		sublen++;
	}
	return NULL;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	size = 1;
	root = MALLOC();
	string s1, s2;
	while (in >> s1 && s1 !="000000"){
		getline(in, s2);
		Insert(s1, s2);
	}
	string unknown = "Unknown";
	string local = "Local";
	while (unknown.length() < 35)
		unknown += " ";
	int time;/////////shijian zhengshu keneg fudian
	while (in >> s1 && s1 != "#"){
		in >> time;
		if (s1[0] != '0'){
			string tmp = local;
			while (tmp.length() + s1.length() < 35)
				tmp += ' ';
			tmp += s1;
			while (s1.length() < 16)
				s1 += ' ';
			cout << s1;
			cout << tmp;
			printf("%5d", time);
			printf("%6.2f", 0.0);
			printf("%7.2f\n", 0.0);
			continue;
		}


		Node* ptr = query(s1);
		if (ptr == NULL){
			while (s1.length() < 16)
				s1 += ' ';
			cout << s1;
			cout << unknown;
			printf("%5d", time);
			printf("      ");
			printf("%7.2f\n", -1.0);
		}
		else{
			string name = ptr->name;
			string number = s1.substr(sublen);

			while (name.length() + number.length() < 35)
				name += ' ';
			while (s1.length() < 16)
				s1 += ' ';
			cout << s1;
			cout << name;
			cout << number;
			printf("%5d", time);
			printf("%6.2f", ptr->price);
			printf("%7.2f\n", time*ptr->price);
		}
	}



	return 0;
}