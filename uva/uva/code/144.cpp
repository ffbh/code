#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int N, K;
int rest[30];
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	while (in >> N >> K){
		if (N == 0 && K == 0)
			break;
		queue<int> qi;
		for (int i = 1; i <= N; ++i){
			qi.push(i);
			rest[i] = 40;
		}

		int nowK = 1;
		int machine = 1;
		while (!qi.empty()){
			int id = qi.front();
			qi.pop();

			if (rest[id] <= machine){
				machine -= rest[id];
				rest[id] = 0;
				printf("%3d", id);
			}
			else{
				rest[id] -= machine;
				machine = 0;
				
				qi.push(id);
			}
			if (machine == 0){
				if (nowK == K){
					nowK = 1;
				}
				else{
					nowK++;
				}

				machine = nowK;
			}
	/*		for (int i = 1; i <= 5; ++i){
				cout << rest[i] << " ";
			}
			cout << endl;*/

		}
		cout << endl;



	}















	return 0;
}