#include <iostream>

int get_fibonacci_last_digit_naive(long long n) {
    if (n <= 1)
        return n;

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
    long long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    return 0;
    }
