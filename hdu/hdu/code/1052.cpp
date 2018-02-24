#include <iostream>
#include <algorithm>
using namespace std;


int p1[1010];
int p2[1010];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	while (scanf("%d",&n)&&n){
		for (int i = 0; i < n; ++i)
			scanf("%d", &p1[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &p2[i]);
		sort(p1, p1 + n,cmp);
		sort(p2, p2 + n,cmp);
		int ps1 = 0, pe1 = n - 1;
		int ps2 = 0, pe2 = n - 1;
		int win = 0;
		int fail = 0;
		while (ps1 <= pe1){
			if (p1[pe1]>p2[pe2]){//田忌的慢马比齐威王的慢马块
				win++;
				pe1--;
				pe2--;
			}
			else if (p1[pe1] < p2[pe2]){//田忌的慢马比齐威王的慢马慢
				fail++;
				ps2++;
				pe1--;
			}
			else{//田忌的慢马和齐威王的慢马一样快
				if (p1[ps1]>p2[ps2]){//田忌的快马比齐威王的快马块
					win++;
					ps1++;
					ps2++;

				}
				else if (p1[ps1] < p2[ps2]){//田忌的快马比齐威王的快马慢
					fail++;
					ps2++;
					pe1--;
				}
				else if (p1[pe1]== p2[ps2])//田忌的慢马和齐威王的快马一样快，此时场上剩余的所有马一样快
					break;
				else if (p1[pe1] < p2[ps2]){//田忌的慢马比齐威王的快马慢
					fail++;
					pe1--;
					ps2++;
				}
				
			}
		}
		cout << 200 * win - 200 * fail << endl;


	}


}