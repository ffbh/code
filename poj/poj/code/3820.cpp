#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
string s;
vector<string> vi;

bool IsPtext(){
	for (int i = 0; i < s.length(); ++i)
		if (s[i]<32 || s[i]>127 || s[i] == '<' || s[i] == '>' || s[i] == '&')
			return 0;
	return 1;
}

void decode(){
	for (int i = 0; i < s.length();++i)
	if (s[i] == '&'){
		if (i + 3 < s.length() ){
			if (s[i + 3] == ';'&&s[i + 2] == 't' && (s[i + 1] == 'l' || s[i + 1] == 'g'))
				s[i] = s[i + 1] = s[i + 2] = s[i+3] = ' ';
		}
		if (i + 4 < s.length()){
			if (s[i + 1] == 'a'&&s[i + 2] == 'm'&&s[i + 3] == 'p'&&s[i + 4] == ';')
				s[i] = s[i + 1] = s[i + 2] = s[i + 3] = s[i+4] = ' ';
		}
	}
}

bool isHexadecimal(string& ss){
	if (ss.length() % 2 != 0)
		return 0;
	bool f;
	for (int i = 0; i < ss.length(); ++i){
		f = 0;
		if (ss[i] >= '0'&&ss[i] <= '9')
			f = 1;
		if (ss[i] >= 'a' && ss[i] <= 'f')
			f = 1;
		if (ss[i] >= 'A'&&ss[i] <= 'F')
			f = 1;
		if (!f)
			return 0;
	}
	return 1;
}


bool Isloweralphanumeric(string& ss){
	bool f;
	for (int i = 0; i < ss.length(); ++i){
		f = 0;
		if (ss[i] >= '0'&&ss[i] <= '9')
			f = 1;
		if (ss[i] >= 'a'&&ss[i] <= 'z')
			f = 1;
		if (!f)
			return 0;
	}
	return 1;
}


int decodelt(int start){
	int end = -1;
	for (int i = start; i < s.length();++i)
	if (s[i] == '>'){
		end = i;
		break;
	}
	return end;
}



bool xml(){
	decode();
	if (IsPtext())
		return 1;
	int nowindex = 0;
	while (nowindex < s.length()){
		if (s[nowindex] == '<'){
			int end = decodelt(nowindex);
			if (end == -1)
				return 0;
			string tag = s.substr(nowindex + 1, end - nowindex - 1);
			if (tag.length() == 0)
				return 0;
	
			if (tag[0] == '/'){
				string tmp = tag.substr(1);
		
				if (!Isloweralphanumeric(tmp))
					return 0;
				if (vi.empty() || vi.back() != tmp)
					return 0;
				vi.pop_back();
			}
			else if (tag[tag.length() - 1] == '/'){
				string tmp = tag.substr(0,tag.length()-1);
		
				if (!Isloweralphanumeric(tmp))
					return 0;
			}
			else{
			
				if (!Isloweralphanumeric(tag))
					return 0;
				vi.push_back(tag);
			}
			nowindex = end + 1;
		}
		else if (s[nowindex] == '&'){
			if (nowindex + 1 >= s.length())
				return 0;
			if (s[nowindex + 1] == 'x'){
				int end = nowindex + 1;
				while (end < s.length() && s[end] != ';')
					end++;
				if (end >= s.length())
					return 0;
				string str = s.substr(nowindex + 2, end - nowindex - 2);
				if (str.length()==0||!isHexadecimal(str))
					return 0;
				nowindex = end + 1;
			}
			else
				return 0;
		}
		else if (s[nowindex] == '>')
			return 0;
		else
			nowindex++;
	}
	return 1;
}



int main(){
	ifstream in("C:\\input.txt");
	while (getline(cin, s)){
		vi.clear();
		if (!xml())
			cout << "invalid" << endl;
		else if (vi.size())
			cout << "invalid" << endl;
		else
			cout << "valid" << endl;




	}





	return 0;
}