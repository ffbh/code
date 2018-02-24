#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
using namespace std;
int map[100010], N, M, src[100010],  s,e;

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> map[i];
		src[i] = map[i];
	}
	sort(map, map + N);
	for (int i = 0; i < N; ++i){
		if (src[i] != map[i]){
			s = i - 1;
			break;
		}
	}
	for (int i = N - 1; i >= s&&i >= 0; --i){
		if (src[i] != map[i]){
			e = i + 1;
			break;
		}

	}
	cout << e - s - 1<< endl;
	
		



















	return 0;
}