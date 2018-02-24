#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int w,l,p;
};
Node data[100001];

int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	int T;
	int N;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < N; ++i)
			//cin >> data[i].w >> data[i].l >> data[i].p;
			scanf("%d%d%d", &data[i].w, &data[i].l, &data[i].p);

		int mmin = data[N - 1].p;
		for (int i = 0; i < N; ++i){
			int f = 0;
			int w = 0;
			for (int j = i; j < N; ++j){
				f += data[j].w;
				if (f <= data[j].l){
					w += data[j].p;
					if (w >= mmin)
						break;
				}
			}
			if (mmin>w)
				mmin = w;
		}
		printf("Case %d: Need to use %d mana points.\n", CASE++, mmin);
	}
	return 0;
}