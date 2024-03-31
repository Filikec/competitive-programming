#include <iostream>
#include <cmath>
#include <list>
#include <vector>

using namespace std;


bool isPalindrome(long long n){
    list<int> nums;

    while (n){
        nums.push_back(n%10);
        n /= 10;
    }
    while (nums.size()){
        if (nums.front()!=nums.back()){
            return false;
        }
        nums.pop_front();
        if (nums.size()) nums.pop_back();
    }
    

    return true;
}

long long toInt(vector<int> &a){
    long long newA = 0;

    for (auto n : a){
        newA *= 10;
        newA += n;
    } 

    return newA;
}

bool isLess(vector<int> &a, long long b){
    long long newA = toInt(a);

    return newA < b;
}



int main(){


    long long n;

    cin >> n;

    list<int> required;

    while (!isPalindrome(n)){
        list<int> nums;
        long long tmp = n;
        int len;
        while (tmp){
            nums.push_front(tmp%10);
            tmp /= 10;
        }
        len = nums.size();
        list<int> rev;
        vector<int> number;
        for (int i=0;i<len/2+(len%2);i++){
            number.push_back(nums.front());
            rev.push_front(nums.front());
            nums.pop_front();
        }

        if (len%2) rev.pop_front();
        for (auto d : rev){
            number.push_back(d);
        }
        
        int index = number.size()/2;
        while (!isLess(number,n) && index > -1){
            if (!number[index] || (number[index]==1 && !index)){
                index--;
                continue;
            }
            number[index]--;
            number[number.size()-1-index]--;
        }
        
        if (!isLess(number,n)){
            for (auto &c : number){
                c = 9;
            }
            number.pop_back();
        }
        long long newN = toInt(number);
        required.push_back(newN);
        n-=newN;
    }
    if (n) required.push_back(n);

    cout << required.size() << '\n';
    for (auto n : required){
        cout << n << '\n';
    }

    return 0;
}
