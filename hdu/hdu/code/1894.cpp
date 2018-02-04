#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
string data[50010];

/*bool cmp(const string& s1, const string& s2){
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	return s1 < s2;

}*/


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	int N;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		sort(data, data + N);
		int ans = 0;
		for (int i = 0; i < N;++i)
		for (int j = i+1; j < N;++j)
		if (data[i].length() < data[j].length()){
			if (data[i] == data[j].substr(0, data[i].length()))
				ans++;
			else break;
		}
		if (ans>11519)
			cout << ans % 11519 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}