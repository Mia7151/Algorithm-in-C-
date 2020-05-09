#include<iostream>
using namespace std;

long long fib_partial_sum_digit(long long n, long long m)
{
	
    long long fl[60] ={0};
    fl[0] = 0;
    fl[1] = 1;

    for(long long i = 2 ; i<60 ; ++i)
    {
        fl[i] = (fl[i-1] +fl[i-2])%10; 
        
    }
    
    long long sum = 0;
   
    n=n%60;
    m=m%60;
    
    if (m<n)
    	m +=60;
    
    
    for(long long i = n ; i<=m; ++i )
    {
        sum += (fl[i%60]);
       
    }
    
	return sum%10;
}

int main()
{
    long long n,m;
    cin >>n>>m ;

    long long ans = fib_partial_sum_digit(n,m);
    cout<<ans;

    return 0;
}
