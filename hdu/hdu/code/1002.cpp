#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	int count;
	int i = 0;
	cin >> count;
	deque<int> d;
	string ts1;
	string ts2;
	int i1;
	int i2;
	int sum;
	string s1;
	string s2;
	while (count-->0){
		cin >> s1;
		cin >> s2;
		int lh1 = s1.length() - 1;
		int lh2 = s2.length() - 1;
		int flag = 0;

		while (lh1 >= 0 && lh2 >= 0){
			ts1 = s1.substr(lh1, 1);
			ts2 = s2.substr(lh2, 1);
			i1 = atoi(ts1.c_str());
			i2 = atoi(ts2.c_str());
			sum = i1 + i2 + flag;
			if (sum>9) {
				flag = 1;
				sum %= 10;
			}
			else flag = 0;
			d.push_front(sum);
			lh1--;
			lh2--;
		}
		while (lh1 >= 0){
			ts1 = s1.substr(lh1, 1);
			i1 = atoi(ts1.c_str());
			sum = i1 + flag;
			d.push_front(sum);
			flag = 0;
			lh1--;
		}
		while (lh2 >= 0){
			ts2 = s2.substr(lh2, 1);
			i2 = atoi(ts2.c_str());
			sum = i2 + flag;
			d.push_front(sum);
			flag = 0;
			lh2--;
		}
		if (flag)
			d.push_front(flag);
		cout << "Case " << ++i << ":" << endl;
		cout << s1 << " + " << s2 << " = ";
		copy(d.begin(), d.end(), ostream_iterator<int>(cout, ""));
		cout << endl;
		if (count != 0)
			cout << endl;
		d.clear();

	}





	return 0;
}