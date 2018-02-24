#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
int K;
map<char, int> mci;
struct Card{
	int value;
	int color;
	bool operator<(const Card& c)const{
		if (value == c.value)
			return color < c.color;
		return value < c.value;
	}
	bool operator>(const Card& c)const{
		return !(*this < c);
	}
};
Card A[30];
Card E[30];





int main(){
	ifstream in("C:\\temp.txt");
	int nn = 1;
	for (char d = '1'; d <= '9'; ++d)
		mci[d] = nn++;
	mci['T'] = 10;
	mci['J'] = 11;
	mci['Q'] = 12;
	mci['K'] = 13;
	mci['A'] = 14;
	mci['H'] = 4;
	mci['S'] = 3;
	mci['D'] = 2;
	mci['C'] = 1;
	int T;
	cin >> T;
	while (T--){
		cin >> K;
		getchar();
		for (int i = 0; i < K; ++i){
			char cc = getchar();
			A[i].value = mci[cc];
			cc = getchar();
			A[i].color = mci[cc];
			getchar();
		}
		for (int i = 0; i < K; ++i){
			char cc = getchar();
			E[i].value = mci[cc];
			cc = getchar();
			E[i].color = mci[cc];
			getchar();
		}
		sort(A, A + K);
		sort(E, E + K);

		int ab, al, eb, el;
		ab = eb = K - 1;
		al = el = 0;
		int ans = 0;
		while (ab >= al){
			if (E[eb] > A[ab]){
				eb--;
				ab--;
				ans++;
			}
			else if (E[eb] < A[ab]){
				el++;
				ab--;
			}
			else{
				if (E[el] < A[al]){
					al++;
					ab--;
				}
				else if (E[el]>A[al]){
					al++;
					al++;
					ans++;
				}
				else{
					ab--;
					el++;
				}
			
			}
		}
		cout << ans << endl;
	}
	return 0;
}