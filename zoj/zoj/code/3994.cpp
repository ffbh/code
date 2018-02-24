#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int N;
int a[1001], b[1001];


void input(){
	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> a[i];
	for (int i = 1; i <= N; ++i)
		in >> b[i];


}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int suma = 0, sumb = 0;
		for (int i = 1; i <= N; ++i){
			suma += a[i];
			sumb += b[i];
		}

		if (suma > sumb){
			cout << "BaoBao"<<endl;
		}
		else{
			cout << "DreamGrid" << endl;
		}










	}


	return 0;
}





