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
ifstream in("/home/ffbh/CLionProjects/acm/InOutput/input.txt");
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


int n;
string op,str;

void input(){
	in>>n;


}

struct Node{
	int next[30];
	int word;
}data[3000010];
int size,root;

int MALLOC(){
	memset(data[size].next,-1,sizeof(data[size].next));
	data[size].word = 0;
	return size++;
}


void insert(){
	int p = root;
	for(char c : str){
	    int x = c - 'a';
	    if(data[p].next[x] == -1){
	        data[p].next[x] = MALLOC();
	    }
	    p = data[p].next[x];
	    data[p].word++;
	}
}

bool exist(){
    int p = root;
    for(char c : str){
        int x = c - 'a';
        if(data[p].next[x] == -1){
            return 0;
        }
        p = data[p].next[x];
    }
    return data[p].word > 0;
}

int getWord(){
    int p = root;
    for(char c : str){
        int x = c - 'a';
        if(data[p].next[x] == -1){
           return -1;
        }
        p = data[p].next[x];
    }
    return data[p].word;
}

void del(){
    int word = getWord();
    if(word <= 0)
        return ;
    int p = root;
    int pp,px;
    for(char c : str){
        int x = c - 'a';
        if(data[p].next[x] == -1){
            assert(0);
        }
        pp = p;
        px = x;
        p = data[p].next[x];
        data[p].word -= word;
    }
    data[pp].next[px] = -1;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		root = MALLOC();

		while(n-->0){
			in>>op>>str;
            if(op == "insert"){
                insert();
            }
            else if(op == "delete"){
                del();

            }
            else{
                if(exist()){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }




		}














	}


	return 0;
}





