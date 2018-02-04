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
string s;

bool ok[266];
vector<int> vi;
int getI(){


	if (!ok[s.back()]){
		return 6;
	}
	if (s.length() == 1){
		return 1;
	}
	if (s.length() == 2){
		switch (s[0]){
		case 'g':
			return 2;
		case 'b':
			return 3;
		case 'd':
			return 4;
		case 'l':
			return 5;
		}
	}
	if (s.length() == 5){
		int key = 0;
		for (int i = 0; i < 5; ++i)
			key = key * 2 + ok[s[i]];
		if (key == 5 || key == 9)
			return 7;
	}
/*	double p = 1.0;
	for (int i = 0; i < 1e10; ++i){
		p = pow(p, p);
	}
	p *= p;*/

	return -1;
}

bool judgeStatement(vector<int>& v){
	int pos = 0;
	bool ok = 0;
	if (pos < v.size()){
		if (v[pos] == 6){
			ok = 1;
			pos++;
		}
		else if (pos + 1 < v.size()){
			if (v[pos] == 5 && v[pos + 1] == 7){
				pos += 2;
				ok = 1;
			}
		}
	}
	if (!ok)
		return 0;
	ok = 0;
	if (pos + 1 < v.size()){
		if (v[pos] == 2 && v[pos + 1] == 7){
			pos += 2;
			ok = 1;
		}
	}

	if (!ok)
		return 0;
	ok = 0;
	if (pos == v.size())
		return 1;
	if (pos < v.size()){
		if (v[pos] == 6){
			ok = 1;
			pos++;
		}
		else if (pos + 1 < v.size()){
			if (v[pos] == 5 && v[pos + 1] == 7){
				pos += 2;
				ok = 1;
			}
		}
	}
	return ok&&pos == v.size();
}



bool judgePredclaim(vector<int>& v){
	int pos = 0;
	bool ok = 0;
	if (pos < v.size()){
		if (v[pos] == 4){
			pos++;
			ok = 1;
		}
		else{
			bool tok = 0;
			if (v[pos] == 6){
				tok = 1;
				pos++;
			}
			else{
				if (pos + 1 < v.size()){
					if (v[pos] == 5 && v[pos + 1] == 7){
						tok = 1;
						pos += 2;
					}
				}

			}
			if (!tok)
				return 0;

			if (pos < v.size()){
				if (v[pos] == 3){
					pos++;
					ok = 1;
				}
			}
		}
	}
	if (!ok)
		return 0;

	while (pos < v.size()){
		if (v[pos] == 7){
			pos++;
			while (pos + 1 < v.size() && v[pos] == 1 && v[pos + 1] == 7){
				pos += 2;
			}
			return pos == v.size();
		}
		else
			return 0;

	}
	return 0;


}

bool clear(string & s){
	bool e = 0;
	for (int i = 0; i < s.length();++i)
	if (s[i] == '.'){
		e = 1;
		break;
	}
	if (e){
		string tmp = s;
		s = "";
		for (int i = 0; i < tmp.size(); ++i){
			if (islower(tmp[i])){
				s += tmp[i];
			}
		}
	}

	return e;
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	ok['a'] = ok['e'] = ok['i'] = ok['o'] = ok['u'] = 1;
	while (in>>s && s!="#"){
		vi.clear();
		bool p = 0;
		while (!p){
			p = clear(s);
			int ret = getI();
			if (vi.empty() || ret != 7 || vi.back() != 7)
				vi.push_back(ret);
			if (!p)
				in >> s;
		}
		getline(in, s);


	//	vector<int> vk({6,2,7,5});
	//	vi = vk;
	

		if (judgePredclaim(vi) || judgeStatement(vi)){
			cout << "Good" << endl;
		}
		else{
			cout << "Bad!" << endl;
		}
	}
	return 0;
}