#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
string s1, s2, s3, s4;
int h[266];

void cale(string& a,string& b,int& apos,int& bpos){
	memset(h, -1, sizeof(h));
	for (int i = 0; i < a.length(); ++i){
		if (h[a[i]] == -1){
			h[a[i]] = i;
		}
	}

	for (int i = 0; i < b.length(); ++i){
		if (h[b[i]] != -1){
			apos = h[b[i]];
			bpos = i;
			break;
		}

	}
}

void blank(int p){
	for (int i = 0; i < p; ++i){
		putchar(' ');
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int a, b, c, d;
	bool ok = 0;
	while (in >> s1&&s1 != "#"){
		if (ok == 0){
			ok = 1;
		}
		else{
			cout << endl;
		}

		in >> s2 >> s3 >> s4;
		a = b = c = d = -1;
		cale(s2, s1, b, a);
		cale(s4, s3, d, c);
		if (a == -1 || c == -1){
			cout << "Unable to make two crosses" << endl;
		}
		else{
			int ah, al, bh, bl, mid;
			if (b >= d){
				ah = 0;
				al = ah + s2.length() - 1;
				bh = b - d;
				bl = bh + s4.length() - 1;
				mid = b;
			}
			else{
				bh = 0;
				bl = bh + s4.length() - 1;
				ah = d - b;
				al = ah + s2.length() - 1;
				mid = d;
			}

			for (int i = 0; i <= max(al,bl); ++i){
				if (i == mid){
						cout << s1 << "   " << s3 << endl;
				}
				else{
					int preblank = 0;
					if (i >= ah&&i <= al){
						blank(a);
						putchar(s2[i - ah]);
						preblank = a + 1;
					}
					if (i >= bh&&i <= bl){
						blank(s1.length()+3+c-preblank);
						putchar(s4[i - bh]);
					}
					cout << endl;
				}
			}
		
		}

	}

	return 0;
}