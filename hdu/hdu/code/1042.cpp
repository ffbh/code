/*#include<iostream>
#include <string>
using namespace std;



void cale(char** np){
	int k = 0;
	char* temp = (char*)malloc(36001 * sizeof(char));
	int* p = (int*)malloc(36000 * sizeof(int));
	memset(temp, 0, 36001 * sizeof(char));
	temp[0] = '1';
	while (k++ <= 10000){
		memset(p, 0, 36000 * sizeof(int));
		int tlen = strlen(temp);
		char a[6] = { 0 };
		itoa(k, a, 10);
		int alen = strlen(a);
		int index = 0;
		for (int i = tlen - 1; i >= 0; --i){
			index = tlen - 1 - i;
			for (int j = alen - 1; j >= 0; j--){
				p[index++] += (temp[i] - '0')*(a[j] - '0');
			}
		}
		int i;
		for (i = 0; i < index; ++i){
			int flag = p[i] / 10;
			p[i] = p[i] % 10 + '0';
			p[i + 1] += flag;
		}
		if (p[index] != 0) p[index++] += '0';
		int j;
		for (i = index - 1, j = 0; i >= 0; --i, ++j)
			temp[j] = p[i];
		int len = strlen(temp);
		len++;
		char* npp = (char*)malloc(len*sizeof(char));
		strcpy(npp, temp);
		np[k] = npp;
	}
	free(p);
	free(temp);
}



int main(){
	int n;
	char* num[10002];
	cale(num);
	while (scanf("%d",&n)!=EOF){
		cout << num[n] << endl;
	}
}*/



#include<iostream>
#include <string>
using namespace std;

char temp[36001] = { 0 };

void cale(int n){
	int* p = (int*)malloc(36000 * sizeof(int));
	memset(p, 0, 36000 * sizeof(int));
	int tlen = strlen(temp);
	char a[6] = { 0 };
	itoa(n, a, 10);
	int alen = strlen(a);
	int index = 0;
	for (int i = tlen - 1; i >= 0; --i){
		index = tlen - 1 - i;
		for (int j = alen - 1; j >= 0; j--){
			p[index++] += (temp[i] - '0')*(a[j] - '0');
		}
	}
	int i;
	for (i = 0; i<index; ++i){
		int flag = p[i] / 10;
		p[i] = p[i] % 10 + '0';
		p[i + 1] += flag;
	}
	if (p[index] != 0) p[index++] += '0';
	int j;
	for (i = index - 1, j = 0; i >= 0; --i, ++j)
		temp[j] = p[i];
	free(p);
}



int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		temp[0] = '1';
		int i = 1;
		while (i <= n) cale(i++);
		cout << temp << endl;



		memset(temp, 0, 36000 * sizeof(char));
	}
}