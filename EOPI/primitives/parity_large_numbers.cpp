#include<iostream>

using namespace std;

const int bits = 16;
const int cache_len = 1<<bits;
short cache [cache_len];
typedef unsigned long long ULL;

short parity(ULL n){
    short r = 0;
    while(n>0){
        r = r ^ 1;
        n = n & (n - 1);
    }
    return r;
}

void init_cache(){
    for(ULL i=0; i < cache_len; i++){
        cache[i] = parity(i);
        //cout << "computing parity "<< i << ": " << cache[i] << endl;
    }
    return;
}

short get_parity_cache(ULL x){
    //cout << "parity "<< x << ": " << cache[x] << endl;
    return cache[x];
}

short parity_cache(ULL n){
    const ULL mask = 0xFFFF;
    ULL u = n>>48, v = (n>>32) & mask, w = (n>> bits) & mask, x = n&mask;
    return get_parity_cache(u) ^ get_parity_cache(v) ^ get_parity_cache(w) ^ get_parity_cache(x);
}

int main(){
    init_cache();

    ULL n = 0;
    do{
        cin >> n;
        short p = parity_cache(n);
        cout << "parity (" << n << ") = " << p << endl;
    } while(n>0);

    return 0;
}