#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int vis[70];

int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	int ans;
	int next;
	while (cin >>a >> b&&a + b){
		memset(vis, 0, sizeof(vis));
		ans = 0;
		while (1){
			
			vis[a] = 1;
			next = a*b % 60;
			a = (a + next) % 60;
			ans++;
			if (a == 0 || vis[a])
				break;
		}
		if (a == 0)
			cout << ans << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}