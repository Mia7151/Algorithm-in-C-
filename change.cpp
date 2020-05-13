#include <iostream>


int get_change(int m) {
	int array[3]={10,5,1};
	int count=0;
	int n=0;
	for (int i=0; i<3; ++i)
		while (m>=array[i]){
			m=m-array[i];
			n +=1;
		}
	return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

