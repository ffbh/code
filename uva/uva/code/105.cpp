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
struct Node{
	int l, h, r;
}data[5010];
int size;
int h[10010];
bool f;
void op(int a,int b){
	if (f){
		printf(" %d %d", a, b);
	}
	else{
		f = 1;
		printf("%d %d", a, b);
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	size = 0;
	f = 0;
	while (in >> data[size].l){
		in >> data[size].h >> data[size].r;
		size++;
	}
	
	for (int i = 0; i < size; ++i){
		for (int j = data[i].l; j < data[i].r; ++j)
			h[j] = max(h[j], data[i].h);
	}

	int pos = 0;
	while (pos < 10010 && h[pos] == 0)
		pos++;

	while (pos < 10010){
		op(pos, h[pos]);
		int now = h[pos];
		while (pos < 10010 && now == h[pos])
			pos++;
	}
	cout << endl;

	return 0;
}