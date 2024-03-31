#include <iostream>

using namespace std;


int get_time(){
    char c;
    int result = 0;
    c = cin.get();
    result += (c-'0')*10;
    c = cin.get();
    result += c-'0';
    result *= 60;
    c = cin.get();
    c = cin.get();
    result += (c-'0')*10;
    c = cin.get();
    result += c-'0';
    cin.get();
    return result;
}

int gcd(int a, int b){
    int r, hi,lo;

    if (a>b){
        hi = a;
        lo = b;
    }else{
        hi = b;
        lo = a;
    }
    r = hi%lo;
    while (r){
        hi = lo;
        lo = r;
        r = hi%lo;
    }
    return lo;
}

string Days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};

void print_time(int t){
    if (t > 9){
        cout << t;
    }else{
        cout << 0 << t;
    }
}

int main(){
    int s1,s2,d1,d2;

    s1 = get_time();
    s2 = get_time();

    d1 = get_time();
    d2 = get_time();

    if (abs(s1-s2)%gcd(d1,d2)){
        cout << "Never\n";
        return 0;
    }
    int time1 = s1, time2 = s2;

    while (time1 != time2){
        if (time1>time2) time2 += d2;
        else time1 += d1;
    }

    int hours = time1/60;
    int minutes = time1%60;
    int day = hours/24;
    hours %= 24;
    
    cout << Days[(day+5)%7] << '\n';
    
    print_time(hours);
    cout << ':';
    print_time(minutes);
    cout << '\n';
    

    return 0;
}