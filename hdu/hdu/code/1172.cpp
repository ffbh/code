#include <iostream>
//#include <fstream>
using namespace std;
struct node{
	int value;
	int B, C;
};
node p[1100];
int getB(int a,int b){
	int num1[4];
	int num2[4];
	bool vis1[4] = { 0 }, vis2[4] = { 0 };
	
	for (int i = 0; i < 4; ++i){
		num1[i] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < 4; ++i){
		num2[i] = b % 10;
		b /= 10;
	}
	int ans = 0;
	for (int i = 0; i < 4;++i)
	for (int j = 0; j < 4;++j)
	if (num1[i] == num2[j] && !vis1[i] && !vis2[j]){
		ans++;
		vis1[i] = vis2[j] = 1;
	}
	return ans;
	
}

int getC(int a, int b){
	int ta, tb;
	int ans = 0;
	for (int i = 0; i < 4; ++i){
		ta = a % 10;
		a /= 10;
		tb = b % 10;
		b /= 10;
		if (ta == tb)ans++;
	}
	return ans;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		int ans = 0;
		int result;
		for (int i = 0; i < N; ++i){
			//in >> p[i].value >> p[i].B >> p[i].C;
			scanf("%d%d%d", &p[i].value, &p[i].B, &p[i].C);
		}
		for (int i = 1000; i <= 9999; ++i){
			int j;
			for (j = 0; j < N; ++j){
				if (getB(i, p[j].value) != p[j].B || getC(i, p[j].value) != p[j].C)
					break;
			}
			if (j == N)
			{
				ans++;
				result = i;
				if (ans == 2)break;
			}

		}
		if (ans == 1)cout << result << endl;
		else
			cout << "Not sure" << endl;
	}

	return 0;
}