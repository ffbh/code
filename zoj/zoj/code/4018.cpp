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

int n,m;
int data[15][15];
int dirs[4][2]={-1,0,0,1,1,0,0,-1};
bool IN(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&&data[x][y]!=-1;
}

void input(){
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) {
            in >> data[i][j];
            if(data[i][j] == 1 || data[i][j] == 3){
                data[i][j] = 4 - data[i][j];
            }
        }
}

vector<pii> all;

pii get_pos(){
   for(pii p : all) {
       int i = p.first;
       int j = p.second;
       if (data[i][j] == -1)
           continue;
       if (data[i][j] != 0) {
           return mp(i, j);
       } else {
           if (IN(i - 1, j) && data[i - 1][j] == 1) {
               return mp(i, j);
           }
       }
   }
    return mp(-1,-1);
}

vector<pii> ans;

void click(pii pos){
    ans.push_back(pos);
    int x = pos.first;
    int y = pos.second;
    while(IN(x,y)){
        if(data[x][y] == -1)
            break;
        data[x][y] = (data[x][y] + 1) % 4;
        int di = data[x][y];
        x += dirs[di][0];
        y += dirs[di][1];
    }
}



int d[15][15];
bool ok_click(pii pos){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            d[i][j] = data[i][j];
    int x = pos.first;
    int y = pos.second;
    while(IN(x,y)){

        if(d[x][y] == -1)
            break;
        d[x][y] = (d[x][y] + 1) % 4;
        int di = d[x][y];
        x += dirs[di][0];
        y += dirs[di][1];
    }
    return (data[pos.first][pos.second] + 1)% 4==d[pos.first][pos.second];
}


bool cmp(pii a,pii b){
    int ad = a.first + a.second;
    int bd = b.first + b.second;
    if(ad != bd){
        return ad > bd;
    }
    else{
        return a.first > b.first;
    }

}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        ans.clear();
        all.clear();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){
                if(data[i][j] != -1)
                    all.push_back(mp(i,j));
            }

        sort(all.begin(),all.end(),cmp);



//
//        for(int i=1;i<=n;++i) {
//            for (int j = 1; j <= m; ++j) {
//                cout << data[i][j];
//            }
//            cout<<endl;
//        }



        while(ans.size() <= 6000){

            pii pos = get_pos();
            if(pos.first == -1)
                break;
            if(data[pos.first][pos.second] == 0){
                pos.first--;
            }
            else if(data[pos.first][pos.second] == 1){

            }
            else if(data[pos.first][pos.second] == 2){
                if(!ok_click(pos)){
                    int di = data[pos.first][pos.second];
                    di = (di + 1) % 4;
                    pos.first += dirs[di][0];
                    pos.second += dirs[di][1];
                }

            }
            else{
                if(IN(pos.first-1,pos.second) && data[pos.first-1][pos.second] <= 1 && data[pos.first-1][pos.second] >= 0){
                    pos.first--;
                }
                else if(!ok_click(pos)){
                    int di = data[pos.first][pos.second];
                    di = (di + 1) % 4;
                    pos.first += dirs[di][0];
                    pos.second += dirs[di][1];
                }

            }



            click(pos);
        }

//        for(int i=1;i<=n;++i) {
//            for (int j = 1; j <= m; ++j) {
//                cout << data[i][j];
//            }
//            cout<<endl;
//        }


        if(ans.size() > 6000){
            assert(0);
            printf("-1\n");
        }
        else{
            printf("%d\n",ans.size());
            for(pii p : ans){
                printf("%d %d\n",p.first,p.second);
            }
        }
	}


	return 0;
}





