#include <bits/stdc++.h>


using namespace std;

typedef struct height{
    int h;
    list<struct height>::iterator next;
} Height;

list<Height> Heights;
list<Height*> Before[1000001];

int get_int(){
    char c;
    int num = 0;

    while ((c=getchar())>='0'){
        num =num*10+c-'0';
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    n = get_int();

    for (int i=0;i<n;i++){
        Height new_height;
        new_height.h=get_int();
        new_height.next = Heights.end();        
        Heights.push_back(new_height);
    }

    for (auto it = Heights.begin();it != Heights.end();it++){
        if (Before[(*it).h+1].size()){
            Before[(*it).h+1].front()->next = it;
            Before[(*it).h+1].pop_front();
        }
        Before[(*it).h].push_front(&(*it));
    }

    int counter=0;
    while (Heights.size()){
        counter++;
        auto cur = Heights.begin();
        while (cur != Heights.end()){
            auto next = cur->next;
            Heights.erase(cur);
            cur = next;
        }
    }

    printf("%d\n",counter);


    return 0;
}