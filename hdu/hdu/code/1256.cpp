#include<iostream>
using namespace std;

int main(){
	int N;
	char c;
	int m;
	cin >> N;
	int ok = 0;
	while (cin >> c >> m){
		if (ok == 1)cout << endl;
		ok = 1;
		int w = m / 6+1;
		int up = (m - 3) / 2;
		int down = m - 3 - up;
		for (int i = 0; i < w; ++i)
			printf(" ");
		for (int i = 0; i < down; ++i)
			printf("%c",c);
		printf("\n");

		for (int k = 0; k < up; ++k){
			for (int i = 0; i < w; ++i)
				printf("%c", c);
			for (int i = 0; i < down; ++i)
				printf(" ");
			for (int i = 0; i < w; ++i)
				printf("%c", c);
			printf("\n");
		}

		for (int i = 0; i < w; ++i)
			printf(" ");
		for (int i = 0; i < down; ++i)
			printf("%c", c);
		printf("\n");

		for (int k = 0; k < down; ++k){
			for (int i = 0; i < w; ++i)
				printf("%c", c);
			for (int i = 0; i < down; ++i)
				printf(" ");
			for (int i = 0; i < w; ++i)
				printf("%c", c);
			printf("\n");
		}

		for (int i = 0; i < w; ++i)
			printf(" ");
		for (int i = 0; i < down; ++i)
			printf("%c", c);
		printf("\n");
	
	}//while



}