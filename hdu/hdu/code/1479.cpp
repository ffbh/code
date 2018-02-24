#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string data[20];

void inventory(int u){
	int temp[10] = { 0 };
	for (int i = 0; i < data[u - 1].length(); ++i)
		temp[data[u-1][i] - '0']++;
	data[u] = "";
	for (int i = 0; i < 10;++i)
	if (temp[i]){
		string t = "";
		while (temp[i]){
			t += char(temp[i] % 10+'0');
			temp[i] /= 10;
		}
		data[u] += string(t.rbegin(), t.rend());
		data[u] += char(i + '0');
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	bool flag;
	while (cin >> data[0] && data[0] != "-1"){
		flag = 0;
		for (int i = 1; i <= 15; ++i){
			inventory(i);
			int loop = -1;
			for (int j = i - 1; j >= 0; --j)
			if (data[i] == data[j]){
				loop = i - j;
			}
			if (loop > 0){
				if (loop == 1){
					if (i == 1){
						printf("%s is self-inventorying\n", data[0].c_str());
						flag = 1;
						break;
					}
					else{
						printf("%s is self-inventorying after %d steps\n", data[0].c_str(), i-1);
						flag = 1;
						break;
					}
				}
				else{
					printf("%s enters an inventory loop of length %d\n", data[0].c_str(), loop);
					flag = 1;
					break;
				}
			}
		}
		if (!flag)
			printf("%s can not be classified after 15 iterations\n", data[0].c_str());
	}
	return 0;
}