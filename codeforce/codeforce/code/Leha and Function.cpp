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
int A[200010], m, ans[200010];
pair<int, int> B[200010];
void input(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> m;
	for (int i = 0; i < m; ++i)
		in >> A[i];
	for (int i = 0; i < m; ++i){
		in >> B[i].first;
		B[i].second = i;
	}

}


int main(){
	input();

	sort(A, A + m,greater<int>());

	sort(B, B + m);

	for (int i = 0; i < m; ++i){
		ans[B[i].second] = A[i];
	}

	for (int i = 0; i < m; ++i)
		printf("%d ", ans[i]);
	cout << endl;















	return 0;
}





