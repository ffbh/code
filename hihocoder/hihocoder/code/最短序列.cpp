#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int data[1000010],head;


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	int ans = N;
	head = -1;
	while (N--){
		int tmp;
		cin >> tmp;
		tmp %= 2;
		if (head == -1 || data[head] == tmp)
			data[++head] = tmp;
		else{
			ans -= 2;
			head--;
		}
	}
	cout << ans << endl;















	return 0;
}