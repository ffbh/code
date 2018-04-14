#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
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
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

typedef long long LL;

string path = "/opt/bin";
string trash_path="/work/trash";
string log_path = "/work/trash/log/";
long long MAX_FILE_SIZE = (LL)5 * 1024 * 1024;//5M


string getName(char* all){
int len = strlen(all);
assert(len > 0);
int pos = -1;
for(int i=len-1;i>=0;--i)
if(all[i]=='/'){
  pos = i;
  break;
}

//assert(pos >= 0);
string name = "";
for(int i=pos+1;i<len;++i)
  name += all[i];
return name;
}

bool is_File(const char* file){
  FILE* fp = fopen(file,"r");
  if(fp == NULL)
    return 0;
  else{
    fclose(fp);
    return 1;
  }


}


long long get_file_size(const char* file){
  FILE* fp = fopen(file,"r");
  if(fp == NULL)
    return -1;
  else{
    fseek(fp,0L,2);
    return ftell(fp);
    
  }

}


string bash_shell(string cmd){
  char buff[1024];
  string ans;
  FILE* fp = popen(cmd.c_str(),"r");
  if(fp != NULL){
     fgets(buff,sizeof(buff),fp);
     ans = string(buff);
  }
  else{
     perror("fail to popen");
     return "";
  }

  pclose(fp);
  return ans.substr(0,ans.length()-1);
}



string get_exec_path(){
  char buff[1024];
  string ans;
  FILE* fp = popen("pwd","r");
  if(fp != NULL){
     fgets(buff,sizeof(buff),fp);
     ans = string(buff);
  }
  else{
     perror("fail to popen");
     return "";
  }

  pclose(fp);
  return ans;
}


string trim(string s){
    return s.substr(0,s.length()-1);
 // int spos = 0,epos = s.length()-1;
//  while(spos < epos && (s[spos]==' ' || s[spos] == '\t' || s[spos] == '\n'))
  //    spos++;
//  while(epos > spos && (s[epos]==' ' || s[epos] == '\t' || s[epos] == '\n'))
  //    epos++;
//  return s.substr(spos,epos - spos );
}

void LOG(string sh){
  string date = string("date '+%Y-%m-%d %H:%M:%S'");
  date += " >> " + log_path;
  system(date.c_str());
  string log = sh + " >> " +  log_path;
  system(log.c_str());
}


int main(int argc,char** argv){



log_path = log_path + string(argv[0]);
//printf("%d\n",argc);
///for(int i=0;i<argc;++i)
//  printf("%s\n",argv[i]);

assert(argc >= 1);
string file = string(argv[argc-1]);
string oldfile = file;

if(file[0] != '/'){
  file = trim(get_exec_path()) + "/" + file;
}
//cout<<file<<endl;
if(is_File(file.c_str()) && get_file_size(file.c_str()) < MAX_FILE_SIZE){
  string cmd = "cp " + file + " " + trash_path+"/"+bash_shell("date '+%Y-%m-%d@%H:%M:%S'")+"_"+oldfile;
 // cout<<cmd<<endl;
  LOG(string("echo ")+"'"+cmd+"'");
  system(cmd.c_str());
}
else{
  //cout<<"file is not exist or file size large than "<<MAX_FILE_SIZE<<endl;
 
  // string cmd = "echo 'file is not exist or too large' >> " + log_path + string(argv[0]);
 //  system(cmd.c_str());
   LOG("echo 'file is not exist or too large'");

}



string command_file = path + "/" + getName(argv[0]);

//string command_file = path + "/" + "pp";



string args = " ";
for(int i=1;i<argc;++i)
  args += string(argv[i]) + "  ";

string exe_cmd = command_file + args;

//cout<<exe_cmd<<endl;


system(exe_cmd.c_str());


return 0;
}
