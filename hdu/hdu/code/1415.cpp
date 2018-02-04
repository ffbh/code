#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int Ca, Cb, N;
const string ffbh[] = {
	"FA", "FB", "PAB", "PBA", "EA", "EB"
};
bool vis[1010][1010];
struct Cup{
	int a, b;
	string pace;
};

bool pour(Cup& p, int i){
	int mmax;
	switch (i){
	case 0:
		if (p.a == Ca)
			return 0;
		p.a = Ca;
		break;
	case 1:
		if (p.b == Cb)
			return 0;
		p.b = Cb;
		break;
	case 2:
		if (p.a == 0)
			return 0;
		mmax = Cb - p.b;
		if (p.a <= mmax){
			p.b += p.a;
			p.a = 0;
		}
		else{
			p.a -= mmax;
			p.b = Cb;
		}
		break;
	case 3:
		if (p.b == 0)
			return 0;
		mmax = Ca - p.a;
		if (p.b <= mmax){
			p.a += p.b;
			p.b = 0;
		}
		else{
			p.b -= mmax;
			p.a = Ca;
		}
		break;
	case 4:
		if (p.a == 0)
			return 0;
		p.a = 0;
		break;
	case 5:
		if (p.b == 0)
			return 0;
		p.b = 0;
		
		break;
	}
	p.pace += ffbh[i];
	return 1;
}


string bfs(){
	queue<Cup> qc;
	Cup temp1, temp2;
	temp1.a = 0;
	temp1.b = 0;
	temp1.pace = "";
	vis[temp1.a][temp1.b] = 1;
	qc.push(temp1);
	while (!qc.empty()){
		temp1 = qc.front();
		qc.pop();
		for (int i = 0; i < 6; ++i){
			temp2 = temp1;
			if (pour(temp2, i) == 0)continue;
			if (temp2.b  == N)
				return temp2.pace;
			if (!vis[temp2.a][temp2.b]){
				vis[temp2.a][temp2.b] = 1;
				qc.push(temp2);
			}
		}
	}
}


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> Ca >> Cb >> N){
		memset(vis, 0, sizeof(vis));
		string pace = bfs();
		int len = pace.length();
		cout << "fill";
		for (int i = 1; i < len;++i)
		if ((pace[i] == 'A' || pace[i] == 'B'))
			printf(" %c", pace[i]);
		else{
			if (pace[i] == 'F')
				printf("\nfill");
			else if (pace[i] == 'E')
				printf("\nempty");
			else
				printf("\npour");
		}
		printf("\nsuccess\n");


	}
	return 0;
}