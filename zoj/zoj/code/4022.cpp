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
ifstream in("/home/fbh/CLionProjects/acm/InOutput/train.txt");
//ifstream inn("/home/fbh/CLionProjects/acm/InOutput/train.txt");
ofstream ou("/home/fbh/CLionProjects/acm/InOutput/train2.txt");
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

string IA[144]={"Je","Tang","U","Nae","Jin","So","Tan","Bing","Nu","Hak","Hwang","Sam","Sagong","Gung","Beon","Jun","Po","I","Jeo","Ho","Min","Gim","Seonu","Chun","Sa","Hwa","Dang","Na","Myeong","Bu","Geun","Chu","Pyeon","Ha","Don","Jeong","Gwak","Mo","Seok","Eom","Gong","Ong","Dae","Hae","Hwangmok","Man","Won","Myo","Hwan","Dokgo","Han","Song","Gyo","Seomun","Sun","Muk","Yuk","Gil","Eum","Gae","Mu","Noe","Ryeo","Pung","Dan","Chang","Yong","Jam","Bae","Da","Bi","Eogeum","Hwangbo","Ban","Du","Ham","Si","Gwon","Gam","Bong","Cho","Choe","Gyeong","Bang","Ju","Mangjeol","Jeup","Heo","Rang","Tae","Gal","Ya","Pan","Su","A","Mi","Sim","Dok","Pyeong","Guk","Gi","Dam","Mok","Wang","Kwae","Beom","Wan","O","Jang","Maeng","Hu","Mae","Sin","Go","Un","No","Ran","Dong","Im","Seo","Yo","Yeop","Gwan","Yeong","Pyo","In","Bak","Dongbang","Ra","Yu","Deungjeong","Tak","Eo","Hong","Hyeong","Seong","Gyeon","Roe","Seung","Bin","Geum","Baek","Chong","Cha"};
string IB[1387]={"Gangho","Byeongdon","Yungu","Sangsil","Jongguk","Bonyeong","Suwon","Busik","Hyeonyeong","Suha","Chijung","Nokyeong","Eungyeong","Chilseung","Jaegon","Hyewon","Yeon","Hyeontak","Duok","Hoseon","Changgwon","Giljong","Ungjo","Gyoil","Hwapyeong","Donghyeon","Gwangjo","Yeonghyeon","Sijun","Bongcheol","Chowon","Hyeondeuk","Munsuk","Seungju","Jinsu","Bokhyeong","Uijin","Cheongwon","Juni","Suhwang","Jonggwan","Pilsang","Manheung","Heonseop","Seongbu","Jumi","Jeonghwa","Huiseop","Jaewon","Jaehak","Oksun","Sangil","Gyeongmun","Sori","Bonghak","Jegyu","Eunjung","Taebo","Inyeong","Juhyeon","Yeonghui","Yunji","Gyuseon","Gisu","Noa","Chungsik","Gigap","Gyoik","Dupyo","Goun","Rumi","Gyuseol","Hyeon","Inbeom","Ina","Taeyong","Namseong","Munhan","Haenyeong","Dahae","Geumseok","Yeyang","Okjin","Yeochi","Seungbo","Somyeong","Sangdo","Geunchan","Jeongmo","Gyeongwon","Ilsun","Haesun","Suhong","Doni","Ilseong","Ikjeom","Changson","Jueun","Byeongu","Jaehyo","Huisik","Sejin","Malsuk","Byeonghu","Huicheol","Yongsu","Munseok","Jijang","Chunggil","Heunggi","Hyeonseong","Munryong","Chan","Yebong","Jiyeon","Sik","Heonchang","Gwanghui","Dujin","Suneon","Juhong","Hun","Jaejun","Eunbin","Hyeonho","Jungu","Yeongdal","Taepung","Hosan","Hakyeon","Yeonga","Yeongwan","Gyuman","Oryeon","Huido","Eokgi","Gonggeun","Chanbeop","Jayeol","Seri","Byeongcheol","Howon","Gyusu","Inhwan","Eunryeong","Jo","Gyeongpil","Donggap","Sukjeong","Seonga","Guman","Sangdon","Namjun","Jeonguk","Kure","Juseon","Eunbeom","Junhwan","Cheolsu","Inhun","Yongsik","Jisuk","Joheung","Seonho","Inbong","Yeongseop","Soyeon","Ungjeon","Haesik","Junu","Huiyeon","Huiwon","Hojung","Yongpil","Semi","Gyeonghwa","Dalsu","Deokgyu","Dugwan","Deokseon","Sangseop","Seokhwan","Hyeokjun","Taejo","Oseong","Jeunghan","Taejin","Jongok","Bangrin","Guan","Jajeom","Yuran","Muryong","Duna","Inpyo","Sinmyeong","Sangmi","Myeongseong","Byeongsu","Hyeongon","Jeu","Heungpyo","Jinu","Eulna","Hyeongwon","Eungryong","Dujun","Ira","Huisang","Beommo","Guhong","Yongnam","Misorang","Sanghun","Geolryun","Yongwon","Myeongil","Jangu","Myeongwon","Chungseon","Seonghyeok","Juwon","Soyu","Useok","Oseol","Jeongsuk","Gangguk","Seulbi","Ihwa","Yeorin","Eunae","Pali","Yeop","Jeongu","Somin","Minjun","Baeksu","Eunseong","Dongju","Wonjun","Gigu","Yowon","Myeongjung","Seonhui","Sungyu","Seunggi","Isu","Manik","Seongtae","Hyeok","Hyeongcheol","Sunbong","Seungrak","Nakyeong","Chaea","Juyeong","Geon","Jasim","Yeseul","Yohwan","Jia","Beomgi","Sugyeong","Hyeonseung","Bohui","Unggil","Baekho","Eungchun","Jeongto","Haeseok","Gyugap","Hyeseong","Nakyun","Deulim","Oban","Huipal","Dongjin","Seungun","Yumin","Sangbyeong","Hyeongmo","Insun","Geunji","Jongo","Taeseong","Honggeun","Saengji","Manho","Hyeonjung","Seokgyu","Myeongseung","Sehyeok","Gitae","Sigyeong","Mingu","Yalsuk","Eungsik","Yeongmu","Dalhui","Eunsu","Sangrok","Jaeseok","Taejeong","Dongseo","Sunha","Heunggil","Byeongwi","Hyeonhoe","Soli","Geonpyeong","Jeongmu","Haemi","Sutaek","Jaemin","Icheom","Donghyeok","Doha","Injik","Myeonggon","Jitu","Gwansik","Yeongae","Yeombang","Hoyeol","Musaeng","Namcheol","Minhyeon","Sangtae","Geukjeung","Uhyeok","Jaemo","Yongjin","Seunggwon","Byeongchun","Nakseo","Hongsik","Dongmin","Yeojun","Yeongguk","Ibae","Seolju","Seongin","Yeongi","Jonghun","Nakyeon","Seokje","Bangheon","Ran","Munsik","Jeongim","Yunbok","Dosun","Chiwon","Seokrae","Hyeonggon","Yeongin","Bawi","Gyeonggu","Seoksu","Seungmin","Bonsang","Taegon","Myeongchan","Sangbyeok","Cheonsu","Seungu","Hyeseok","Jongyun","Heonpyo","Inje","Yeongje","Eunjae","Myeongik","Eunju","Gyunam","Gyuheon","Gyeonghui","Yeongsu","Baul","Jeonsik","Jigang","Bonneung","Jeongbok","Rayeong","Seongguk","Chunseong","Ryeongu","Saerim","Gane","Dusun","Sangwon","Yeryeong","Jeongho","Seongyong","Euni","Sanghyeon","Sangok","Gyeongu","Doeon","Nogap","Sowon","Buseong","Wijong","Sunok","Sulji","Minseung","Sacheol","Gyeongchan","Jungi","Huichan","Museong","Jinho","Bonggi","Yeongmyeong","Seongpyo","Byeonguk","Eungwang","Miran","Dongchan","Myeonghun","Minhyeok","Uyeon","Bokgi","Dongyeol","Sogeo","Cheonsik","Mijin","Hyeongji","Seuk","Jaebeom","Nakhun","Jihaeng","Jingeon","Jong","Jauk","Sewon","Eunjin","Seyeon","Ajin","Yeongbae","Duchi","Inguk","Seungpyo","Sehwang","Hanik","Hyosin","Giyun","Ilhu","Ilhwan","Wonho","Changil","Gilseung","Minseon","Yeonggyun","Huipyo","Sangu","Gyubeom","Seongdam","Taeyeong","Ocheon","Sehong","Chunhui","Bau","Mungchi","Iseul","Hojun","Hyeonman","Jeonghyeok","Unyeong","Haeseong","Hyeonggwang","Hyeokbin","Jachun","Junga","Manpyo","Jehun","Giwan","Yesu","Sangik","Jeongwan","Haechang","Daseong","Changsik","Geomsu","Soang","Hyeonsil","Deokhwan","Rokheun","Jeongeum","Seonil","Hansu","Mansu","Somang","Nakgil","Namchun","Sanggyu","Hyeongjin","Jiseon","Seongju","Gyuhyeon","Junyong","Seonggyeong","Jaeeun","Solbin","Hoje","Bongju","Juyeol","Deokhun","Wonsun","Jijon","Yongu","Uicheol","Hyeonje","Jaedeuk","Beoprin","Daegi","Giheung","Yeonha","Yonggwan","Jonggeun","Duseok","Byeonghui","Hwangyu","Deokim","Hakgyu","U","Jaeyeop","Wongi","Giak","Seungil","Namjeong","Yeongju","Sindeok","Insu","Hyoseong","Sadok","Chunggi","Hangi","Yeongrok","Seunggon","Okbin","Junghyeon","Sanghong","Suho","Wonchaek","Myeonghwa","Yeonjun","Jineon","Muryeok","Gangchan","Chun","Seol","Yongin","Gibeom","Taegap","Pulip","Dongu","Gwangnam","Haeyeon","Chanhyeon","Gyuseop","Songryeong","Gaeul","Changyeong","Seongryul","Sugeun","Gwija","Gyeongjung","Manre","Gyeongman","Geunyeong","Junpyo","Yeongjun","Changi","Ihyeon","Seungchun","Gyeongyeop","Mija","Seondal","Daeyong","Taehwi","Sieun","Ubin","Gamdo","Yeongeun","Migyeong","Binson","Suri","Hayan","Jongmyeon","Gyuseung","Wangu","Geukyeong","Uigyeong","Seunghui","Hanui","Mungi","Jagyun","Jeongui","Jongbeom","Palmaen","Seongmo","Gakgyu","Eunho","Cheolmin","Myeongun","Inseon","Seongho","Gyeongja","Sunyeong","Indeuk","Jeongyang","Daejung","Byeongjik","Siyeong","Gwinam","Jongchan","Chaeyeong","Jongpil","Seonggap","Donghan","Jeongjae","Hongeun","Gahye","Songyeon","Ikhui","Yeongseong","Jijik","Jiseop","Yungyeong","Mina","Muyong","Seongdae","Inhu","Sihyeon","Muil","Minho","Yuksa","Inho","Ajung","Namjo","Gwangmo","Daemyeong","Dongun","Taerim","Gyeongeun","Sanghwa","Hwanghu","Seungchan","Seolbu","Gayeon","Miyeong","Sunil","Junggwon","Guk","Gyupyo","Dongik","Munhui","Jeok","Yunjik","Yangsun","Yusu","Najeong","Gangyong","Okcheol","Minsik","Sangcheon","Hunjeong","Soeung","Gayun","Dayeong","Ryeonho","Malbong","Seungyong","Seongyeong","Gangto","Changwon","Daeseong","Yunha","Taehoe","Jinseon","Gyepa","Jehu","Chunhwa","Siho","Sehui","Hwandu","Chungil","Myeongsu","Baekhyeon","Wonyong","Yeorim","Gyeongrok","Byeongryeol","Myeonghoe","Changyong","Boyeong","Hayun","Samsu","Yongseong","Yonguk","Yeohae","Jongeung","Nomin","Janghwa","Munpyo","Seonggyu","Pyeongu","Sanggon","Jinhu","Gyeong","Hyeonbin","Seokgi","Hunhyeon","Jeonggwon","Deokhoe","Songju","Dani","Bonggil","Sangjung","Junsik","Seokyeong","Jangyeop","Daeho","Yongik","Gyucheol","Jiho","Ojun","Seunghun","Jeonghui","Gyuseong","Jiwan","Gyeongwan","Myeongseop","Gwangyeol","Suntae","Namsan","Inyong","Hanguk","Yeongyeong","Suin","Changgeuk","Haesong","Seonggeol","Sangjin","Gyeonguk","Bogeun","Jungseo","Uhang","Mihong","Hohyeon","Sago","Seongmun","Sira","Ilseung","Ilu","Sangbaek","Hyori","Deoksul","Yeongchan","Byeongju","Seokmo","Jaeyun","Yeongji","Subin","Sinae","Gyuri","Deokhan","Sera","Gyoan","Seonhwa","Heonseong","Geungyeon","Gwangyeon","Hyomyeong","Munsun","Garam","Suchang","Cheolju","Hyeonggeun","Huiseung","Gyeongyeong","Jaebong","Sunchang","Eoni","Sechae","Seungbeom","Iljun","Cheondeuk","Daeseung","Jaehun","Hyosuk","Gangseok","Yunhwan","Sunmo","Huibeom","Woncheol","Heungyong","Gwangak","Dain","Byeongwon","Myeongsin","Geonmo","Chiyang","Unpyo","Gyeongjae","Hyoyeon","Hongje","Yeongsik","Jihan","Sihak","Anna","Yongok","Haesuk","Gyubaek","Geunhyeong","Sinnam","Gitaek","Gukhyeon","Seungmi","Bogyeong","Yunho","Mi","Ilmok","Gyeongsik","Ujin","Hyojin","Hayeon","Hyojeong","Eunha","Gijeong","Munhyeok","Jinhui","Jaseong","Gyeongsu","Jongdeok","Gyuok","Jongbin","Hyeonguk","Jeongwon","Minhan","Gyeheung","Jimin","Hyeontae","Geunpyo","Gichan","Bin","Nayeon","Mira","Ungseo","Sinbong","Janggang","Munhoe","Jihun","Dongyeop","Gwanyeong","Wongyeong","Uhui","Seoin","Wi","Sejae","Yeonhui","Yebin","Yang","Jinseok","Seokhui","Seonye","Seoku","Geukgyeom","Geurin","Jiyun","Seokju","Seonja","Seonyu","Huiji","Yeonghwan","Yeongtaek","Ryeong","Seungman","Seongje","Myeonghyeon","Chunsaeng","Uiji","Jinseop","Pyeonghoe","Hojeong","Nari","Deokhwa","Yua","Yongpyo","Eungseop","Miso","Byeonghyeon","Gongju","Changuk","Jiae","Hyeonsuk","Yeongha","Yeongbok","Ingwon","Minbok","Ungryeol","Gyujin","Haknyeon","Jinbo","Wangguk","Inji","Ingu","Jaeil","Yeongchun","Jaeseo","Hyeongyu","Jonggyun","Seon","Hyeongjun","Uiyeon","Jeonchung","Jaeryong","Seonggwan","Sangyong","Jangseok","Yeongjeong","Hyeongsik","Sangryeol","Yongmuk","Hyeonseon","Wanyong","Eunryul","Minu","Yeongse","Inchang","Huiseon","Myeonggwan","Taewon","Hyeonmo","Yeongcheol","Gamchan","Bonggon","Seure","Yejin","Gyeonggi","Arang","Jaegyun","Dalhwan","Seongu","Seungyeon","Harin","Hangseo","Nakgyun","Jaewan","Juseok","Seonha","Suseong","Ucheol","Sunu","Soran","Heonjae","Yeonggi","Gu","Janggyeom","Yeongtae","Gapgyeong","Haejin","Hyeonseop","Jaeyong","Ondong","Yugeun","Gipyo","Sewan","Myeongju","Seyeong","Seongheun","Byeonggwon","Yeona","Changhyeon","Junggak","Wongyun","Cheonga","Yubu","Giu","Deokjuk","Chiyong","Yeonggeun","Deoksun","Incheon","Nameok","Cheolhwan","Sinhye","Mari","Intaek","Seongjin","Ilgu","Jegyeong","Gwangeun","Seunghye","Yunhyeong","Mingyeong","Huijung","Jaeseong","Ja","Seonggu","Jewon","Dongjun","Gyeongae","Hyeonjong","Seonggeun","Hakryeol","Gwansu","Jaeseung","Jaegwang","Sora","Yonghui","Taehui","Jungdong","Giung","Bangyong","Sihyeong","Jaehang","Hyeseon","Byeongjo","Byeongseok","Hakseo","Dam","Chanung","Simin","Mihui","Seoyeong","Dogyeom","Hyerim","Daegwan","Hyesu","Nanpa","Hongseok","Gyeonghak","Donggeun","Geukbae","Gapseong","Jugong","Gyuje","Jeongryeol","Hui","Eunjeong","Jeonggu","Gwangu","Seonghyeon","Giri","Jinseong","Eungmo","Geonpyo","Yeonggil","Nogeun","Seonju","Gyeongjik","Hongji","Sunchil","Jiman","Sosaeng","Daim","Gwanghong","Daran","Gwanu","Jiyong","Jagyeong","Janghyeok","Taeil","Gihyeon","Hogyeong","Yeonsu","Yohan","Donghwa","Dongseok","Gukgang","Gura","Sanghyeok","Yangrae","Sehu","Jae","Uhong","Ildu","Jeongdal","Euna","Injeong","Hwaseon","Reti","Jeongnam","Junho","Mujin","Guhan","Jeongsik","Sunmok","Harim","Hajin","Myeonghwan","Bokgeo","Beomsan","Jayeon","Donghwan","Beomgon","San","Chansuk","Heungmun","Hanhui","Hyeongdo","Taegyun","Inha","Junhui","Dongrip","Deokhui","Haechan","Yunhui","Gukjin","Ukseo","Donggu","Seongun","Chanuk","Sangjeong","Jongseop","Jangsik","Sangun","Ak","Sujong","Jonggu","Jinmyeong","Seonmi","Jingap","Suyeon","Jiwon","Sunim","Seohui","Yunseon","Munsu","Chorong","Jaro","Junyeong","Namil","Chunhyang","Yuryeon","Bongsu","Eungdu","Wonsuk","Jemin","Minseo","Haejo","Beomhyeon","Huigyeong","Sayeon","Yangho","Wonhyeong","Chulgu","Udol","Hyeongtae","Ikseon","Beomju","Seonmyeong","Daerak","Byeongjae","Wonjung","Wonil","Eunbyeol","Jaejin","Hyeongil","Sajun","Narae","Seonggeon","Eungi","Hyeongryeol","Seha","Chido","Jaepil","Sin","Daehui","Yunseok","Hae","Huijae","Taeju","Jungil","Uijun","Seongheon","Daesik","Gangmin","Myeongcheol","Chungsu","Yeol","Pildal","Gwangju","Bongil","Dingyo","Jaeho","Deukchul","Giseok","Yeongjae","Gyeongheum","Minyeong","Yeongbin","Sarang","Jaejeong","Daesu","Bangeon","Gyeonu","Suran","Hyeonhwak","Jeongsang","Jonggi","Gyeongjin","Jamyeong","Rojin","Chanmi","Seongjeung","Jongsu","Seongyo","Yunok","Useong","Gwanghyeon","Yeonggyo","Seongae","Jeguk","Incheom","Changmu","Haewon","Huira","Dusik","Seok","Hyeonsu","Taegyeong","Bokhyeon","Aseop","Jaerim","Igyeong","Yeook","Boyun","Janggun","Dalhyeong","Chungi","Myeongsun","Yerin","Jaecheol","Hogu","Jaegeun","Sihyeok","Hansol","Hyein","Gyeongcheol","Hyesuk","Hyeran","Hansang","Miryeong","Chanyong","Seomyeon","Morae","Dohyang","Jisu","Gwangcheol","Hyeongseok","Seungwon","Hoechan","Mangi","Nakcheong","Haeun","Sangmin","Danyeong","Beomgye","Chiyeol","Hoseong","Sanggil","Jeongmi","Chaewon","Hwan","Dongsu","Jaeuk","Seunghwan","Sea","Gyeju","Jueok","Deokbae","Satgat","Sumi","Jaegeuk","Sujaeng","Bongyeon","Jihyeon","Goengpil","Boseon","Eunseo","Giryong","Hyocheon","Jeongyeol","Sangmu","Taeun","Ikjung","Dongsik","Namgil","Dongbin","Myeongseok","Jungyu","Hyeoncheon","Mingyu","Sunseok","Jinhwan","Seungcheol","Seongbo","Eungno","Gaengyo","Hyeongbo","Jeongguk","Jeomhui","Palgyun","Dorae","Jinhwa","Bujin","Gapsu","Geonchang","Seokjae","Jinsil","Hwiman","Suhui","Geonho","Gokpa","Maengu","Hyeongbin","Yongman","Misuk","Jeongseop","Jeonghan","Byeongho","Juri","Jabeom","Naksu","Dahui","Gyuho","Seokjung","Junhu","Gyudeok","Manhui","Paengnyeon","Huisu","Yonghwa","Gukui","Seulgi","Seonghwan","Seunghyeon","Cheolyong","Bingbing","Sangheon","Taeji","Isik","Dongyeon","Hyeryeon","Yu","Donghun","Heungmin","Mundo","Jihyeok","Yeongok","Jeonggyun","Jaeu","Nyeong","Yeonjae","Juno","Jinsan","Eungyo","Noak","Seolhyeon","Yong","Ugyun","Yeseo","Alji","Sinho","Jeonghun","Cheongsu","Geonhui","Minseong","Ungcheon","Raim","Taeyeol","Hayeong","Yongui","Yeorip","Oseok","Gyuhyeok","Jongnam","Jayu","Jaechang","Wonju","Hwayeong","Geumyeong","Deokju","Jesun"};
string NA[338]={"Takai","Okazaki","Suda","Adati","Miyazima","Takada","Kawamoto","Kawai","Baba","Noda","Matuyama","Ikegami","Kaneda","Itou","Koide","Sibata","Narita","Tukada","Fukuda","Harada","Hasegawa","Sinohara","Matumoto","Sakaguti","Yamamoto","Yasuda","Ookawa","Iizima","Sinoda","Simizu","Fuzimoto","Sudou","Murai","Taketa","Higa","Nakanisi","Niwa","Tutiya","Uemura","Tazima","Syouzi","Nemoto","Yosimoto","Oosawa","Sakamoto","Takase","Miyosi","Oono","Hotta","Kataoka","Mizutani","Yosida","Nisimura","Koyanagi","Terazima","Matuoka","Tomita","Terada","Ono","Nakao","Takasima","Koizumi","Yokota","Yano","Tamura","Uehara","Inoue","Yokoyama","Kanno","Nisikawa","Hayakawa","Ookubo","Takeuti","Mukai","Honma","Miyata","Komatu","Suge","Misima","Naitou","Mizuno","Mizoguti","Hatanaka","Takeda","Nisihara","Yamaguti","Kasahara","Kanai","Endou","Taguti","Kanesiro","Utiyama","Nozaki","Yamaoka","Yamanaka","Akiyama","Horiuti","Motiduki","Saitou","Okuda","Umeda","Makino","Yokoi","Kurokawa","Yazima","Oti","Oosaki","Wada","Miki","Kamata","Abe","Simura","Nisida","Iwamoto","Suzuki","Takenaka","Ooba","Oohira","Nisioka","Sonoda","Hosi","Inagaki","Arai","Kaziwara","Ogata","Yokawa","Okamoto","Tuzi","Koga","Kanou","Yosimura","Araya","Fuzimura","Oonisi","Hayasi","Kawata","Takemura","Kawasima","Miyahara","Ikeda","Miura","Kubota","Sugahara","Miyasita","Kuroda","Nisi","Sugihara","Matui","Kurosawa","Maeda","Kanazawa","Kasiwagi","Sugimoto","Yosizawa","Andou","Siraisi","Uno","Nakagawa","Konisi","Negisi","Kubo","Morikawa","Nagaoka","Toyoda","Morioka","Horikawa","Tuda","Sakurai","Tasiro","Kawamura","Miyagawa","Murakami","Kumagaya","Satou","Okano","Kondou","Yuasa","Sakata","Yamane","Okuyama","Oka","Yosii","Fuzino","Numata","Oouti","Miyazaki","Ninomiya","Tutumi","Hirayama","Fukuoka","Nakazima","Hara","Ootake","Asada","Tanabe","Ozawa","Kimura","Seki","Sinozaki","Yamamura","Fuzita","Hidaka","Yamazaki","Sibuya","Akimoto","Yosino","Hamada","Kawabata","Nakatani","Fukunaga","Aizawa","Horiguti","Itikawa","Oomori","Takizawa","Kosaka","Takagi","Isibasi","Nisio","Takesita","Senda","Isii","Hirano","Tanoue","Hirose","Kudou","Tani","Nagata","Otiai","Ogawa","Oikawa","Yagi","Isida","Isihara","Hattori","Murayama","Hamaguti","Kawahara","Isiguro","Mori","Sakakibara","Kurita","Seto","Tabata","Iwata","Oda","Nisizawa","Nakata","Isiyama","Matumura","Kouda","Kawaguti","Fukazawa","Haraguti","Inada","Hirata","Murase","Sugiura","Simamura","Sakai","Hiramatu","Okabe","Saeki","Yaguti","Izumi","Okumura","Fuziwara","Matuno","Sakuma","Yosihara","Tutui","Sinden","Kamei","Kouno","Higuti","Nomura","Fukusima","Matubara","Azuma","Fuzii","Simada","Tukamoto","Iwai","Morita","Nisimoto","Hirota","Miyazawa","Takei","Tahara","Fukumoto","Hatakeyama","Tiba","Asano","Komori","Fukui","Ootuka","Minami","Noguti","Usui","Aoyagi","Takahasi","Hosokawa","Matusita","Miwa","Oota","Kurihara","Kitazima","Kobayasi","Araki","Kamiya","Kozima","Onodera","Eguti","Nisiyama","Sugita","Morisita","Furukawa","Nakahara","Mogi","Oomura","Iwase","Iiduka","Hayasida","Oosima","Oosiro","Kitagawa","Miyamoto","Kitano","Hamano","Nakayama","Imamura","Nagasima","Matuzaki","Tanigawa","Ueda","Sekine","Ogasawara","Ogino"};
string NB[1409]={"Anka","Sara","Keiri","Yosiharu","Moi","Kotoko","Masai","Ran","Kiyohi","Sumiko","Tomiko","Sayano","Eturou","Arika","Seki","Taisuke","Ouri","Koumi","Syoka","Sidu","Syunri","Reimi","Hano","Touma","Miha","Sono","Youta","Akaho","Mikikazu","Tomomasa","Miako","Yasuyo","Samasa","Sigehisa","Kurei","Miaka","Rei","Zen","Rikito","Kensaku","Nanaki","Riduki","Memi","Sumiha","Nanoha","Sima","Kousuke","Matuki","Hatuna","Takuo","Harumi","Akinobu","Kyouki","Mitunori","Fuzika","Asae","Noriteru","Kii","Aiho","Ryouiti","Hatuku","Hatuki","Tiyu","Hideya","Koudai","Yuusi","Mamoru","Satiko","Kazuhisa","Kanta","Sasa","Hayato","Ikue","Syouno","Tadasi","Koto","Keiki","Youto","Orisa","Nikori","Urue","Asayo","Hidekazu","Yosifumi","Kayou","Rin","Hituzi","Fua","Ae","Yuko","Souto","Kyouna","Hinatu","Nobuo","Tigusa","Azuna","Nati","Houka","Konoka","Siraho","Ryuunosuke","Mano","Oto","Tosiya","Haruki","Rio","Satoko","Yuasa","Keino","Ryuubi","Kadumi","Takaaki","Kirine","Kahane","Momomi","Anon","Tomi","Ukyou","Tomose","Ikuho","Harumo","Mayako","Yasuki","Maaya","Seiga","Motoyuki","Raito","Tamawo","Minaki","Moka","Kaho","Nanase","Kinue","Ouka","Mariya","Syuuzi","Mikako","Urume","Fuyumi","Sakuno","Zyurin","Aai","Akiharu","Hinaki","Mizuo","Niziho","Fusazi","Kinori","Kyouzi","Fusana","Yosinaga","Suguri","Kami","Takuyou","Kokoha","Suzuno","Atune","Kotose","Satiyo","Tosiki","Suzue","Kisa","Karina","Tositaka","Norihito","Kisei","Haruaki","Kazuto","Yuuno","Syunpei","Siimi","Meo","Sii","Koyumi","Eho","Moeka","Hisaki","Yuuitirou","Teruno","Nahoko","Ei","Sadahiro","Itiha","Kaki","Mizuno","Kazuyuki","Suzuha","Yosihisa","Ranan","Utayo","Yousei","Tosikazu","Naoya","Hinon","Mitusi","Sizuo","Yuiho","Rine","Tomono","Saeka","Hosimi","Yuuzou","Seina","Manaya","Kiyono","Maremu","Ridu","Toa","Mizuho","Keiiti","Mikihiro","Yasue","Tatuo","Masanao","Neiro","Syoon","Reeko","Aoha","Mami","Manan","Ieyasu","Hisano","Minagi","Kaai","Musasi","Yumino","Tateyosi","Hyakusige","Hami","Maou","Mahona","Rena","Fumiaki","Taiga","Tosimitu","Syuuto","Madoha","Anan","Kozumi","Hideaki","Minami","Syuuya","Rikka","Tugikazu","Tomie","Taiti","Kotone","Suzu","Mebae","Sakurako","Ayae","Hinako","Kenzi","Rurika","Masiho","Kika","Kuu","Sigenori","Tamaho","Takayasu","Sieru","Tosino","Moko","Yumika","Tamamo","Komoe","Sarii","Amu","Arata","Nau","Haruho","Fuuki","Yutaka","Keisa","Mikan","Koyume","Miiha","Kouzirou","Itimi","Tosiyasu","Mutumi","Sayui","Syuu","Akii","Miku","Sayori","Kureno","Sorati","Meya","Hiyu","Minaka","Reisi","Kisaki","Syuusuke","Hiziri","Mume","Ria","Reizi","Tokiha","Mayuzumi","Meiran","Syouma","Ryuuzirou","Tomoka","Hirohisa","Sadaetu","Manami","Yuri","Mihiro","Soudai","Toyotaka","Tosio","Zyukia","Hirotosi","Misaho","Ema","Kanatu","Mutuki","Hirotatu","Yuutarou","Ippei","Namina","Kari","Hideri","Masasi","Fumi","Kakeru","Yasunobu","Aruha","Hayase","Erei","Inori","Sawae","Manao","Ooaya","Yayori","Misyuri","Reiko","Raina","Maine","Satori","Kiyosi","Azumi","Takehiko","Kaori","Yosizumi","Seisa","Akihito","Kinzi","Akari","Yosikazu","Hosina","Fuzina","Akihiko","Ruiri","Rino","Hanako","Kousei","Naosi","Rikizou","Karei","Yuusuke","Haruko","Nanon","Sinnosuke","Kenkiti","Daito","Anmi","Momoku","Sigeru","Katuo","Kanae","Yasuhiko","Kotoe","Asuhi","Keimi","Moto","Ui","Kurumi","Mayu","Morimiti","Tatuki","Eina","Kazuti","Zyouzi","Takami","Narisa","Nanoko","Ayuto","Fuyuno","Yunon","Masataka","Meira","Naomi","Siose","Akitaka","Ayuna","Mizune","Yayoi","Meguri","Ruki","Daiki","Hayuma","Saiha","Mihoka","Mituki","Kirin","Tomoe","Yosizou","Katuiti","Ryouko","Fumie","Tosiaki","Konoe","Seya","Tukuru","Ryuuken","Hiroki","Atuka","Sano","Saori","Izuho","Ryuuta","Gakuto","Siono","Hisafumi","Kimiyuki","Sawayo","Utako","Haruya","Fuuno","Soyo","Syuho","Awano","Akino","Mizue","Ina","Sahori","Minase","Tise","Hironari","Sizuko","Eo","Riho","Tinae","Tuguri","Seiiti","Mifuki","Wakako","Kan","Kouzou","Sizuho","Oumi","Sawaka","Namiha","Masana","Ryuuto","Mizyu","Sigeno","Saho","Haruno","Hina","Saku","Saka","Touki","Sea","Aona","Raisa","Ruriko","Ao","Tomotosi","Nanaho","Kureha","Yukizi","Yuya","Iri","Teruhiko","Hideyosi","Niko","Anbi","Mayume","Midue","Takesi","Sau","Mabuki","Takai","Naoyuki","Nayura","Hirotarou","Miei","Hazyu","Maiho","Soukuu","Utaha","Hiira","Mitihiro","Hosiha","Aiki","Momoka","Singo","Kotoyo","Naosuke","Takuma","Rimi","Masayuki","Tokuko","Syuuko","Sahoko","Yumiyo","Kazuno","Ruo","Rinon","Akira","Siou","Osamu","Tiyuki","Robin","Amiru","Kentarou","Syuuha","Hiina","Ikuko","Mibuki","Ayaka","Eren","Fuyuhi","Maina","Ayaha","Hironori","Masayo","Kiki","Kiyora","Takanori","Nizika","Syouta","Asana","Maren","Nobuaki","Fuuka","Zyou","Rikuto","Sakutarou","Fuune","Mimari","Haruyo","Riona","Yuudai","Kikuno","Tiko","Tamari","Nodoka","Rituko","Mikawa","Taisei","Adumi","Syouiti","Hatuno","Tenna","Satone","Wakao","Ikkou","Kaito","Mafumi","Kiya","Marika","Mae","Hidenori","Katunori","Zyunko","Natume","Syuuma","Noriaki","Yuma","Mitina","Sami","Saara","Takeo","Momone","Honori","Miduki","Nanaha","Hosine","Wakaha","Anzu","Touka","Biei","Miora","Fumiya","Yuugi","Yasuo","Ansya","Momoko","Mayuna","Yuugo","Reisa","San","Marei","Yasuta","Manon","Reiho","Zyunri","Sioka","Satuki","Norihiro","Eizirou","Aeri","Mitie","Keigou","Riria","Nobutaka","Toranosuke","Ayaho","Nazumi","Miasa","Tadatugu","Sizuma","Tiyumi","Hatumi","Kiyoha","Kadusa","Yasuka","Toyohiro","Tooru","Eigorou","Tokiri","Hikari","Koutarou","Mayaka","Sizuno","Miyusa","Ruuru","Yasuhiro","Ryuumi","Madoka","Tutako","Siun","Sisei","Taisaku","Takeaki","Honami","Kento","Youitirou","Minoru","Yasuho","Sakuri","Mayumu","Syuka","Fusa","Sizuna","Naoto","Yaemi","Natuha","Zyuno","Kae","Ikuyo","Hanon","Fuuna","Tosiiti","Etumi","Takuzou","Miru","Toyoaki","Morio","Ayuki","Itino","Hirona","Hatuho","Fumikazu","Seo","Rumi","Sinzi","Ehana","Yosiuke","Akiyo","Meiya","Riha","Ryuusuke","Syue","Hosino","Mino","Seira","Akeno","Mihona","Riko","Saika","Eiko","Sakaki","Kokoe","Suika","Tosimi","Sio","Rie","Takumu","Nie","Kiyui","Mahiro","Koimi","Korin","Makino","Sona","Ayumi","Yuuto","Syouzou","Kobato","Takahito","Asuka","Hisanari","Miruka","Moa","Ouzi","Nae","Masatosi","Suzuna","Yomogi","Kirina","Mituru","Kazune","Hayasa","Sakiko","Ion","Yosiyasu","Nobue","Sidue","Rizumu","Hozumi","Naoki","Raimu","Asai","Hinano","Kinami","Nobutosi","Marin","Atue","Seizyu","Tatunori","Masano","Yasuhide","Sinki","Gunta","Rikimaru","Tisumi","Norina","Utaka","Airu","Mina","Masami","Yuiha","Utuki","Manama","Sakimi","Mihayu","Daigo","Emiri","Syuuna","Yukinari","Tikako","Naina","Reena","Tunehisa","Akeo","Mire","Norihisa","Tetuya","Saeri","Yasumasa","Tadamori","Makiha","Reino","Kun","Kiyoe","Sawako","Nawa","Tinami","Aoka","Nobumasa","Kazuaki","Syouzi","Noa","Iku","Raiki","Kanata","Reia","Yura","Ayako","Eruna","Hanatu","Suzuyo","Satika","Takumi","Kiho","Fumio","Yosihiro","Mineki","Naohiko","Tetusi","Syura","Kiyofumi","Deruta","Kotoki","Takanaga","Manaha","Kimiaki","Tuki","Masanaga","Aise","Ryou","Nattu","Yasusi","Kuniharu","Ayari","Nanato","Aono","Rimu","Uru","Akitomo","Riza","Haya","Yuhana","Sadafumi","Kiharu","Gai","Yuiki","Nanako","Tamaka","Tikoto","Sinpei","Mimori","Youzyu","Kohina","Yukako","Kiran","Yukiyo","Yumeho","Hiroyosi","Kumiko","Rumiko","Risato","Tonami","Ururu","Akihiro","Tieri","Yazuya","Tosinori","Satoho","Misaki","Siniti","Riyu","Makiko","Hyouga","Aguri","Reiha","Rui","Honone","Hayaka","Ryuuzi","Youki","Reen","Natuho","Rintarou","Itirou","Hio","Hideto","Kanawa","Miina","Motomi","Mono","Nona","Nene","Yuuta","Hiyori","Norisa","Mituhiro","Ayami","Kiyona","Isa","Mutuko","Kana","Tomotarou","Rieko","Harume","Kazutarou","Nanaka","Minae","Yamato","Moeri","Masayosi","Mutuyo","Satoru","Hiroyasu","Katusi","Yasuyosi","Kiyuki","Noboru","Rikuo","Kie","Katunari","Akeha","Hanna","Yosimi","Kotome","Yosie","Hirotaka","Ayai","Yuuri","Suzuto","Sirou","Saemi","Zennosuke","Asahi","Kisya","Mimi","Fusae","Hirotada","Aiha","Siyono","Sumino","Gen","Nayuki","Hiizu","Natuko","Itiriki","Sizuto","Tomoyo","Hokuto","Eiha","Satimi","Kimika","Terue","Yua","Fubuki","Atomu","Nizi","Nizina","Nobuya","Itina","Nobuhiko","Takase","Wayu","Youzirou","Ariha","Riyo","Tiki","Kihiro","Hiromiki","Misao","Yuno","Ryuuiti","Aki","Yuduki","Tomoki","Ryoutarou","Mayumi","Rikiya","Yosiki","Akane","Ryouta","Naoteru","Atuki","Sien","Uiti","Kazuma","Yasuyuki","Masazumi","Mituho","Daisaku","Syungo","Zyunna","Naohisa","Zinitirou","Yasuna","Kitino","Nayumi","Miaki","Hideyasu","Syouna","Ten","Tuneyasu","Seiko","Yuiri","Raira","Zyuniti","Masatugu","Kayume","Mikiko","Etuki","Katuhiro","Seria","Koharu","You","Mituyo","Sino","Maya","Yumeha","Hona","Hasumi","Muteki","Hanae","Runo","Maai","Miwa","Yuuyu","Kikuko","Namiko","Hidetugu","Manari","Sayami","Aose","Tiduru","Rairi","Takezi","Otoka","Niki","Syunyou","Aya","Fuyue","Yuki","Seiya","Zyun","Tadanori","Otona","Masako","Tatuzi","Serisa","Titose","Mayura","Atuna","Yukana","Sizuri","Yuuzin","Fuuga","Mayo","Arimi","Fei","Hare","Kyouno","Ryuuzou","Morihiro","Aozora","Emio","Mion","Rinka","Yusato","Risaki","Natu","Toon","Syuuiti","Seigo","Minato","Kazue","Fusano","Miyako","Tosihiko","Akae","Rituki","Sati","Hidenari","Gou","Tomosi","Terutaka","Yuuzi","Akihisa","Sumika","Mituno","Wakasi","Yosinobu","Homare","Haruma","Mitika","Tatuaki","Arisa","Takao","Harune","Imi","Asari","Sera","Motoka","Ryouha","Mineka","Kayoko","Maiki","Zyunpei","Futaba","Nanka","Hiho","Yukihiro","Norie","Atuo","Yuzusa","Syuugetu","Yutuki","Mineyuki","Taikei","Tappei","Tadaharu","Reo","Rana","Hironobu","Hidehito","Sarasa","Runa","Motoi","Syoutarou","Masahiro","Keiitirou","Hiroyuki","Hidenaga","Tikano","Yuuwa","Kazusige","Haruse","Aito","Aiko","Riki","Kimi","Eriko","Miyuka","Yuina","Mine","Honon","Tatuhiko","Ayasa","Katumi","Yuuga","Seine","Hitoka","Sizura","Ayume","Norito","Kimie","Katutarou","Zirou","Yosino","Yukio","Kazitu","Atuto","Norio","Yasutoyo","Koue","Fumitosi","Kairi","Kohane","Awana","Souka","Sinzirou","Nirei","Sigerou","Yuusei","Monan","Otoe","Tomu","Yuui","Ringo","Sena","Aomi","Momoo","Haruo","Narika","Itidou","Tisako","Narikazu","Akana","Sizumi","Sindou","Tomoyosi","Tooi","Katuhisa","Naohito","Tatu","Yuuiti","Mituko","Azuki","Risuzu","Yume","Atuno","Sora","Masaki","Yasunari","Saharu","Kuruti","Gaku","Kotomi","Manase","Ayuri","Tidumi","Asato","Masuhiro","Tetuzi","Kotoho","Ryouka","Sayako","Inatu","Tetuhiro","Kanan","Konatu","Tositarou","Fusatugu","Narihiro","Katuyosi","Kiyomi","Sakura","Kosato","Naito","Maira","Waya","Sakumi","Yosio","Yukihide","Syouei","Orina","Honoka","Yasunori","Seiitirou","Masakazu","Mizuha","Kiyoka","Kokoru","Akimasa","Fumihide","Tona","Rento","Hidenobu","Aoba","Masao","Yusana","Kazuyosi","Umi","Mioka","Aruna","Emina","More","Yunoka","Masahito","Makie","Ayato","Sumiho","Tomonori","Yosiaki","Eiri","Syougo","Noritomo","Haine","Tamotu","Taikai","Hidemi","Aduki","Sousuke","Ituho","Toko","Arei","Sayomi","Ito","Mihoko","Sawaki","Sieri","Emiko","Yumie","Hideki","Kazusa","Nanana","Keigo","Pinku","Aori","Mayuri","Sana","Zyuan","Yuturu","Kuniyosi","Tomoaki","Tuyosi","Yuine","Kasaki","Miyou","Takusi","Kengo","Rua","Eko","Meguka","Wataru","Kina","Syuuzou","Kotoka","Seri","Mizuse","Satuka","Miyoka","Mituha","Miori","Mikuho","Hatuka","Hayami","Ako","Nanoka","Remon","Sukai","Momona","Natuki","Kenitirou","Isae","Muneo","Takehiro","Hirokazu","Tikasi","Yuusa","Mima","Yori","Mia","Tomona","Manabu","Miu","Mikina","Kasui","Kohana","Rira","Mario","Nayume","Siho","Tono","Haruhi","Kouhei","Namiki","Matumi","Siina","Tosi","Tosie","Tae","Asumi","Keizou","Riri","Tokino","Tinatu","Misono","Mituaki","Miko","Nobuyuki","Imari","Naoko","Itie","Hitosi","Futosi","Nanari","Yosina","Hiori","Harunobu","Eruru","Tomohiro","Soutarou","Riharu","Hazime","Nanasi","Yasuaki","Hideyuki","Tomoyasu","Yuzuha","Atusa","Ami","Kousien","Seizyuurou","Mikae","Maho","Hisui","Iruka","Tunehiro","Fumika","Kiku","Natika","Yasuko","Kouri","Ayaki","Mihato","Rasa","Tisato","Kanana","Mitugi","Natusa","Katuzi","Nizirou","Nao","Natue","Sakira","Ayane","Naori","Rika","Mituyosi","Serie","Hitose","Yositaka","Hatune","Nanaya","Saari","Momohi","Kasane","Risana","Katunobu","Sayuki","Renon","Utano","Tikaru","Saki","Sasara","Anamu","Saya","Yumio","Syunta","Atuhiro","Keisuke","Tisaki","Nina","Mariko","Yositomo"};


