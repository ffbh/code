#include <iostream>
using namespace std;
_int64 getNum(int M,int N){
	if (M == 0)
		return N + 1;
	else if (M == 1)
		return N + 2;
	else
		return N * 2 + 3;


}

_int64 dfs(int M, int N){
	if (N == 0)
		return  getNum(M - 1, 1);
	if (M == 3)
		return dfs(M - 1, dfs(M, N - 1));
	else return getNum(M, N);


}

int main(){
	int M, N;
	while (cin >> M >> N){
		if (M <= 2)
			cout << getNum(M, N) << endl;
		else
			cout << dfs(M, N) << endl;
			
	}


	return 0;
}