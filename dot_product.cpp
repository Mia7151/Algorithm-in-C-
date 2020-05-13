#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  
  if (a.size()>1){
  	for (int j=0; j<a.size()-1; ++j){
  		for (int m=0; m<a.size()-j-1;++m){
  			if (a[m+1] < a[m]){
  				int temp=a[m+1];
  				a[m+1]=a[m];
  				a[m]=temp;
			  }
			if (b[m+1] < b[m]){
  				int temp=b[m+1];
  				b[m+1]=b[m];
  				b[m]=temp;
			  }
		  }
	  }
  } 
  		
  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
  
  
   
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
