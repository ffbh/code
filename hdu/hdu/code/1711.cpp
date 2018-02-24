#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int num1[1000010];
int num2[10010];
int Next[10010];

void getNext(){
	int i = 0;
	int j = -1;
	Next[0] = -1;
	while (i < M)
	if (j == -1 || num2[i] == num2[j])
		Next[++i] = ++j;
	else
		j = Next[j];
}

int kmp(){
	getNext();
	int i, j;
	i = j = 0;
	while (i < N){
		if (j == -1 || num1[i] == num2[j]){
			++i;
			++j;
		}
		else
			j = Next[j];
		if (j == M)
			return i - M + 1;
	}
	return -1;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
			//	in >> num1[i];
			scanf("%d", &num1[i]);
		for (int i = 0; i < M; ++i)
		//	in >> num2[i];
		scanf("%d", &num2[i]);
		cout << kmp() << endl;
	}
	return 0;
}