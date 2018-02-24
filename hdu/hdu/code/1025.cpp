#include <iostream>
using namespace std;
#define MAXSIZE 500000

int num[MAXSIZE + 10] = { 0 };
int temp[MAXSIZE + 10] = { 0 };


int main(){
	int n, index, len;
	int c = 1;
	while (cin >> n){
		int i = 0;
		while (i++<n){
			scanf("%d", &index);
			scanf("%d", &num[index]);
		}
		if (n == 1){
			printf("Case %d:\n", c++);
			printf("My king, at most 1 road can be built.\n\n");
			continue;
		}
		len = 0;
		temp[len] = num[1];
		for (i = 2; i <= n; ++i){
			if (temp[len] < num[i]){
				len++;
				temp[len] = num[i];
				continue;
			}
			int low = 0;
			int high = len-1;
			int mid;
			while (low<=high){
				mid = (low + high) / 2;
				if (temp[mid] < num[i]) low = mid + 1;
				else high = mid - 1;
			}
			temp[low] = num[i];
		}
		printf("Case %d:\n", c++);
		if (len+1==1)
			printf("My king, at most 1 road can be built.\n\n" );
		else printf("My king, at most %d roads can be built.\n\n", len+1);
	}




	return 0;
}