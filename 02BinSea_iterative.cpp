#include <iostream>
#include <vector>
using namespace std;

int binSeaIt(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
       
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1; 
        }
    }

    return -1;
}
int main(){
    vector <int> arr = {14,23,56,89,100};
    int target = 89;
    int x= binSeaIt(arr,target);
    if(x==-1){
        cout<<"Not found";
    }else{
        cout<<target<<" Found at index "<<x;
    }
    return 0;
}
