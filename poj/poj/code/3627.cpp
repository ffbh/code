
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
long long data[20010];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	long long B;
	cin >> N >> B;
	for (int i = 0; i < N; ++i)
		cin >> data[i];
	sort(data, data + N);
	int ans = 0;
	long long sum = 0;
	for (int i = N - 1; sum<B&&i>=0; --i, ++ans)
		sum += data[i];
	cout << ans << endl;








	return 0;
}
