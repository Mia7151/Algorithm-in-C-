#include <iostream>
#include <cstdlib>
long long getPeriodLength(long long m);

long long get_fibonaccihuge(long long n, long long m){
	if (n<=1)
		return n;
	
	n=n % getPeriodLength(m);
	if (n==0)
		return 0;
	
	long long previous=0;
	long long current=1;
	
	for (long long i=2; i<=n; i++){
		long long temp=previous;
		previous=current;
		current=(temp+current) % m;
	} 
	
	return current ;
} 
    
long long getPeriodLength(long long m){
	long modEq1 = 0, modEq2 = 1, fib3 = modEq1 + modEq2;
	for (long i = 0; i < m*m ; i++) {       //why m*m ???
		fib3 = (modEq1 + modEq2) % m;   
		modEq1 = modEq2;
		modEq2 = fib3;
		if (modEq1 == 0 && modEq2 == 1)
			return i + 1; 
	}
	return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
    return 0;
}
















