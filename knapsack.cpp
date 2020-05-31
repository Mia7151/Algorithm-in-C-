#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std; 
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
/*
    int n=w.size();
    int dp[W+1];
    fill_n(dp,W+1,0);
    for(int i=0;i<=n;++i){
        for(int j=w[i];j<=W;++j){
            dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    return dp[W];*/
    
  const int w_size = w.size();
  int** weights = new int* [w_size + 1];

  for (int i = 0; i <= w_size; i++) {
    weights[i] = new int[W + 1];
  }

  for (int i = 0; i <= w_size; i++) {
    for (int j = 0; j <= W; j++) {      
        if (i==0 || j==0) {
          weights[i][j] = 0;
        }
        else if (w[i - 1] <= j) 
          weights[i][j] = std::max(w[i - 1] + weights[i - 1][j - w[i - 1]],  weights[i - 1][j]);
        else
          weights[i][j] = weights[i - 1][j];
    }
  }

  int result = weights[w_size][W];

  for (int i = 0; i < w_size; i++) {
    delete[] weights[i];
  }

  delete[] weights;//释放new分配的对象数组指针指向的内存

  return result;
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}



