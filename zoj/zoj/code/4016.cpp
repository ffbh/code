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
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("/home/fbh/CLionProjects/acm/InOutput/input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int n,q;

void input(){

	in>>n>>q;

}



struct List{
	int pre,next;
	int v;
}data[600010];
int size;
int alloc(int v,int p){
	data[size].pre = p;
	data[size].v = v;
	data[size].next = -1;
	data[p].next = size;
	return size++;
}

int top[300010];

void Init(){
	size = 1;
	for(int i=1;i<=n;++i)
		top[i] = alloc(-1,-1);
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		Init();

		while(q-->0){
			int op;
		//	in>>op;
			scanf("%d",&op);
			int a,b;
			if(op== 1){
			//	in>>a>>b;
				scanf("%d%d",&a,&b);
				top[a] = alloc(b,top[a]);
			}
			else if(op==2){
			//	in>>a;
				scanf("%d",&a);
				if(data[top[a]].v == -1){
					printf("EMPTY\n");
				}
				else{
					printf("%d\n",data[top[a]].v);
					top[a] = data[top[a]].pre;
					data[top[a]].next = -1;
				}
			}
			else{
			//	in>>a>>b;
				scanf("%d%d",&a,&b);
				if(data[b].next == -1){

				}
				else{
					int ptr = data[b].next;
					data[b].next = -1;
					data[top[a]].next = ptr;
					data[ptr].pre = top[a];
					top[a] = top[b];
					top[b] = b;
				}


			}


		}







	}


	return 0;
}





