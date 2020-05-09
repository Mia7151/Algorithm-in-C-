#include <iostream>

/*
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
*/

long long gcd_naive(long a, long b){
	long long current_gcd=b;
	while (a%b !=0 ){
		current_gcd=a%b;
		a=b;
		b=current_gcd;
	}
			
	return current_gcd;
}

long long lcm_naive(long a, long b){
	long long temp=gcd_naive(a,b);
	long long ret= a/temp*b;
	return ret;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
