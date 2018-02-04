#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int X;
bool getOne(int t){
	int num = 0;
	for (int i = 0; i < 12;++i)
	if (t & (1 << i))
		num++;
	return num == X;
}

bool judgeOver(int t){
	return (t % 64) < 60 && (t / 64) < 24;
	
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> X;
	for (int i = 0; i <= 2048; ++i){
		if (getOne(i)&&judgeOver(i)){
			printf("%02d:%02d\n", i / 64, i % 64);
		}
	}
	return 0;
}