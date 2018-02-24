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
int n, a[1010], b[1010];

void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> n;

	for (int i = 1; i <= n; ++i)
		in >> a[i];

	for (int i = 1; i <= n; ++i)
		in >> b[i];

}
bool vis[1010];

int main(){
	input();

	vector<int> diff;
	for (int i = 1; i <= n; ++i){
		if (a[i] != b[i]){
			diff.push_back(i);
		}
		else{
			vis[a[i]] = 1;
		}
	}

	if (diff.size() == 1){
		
		int dig;
		for (int i = 1; i <= n; ++i){
			if (!vis[i]){
				dig = i;
				break;
			}
		}
		for (int i = 1; i <= n; ++i){
			if (a[i] == b[i]){
				cout << a[i] << " ";
			}
			else
				cout << dig << " ";
		}
	}
	else if (diff.size() == 2){
		int ka, kb;
		if (!vis[a[diff[0]]] && !vis[b[diff[1]]]){
			ka = a[diff[0]];
			kb = b[diff[1]];
		}
		else{
			ka = b[diff[0]];
			kb = a[diff[1]];
		}
		for (int i = 1; i <= n; ++i){
			if (a[i] == b[i]){
				cout << a[i] << " ";
			}
			else if (i == diff[0]){
				cout << ka << " ";
			}
			else{
				cout << kb << " ";
			}

		}
	}
	else{
		cout << "WA" << endl;
	}


	cout << endl;











	return 0;
}





