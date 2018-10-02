#include<iostream>
#include<limits>
#include<random>

using namespace std;

int main(){
    unsigned int x = 0xFFFFffff;
    cout << x << endl;
    cout << numeric_limits<double>::infinity() << endl;
    cout << numeric_limits<float>::lowest() << endl; // -Float max
    cout << numeric_limits<float>::min() << endl; // Smallest possible float 
    cout << numeric_limits<int>::lowest() << endl; // Same as INT_MIN
    cout << numeric_limits<int>::min() << endl; // Same as INT_MIN

    uniform_int_distribution<int> dist(0, 10);
    uniform_real_distribution<double> real(0.1, 0.9);
    random_device dev;
    mt19937 gen(dev());
    int r = dist(gen);
    double d = real(gen);  
    cout << "random int (0,10): " << r << endl;
    cout << "random double(0.1, 0.9): " << d << endl;

    cout << sizeof(unsigned long long) << endl;
    return 0;
}