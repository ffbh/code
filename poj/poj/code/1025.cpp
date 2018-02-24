#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//ifstream in("C:\\input.txt");
struct Room{
	int floor, roomid, staytime;
	string getFR(){
		string ret(4, '0');
		ret[0] = floor / 10 + '0';
		ret[1] = floor % 10 + '0';
		ret[2] = roomid / 10 + '0';
		ret[3] = roomid % 10 + '0';
		return "room " + ret;

	}
};

void printfTime(int t){
	int h = t / 3600;
	t %= 3600;
	int m = t / 60;
	t %= 60;
	int sec = t;
	printf("%02d:%02d:%02d ", h, m, sec);

}

struct Message{
	int starttime, endtime;
	string message;
};
struct Agent{
	Agent(){
		vr_index = now_roomid = -1;
		now_floor = 1;
		state = "";
		wait = 0;
	}
	string state;
	char code;
	int entrytime, lasttime;
	bool wait;
	string waitmess;
	vector<Room> vr;
	int vr_index, now_floor, now_roomid;
	vector<Message> ans;
	bool operator<(const Agent& p)const{
		return code < p.code;
	}

	void output(){
		putchar(code);
		putchar('\n');
		for (int i = 0; i < ans.size(); ++i){
			printfTime(ans[i].starttime);
			printfTime(ans[i].endtime);
			printf("%s\n", ans[i].message.c_str());
		}
		putchar('\n');
	}
};

vector<Agent> va;

int getTimeIntInt(){
	string s;
	cin >> s;
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int m = (s[3] - '0') * 10 + s[4] - '0';
	int sec = (s[6] - '0') * 10 + s[7] - '0';
	return h * 3600 + m * 60 + sec;
}

struct Node{
	int index;
	int time;

	bool operator<(const Node& p)const{
		if (time != p.time)
			return time > p.time;
		else
			return index > p.index;
	}
};



priority_queue<Node> qn;
int roomconf[20][20], elevtorconf[20];

void Init(){
	va.clear();
	memset(roomconf, -1, sizeof(roomconf));
	memset(elevtorconf, -1, sizeof(elevtorconf));
	while (!qn.empty())
		qn.pop();
}

