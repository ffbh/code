#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
struct Person{
	string name;
	int RP;
	int l, r,d;
	bool operator<(const Person& p)const{
		if (RP != p.RP)
			return RP < p.RP;
		return name>p.name;
	}
};
int car[10010];
Person person[1000010];
int cnt;


int Merge(int x, int y){
	if (x == 0)return y;
	if (y == 0)return x;
	if (person[y] < person[x])
		swap(x, y);
	person[x].r = Merge(person[x].r, y);
	if (person[person[x].r].d>person[person[x].l].d)
		swap(person[x].l, person[x].r);

	if (person[x].r == 0)
		person[x].d = 0;
	else person[x].d = person[person[x].r].d + 1;

	
	
	return x;
}

int Init(string& s, int RP){
	person[cnt].l = person[cnt].r = 0;
	person[cnt].d = 0;
	person[cnt].name = s;
	person[cnt].RP = RP;
	return cnt++;
}

int Initcar(string& s, int rp){
	return  Init(s, rp);
}


int Push(int car,string& s, int RP){
	int tt = Init(s, RP);
	return Merge(car, tt);
}


int Pop(int car){
	return  Merge(person[car].l, person[car].r);
}


int main(){
	ifstream in("C:\\temp.txt");
	int K,rp;
	int ccar;
	int car1, car2;
	string s;
	while (in >> N >> M){
		cnt = 1;
		for (int i = 1; i <= N; ++i){
			in >> K;
			//scanf("%d", &K);
			in >> s>>rp;
			//scanf("%d",&rp);
			car[i] = Initcar(s,rp);
			for (int j = 0; j < K-1; ++j){
				in >> s >> rp;
			//	cin >> s;
				//scanf("%d", &rp);
				car[i] = Push(car[i], s, rp);
			}
		}
		person[0].d = 0;
		for (int k = 0; k < M; ++k){
			in >> s;
			if (s == "GETOUT"){
				in >> ccar;
			//	scanf("%d", &ccar);
				printf("%s\n", person[car[ccar]].name.c_str());
				car[ccar]=Pop(car[ccar]);
			}
			else if (s == "JOIN"){
				in >> car1 >> car2;
			//	scanf("%d%d", &car1, &car2);
				car[car1] = Merge(car[car1], car[car2]);
			}
			else{
				in >> ccar;
			//	scanf("%d", &ccar);
				in >> s;
			//	scanf("%d", &rp);
				in >> rp;
				car[ccar] = Push(car[ccar], s, rp);
			}
		}
	}
	return 0;
}