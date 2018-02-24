#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct Boat{
	int b, e;
};
Boat data[110];

int GetTime(const string& s){
	static stringstream ss;
	ss.clear();
	ss.str(s);
	int h,m;
	ss >> h >> m;
	return 60 * h + m;
}


int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	memset(data, -1, sizeof(data));
	int ans = 0;
	int ttl = 0;
	while (getline(cin,s)&&s[0] != '-'){
		if (s[0] != '0'){
			string time = s.substr(4);
			time[2] = ' ';
			if (s[2] == 'S'){
				if (data[s[0] - '0'].b != -1)
					continue;
				data[s[0] - '0'].b = GetTime(time);
			}
			else if (data[s[0] - '0'].b!=-1){
				data[s[0] - '0'].e = GetTime(time);
				ans++;
				ttl += data[s[0] - '0'].e-  data[s[0] - '0'].b;
				data[s[0] - '0'].b = -1;
			}
		}
		else{
			if (ans == 0)
				printf("0 0\n");
			else
			printf("%d %d\n", ans, int(double(ttl) / ans+0.99999));
			ans = ttl = 0;
			memset(data, -1, sizeof(data));
		}
	}
	return 0;
}