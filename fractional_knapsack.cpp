#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  if (values.size() >1){
  	for (int n=0; n<values.size()-1; ++n){
  		for (int m=0; m<values.size() - n -1; ++m){
			  if (((double) values[m]/weights[m]) < ((double) values[m+1]/weights[m+1])){
  				int temp1=values[m];
  				values[m]=values[m+1];
  				values[m+1]=temp1;
  				
  				int temp2=weights[m];
  				weights[m]=weights[m+1];
  				weights[m+1]=temp2;
			  }
		  }
	  }
  } 
  
  long long weight_current=0;
  for (int i=0; i<weights.size(); ++i){
  	if (weight_current+weights[i]<capacity){
  		weight_current += weights[i];
  		value += values[i];
	}
	else {
		double fraction = capacity-weight_current;
		value += fraction*values[i]/weights[i];
		break;
	}
  }

  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}


