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
using namespace std;
#define DEBUG (0)
struct Node{
	int a, b;
	char c;
	bool operator<(const Node& p)const{
		if (a != p.a)
			return a < p.a;
		else if (b != p.b)
			return b < p.b;
		else
			return c < p.c;
	}
}data[3];
int la, lb, lc, ma, mb, mc;

char cale(){
	data[0].a = la;
	data[0].b = ma;
	data[0].c = 'a';
	data[1].a = lb;
	data[1].b = mb;
	data[1].c = 'b';
	data[2].a = lc;
	data[2].b = mc;
	data[2].c = 'c';
	sort(data, data + 3);
	return data[0].c;
}

class ConstructLCS {
	public:
	string construct(int ab, int bc, int ca) {
		la = max(ab, ca);
		lb = max(ab, bc);
		lc = max(bc, ca);
		ma = min(ab, ca);
		mb = min(ab, bc);
		mc = min(bc, ca);
		char ret = cale();
		if (ret == 'a'){
			string a(la, '0');
			string b(ab, '0');
			string c(ca, '0');
			string p(bc - min(b.length(), c.length()), '1');
			return a + " " + b + p + " " + c + p;
		}
		else if (ret =='b'){
			string b(lb, '0');
			string a(ab, '0');
			string c(bc, '0');
			string p(ca - min(a.length(), c.length()), '1');
			return a + p + " " + b + " " + c + p;
		}
		else{
			string c(lc, '0');
			string a(ca, '0');
			string b(bc, '0');
			string p(ab - min(a.length(), b.length()), '1');
			return a + p + " " + b + p + " " + c;
		}

	}
};



#if 0
int main(){
	
	ConstructLCS so;
	cout<<so.construct(8,7,8)<<endl;
















	return 0;
}
#endif

