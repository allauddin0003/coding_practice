#include<iostream>
#include<vector>

using namespace std;

int find_rotated_sorted(vector<int> array, int left, int right, int key)
{
    if(right < left)
    {
        return -1;
    }
    if(right == left)
    {
        if(key == array[left])
        {
            return left;
        }
        return -1;
    }
    int mid = left + (right - left) / 2;

    if(key == array[mid])
    {
        return mid;
    }
    cout << "left: "<<left<<" right: "<< right << " mid: " << mid << endl;
    if(array[left] > array[mid] && (key >= array[left] || key < array[mid]))
    {
        // Rotation point is between left and mid
        return find_rotated_sorted(array, left, mid - 1, key);
    }
    if(array[right] < array[mid] && (key <= array[right] || key > array[mid]))
    {
        // Rotation point is between mid and right
        return find_rotated_sorted(array, mid + 1, right, key);
    }
    if(array[left] <= key && array[mid] > key)
    {
        return find_rotated_sorted(array, left, mid - 1, key);
    }
    if(array[mid] < key && array[right] >= key)
    {
        return find_rotated_sorted(array, mid + 1, right, key);
    }
    return -1;
}


int main()
{
    int n;
    cin >> n;
    vector<int> array(n, 0);

    for(int i=0; i<n; i++)
    {
        cin >> array[i];
    }
    
    int key;
    cin >> key;

    cout << find_rotated_sorted(array, 0, n - 1, key) << endl;
}