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
using namespace std;
#define DEBUG (0)
struct Node{
	int in, id;
	bool operator<(const Node& p)const{
		if (in != p.in)
			return in > p.in;
		else{
			return id < p.id;
		}
	}
}data[110];


int N;
bool  p[110][110];
class ScoresSequence {
public:
	int count(vector <int> s) {
		N = s.size();
		sort(s.begin(), s.end());
		memset(data, 0, sizeof(data));
		memset(p, 0, sizeof(p));
		for (int i = 0; i < N; ++i){
			data[i].in = N - 1 - s[i];
			data[i].id = i;
		}
		for (int i = N - 1; i >= 0; --i){
			sort(data, data + N);
			for (int j = 0; j < N && s[i] > 0; ++j){
				if (data[j].id == i){
					continue;
				}
				s[i]--;
				p[i][data[j].id] = 1;
				data[j].in--;
			}
		}
		for (int i = 0; i < N; ++i)
			p[i][i] = 1;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		for (int k = 0; k < N; ++k){
			if (p[j][i] && p[i][k])
				p[j][k] = 1;
		}

		int ans = 0;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		if (p[i][j])
			ans++;
		return ans;


	}
};



#if 1
int main(){
	vector<int> p({ 4,4,4,4,4,4,4,4,4 });
	ScoresSequence so;
	cout << so.count(p) << endl;
















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