unordered_set<string> ia,ib,na,nb;

void Init(){
	for(int i=0;i<144;++i)
		ia.insert(IA[i]);
	for(int i=0;i<1387;++i)
		ib.insert(IB[i]);
	for(int i=0;i<338;++i)
		na.insert(NA[i]);
	for(int i=0;i<1409;++i)
		nb.insert(NB[i]);


}

string a[10010],b[10010];
bool suf[10010];

string random_str(){
    int len = abs(random()) % 5 + 1;
    string str = "";
    for(int i=0;i<len;++i){
        str += char(abs(random()) % 26 + 'A');
        str += char(abs(random()) % 26 + 'a');
    }
    return str;

}


//void get_input(int t){
//    Init();
//    cout<<"start"<<endl;
//    while(ia.size() < 200){
//        ia.insert(random_str());
//    }
//    while(ib.size() < 2800){
//        ib.insert(random_str());
//    }
//    while(na.size() < 480){
//        na.insert(random_str());
//    }
//    while(nb.size() < 2800){
//        nb.insert(random_str());
//    }
//    for(int i=0;i<100;++i){
//        string s = random_str();
//        ib.insert(s);
//        nb.insert(s);
//    }
//    cout<<"ok"<<endl;
//    vector<string> a,b,c,d;
//    for(string s : ia){
//        a.push_back(s);
//    }
//    for(string s : ib){
//        b.push_back(s);
//    }
//    for(string s : na){
//        c.push_back(s);
//    }
//    for(string s : nb){
//        d.push_back(s);
//    }
//    ou<<t<<endl;
//    for(int i=0;i<t;++i){
//        int o = abs(random())%2;
//        if(o){
//            int v1 = abs(random())%a.size();
//            int v2 = abs(random())%b.size();
//            ou<<a[v1]<<" "<<b[v2]<<endl;
//        }
//        else{
//            int v1 = abs(random())%c.size();
//            int v2 = abs(random())%d.size();
//            ou<<c[v1]<<" "<<d[v2]<<endl;
//        }
//    }
//
//}

