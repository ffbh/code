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
#define pii pair<int,int>
vector<pii> A;
vector<int> B;
vector<int> P;
void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	int n;
	in >> n;
	for (int i = 1; i <= n; ++i){
		int type, k = -1;
		in >> type;
		if (type == 1 || type == 3){
			in >> k;
		}
		if (type == 5){
			type = 3;
			k = 11111111;
		}

		if (type % 2 == 0){
			B.push_back(type);
		}
		else{
			A.push_back(make_pair(type, k));
			if (type == 1){
				P.push_back(A.size() - 1);
			}
		}

	}

}

bool vis[200010];

int main(){
	input();


	int ans = 0;
	if (!B.empty()){
		bool drive = 0;
		for (int i = B.size() - 1; i >= 0; --i){
			if (B[i] == 2){
				drive = 1;
			}
			else if (B[i] == 4){
				drive = 0;
			}
			else{
				if (drive){
					ans++;
				}
			}
		}
	}
	

	for (int pos : P){
		int speed = A[pos].second;
		for (int i = pos + 1; i < A.size() && A[i].first != 1; ++i){
			if (A[i].first == 3){
				if (speed > A[i].second){
					if (!vis[i]){
						vis[i] = 1;
						ans++;
					}
				}
			}
		}
		
	}
	vector<int> S;
	for (int i = 0; i < A.size(); ++i){
		if (vis[i])
			continue;
		if (A[i].first == 1){
			while (!S.empty() && S.back() < A[i].second){
				S.pop_back();
				ans++;
			}

		}
		else{
			S.push_back(A[i].second);
		}
	}


	cout << ans << endl;

	return 0;
}





