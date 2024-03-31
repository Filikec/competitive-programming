#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

using namespace std;


class BigNum { // represents a big number in base 10
    public:
    string numerator,denumerator;
    int sign;
    BigNum(){
        numerator = "0";
        denumerator = "1";
        sign = 1;
    }
    BigNum(int n){
        if (n<0){
            n *= -1;
            sign = -1;
        }else{
            sign = 1;
        }
        numerator = to_string(n);
        denumerator = "1";
    }
    BigNum(long long n){
        if (n<0){
            n *= -1;
            sign = 1;
        }else{
            sign = 1;
        }
        numerator = to_string(n);
        denumerator = "1";
    }
   
    BigNum(int n,int d){
        if (n < 0 && d < 0){
            n *= -1;
            d *= -1;
            sign = 1;
        }else if (n < 0){
            n *= -1;
            sign = -1;
        }else if (d < 0){
            d *= -1;
            sign = -1;
        }else{
            sign = 1;
        }
        
        numerator = to_string(n);
        denumerator = to_string(d);
    }
   
    void print(){
        if (sign == 1){
            cout << numerator << '/' << denumerator << '\n';
        }else{
            cout << '-' << numerator << '/' << denumerator << '\n';
        }
        
    }
   
    BigNum add(BigNum n2){
        BigNum new_num = BigNum(0);

        string gcd = GCD(&n2.denumerator,&denumerator);
        string tmp = multiplication(&denumerator,&n2.denumerator);
        new_num.denumerator = division(&tmp,&gcd);

        string i_l = division(&new_num.denumerator,&denumerator), i_r = division(&new_num.denumerator,&n2.denumerator);
        string n_l, n_r;

        if (sign == -1){
            n_l =  "-";
        }

        if (n2.sign == -1){
            n_r = "-";
        }

        n_l += multiplication(&i_l,&numerator), n_r += multiplication(&i_r,&n2.numerator);

        new_num.numerator = addition(&n_l,&n_r);

        new_num.update_sign();
        new_num.shrink();

        return new_num;
    }

    BigNum multiply(BigNum n2){
        BigNum new_num = BigNum(0);

        string n_l, n_r,d_l,d_r;

        if (sign == -1){
            n_l = '-';
        }
        if (n2.sign == -1){
            n_r = '-';
        }

        n_l += numerator;
        d_l += denumerator;
        n_r += n2.numerator;
        d_r += n2.denumerator;


        new_num.numerator = multiplication(&n_l,&n_r);
        new_num.denumerator = multiplication(&d_l,&d_r);

        new_num.update_sign();
        new_num.shrink();

        

        return new_num;
    }

    BigNum inverse(){
        BigNum new_num = BigNum(0);

        new_num.sign = sign;
        new_num.numerator = denumerator;
        new_num.denumerator = numerator;

        return new_num;
    }

    string get_scientific_form(int precision=7){
        string result;
        bool once = false, point = false, add_point = false;
        int decimal = 0;

        string left;
        left += numerator[0];
        int index = 1;

        if (sign == -1){
            result += '-';
        }

        if (numerator == "0"){
            result = "0";
            return result;
        }

        while (decimal<precision){
            int is_bigger = bigger(&left,&denumerator);
            if (add_point){
                if (left == "0" || left == "") break;
                if (!result.size()) result += "0", once = true;
                result += '.', point = true, add_point = false;
                if (point) return "is not an integer with less than 100 digits.";
            }
            if (is_bigger != 2){
                string modulo;
                string tmp = division_raw(&left,&denumerator,&modulo);
                if (point) decimal+=tmp.size();
                result += tmp;
                left = modulo;
                once = true;

            }else if (once){
                if (point) decimal++;
                result += "0";
            }

            if (index >= numerator.size()){
                if (left == "0") left = "";
                left += '0';
                
                if (!point) add_point = true;
            }else{
                if (left == "0") left = "";
                left += numerator[index++];
            }
        }

        return result;
    }
    
    void shrink(){
        if (numerator == "0"){
            denumerator = "1";
            return;
        }
        string gcd = GCD(&numerator,&denumerator);
        string tmp_n = division(&numerator,&gcd), tmp_d = division(&denumerator,&gcd);
        numerator = tmp_n;
        denumerator = tmp_d;
    }

