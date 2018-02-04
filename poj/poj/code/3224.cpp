#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int data[110][110];
int win[110];
int main(){
	ifstream in("C:\\input.txt");
	int  ans, N, maxsum = -1;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= N; ++j)
		cin >> data[i][j];
	for (int i = 1; i <= N;++i)
	for (int j = i + 1; j <= N;++j)
	if (data[i][j] > data[j][i])
		win[i]++;
	else
		win[j]++;
	for (int i = 1; i <= N;++i)
	if (win[i] > maxsum){
		maxsum = win[i];
		ans = i;
	}
	cout << ans << endl;
















	return 0;
}