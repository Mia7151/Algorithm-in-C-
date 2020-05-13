#include <iostream>
#include <vector>
#include <numeric>
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  
  if (n==2){
  	summands.push_back(2);
  }
  else{
  	int i=1;
    while (accumulate(summands.begin(),summands.end(),0) <= n){
  	 summands.push_back(i);
	 i +=1;
	 }
    summands.pop_back();
  
    if (accumulate(summands.begin(),summands.end(),0)<n){
  	  summands.pop_back();
  	  int sum_new=accumulate(summands.begin(),summands.end(),0);
  	  summands.push_back(n-sum_new);
		}
  }
  
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