    void update_sign(){
        if (numerator == "0"){
            sign = 1;
            return;
        }

        if (this->numerator[0] != '-' && this->denumerator[0] != '-' && sign == -1) sign = 1;

        if (this->numerator[0] == '-'){
            reverse(this->numerator.begin(),this->numerator.end());
            this->numerator.pop_back();
            reverse(this->numerator.begin(),this->numerator.end());
            this->sign *= -1;
        }
        if (this->denumerator[0] == '-'){
            reverse(this->denumerator.begin(),this->denumerator.end());
            this->denumerator.pop_back();
            reverse(this->denumerator.begin(),this->denumerator.end());
            this->sign *= -1;
        }
    }

    string add_strings(string *string1, string *string2){
        string result;
        int carry=0;
        int index1 = string1->size()-1, index2 = string2->size()-1;
        int end = -1;
        if (string1->at(0) == '-') end++; // means both are negative
        
        while (index1>end||index2>end||carry){
            int digit=0;
            if (index2>end) digit += string2->at(index2--)-'0';
            if (index1>end) digit += string1->at(index1--)-'0';
            digit += carry;
            
            carry = digit/10;
            result += digit%10 + '0';
        }


        if (!end) result += '-';

        reverse(result.begin(),result.end());

        return result;
    }

    string sub_strings(string *string1, string *string2, bool no_sign=false){ // assume exactly one is negative

        string result;
        bool negative = false, inverse = false;
        int end1 = -1, end2 = 0, bigger = 0;

        // make string2 negative
        if (string1->at(0) == '-'){
            string *tmp = string1;
            string1 = string2;
            string2 = tmp;
        }

        // assert which number is bigger
        if (string1->size() < string2->size()-1){
            string *tmp = string1;
            string1 = string2;
            string2 = tmp;
            end2 = -1;
            end1 = 0;
            inverse = true;
        }else if (string1->size() == string2->size()-(no_sign==false)){
            for (int i=0;i<string1->size();i++){
                if (string1->at(i) > string2->at(i+(no_sign==false))){
                    bigger = 1;
                    break;
                }else if (string2->at(i+(no_sign==false)) > string1->at(i)){
                    bigger = 2;
                    break;
                }
            }
            if (!bigger){
                result = "0";
                return result;
            }else if (bigger==2){
                string *tmp = string1;
                string1 = string2;
                string2 = tmp;
                end2 = -1;
                end1 = 0;
                inverse = true;
            }   
        }

        if (no_sign){
            end1 = -1;
            end2 = -1;
        }

        int index1 = string1->size()-1, index2 = string2->size()-1;
        int carry=0;
        while (index1>end1||index2>end2||carry){
            int digit = 0;
            if (index2>end2) digit -= string2->at(index2--)-'0';
            if (index1>end1) digit += string1->at(index1--)-'0';
            
        
            digit -= carry;
            if (digit < 0){
                if (index1>end1){
                    digit += 10, carry = 1;
                }else{
                    negative = true;
                    carry = 0;
                }
            }
            else carry = 0;

            result += digit%10 + '0';
        }
        
        while (result.back() == '0' && result.size() != 1){
            result.pop_back();
        }

        if (negative ^ inverse) result += '-';
        
        reverse(result.begin(),result.end());
        
        return result;
    }

    string addition(string *s1, string *s2){
        if (s1->at(0) == '-' && s2->at(0) == '-') return add_strings(s1,s2);
        if (s1->at(0) != '-' && s2->at(0) != '-') return add_strings(s1,s2);
        return sub_strings(s1,s2);
    }

    string division_raw(string *s1, string *s2, string *modulo=NULL){ // divide s1 by s2
        string counter="0";
        string new_s=*s1, last = "0",tmp;
        string add = "1";
        while ((tmp = sub_strings(&new_s,s2,true)).at(0) != '-'){
            new_s = tmp;
        
            counter = addition(&counter,&add);
            last = new_s;
        }

        if (modulo != NULL){
            *modulo = last;
        }

        return counter;
    } 

