#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int data[27];

int main(){
	ifstream in("C:\\temp.txt");
	string s;
	priority_queue<int,vector<int>,greater<int> > pi;
	while (cin >> s&&s!= "END"){
		while (!pi.empty())
			pi.pop();
		memset(data, 0, sizeof(data));
		for (int i = 0; i < s.length();++i)
		if (s[i] == '_')
			data[26]++;
		else
			data[s[i] - 'A']++;
		for (int i = 0; i < 27;++i)
		if (data[i])
			pi.push(data[i]);
		int sum;
		if (pi.size() == 1)
			sum = pi.top();
		else{
			sum = 0;
			int a, b;
			while (pi.size()>1){
				a = pi.top();
				pi.pop();
				b = pi.top();
				pi.pop();
				sum += (a + b);
				pi.push(a + b);
			}
			
		}
		printf("%d %d %.1f\n", s.length() * 8, sum, double(s.length() * 8) / sum);
	}
	return 0;
}