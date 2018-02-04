#include <iostream>

using namespace std;

bool vis[5050];
int main(){
	int N;
	cin >> N;
	int num;
	while (N--){
		memset(vis, 1, sizeof(vis));
		cin >> num;
		int mm = num;
		int flag = 2;
		int tt;
		while (num > 3){
			tt = 0;
			for (int i = 1; i <= mm; ++i)
				if (vis[i]){
					tt++;
					if (tt == flag){
						tt = 0;
						vis[i] = 0;
						num--;
					}
				}
			
			if (flag == 2)flag = 3;
			else flag = 2;
		}
		int k = 1;
		for (int i = 1; i <=mm && k <= num; ++i){
			if (vis[i]){
				if (k != num)
					printf("%d ", i);
				else
					printf("%d\n", i);
				k++;
			}
		}
	
	
	}


	return 0;
}