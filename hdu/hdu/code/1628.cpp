#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <list>
using namespace std;
list<int> ll;
list<int>::iterator it,temp;
int getSurvive(int n, int k){
	it = ll.begin();
	while (ll.size() > 1){
		int time = k % ll.size();
		if (time == 0)
			time = ll.size();
		int start = *it;
		while (--time){
			it++;
			if (it == ll.end())
				it = ll.begin();
		}
		int dead = *it;
		if (ll.size() == 2){
			ll.erase(it);
			break;
		}


		it++;
		if (it == ll.end()){
			temp = ll.begin();
		}
		else{
			temp = it;
		}
		
		if (it == ll.begin()){
			it = --ll.end();
		}
		else
			it--;

		time = k % (ll.size() - 1);
		if (time == 0)
			time = ll.size() - 1;
		while (--time){
			temp++;
			if (temp == ll.end())
				temp = ll.begin();
			if (*temp == dead)
				time++;
		}
		*it = *temp;
		int bury = *it;
		ll.erase(temp);
		it = ll.begin();
		
		it = ll.begin();
		while (*it != bury) it++;
		it++;
		if (it == ll.end())
			it = ll.begin();

	}
	return ll.back();
}

int main(){
	ifstream in("C:\\input.txt");
	int n, k;
	while (cin >> n >> k&&n + k){
		ll.clear();
		for (int i = 1; i <= n; ++i)
			ll.push_back(i);
		int surv = getSurvive(n, k);

		int move = (n + 1 - surv)%n;
		cout << (1 + move) << endl;

		



	}
















	return 0;
}