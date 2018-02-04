#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int data[1010][1010];
int num[1010][1010];


void updata(int x, int y, int v){
	for (int i = x; i <= 1001; i += i&(-i))
	for (int j = y; j <= 1001; j += j&(-j))
		data[i][j] += v;
}

int getsum(int x, int y){
	int sum = 0;
	for (int i = x; i > 0; i -= i&(-i))
	for (int j = y; j > 0; j -= j&(-j))
		sum += data[i][j];
	return sum;
}

int main(){
//	ifstream in("C:\\temp.txt");
	int T;
	int M;
	cin >> T;
	int CASE = 1;
	while (T--){
		cin >> M;
		memset(data, 0, sizeof(data));
		for (int i = 1; i <= 1002; ++i)
		for (int j = 1; j <= 1002; ++j){
			updata(i, j, 1);
			num[i][j] = 1;
		}
		printf("Case %d:\n", CASE++);
		while(M--){
			char C;
			int a, b, c, d, e; 
			getchar();
			C = getchar();
			if (C == 'S'){
				//in >> a >> b >> c >> d;
				scanf("%d%d%d%d", &a, &b, &c, &d);
				a++;
				b++;
				c++;
				d++;
				if (a>c)
					swap(a, c);
				if (b > d)
					swap(b, d);
				int R = getsum(c,d);
				int L = getsum(a-1,b-1);
				int LR = getsum(a - 1, d);
				int RL = getsum(c, b - 1);
				cout << R + L - LR - RL << endl;
			}
			else if(C=='A'||C=='D'){
				
				//in >> a >> b >> c;
				scanf("%d%d%d", &a, &b, &c);
				if (c){
					a++;
					b++;
					if (C == 'D')
						c = -c;
					if (num[a][b] + c < 0)
						c = -num[a][b];
					updata(a, b, c);
					num[a][b] += c;
				}
			}
			else{
			//	in >> a >> b >> c >> d >> e;
				scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
				if (e){
					a++;
					b++;
					c++;
					d++;
					if (e > num[a][b])
						e = num[a][b];
					updata(a, b, -e);
					updata(c, d, e);
					num[c][d] += e;
					num[a][b] -= e;
				}
			}
		}
	}
	return 0;
}