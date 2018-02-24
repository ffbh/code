#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
vector<int> vi;

bool judge(int time,int cycle){
	time %= (cycle * 2);
	return time < cycle - 5;
}

bool bothgreen(int time){
	for (int i = 0; i < vi.size(); ++i){
		if (!judge(time, vi[i]))
			return 0;
	}
	return 1;
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	int t1, t2, t3;
	while (in >> t1 >> t2 >> t3){
		if (t1 == 0 && t2 == 0 && t3 == 0)
			break;
		vi.clear();

		vi.push_back(t1);
		vi.push_back(t2);
		while (t3 != 0){
			vi.push_back(t3);
			in >> t3;
		}
		int mmin = 1111;
		for (int i = 0; i < vi.size(); ++i){
			mmin = min(mmin, vi[i]);
		}
		int start = mmin - 5;

		for (; start <= 5 * 60 * 60; ++start){
			if (bothgreen(start))
				break;
		}

		if (start > 5 * 60 * 60){
			cout << "Signals fail to synchronise in 5 hours" << endl;
		}
		else{
			int h = start / 3600;
			start %= 3600;
			int m = start / 60;
			int s = start % 60;

			printf("%02d:%02d:%02d\n", h, m, s);
		}

	}





	return 0;
}