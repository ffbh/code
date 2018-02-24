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
using namespace std;
struct Node{
	int val, idx;
	bool operator<(const Node& p)const{
		if (val != p.val)
			return val < p.val;
		return idx < p.idx;
	}
}data[100010];
int N;

int c[400010];

int Lowbit(int x){
	return x&(-x);
}

void upd(int pos, int num)
{
	while (pos <= N)
	{
		c[pos] += num;
		pos += Lowbit(pos);
	}
}

int qur(int end)
{
	int sum = 0;
	while (end > 0)
	{
		sum += c[end];
		end -= Lowbit(end);
	}
	return sum;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;
	for (int i = 1; i <= N; ++i){
		in >> data[i].val;
		data[i].idx = i;
	}
	sort(data + 1, data + N + 1);
	long long ans = 0;
	for (int i = 1; i <= N; ++i)
		upd(i, 1);
	int pre = -1;
	for (int i = 1; i <= N; ++i){
		int a = i;
		int b = a;
		int last = -1;
		int mmid = -1;
		while (b <= N && data[b].val == data[a].val){
			if (data[b].idx < pre){
				last = data[b].idx;
			}
			mmid = max(mmid, data[b].idx);
			b++;
		}
		b--;
		if (last == -1){
			last = mmid;
		}


		if (pre < last){
			ans += qur(last) - qur(pre);
		}
		else{
			ans += (qur(N) - qur(pre)) + qur(last);
		}
		for (int k = a; k <= b&&k <= N; ++k){
			upd(data[k].idx, -1);
		}
		i = b;
		pre = last;



	}




	cout << ans << endl;











	return 0;
}





