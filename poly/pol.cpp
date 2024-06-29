//danial tighbakhsh   4001406114
#include <iostream>
#include <string>  
#include <math.h>
#include <sstream>
using namespace std;

class plo{
    public:
        int zarib = 0, tawan = 0;  
};
class pol_result{
    private:
        plo* a;
        plo* b;
        int a_size = 0, b_size = 0;
    public:
        plo* result;
        pol_result(){
            a = new plo[a_size];
            b = new plo[b_size];  
            result = new plo[b_size * a_size];  
        }
        void pol_make(string num_1, string num_2){
            size(num_1, num_2);
            pol_i(num_1, a);
            pol_i(num_2, b);
            a_in_b();
        }
        void size(string num_1, string num_2){
            for (int i = 0 ; num_1[i] != '\0' || num_2[i] != '\0'; i++){
                if ((num_1[i] == '+' || num_1[i] == '-') && i !=0)  
                    a_size++;
                if ((num_2[i] == '+' || num_2[i] == '-') && i !=0)  
                    b_size++;
            }
            a_size++;
            b_size++;
            pol_result();
        }
        void pol_i(string num, plo* s){
            string temp_zarib = "", temp_tawan = "";
            int j = 0, h = 0, f = 0;
            for (int i = 0 ; num[i] != '\0'; i++){
                if(num[i] == 'x'){
                    for (; h < i ; h++){
                        temp_zarib += num[h];
                    }
                    f = i+2 ;
                    while(true){
                        if (num[f] == '+' || num[f] == '-' || num[f] == '\0'){
                            h = f+1 ;
                            break;
                        }
                        temp_tawan += num[f];
                        f++ ;
                    }
                    s[j].tawan = stoi(temp_tawan);
                    s[j].zarib = stoi(temp_zarib);
                    j++;
                    temp_tawan = "";
                    temp_zarib = "";
                }
            }
        }
        void a_in_b(){
            int f = 0;
            for(int i = 0 ; i < a_size ; i++){
                for(int j = 0 ; j < b_size ; j++){
                    if ( a[i].tawan == b[j].tawan ){
                            result[f].tawan = a[i].tawan;
                            result[f].zarib = a[i].zarib * b[j].zarib;
                            f++ ;
                    }else{
                            result[f].tawan = a[i].tawan + b[j].tawan;
                            result[f].zarib = a[i].zarib * b[j].zarib;
                            f++ ;
                    }        
                }
            }
        }
        void sort_result(){
            for (int i = 0 ; i < a_size * b_size ; i++){
                for (int j = 0 ; j < a_size * b_size ; j++){

                }
            }
        }
};
int main(){
    string a = "5x^10+4x^11+0x^6", b = "4x^1+5x^2+8x^4";
    pol_result aaa;
    aaa.pol_make(a, b);
    for(int i = 0 ;i < 9; i++){
        cout<<aaa.result[i].zarib<<","<<aaa.result[i].tawan<<'\n';
    }
    return 0;
}
