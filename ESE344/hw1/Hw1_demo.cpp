#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//relative sort function
vector<int> relativeSortArray(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_map<int, int> freq;
    //frequency count loop to use for later
    for (int num : arr1) {
        freq[num]++;
    }
    
    vector<int> result;
    //using counts from before insert into a new array having been counted.
    for (int num : arr2) {
        if (freq.count(num)) {
            //insertion
            result.insert(result.end(), freq[num], num);
            //move onto next one and remove from addition queue 
            freq.erase(num);
        }
    }
    
    //array 2 needs a secondry vector for holding
    vector<int> extras;
    for (auto pair : freq) {
        // Insert the value "pair.second" times.
        extras.insert(extras.end(), pair.second, pair.first);
    }
    // Sort the extras in ascending order with built in sort function
    sort(extras.begin(), extras.end());
    
    // Append extras
    result.insert(result.end(), extras.begin(), extras.end());
    return result;
}

int main() {
   cout<< " EXPECTED BEHAVIOR : Example 1: \n \n Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6] \n Output: [2,2,2,1,4,3,3,9,6,7,19] \n Example 2: \n Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6] \n Output: [22,28,8,6,17,44]";
   
   
    // Example 1 run 
    vector<int> arr1_1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2_1 = {2, 1, 4, 3, 9, 6};
    vector<int> sorted1 = relativeSortArray(arr1_1, arr2_1);
    
    cout << "\n\nNOW FOR SORTING PROOFS: \n";


    cout << "Sorted arr1 for Example 1: ";
    for (int num : sorted1)
        cout << num << " ";
    cout << "\n";
    
    // Example 2 run
    vector<int> arr1_2 = {28, 6, 22, 8, 44, 17};
    vector<int> arr2_2 = {22, 28, 8, 6};
    vector<int> sorted2 = relativeSortArray(arr1_2, arr2_2);
    
    cout << "Sorted arr1 for Example 2: ";
    for (int num : sorted2)
        cout << num << " ";
    cout << "\n";
    
    return 0;
}
