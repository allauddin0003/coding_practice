#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_element(vector<int>array, int left, int right, int index){
    // cout << "left: "<< left << " right: "<< right << endl;
    if(right - left <= 5){
        sort(array.begin() + left, array.begin() + right + 1);
        return array[index];
    }
    int size = right - left + 1;
    int no_medians = ((size - 1) / 5) + 1;
    vector<int> medians;
    for(int iter = left; iter <= right; iter+= 5){
        int end = iter + 5;
        if(end >= right){
            end = right + 1;
        }
        sort(array.begin()+iter, array.begin() + end);
        medians.push_back(array[iter + ((end - iter) / 2)]);
    }

    int pivot = find_element(medians, 0, medians.size() - 1, medians.size() / 2);
    
    int lower = left, upper = left;

    for(int i=left; i<=right; i++){
        if(array[i] < pivot){
            int temp = array[upper];
            array[upper] = array[i];
            array[i] = temp;
            if(lower < upper){
                array[lower] = array[upper];
                array[upper] = pivot;
            }
            lower++;
            upper++;
        }
        else if (array[i] == pivot){
            array[i] = array[upper];
            array[upper] = pivot;
            upper++;
        }
    }
    if(lower <= index && index < upper){
        return pivot;
    }
    else if(lower > index){
        return find_element(array, left, lower-1, index);
    }
    else{
        return find_element(array, upper, right, index);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> array (n, 0);
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    
    int index;
    cin >> index;

    if(index >=0 && index < n){
        int ans = find_element(array, 0, n-1, index);
        cout << ans << endl;
    }
    sort(array.begin(), array.end());
    cout << array[index] << endl;
    return 0;
}