#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> vs;
int N;


bool cmp(const string& s1, const string& s2){
	return s1.size() < s2.size();
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		vs.clear();
		cin >> N;
		for (int i = 0; i < N; ++i){
			string temp;
			cin >> temp;
			vs.push_back(temp);
		}
		sort(vs.begin(), vs.end(), cmp);
		int MAXLEN = vs[0].size();
		int ans;
		for (ans = MAXLEN; ans >= 0; --ans)
			for (int i = 0; i + ans <= MAXLEN; ++i){
				string now = vs[0].substr(i, ans);
				string tnow(now.rbegin(), now.rend());
				bool FLAG = 1;
				for (int j = 1; j < N; ++j){
					int k;
					for (k = 0; k < vs[j].size(); ++k){
						string tt = vs[j].substr(k, ans);
						if (now == tt||tnow==tt)
							break;
					}
					if (k>=vs[j].size()){
						FLAG = 0;
						break;
					}
				}
				if(FLAG)
					goto end;
				
			}
		end:
			cout << ans << endl;
	}





	return 0;
}