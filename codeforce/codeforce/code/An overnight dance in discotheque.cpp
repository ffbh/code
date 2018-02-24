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
int n;
const double PI = acos(-1.0);
struct Node{
	long long x, y, r;
	bool operator<(const Node& p)const{
		if (r != p.r)
			return r > p.r;
		else if (x != p.x)
			return x < p.x;
		else
			return y < p.y;
	}

	long long area(){
		return r * r;
	}


}data[1010];

vector<int> vi[1010];
void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> data[i].x >> data[i].y >> data[i].r;
}



int deep[1010];
long long  val[1010];
long long pre_dfs(int p,int dep){
	deep[p] = dep;
	val[p] = data[p].area();
	if (dep == 1){
		val[p] = -val[p];
	}
	for (int son : vi[p]){
		val[p] += pre_dfs(son, 1 - dep);
	}
	return val[p];
}
bool top[1010];

long long dfs(int p){
	if (p == 3){
		int t = 0;
	}
	long long sum = 0;
	for (int son : vi[p]){
		sum += dfs(son);
	}

	if (p == 0)
		return sum;

	if (!top[p]){
		if (deep[p] == 0){
			return sum;
		//	return max(val[p] , sum);
		}
		else{
			return max( -2 * val[p],sum);
		}
	}
	else{
		return sum;
	}
}


int main(){
	input();

	sort(data + 1, data + n + 1);
	data[0].x = data[0].y = data[0].r = 0;
	for (int i = n; i >= 1; --i){
		bool ok = 0;
		for (int j = i - 1; j >= 1; --j){
			if ((data[i].x - data[j].x)*(data[i].x - data[j].x) + (data[i].y - data[j].y)*(data[i].y - data[j].y) < data[j].r*data[j].r){
				vi[j].push_back(i);
				ok = 1;
				break;
			}
		}
		if (!ok){
			top[i] = 1;
			vi[0].push_back(i);
		}
		
	}

	pre_dfs(0,1);
	long long ret = dfs(0);
	printf("%.10f\n", PI * ((double)ret+val[0]));
	
	











	return 0;
}