vector<int> ran;

int main(){
//	int N;
//	inn>>N;
//	while(N-->0){
//		string a,b;
//		inn>>a>>b;
//		if(b.back() == 'i'){
//			ia.insert(a);
//			ib.insert(b.substr(0,b.length()-4));
//		}
//		else{
//			na.insert(a);
//			nb.insert(b.substr(0,b.length()-4));
//		}
//	}

//	for(string s : nb){
//		ou<<"\""<< s <<"\""<<",";
//	}
//
//	cout<<ia.size()<<endl;
//	cout<<ib.size()<<endl;
//	cout<<na.size()<<endl;
//	cout<<nb.size()<<endl;


//
//
//    get_input(10000);
//    return 0;




	Init();




	int T;
	in>>T;

	int icnt,ncnt;
	icnt=ncnt=0;
	for(int i=0;i<T;++i)
		in>>a[i]>>b[i];
    for(int K=0;K<30;++K) {
        for (int i = 0; i < T; ++i) {
            if(ia.count(a[i])){
                ib.insert(b[i]);
            }
            else if(na.count(a[i])){
                nb.insert(b[i]);
            }
        }
        for(int i=0;i<T;++i){
            bool A = ib.count(b[i]);
            bool B = nb.count(b[i]);
            if(A&&!B){
                if(!na.count(a[i]))
                    ia.insert(a[i]);

            }
            else if(!A&&B){
                if(!ia.count(a[i])){
                    na.insert(a[i]);
                }
            }
//            assert(ia.size()<500);
//            assert(na.size()<500);
//            assert(ib.size()<3000);
//            assert(nb.size()<3000);
        }

    }

	for(int i=0;i<T;++i){
        bool A,B;
        A = ia.count(a[i]);
        B = na.count(a[i]);
		if(A&&!B){
			suf[i] = 0;//ssi
			icnt++;
		}
		else if(B&&!A){
			suf[i] = 1;//san
			ncnt++;
		}
		else{
			A = ib.count(b[i]);
			B = nb.count(b[i]);
			if(!A&&!B ||A&&B){
                ran.push_back(i);
			}
			else if(A){
				suf[i] = 0;
				icnt++;
			}
			else{
				suf[i] = 1;
				ncnt++;
			}
		}

	}

	random_shuffle(ran.begin(),ran.end());
	int inned = min(max(T / 2 - icnt,0),(int)ran.size());

	for(int i=0;i<inned;++i)
		suf[ran[i]]=0;
	for(int i=inned;i<ran.size();++i)
		suf[ran[i]]=1;

	for(int i=0;i<T;++i){
        if(suf[i]==0)
		    printf("%s %s-ssi\n",a[i].c_str(),b[i].c_str());
        else{
            printf("%s %s-san\n",a[i].c_str(),b[i].c_str());
        }
	}

//
//    cout<<ia.size()<<endl;
//	cout<<ib.size()<<endl;
//	cout<<na.size()<<endl;
//	cout<<nb.size()<<endl;

	return 0;
}





