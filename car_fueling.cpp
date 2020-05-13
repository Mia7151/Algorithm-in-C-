#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.insert(stops.begin(),0);
    stops.insert(stops.end(), dist);
    int count=0;
    int currentRefill=0;
    while (currentRefill< stops.size()){
    	int lastRefill = currentRefill;
    	while (currentRefill < stops.size() && stops[currentRefill+1]-stops[lastRefill]<= tank){
    		currentRefill += 1;
		}
		if (currentRefill == lastRefill){
			return -1;
		}
		if (currentRefill < stops.size()){
			count += 1;
		}
	}
    return count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
