#include<iostream>
#include<vector>

using namespace std;

int calculate_best_profit_start(vector<int>, int);

int main(){
    vector<int> s;
    int n;
    cin >> n;
    s.resize(n);
    for(auto &i: s){
        int tmp;
        cin >> i;
    }
    int best_profit = calculate_best_profit_start(s, n);

    cout << "best profit is: " << best_profit << endl;
    return 0;
}

int calculate_best_profit_start(const vector<int> s, const int n){
    int p = -1, min = s[0];
    for(auto &i : s){
        if(i < min){
            min = i;
        }
        else if(i - min > p){
            p = i-min;
        }
    }
    return p;
}