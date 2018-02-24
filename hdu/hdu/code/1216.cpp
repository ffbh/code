#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#define MMAX 33830
vector<int> V;

bool vis[MMAX];
void Init(){
	for (int i = 2; i < MMAX;++i)
	if (!vis[i]){
		V.push_back(i);
		int flag = 0;
		for (int j = i+1; j < MMAX; ++j)
		if (!vis[j]){
			if (++flag == i){
				flag = 0;
				vis[j] = 1;
			}
		}
	}

}


int main(){
	ifstream in("C:\\temp.txt");
	Init();
	int N;
	while (cin >> N&&N)
		cout << V[N-1] << endl;




	return 0;
}