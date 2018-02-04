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
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
long long coin[100010][2];
long long N, aim;

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;
	long long sum = 0;
	for (int i = 0; i < N; ++i){
		in >> coin[i][0] >> coin[i][1];
		sum += coin[i][0];
		sum += coin[i][1];
	}
	
	aim = sum / N / 2;
	long long ans = 0;
	for (int i = 0; i < N; ++i){
		if (coin[i][0] > aim){
			long long duo = coin[i][0] - aim;
			ans += duo;
			long long downneed = aim - coin[i][1];
			long long chan = min(duo, downneed);
			if (chan > 0){
				coin[i][0] -= chan;
				coin[i][1] += chan;
				duo = coin[i][0] - aim;
			}
			if (duo > 0){
				coin[i][0] -= duo;
				coin[i + 1][0] += duo;
			
			}
		}
		else if (coin[i][0] < aim){
			long long shao = aim - coin[i][0];
			ans += shao;
			long long downduo = coin[i][1] - aim;
			long long chan = min(shao, downduo);
			if (chan > 0){
				coin[i][0] += chan;
				coin[i][1] -= chan;
				shao = aim - coin[i][0];
			}
			if (shao > 0){
				coin[i][0] += shao;
				coin[i + 1][0] -= shao;
			}
		}

		
		coin[i + 1][1] += coin[i][1] - aim;
		ans += abs(coin[i][1] - aim);
		coin[i][1] = aim;
	}

	cout << ans << endl;


	return 0;
}





