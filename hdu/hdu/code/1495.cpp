#include <iostream>
#include <fstream>
#include <queue>
#include <map>
using namespace std;
double D[3];
map<int, bool> mib;
struct node{
	double d[3];
	int step;
};

int getHash(const node& p){
	int res = p.d[0];
	res = res * 102 + p.d[1];
	res = res * 102 + p.d[2];
	return res;
}

void Pour(node& p,int i, int j){
	if (p.d[i] <= D[j] - p.d[j]){
		p.d[j] += p.d[i];
		p.d[i] = 0;
	}
	else{
		p.d[i] -= (D[j] - p.d[j]);
		p.d[j] = D[j];
	}
}

bool Ok(node& p){
	return p.d[0] == D[0] / 2 && (p.d[1] == 0 || p.d[2] == 0);
}
int bfs(){
	queue<node> qn;
	node temp1, temp2;
	int HH;
	temp1.d[0] = D[0];
	temp1.d[1] = 0;
	temp1.d[2] = 0;
	temp1.step = 0;
	qn.push(temp1);
	mib[getHash(temp1)] = 1;
	while (!qn.empty()){
		temp1 = qn.front();
		if (Ok(temp1))
			return temp1.step;
		temp1.step++;
		qn.pop();
		temp2 = temp1;
		Pour(temp2, 0, 1);
		HH = getHash(temp2);
		if (mib[HH] == 0){
			mib[HH] = 1;
			qn.push(temp2);
		}
		
		temp2 = temp1;
		Pour(temp2, 1, 0);
		HH = getHash(temp2);
		if (mib[HH] == 0){
			mib[HH] = 1;
			qn.push(temp2);
		}

		temp2 = temp1;
		Pour(temp2, 0, 2);
		HH = getHash(temp2);
		if (mib[HH] == 0){
			mib[HH] = 1;
			qn.push(temp2);
		}

		temp2 = temp1;
		Pour(temp2, 2, 0);
		HH = getHash(temp2);
		if (mib[HH] == 0){
			mib[HH] = 1;
			qn.push(temp2);
		}

		temp2 = temp1;
		Pour(temp2, 2, 1);
		HH = getHash(temp2);
		if (mib[HH] == 0){
			mib[HH] = 1;
			qn.push(temp2);
		}

		temp2 = temp1;
		Pour(temp2, 1, 2);
		HH = getHash(temp2);
		if (mib[HH] == 0){
			mib[HH] = 1;
			qn.push(temp2);
		}
		
	}
	return -1;
}




int main(){
//	ifstream in("C:\\temp.txt");
	
	while (cin >> D[0]>>D[1]>>D[2]){
		if (D[0] + D[1] + D[2] == 0)break;
		mib.clear();
		int ans = bfs();
		if (D[0] / 2 <= D[1] + D[2]){
			if (ans == -1)
				cout << "NO" << endl;
			else
				cout << ans << endl;
		}
		else
			cout << ans << endl;




	}

	return 0;
}