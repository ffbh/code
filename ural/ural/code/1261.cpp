#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<unsigned int> usi;
unsigned int data[3000010], size;
vector<unsigned int> vi;
int N;
bool ok(int b){
	if (usi.count(b - N)){
		cout << b << " "<<b - N << endl;

		return 1;
	}
	else if (usi.count(b + N)){
		cout << b+N << " " << b  << endl;
		return 1;
	}
	return 0;
}

void cale(){
	long s = clock();
	long long k = 1;
	while (k <= int(3e7)+1){
		vi.push_back(k);
		k *= 3;
	}
	for (int i = 0; i < vi.size(); ++i){
		int oldsize = size;
		data[size] = vi[i];
		if (ok(data[size]))
			return;
		usi.insert(data[size++]);
		for (int j = 0; j < oldsize; ++j){
			data[size] = vi[i] + data[j];
			if (ok(data[size]))
				return;
			usi.insert(data[size++]);
		}
	}


	cout << clock() - s << endl;
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	cale();















	return 0;
}