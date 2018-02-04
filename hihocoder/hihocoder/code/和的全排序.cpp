#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <list>
using namespace std;
long long data[1010],N;
list<int> ll;

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	long long  sum = 0;
	for (int i = 1; i <= N; ++i){
		cin >> data[i];
		sum += data[i];
	}

	if (sum < 0){
		cout << "Impossible" << endl;
	}
	else{
		for (int i = 1; i <= N; ++i)
			ll.push_back(i);
		sum = 0;
		list<int>::iterator it;
		while (!ll.empty()){
			it = ll.begin();
			while (data[*it] + sum < 0)
				it++;
			sum += data[*it];
			printf("%d ", *it);
			ll.erase(it);
		}
		cout << endl;
	}
	return 0;
}