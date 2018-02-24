#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int  vi[100010][110];
int num[100010];
int N, M;
bool apple[100010];
int data[100010];
int f[100010];

int Dfs_Init(int u){
	data[u] = 1;
	for (int i = 0; i < num[u]; ++i){
		int v = vi[u][i];
		data[u] += Dfs_Init(v);
	}
	return data[u];
}

void updata(int u,int flag){
	data[u] += flag;
	if (u != 1)
		updata(f[u], flag);
}




int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 1; i <= N; ++i){
		num[i] = 0;
		apple[i] = 1;
	}
	for (int i = 1; i < N; ++i){
		int a, b;
	//	in >> a >> b;
		scanf("%d%d", &a, &b);
		vi[a][num[a]++] = b;
		f[b] = a;
	}
	Dfs_Init(1);
	cin >> M;
	while (M--){
		char c;
		int k;
	//	in >> c >> k;
		getchar();
		scanf("%c%d", &c, &k);
		if (c == 'Q')
			//	cout << data[k] << endl;
			printf("%d\n", data[k]);
		else{
			if (apple[k]){
				apple[k] = 0;
				updata(k, -1);
			}
			else{
				apple[k] = 1;
				updata(k, 1);
			}
		}
	}
	return 0;
}