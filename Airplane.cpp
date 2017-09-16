#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

template<typename T> int pushAndGetMax(T& q, int e, int max){
    q.push(e);
    if(max < q.size()){
        max = q.size();
    }
    return max;
}

int findMinGates(vector<int> arrivals, vector<int> departures, int flights){
    int gates = 0;
    int n = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n < flights ){
        if(pq.empty()){
            gates = pushAndGetMax(pq, departures[n], gates);
            n++;
        }else{
            int nextDep = pq.top();
            if (nextDep < arrivals[n]){
                pq.pop();
            }else{
                gates = pushAndGetMax(pq, departures[n], gates);
                n++;
            }
        }
    }
    return gates;
}
int main(){
    int flights = 6;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << findMinGates(arr, dep, flights) << endl;
    return 0;
}
