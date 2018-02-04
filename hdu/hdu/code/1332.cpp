#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void PrintOne(int n,char c){
	char cc = '-';
	printf(" ");
	if (c == '1' || c == '4')
		cc = ' ';
	for (int i = 0; i < n; ++i)
		printf("%c",cc);
	printf(" ");
}

void PrintTwo(int n, char c){
	if (c == '1' || c == '2' || c == '3' || c == '7'){
		for (int j = 0; j < n + 1; ++j)
			printf(" ");
		printf("|");
	}
	else if (c == '5' || c == '6'){
		printf("|");
		for (int j = 0; j < n+1; ++j)
			printf(" ");
		
	}
	else {
		printf("|");
		for (int j = 0; j < n ; ++j)
			printf(" ");
		printf("|");
	}
}

void PrintThree(int n, char c){
	char cc = '-';
	printf(" ");
	if (c == '1' || c == '7' || c == '0')
		cc = ' ';
	for (int i = 0; i < n; ++i)
		printf("%c", cc);
	printf(" ");
}
void PrintFour(int n, char c){
	if (c == '2'){
		printf("|");
		for (int j = 0; j < n+1; ++j)
			printf(" ");
	}
	else if (c == '6' || c == '8' || c == '0'){
		printf("|");
		for (int j = 0; j < n; ++j)
			printf(" ");
		printf("|");
	}
	else{
		for (int j = 0; j < n + 1; ++j)
			printf(" ");
		printf("|");
	}
}
void PrintFive(int n, char c){
	char cc = '-';
	printf(" ");
	if (c == '1' || c == '4' || c == '7')
		cc = ' ';
	for (int i = 0; i < n; ++i)
		printf("%c", cc);
	printf(" ");
}
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	string s;
	while (cin >> N >> s){
		if (N == 0 && s == "0")break;
		int len = s.length();

		for (int i = 0; i < len - 1; ++i){
			PrintOne(N, s[i]);
			printf(" ");
		}
		PrintOne(N, s[len-1]);
		printf("\n");

		for (int k = 0; k < N; ++k){
			for (int i = 0; i < len - 1; ++i){
				PrintTwo(N, s[i]);
				printf(" ");
			}
			PrintTwo(N, s[len - 1]);
			printf("\n");
		}

		for (int i = 0; i < len - 1; ++i){
			PrintThree(N, s[i]);
			printf(" ");
		}
		PrintThree(N, s[len - 1]);
		printf("\n");

		for (int k = 0; k < N; ++k){
			for (int i = 0; i < len - 1; ++i){
				PrintFour(N, s[i]);
				printf(" ");
			}
			PrintFour(N, s[len - 1]);
			printf("\n");
		}

		for (int i = 0; i < len - 1; ++i){
			PrintFive(N, s[i]);
			printf(" ");
		}
		PrintFive(N, s[len - 1]);
		printf("\n\n");
	
	}

	return 0;
}