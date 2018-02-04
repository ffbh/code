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
int T, N, Q;
unordered_map<string, int> usi;
string name[210];
int quy[210][210];
int tmp[210];
int C;
void Init(){
	usi.clear();
	memset(quy, 0, sizeof(quy));
}

bool eq(int* a,int * b,int num){
	for (int i = 1; i <= num;++i)
	if (*(a + i) != *(b + i))
		return 0;
	return 1;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> T;
	while (T-- > 0){
		Init();


		in >> N >> Q;
		in >> C;
		for (int i = 1; i <= C; ++i){
			in >> name[i];
			usi[name[i]] = i;
		}

		for (int i = 1; i <= Q; ++i){
			int t;
			in >> t;
			while (t-- > 0){
				string s;
				in >> s;
				quy[usi[s]][i] = 1;
			}
		}

		while (N-- > 0){
			for (int i = 1; i <= Q; ++i)
				in >> tmp[i];

			int num = 0;
			int ans;
			for (int i = 1; i <= C; ++i){
				if (eq(tmp, quy[i], Q)){
					num++;
					ans = i;
				}
			}
			if (num == 1){
				cout << name[ans] << endl;
			}
			else{
				cout << "Let's go to the library!!" << endl;
			}
		}




	}
















	return 0;
}





