#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	set<int> si;
	while (cin >> N >> M){
		si.clear();
		int t;
		for (int i = 0; i < N; ++i){
			//in >> t;
			scanf("%d",&t);
			si.insert(t);
		}
		for (int i = 0; i < M; ++i){
		//	in >> t;
			scanf("%d",&t);
			si.insert(t);
		}
		int size = si.size();
		set<int>::iterator it = si.begin();
		for (int i = 0; i < size - 1; ++i)
			printf("%d ", *it++);
		printf("%d\n", *it);
	}

	return 0;
}