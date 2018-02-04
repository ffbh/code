#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
string name[30];
queue<int> qi[1010];
bool vis[30];
int N, size;

void eliminat(){
	for (int i = 1; i < size;++i)
	while (!qi[i].empty() && vis[qi[i].front()])
		qi[i].pop();
}

bool judgetie(){
	for (int i = 1; i <= N;++i)
	if (!vis[i])
		return false;
	return true;
}

int main(){
	ifstream in("C:\\input.txt");
	size = 1;
	in >> N;
	in.get();
	for (int i = 1; i <= N; ++i)
		getline(in, name[i]);
	int tmp;
	while (in >> tmp){
		qi[size].push(tmp);
		for (int j = 1; j < N; ++j){
			in >> tmp;
			qi[size].push(tmp);
		}
		size++;
	}
	while (1){
		int vote[30] = { 0 };

		eliminat();
		if (judgetie()){
			for (int i = 1; i <= N; ++i)
				cout << name[i] << endl;
			return 0;
		}

		for (int i = 1; i < size; ++i)
			vote[qi[i].front()]++;

		for (int i = 1; i <= N;++i)
		if (vote[i] > size / 2){
			cout << name[i] << endl;
			return 0;
		}

		int mmin = 1010;
		for (int i = 1; i <= N;++i)
		if (!vis[i]){
			if (vote[i] < mmin)
				mmin = vote[i];
		}
		for (int i = 1; i <= N;++i)
		if (vote[i] == mmin)
			vis[i] = 1;

	}

	return 0;
}