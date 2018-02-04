#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int data[101][2];

int main(){
//	ifstream in("C:\\temp.txt");
	map<char, int> msi;
	msi['r'] = 1;
	msi['p'] = 2;
	msi['s'] = 0;
	int N, M;
	string s1, s2;
	int ok = 0;
	while (cin >> N >> M){
		if (ok)cout << endl;
		ok=1;
		memset(data, 0, sizeof(data));
		while (M--){
			int a, b;
			cin >> a >> s1 >> b >> s2;
			if (s1[0] == s2[0])
				continue;
			if ((msi[s1[0]] + 1) % 3 == msi[s2[0]]){
				data[a][0]++;
				data[b][1]++;
			}
			else{
				data[a][1]++;
				data[b][0]++;
			}
		}
		for (int i = 1; i <= N; ++i){
			if (data[i][0] + data[i][1]){
				printf("%.3f\n", double(data[i][1]) / (data[i][1] + data[i][0]));

			}
			else{
				putchar('-');
				putchar('\n');
			}
		}
	}
	return 0;
}