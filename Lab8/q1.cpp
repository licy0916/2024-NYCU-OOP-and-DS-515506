#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, vector<int>& left, vector<int>& right) {
    //TO-DO
    int i = 0, j = 0, k = 0;
    while (i < int(left.size()) && j < int(right.size())) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < int(left.size())) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < int(right.size())) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
}

void mergeSort(vector<int>& arr) {
    //TO-DO
    if (arr.size() <= 1) return;

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    mergeSort(left);
    mergeSort(right);

    merge(arr, left, right);
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //TO-DO
    mergeSort(arr);

    for(int num : arr){
        cout << num << " ";
    }
    return 0;
}
