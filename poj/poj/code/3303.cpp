#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
int T, R, K;
struct Node{
	int A, B;
	vector<int> vi;

	bool operator<(const Node& p)const{
		if (A != p.A)
			return A < p.A;
		else
			return B < p.B;
	}

}data[15];

vector<int> V[10];

bool dfs(int pos){
	if (pos == R)
		return 1;
	int A = data[pos].A;
	int B = data[pos].B;
	for (int i = 0; i < data[pos].vi.size(); ++i){
		int candidate = data[pos].vi[i];
		if (V[candidate].empty() || V[candidate].back() < A){
			V[candidate].push_back(B);
			if (dfs(pos + 1))
				return 1;
			V[candidate].pop_back();
		}
	}
	return 0;
}

void Init(){
	for (int i = 0; i < 10; ++i)
		V[i].clear();
	for (int i = 0; i < 15; ++i)
		data[i].vi.clear();
}

int main(){
//	ifstream in("C:\\input.txt");

	cin >> T;
	while (T--){
		Init();
		cin >> R;
		for (int i = 0; i < R; ++i){
			cin >> data[i].A >> data[i].B;
			cin >> K;
			while (K-- > 0){
				int t;
				cin >> t;
				data[i].vi.push_back(t);
			}
		}
		sort(data, data + R);
		if (dfs(0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;





	}
















	return 0;
}