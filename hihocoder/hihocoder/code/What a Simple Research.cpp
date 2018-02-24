#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int num[150];
struct Node{
	char c;
	int ans;
	bool operator<(const Node& p)const{
		if (ans != p.ans)
			return ans > p.ans;
		else
			return c < p.c;
	}
}data[20];
char k[] = { 'A', 'C', 'D', 'E', 'G' };
int main(){
	ifstream in("C:\\input.txt");
	int N, M;
	while (in >> N >> M&&N+M){
		memset(num, 0, sizeof(num));
		while(N--){
			char s[100];
			in >> s;
			for (int j = 0; j < M; ++j){
				num[s[j]]++;
			}
		}
		for (int i = 0; i < 5;++i){
			data[i].c = k[i];
			data[i].ans = num[k[i]];
		}
		sort(data, data + 5);
		for (int i = 0; i < 5&&data[i].ans; ++i)
			cout << data[i].c << " " << data[i].ans << ' ';
		cout << endl;
	//	printf("%c %d\n", data[4].c, data[4].ans);

	}
















	return 0;
}