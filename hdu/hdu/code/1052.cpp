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
			if (p1[pe1]>p2[pe2]){//��ɵ�������������������
				win++;
				pe1--;
				pe2--;
			}
			else if (p1[pe1] < p2[pe2]){//��ɵ��������������������
				fail++;
				ps2++;
				pe1--;
			}
			else{//��ɵ������������������һ����
				if (p1[ps1]>p2[ps2]){//��ɵĿ�����������Ŀ����
					win++;
					ps1++;
					ps2++;

				}
				else if (p1[ps1] < p2[ps2]){//��ɵĿ�����������Ŀ�����
					fail++;
					ps2++;
					pe1--;
				}
				else if (p1[pe1]== p2[ps2])//��ɵ�������������Ŀ���һ���죬��ʱ����ʣ���������һ����
					break;
				else if (p1[pe1] < p2[ps2]){//��ɵ�������������Ŀ�����
					fail++;
					pe1--;
					ps2++;
				}
				
			}
		}
		cout << 200 * win - 200 * fail << endl;


	}


}