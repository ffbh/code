#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
_int64 num[3];
bool Ok(){
	if (num[1])
		return num[0] + num[1] == num[2]
		|| num[0] - num[1] == num[2]
		|| num[0] * num[1] == num[2]
		|| num[0] % num[1] == num[2]
		|| (num[0] % num[1] == 0 && num[0] / num[1] == num[2]);
	else
		return num[0] + num[1] == num[2]
		|| num[0] - num[1] == num[2]
		|| num[0] * num[1] == num[2];

}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> num[0]){
		cin >> num[1] >> num[2];
		sort(num, num + 3);
		bool flag = Ok();
		while (!flag&&next_permutation(num, num + 3))
			flag = Ok();
		if (flag)
			cout << "oh,lucky!" << endl;
		else
			cout << "what a pity!" << endl;
	}
	return 0;
}