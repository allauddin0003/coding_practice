#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void rotate_array(int * array, int len, int k){
    if(len <= 1){
        return;
    }

    if(k >= len){
        k = k % len;
    }

    if(k <= 0){
        return;
    }
    int temp;
    for(int i=0; i < (k + 1) / 2; i++){
        temp = array[i];
        array[i] = array[k-i];
        array[k-i] = temp;
    }

    for(int i=0; i < (len - k) / 2; i++){
        temp = array[k + i + 1];
        array[k + i + 1] = array[len - i - 1];
        array[len - i - 1] = temp;
    }

    for(int i=0; i < len /2; i++){
        temp = array[i];
        array[i] = array[len - 1 - i];
        array[len - 1 - i] = temp;
    }
    
    return;
}

int main(){
    int n, *a;
    cin >> n;
    a = (int *)calloc(n, sizeof(int));
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    rotate_array(a, n, k);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}