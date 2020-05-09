#include <iostream>
int get_fib(int n);
 
int fibonacci_sum_squares_naive(long long n){
	if (n<=1){
		return n;
	}
	
	return (get_fib(n%60)*get_fib((n+1)%60) % 10);
}

int get_fib(int n){
	if (n<=1){
		return n;
	}
	
	long long previous = 0;
    long long current  = 1;
    long long ret=0;

    for (long long i = 0; i < n - 1; ++i) {
        ret=(previous+current) % 10;
        previous = current;
        current = ret;
    }

    return current; 
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
