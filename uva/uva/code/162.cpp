#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
queue<int> q1, q2;
stack<int> s1, s2;
deque<int> deck;
int h[256];
void push(char c,int play){
	if (play == 1){
		s1.push(h[c]);
	}
	else{
		s2.push(h[c]);
	}
}


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	h['J'] = 1;
	h['Q'] = 2;
	h['K'] = 3;
	h['A'] = 4;
	string s;
	while (in >> s&&s != "#"){


		while (!s1.empty())
			s1.pop();
		while (!s2.empty())
			s2.pop();
		while (!deck.empty())
			deck.clear();


		int play = 1;
		push(s[1], play);
		play = 3 - play;
		for (int i = 0; i < 51; ++i){
			in >> s;
			push(s[1], play);
			play = 3 - play;
		}

		play = 1;
		int mark = -1;
		while (1){
			if (play == 1){
				if (deck.empty()){
					deck.push_back(s1.top());
					s1.pop();
				}
				else if (deck.back() == 0){
					if (mark == -1){
						if (s1.empty())
							break;
						deck.push_back(s1.top());
						s1.pop();
					}
					else{
						while (!deck.empty()){
							s1.push(deck.front());
							deck.pop_front();
						}
						mark = -1;
						play = 3 - play;
					}
				}
				else{
					mark = 2;
					int num = deck.back();
					bool e = 0;
					for (int k = 0; k < num&&!e; ++k){
						if (!s1.empty()){
							deck.push_back(s1.top());
							s1.pop();
							if (deck.back() != 0){
								e = 1;
							}
						}
						else{
							break;
						}
					}
					
				}
			}
			else{
				if (deck.empty()){
					deck.push_back(s2.top());
					s2.pop();
				}
				else if (deck.back() == 0){
					if (mark == -1){
						if (s2.empty())
							break;
						deck.push_back(s2.top());
						s2.pop();
					}
					else{
						while (!deck.empty()){
							s2.push(deck.front());
							deck.pop_front();
						}
						mark = -1;
						play = 3 - play;
					}
				}
				else{
					mark = 1;
					int num = deck.back();
					bool e = 0;
					for (int k = 0; k < num&&!e; ++k){
						if (!s2.empty()){
							deck.push_back(s2.top());
							s2.pop();
							if (deck.back() != 0){
								e = 1;
							}
						}
						else{
							break;
						}
					}
					
				}

			}
			play = 3 - play;

		}

		if (!s1.empty()){
			cout << 2 << " " << s1.size() << endl;
		}
		else{
			cout << 1 << " " << s2.size() << endl;
		}





	}















	return 0;
}