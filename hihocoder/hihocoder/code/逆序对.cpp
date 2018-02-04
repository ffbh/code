/*#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int data[100010];
int tmp[100010];
int N, ans, size;

int a[1000010];
int lowbit(int x)
{
	return x & (-x);
}
void modify(int x, int add)
{
	while (x < size)
	{
		a[x] += add;
		x += lowbit(x);
	}
}
int get_sum(int x)
{
	int ret = 0;
	while (x != 0)
	{
		ret += a[x];
		x -= lowbit(x);
	}
	return ret;
}


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	
	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> data[i];
	size = 1;
	for (int i = 1; i <= N ; ++i){
		a[size] = 0;
		data[size++] = data[i];
	}
	sort(data + 1, data + size);
	unique(data + 1, data + size);
	int ans = 0;
	int sum = 0;
	for (int i = 1; i <= N; ++i){
		ans += sum - get_sum(data[i]);
		sum++;
		modify(data[i], 1);
	}

	cout << ans << endl;




	return 0;
}*/



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
int data[100010];
int tmp[100010];
int N;
long long ans;

void dfs(int l, int r){
	if (l == r){
		return;
	}
	int mid = (l + r) / 2;
	dfs(l, mid);
	dfs(mid + 1, r);
	if (l == 1 && r == 5){
		int t = 0;
	}
	for (int i = l; i <= r; ++i)
		tmp[i] = data[i];
	int a = l, b = mid + 1;
	int pos = a;
	while (a <= mid){
		while (b <= r && tmp[a] > tmp[b]){
			data[pos++] = tmp[b++];
			ans += (mid - a + 1);
		}
		data[pos++] = tmp[a++];
	}

}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> data[i];
	ans = 0;
	dfs(1, N);

	cout << ans << endl;




	return 0;
}