    int bigger(string *s1, string *s2){ // s1 is bigger than s2, 1 true, 2 s2 is bigger, 0 same
        if (s1->size() > s2->size()) return 1;
        else if (s2->size() > s1->size()) return 2;

        for (int i=0;i<s1->size();i++){
            if (s1->at(i) > s2->at(i)) return 1;
            else if (s2->at(i) > s1->at(i)) return 2;
        }

        return 0;
    }

    string division(string *s1, string *s2, string *modulo=NULL){
        string left,result;
        int index = 0;
        bool once = false;

        if (*s2 == "0") {
            result = "-1";
            return result;
        }
        
        while (index < s1->size()){
            left += s1->at(index++);

            if (left == "0") left = "";
            
            int is_bigger = bigger(&left,s2);

            if (is_bigger != 2){
                
                string modulo;
                result += division_raw(&left,s2,&modulo);
                
                left = (modulo=="0"?"":modulo);
                
                once = true;
            }else if (once){
                result += "0";
            }
        }
        
        if (modulo != NULL) *modulo = (left==""?"0":left);

        if (!result.size()) result = "0";

        return result;
    }

    string GCD(string *s1, string *s2){
        string big, small, mod;
        

        if (*s1 == "0" || *s2 == "0"){
            mod = "0";
            return mod;
        }

        if (bigger(s1,s2) == 2){
            big = *s2;
            small = *s1;
        }else{
            big = *s1;
            small = *s2;
        }

        division(&big,&small,&mod);

        while (mod != "0"){
            big = small;
            small = mod;
            division(&big,&small,&mod);
        }    

        return small;
    }
    
    string multiplication(string *s1, string *s2){
        string result="0", *big, *small, zeroes;
        int end1 = 0, end2 = 0;


        if (*s1 == "0" || *s2 == "0"){
            return result;
        }

        if (s1->size() > s2->size()) big = s1, small = s2;
        else big = s2, small = s1;

        if (big->at(0) == '-') end1++;
        if (small->at(0) == '-') end2++;

        for (int i=small->size()-1;i>=end2;i--){
            string tmp = zeroes;
            int carry=0, current = small->at(i)-'0';
            for (int j=big->size()-1;j>=end1;j--){
                int digit = (big->at(j)-'0')*current+carry;
                carry = digit/10;
                tmp += digit%10+'0';
            }
            if (carry) tmp += carry+'0';
            
            reverse(tmp.begin(),tmp.end());
            string tmp1 = add_strings(&result,&tmp);
            result = tmp1;
            zeroes += '0';
        }

        if (s1->at(0) == '-' ^ s2->at(0) == '-'){
            reverse(result.begin(),result.end());
            result += '-';
            reverse(result.begin(),result.end());
        }

        return result;
    }
    
};

unordered_map<int,BigNum> Powers;

BigNum getPower(int n, int p, int c=0){
    auto it = Powers.find(p);
    
    if (it != Powers.end()) return it->second;
    
    if (p == 0){
        return 1;
    }

    BigNum r;
    cout << p << "\n";
    if (p%2){
         r = getPower(n,p-1,c).multiply(n);
    }else{
         r = getPower(n,p/2,c).multiply(getPower(n,p/2,c));
    }
    cout << p << "\n";
    Powers[p] = r;
    //cout << r.get_scientific_form() << '\n';
    return r;
}   

bool lessThan100(int t, int a, int b){
    if (t == 10){
        return (a-1)-(b-1)<100;
    }
    double digits = ((double)a)*log10((double)t)-((double)b)*log10((double)t);
    return digits < (double)100;

}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    long long t,a,b;
    
    while (cin >> t >> a >> b){
        cout << '(' << t << '^' << a << "-1)/(" << t << '^' << b << "-1)";
        if (lessThan100(t,a,b)){
            Powers.clear();
            BigNum first = getPower(t,a).add(-1);
            BigNum second = getPower(t,b).add(-1);
            
            BigNum result = first.multiply(second.inverse());
            string res =  result.get_scientific_form();
        
            cout << ' ' << res << '\n';
        }else{
            cout << " is not an integer with less than 100 digits.\n";
        }
    }


    return 0;
}