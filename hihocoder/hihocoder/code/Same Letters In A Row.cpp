#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int K;
string s;
int data[100010], size;
int getMaxconsectiveOf(char c){
	int sum = 0;
	int pos = 0;
	while (pos < s.length() && s[pos] != c){
		pos++;
	}
	if (pos == s.length())
		return 0;
	size = 0;
	bool f = 1;
	int num = 0;
	while (pos < s.length()){
		if (s[pos] == c)
			sum++;
		if (f&&s[pos] == c){
			num++;
		}
		else if (!f &&s[pos] != c){
			num++;
		}
		else{
			data[size++] = num;
			f = !f;
			num = 1;
		}
		pos++;
	}
	data[size++] = num;
	if (size % 2 == 0)
		size--;
	if (K >= sum)
		return sum;
	int ans = 0, now = 0, nowK = K;
	pos = 0;
	int spos = pos + 1;
	while (pos < size){
		if (pos % 2 == 0){
			now += data[pos];
		}
		else if (nowK >= data[pos]){
			nowK -= data[pos];
			now += data[pos];
		}
		else{
			if (ans < now)
				ans = now;
			if (data[pos] > K){
				now = 0;
				spos = pos + 2;
			}
			else{
				while (spos < pos && nowK < data[pos]){
					now -= (data[spos - 1] + data[spos]);
					nowK += data[spos];
					spos += 2;
				}
				pos--;
			}
		}
		pos++;
	}
	if (ans < now)
		ans = now;
	return min(ans, sum);
}



int main(){
	ifstream in("C:\\input.txt");
	cin >> K >> s;

	int ans = 0;
	for (char c = 'a'; c <= 'z'; ++c){
		int ret = getMaxconsectiveOf(c);
		ans = max(ans,ret);
	}
	cout << ans << endl;


	return 0;
}