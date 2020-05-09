#include<iostream>
using namespace std;

long long fib_sum_digit(long long n)
{
    long long fl[60] ={0};
    fl[0] = 0;
    fl[1] = 1;
   

    for(long long i = 2 ; i<60 ; i++)
    {
        fl[i] = (fl[i-1] +fl[i-2])%10 ; 
        
    }


    long long sum = 0;
   
    

    for(long long i = 1; i<=(n%60); i++ )
    {
        sum += (fl[i]);
       
    }
    
    

return sum%10;
}

int main()
{
    long long n;
    cin >>n ;

    long long ans = fib_sum_digit(n);
    cout<<ans;

    return 0;
}
