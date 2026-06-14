#include <iostream>
#include <vector>

using namespace std;

// recursive BS
int binSeaRec(const vector<int> &arr, int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binSeaRec(arr, mid + 1, right, target);
    }
    else
    {
        return binSeaRec(arr, left, mid - 1, target);
    }
}

int main()
{
    vector<int> arr = {14, 23, 56, 89, 100};
    int target = 89;
    
    // Fixed: passed size()-1 instead of accessing out-of-bounds index
    int x = binSeaRec(arr, 0, arr.size() - 1, target); 
    
    if (x == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << target << " Found at index " << x;
    }
    return 0;
}
