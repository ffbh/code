#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
string good, pattern, str, L, R;
bool ok[266];
int N;

bool L_match(){
	for (int i = 0; i < L.length(); ++i){
		if (L[i] == '?'){
			if (!ok[str[i]])
				return 0;
		}
		else{
			if (L[i] != str[i])
				return 0;
		}
	}
	return 1;
}

bool R_match(){
	for (int i = 0; i < R.length(); ++i){
		int pos = str.length() - R.length() + i;
		if (R[i] == '?'){
			if (!ok[str[pos]])
				return 0;

		}
		else{
			if (R[i] != str[pos])
				return 0;

		}

	}
	return 1;
}


bool bad_judge(){
	int st = L.length();
	int en = str.length() - R.length();
	for (int i = st; i < en;++i)
	if (ok[str[i]])
		return 0;
	return 1;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> good >> pattern;

	for (char c : good){
		ok[c] = 1;
	}

	int pos = -1;
	for (int i = 0; i<pattern.size(); ++i){
		if (pattern[i] == '*'){
			pos = i;
			break;
		}
	}
	
	L = pattern.substr(0, pos);
	if (pos == -1){
		R = "";
	}
	else{
		R = pattern.substr(pos + 1);
	}

	in >> N;
	getline(in, str);
	while (N-- > 0){
		getline(in, str);
		if (L.length() + R.length() > str.length() || (pos==-1 && L.length() != str.length())){
			printf("NO\n");
			continue;
		}
		if (L_match() && R_match() && bad_judge())
			printf("YES\n");
		else
			printf("NO\n");
	}



	return 0;
}





