#include <iostream>
#include <algorithm>
//#include <fstream>
using namespace std;
struct node{
	int time;
	int p;
	int index;
};
node num[150];
bool cmp(const node& a, const node& b){
	if (a.p != b.p)
		return a.p > b.p;
	return a.time<b.time;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N, G, S, C, M;
	while (cin >> N >> G >> S >> C >> M&&N){
		int h, m, s;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= N; ++i){
			scanf("%d", &num[i].p);
			scanf("%d:%d:%d", &h, &m, &s);
			num[i].time = 3600 * h + 60 * m + s;
			num[i].index = i;
		}
		sort(num+1, num + N + 1, cmp);
		int kk = 0;
		for (int i = 1; i <= N; ++i){
			if (num[i].index == M){
				kk = i;
				break;
			}
		}
		if (kk <= G)printf("Accepted today? I've got a golden medal :)\n");
		else if (kk <= G+S)printf("Accepted today? I've got a silver medal :)\n");
		else if (kk <= G+S+C)printf("Accepted today? I've got a copper medal :)\n");
		else printf("Accepted today? I've got an honor mentioned :)\n");
	
	}


	return 0;
}