int main(){

	Init();

	char code;
	while (cin >> code && code != '.'){
		Agent agent;
		agent.code = code;
		agent.entrytime = getTimeIntInt();
		agent.lasttime = agent.entrytime;
		int fr;
		while (cin >> fr && fr){
			Room room;
			room.floor = fr / 100;
			room.roomid = fr % 100;
			cin >> room.staytime;
			agent.vr.push_back(room);
		}
		va.push_back(agent);
	}

	sort(va.begin(), va.end());
	for (int i = 0; i < va.size(); ++i){
		Node node;
		node.index = i;
		node.time = va[i].entrytime;
		qn.push(node);
	}

	while (!qn.empty()){
		Node node = qn.top();
		qn.pop();
		Agent& now = va[node.index];
		


		if (now.vr_index == -1){//entry building
			Message mess;
			mess.starttime = now.entrytime;
			mess.endtime = now.entrytime + 30;
			mess.message = "Entry";
			now.ans.push_back(mess);

			now.vr_index++;
			now.lasttime = mess.endtime;
			node.time = mess.endtime;
			qn.push(node);
		}
		else if (now.vr_index >= now.vr.size()){//exit building
			if (now.now_floor != 1){
				int floor = now.now_floor;
				int gofloor = 1;
				if (now.state != "elevator" && now.state !=""){
					Message mess;
					mess.starttime = node.time;
					mess.endtime = node.time + 10;
					mess.message = "Transfer from " + now.state + " to elevator";
					now.ans.push_back(mess);
					now.state = "elevator";

					now.lasttime = mess.endtime;
					node.time = mess.endtime;
					qn.push(node);
					continue;
				}

				if (node.time % 5 != 0){//wait for elevator
					now.wait = 1;
					now.waitmess = "Waiting in elevator queue";
					node.time = node.time - node.time % 5 + 5;
					qn.push(node);
				}
				else if (node.time <= elevtorconf[floor]){//wait for elevator
					now.wait = 1;
					now.waitmess = "Waiting in elevator queue";
					node.time = elevtorconf[floor] + 5;
					qn.push(node);
				}
				else{//entry elevator
					if (now.wait){
						Message mess;
						mess.starttime = now.lasttime;
						mess.endtime = node.time;
						mess.message = now.waitmess;
						now.ans.push_back(mess);
						now.wait = 0;
					}

					Message mess;
					mess.starttime = node.time;
					mess.endtime = node.time + 30 * abs(gofloor - floor);
					mess.message = "Stay in elevator";
					now.ans.push_back(mess);

					now.state = "elevator";
					elevtorconf[floor] = mess.starttime;

					now.now_floor = gofloor;
					now.lasttime = mess.endtime;

					node.time = mess.endtime;
					qn.push(node);
				}

			}
			else{//exit
				Message mess;
				mess.starttime = node.time;
				mess.endtime = node.time + 30;
				mess.message = "Exit";
				now.ans.push_back(mess);
			}
		}
		else{
			int floor = now.now_floor;
			int gofloor = now.vr[now.vr_index].floor;
			int goroomid = now.vr[now.vr_index].roomid;
			if (floor == gofloor){
				if (now.state == ""){//entry room
					if (roomconf[gofloor][goroomid] <= node.time){
						if (now.wait){
							Message mess;
							mess.starttime = now.lasttime;
							mess.endtime = node.time;
							mess.message = now.waitmess;
							now.ans.push_back(mess);
							now.wait = 0;
						}
						now.state = now.vr[now.vr_index].getFR();
						Message mess;
						mess.starttime = node.time;
						mess.endtime = node.time + now.vr[now.vr_index].staytime;
						mess.message = "Stay in " + now.state;
						now.ans.push_back(mess);

						roomconf[gofloor][goroomid] = mess.endtime;

						now.vr_index++;
						now.lasttime = mess.endtime;
						node.time = mess.endtime;
						qn.push(node);
					}
					else{//wait for room
						now.wait = 1;
						now.waitmess = "Waiting in front of " + now.vr[now.vr_index].getFR();
						node.time = roomconf[gofloor][goroomid];
						qn.push(node);
					}

				}
				else{//tran room to room
					Message mess;
					mess.starttime = node.time;
					mess.endtime = node.time + 10;
					mess.message = "Transfer from " + now.state + " to " + now.vr[now.vr_index].getFR();
					now.ans.push_back(mess);

					now.state = "";
					now.lasttime = mess.endtime;
					node.time = mess.endtime;
					qn.push(node);
				}


			}
			else{//want to elevator
				if (now.state != "elevator" && now.state != ""){//tran to elevator
					Message mess;
					mess.starttime = node.time;
					mess.endtime = node.time + 10;
					mess.message = "Transfer from " + now.state + " to elevator";
					now.ans.push_back(mess);
					now.state = "elevator";

					node.time = mess.endtime;
					now.lasttime = mess.endtime;
					qn.push(node);
					continue;
				}

				if (node.time % 5 != 0){//wait for elevator
					now.wait = 1;
					now.waitmess = "Waiting in elevator queue";
					node.time = node.time - node.time % 5 + 5;
					qn.push(node);
				}
				else if (node.time <= elevtorconf[floor]){//wait for elevator
					now.wait = 1;
					now.waitmess = "Waiting in elevator queue";
					node.time = elevtorconf[floor] + 5;
					qn.push(node);
				}
				else{// entry elenator
					if (now.wait){
						Message mess;
						mess.starttime = now.lasttime;
						mess.endtime = node.time;
						mess.message = now.waitmess;
						now.ans.push_back(mess);
						now.wait = 0;
					}
					Message mess;
					mess.starttime = node.time;
					mess.endtime = node.time + 30 * abs(gofloor - floor);
					mess.message = "Stay in elevator";
					now.ans.push_back(mess);

					now.state = "elevator";
					elevtorconf[floor] = mess.starttime;

					now.now_floor = gofloor;
					now.lasttime = mess.endtime;

					node.time = mess.endtime;
					qn.push(node);
				}
			}
		}
	}


	for (int i = 0; i < va.size(); ++i){
		Agent& now = va[i];
		now.output();
	}











	return 0;
}