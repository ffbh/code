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

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int n, m;
LL bounty, damage, increace;
bool infi;

pii enemy[100010];

struct Event{
	int time, idx;
	pii e;
	bool operator<(const Event& p)const{
		if (time != p.time)
			return time < p.time;
		else{
			return e < p.e;
		}
	}
}data[100010];


void input(){
	in >> n >> m;
	in >> bounty >> increace >> damage;

	for (int i = 0; i < n; ++i){
		int max_h;
		//in >>  max_h >> enemy[i].first >> enemy[i].second;
		scanf("%d%d%d", &max_h, &enemy[i].first, &enemy[i].second);
		if (max_h <= damage)
			infi = 1;
		
	}
	for (int i = 0; i < m; ++i){
	//	in >> data[i].time >> data[i].e.first >> data[i].e.second;
		scanf("%d%d%d", &data[i].time, &data[i].e.first, &data[i].e.second);
		data[i].e.first--;

	}

}

vector<pii> V[100010];

vector<pii> eve[100010];
int pos[100010];

int blood_end[100010];


map<int, int> mmp;


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		if (increace){
			if (infi){
				cout << -1 << endl;
				return 0;
			}
		}

		sort(data, data + m);
		for (int i = 0; i < n; ++i)
			blood_end[i] = enemy[i].first;
		for (int i = 0; i < m; ++i){
			blood_end[data[i].e.first] = data[i].e.second;

		}

		for (int i = 0; i < n; ++i)
			eve[i].push_back(mp(0,enemy[i].first));
		for (int i = 0; i < m; ++i){
			data[i].idx = eve[data[i].e.first].size();
			eve[data[i].e.first].push_back(mp(data[i].time,data[i].e.second));
		}

		for (int i = 0; i < n; ++i)
			eve[i].push_back(mp(2e9, 2e9));

		if (increace){
			for (int i = 0; i < n; ++i){
				if (blood_end[i] <= damage && enemy[i].second == 0){
					cout << -1 << endl;
					return 0;
				}

			}
		}

		for (int i = 0; i < n; ++i){
			if (enemy[i].first <= damage){
				if (enemy[i].second != 0){
					int E = (damage - enemy[i].first) / enemy[i].second;
					V[i].push_back(mp(0, E));
				}
				else{
					while (eve[i][pos[i]].second <= damage){
						pos[i]++;
					}
					V[i].push_back(mp(0, eve[i][pos[i]].first - 1));
				}
			}
		}

		/**rege === 0*?*/

		


		for (int i = 0; i < m; ++i){
			int m_id = data[i].e.first;
			int blood = data[i].e.second;
			if (blood > damage){
				if (V[m_id].empty() || V[m_id].back().second < data[i].time){
					//nothing
				}
				else{
					V[m_id].back().second = data[i].time - 1;
				}
			}
			else{
				int start_time, E;
				if (V[m_id].empty() || V[m_id].back().second < data[i].time){
					start_time = data[i].time;
				}
				else{
					start_time = V[m_id].back().first;
					V[m_id].pop_back();
				}
				if (enemy[m_id].second != 0){
					E = data[i].time + (damage - blood) / enemy[m_id].second;
				}
				else{
					if (pos[m_id] < data[i].idx){
						pos[m_id] = data[i].idx;
					}
					while (eve[m_id][pos[m_id]].second <= damage){
						pos[m_id]++;
					}
					E = eve[m_id][pos[m_id]].first - 1;
				}
				V[m_id].push_back(mp(start_time, E));

			}
		}

		for (int i = 0; i < n;++i)
		for (pii p : V[i]){
			mmp[p.first]++;
			mmp[p.second + 1]--;
			mmp[p.second] += 0;
		}

		LL ans = 0;
		LL num = 0;
		for (pii p : mmp){
			num += p.second;
			ans = max(ans, num * (bounty + p.first * increace));
		}

		cout << ans << endl;


	}


	return 0;
}





