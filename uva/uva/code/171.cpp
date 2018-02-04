#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;
string str;
stack<int> ss;
int e[100];

string GetNext(int& pos){
	while (pos < str.length() &&str[pos] == ' ')
		pos++;
	if (pos == str.length()){
		return "";
	}
	string ret = "";
	if (str[pos] == '\"'){
		ret = str.substr(pos, e[pos] - pos + 1);
		ss.push(pos);
		pos = e[pos] + 1;
	}
	else{
		int epos = pos;
		while (epos < str.length() && str[epos] != ' ')
			epos++;
		ret = str.substr(pos, epos - pos);
		ss.push(pos);
		pos = epos;
	}
	return ret;
}

void getPre(int& pos){
	pos = ss.top();
	ss.pop();
}

bool judgeDigits(string& s){
	for (int i = 0; i < s.length();++i)
	if (!isdigit(s[i]))
		return 0;
	return 1;
}

bool fjudge(){
	string s = "";
	int num = 0;
	for (int i = 0; i < str.length(); ++i){
		if (str[i] == ' '){
			if (!s.empty() && s.back() != ' '){
				s += ' ';
			}

		}
		else if (isupper(str[i]) || str[i] == '.' || isdigit(str[i]) || str[i] == '\"'){
			if (str[i] == '\"'){
				num++;
			}
			s+= str[i];
		}
		else{
			return 0;
		}
	}
	str = s;
	return num%2==0;
}

bool IsNavigation(int pos){
	string p;
	p = GetNext(pos);
	if (p == "GO"){
		p = GetNext(pos);
		if (p == "FIRST" || p == "SECOND" || p == "THIRD"){
			p = GetNext(pos);
		}
	}
	else if (p == "KEEP"){
		p = GetNext(pos);
	}
	else{
		return 0;
	}
	if (p == "RIGHT" || p == "LEFT"){
		p = GetNext(pos);
	}
	else{
		return 0;
	}

	if (p == "AT"){
		p = GetNext(pos);
		if (p[0] == '\"'){
			p = GetNext(pos);
		}
		else
			return 0;
	}


	if (p == "AND"){
		p = GetNext(pos);
		if (p == "THEN"){
			return IsNavigation(pos);
		}
		else{
			return 0;
		}
	}
	else if (p == ""){
		return 1;
	}
	else{
		return 0;
	}

}


bool isTimekeep(int pos){
	string p;
	p = GetNext(pos);
	if (p == "RECORD"){
		p = GetNext(pos);
		if (p == "TIME"){
			p = GetNext(pos);
			return p == "";
		}
		else{
			return 0;
		}
	}
	else{
		if (p == "CAS"){
			p = GetNext(pos);
		}
		else if(p=="CHANGE"){
			p = GetNext(pos);
			if (p == "AVERAGE"){
				p = GetNext(pos);
				if (p == "SPEED"){
					p = GetNext(pos);
				}
				else{
					return 0;
				}
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}

		if (p == "TO"){
			p = GetNext(pos);
			if (judgeDigits(p)){
				p = GetNext(pos);
				if (p == "KMH"){
					p = GetNext(pos);
					return p == "";
				}
				else{
					return 0;
				}
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
}


bool judgeNT(int pos){
	string p;
	p = GetNext(pos);
	if (p == "GO"){
		p = GetNext(pos);
		if (p == "FIRST" || p == "SECOND" || p == "THIRD"){
			p = GetNext(pos);
		}
	}
	else if (p == "KEEP"){
		p = GetNext(pos);
	}
	else{
		return 0;
	}
	if (p == "RIGHT" || p == "LEFT"){
		p = GetNext(pos);
	}
	else{
		return 0;
	}

	if (p == "AT"){
		p = GetNext(pos);
		if (p[0] == '\"'){
			p = GetNext(pos);
		}
		else
			return 0;
	}


	if (p == "AND"){
		p = GetNext(pos);
		if (p == "THEN"){
			return judgeNT(pos);
		}
		else{
			getPre(pos);
			return isTimekeep(pos);
		}
	}
	else {
		return 0;
	}

}
	ofstream ou("C:\\input2.txt");
void output(){
	bool kp = 0;
	for (int i = 0; i < str.length(); ++i){
		if (!kp){
			if (str[i] == ' '){
				if (i + 1 < str.length()){
					cout << str[i];
					ou << str[i];
				}
			}
			else{
				cout << str[i];
				ou << str[i];
			}
		}
		else{
			if (str[i] !=' ' ||(i + 1 < str.length() && str[i + 1] != '\"' && str[i - 1] != '\"')){
				cout << str[i];
				ou << str[i];
			}
		}
		if (str[i] == '\"'){
			kp = 1 - kp;
		}

	}
	cout << endl;
	ou << endl;
}

bool wordjudge(int a,int b){
	for (int i = a; i <= b;++i)
	if (str[i] == '.' || isupper(str[i]))
		return 1;
	return 0;
}

int main(){
	//ifstream in("C:\\input.txt");

	istream& in = cin;
	int CASE = 1;
	while (getline(in, str) && str != "#"){
		while (!ss.empty())
			ss.pop();
		bool ok = 1;
		if (!fjudge()){
			ok = 0;
		}
		else{
			int start = -1;
			for (int i = 0; i < str.length(); ++i){
				if (str[i] == '\"'){
					if (start == -1){
						start = i;
					}
					else{
						if (!wordjudge(start,i)){
							ok = 0;
							break;
						}
						e[start] = i;
						start = -1;
					}
				}
				else if (isdigit(str[i])){
					if (start != -1){
						ok = 0;
						break;
					}
				}
			}
			if (ok){
				if (IsNavigation(0) || isTimekeep(0) || judgeNT(0)){

				}
				else{
					ok = 0;
				}
			}

		}
		ou << setw(3) << CASE << ". ";
		printf("%3d. ", CASE++);
		
		if (ok){
			output();
			
		}
		else{
			cout << "Trap!" << endl;
			ou << "Trap!" << endl;
		}
	}

	return 0;
}