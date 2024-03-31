#include <bits/stdc++.h>


using namespace std;

double Dist, Time, Speed;

bool work(){
    string line;
    if (!getline(cin,line)) return false;

    int n,time=0;
    n = line[0]*10+line[1];
    n *= 60*60;
    time += n;
    n = line[3]*10+line[4];
    n *= 60;
    time += n;
    n = line[6]*10+line[7];
    time += n;

    if (line.size()>8){
        int num=0;
        for (int i=9;i<line.size();i++){
            num *= 10;
            num += line[i]-'0';
        }
        Dist += (time-Time)*Speed;
        Speed = num;
        Speed /= 3600;
        Time = time;   
    }else{
        Dist += (time-Time)*Speed;
        Time = time;
        for (int i=0;i<8;i++){
            cout << line[i];
        }
        cout << fixed << setprecision(2) << " " <<  Dist << " km\n";
    }

    return true;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (work()){
        ;
    }


    return 0;
}