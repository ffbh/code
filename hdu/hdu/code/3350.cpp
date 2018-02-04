#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
string d;
char  data[1010];
struct Node{
	int res, add;
	Node(){
		res = add = 0;
	}
};
Node CaleMarco(int, int r);
Node CaleExpression(int l, int r){
	int t = 0;
	Node ret;
	for (int i = l; i <= r; ++i){
		if (data[i] >= '0' && data[i] <= '9')
			t = t * 10 + data[i] - '0';
		else if (data[i] == '('){
			int end = i;
			int offset = 0;
			while (1){
				if (data[end] == ')'){
					offset--;
					if (offset == 0)
						break;

				}
				if (data[end] == '(')
					offset++;
				end++;
			}
			Node p = CaleMarco(i, end);
			ret.add += p.add;
			ret.res += p.res;
			i = end;
			t = 0;
		}
		else if (data[i] == '+'){
			ret.res += t;
			ret.add++;
			t = 0;
		}
	}
	ret.res += t;
	return ret;
}

Node CaleMarco(int l, int r){
	Node ret;
	if (data[l] == '('){
		int offset = 0,limit=0;
		for (int i = l + 1; i <= r; ++i){
			if (data[i] == '(')
				offset++;
			else if (data[i] == ')')
				offset--;
			else if (offset == 0 && data[i] == ','){
				limit = i;
				break;
			}
		}
		Node p1 = CaleExpression(l + 1, limit - 1);
		Node p2 = CaleExpression(limit + 1, r - 1);
		ret.res = max(p1.res, p2.res);
		if (p1.res > p2.res)
			ret.add = 2 * p1.add + p2.add;
		else
			ret.add = p1.add + 2 * p2.add;
		return ret;
	}
	return ret;
}


int main(){
	ifstream in("C:\\input.txt");
	int T, ll;
	cin >> T;
	cin.get();
	while (T--){
		getline(cin, d);
		memset(data, 0, sizeof(data));
		ll = 0;
		for (int i = 0; i<d.length();++i)
		if (d[i] != ' '&&(d[i] < 'A' || d[i] > 'Z'))
			data[ll++] = d[i];
		ll--;
		
		Node ans = CaleExpression(0, ll);
		
		printf("%d %d\n", ans.res, ans.add);

	}
	return 0;
}