#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
int dp[10010];

int main(){
	ifstream in("C:\\temp.txt");
	string s;
	int size = 1;
	int count;
	map<string, int> msi;
	while (cin >> s){
		msi.clear();
		size = 1;
		msi[s] = size++;
		while (cin >> s&&s != "#"){
			if (!msi[s])
				msi[s] = size++;
		}
		count = 0;
		dp[count++] = 0;//���⴦��ڶ�ƪ���ĸտ�ʼ�ͳ������һƪ���Ĳ�ͬ����
		while (cin >> s&&s != "#"){
			int id = msi[s];
			if (id == 0)
				continue;
			if (id > dp[count - 1])
				dp[count++] = id;
			else{
				*lower_bound(dp, dp + count, id) = id;
			}
		}
		cout << count - 1 << endl;
	}
	return 0;
}