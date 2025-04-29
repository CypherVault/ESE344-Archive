#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    set<string> foodItems;
    map<int, map<string, int>> tableCounts;

    // sort and index all contents, parsing section
    for (auto& order : orders) {
        int table = stoi(order[1]);
        string food = order[2];
        foodItems.insert(food);
        tableCounts[table][food]++;
    }

    // Prepare sorted components
    vector<string> foods(foodItems.begin(), foodItems.end());
    sort(foods.begin(), foods.end()); // sort foods detected for count / insertion later for database 
    
    vector<int> tables;
    for (auto& entry : tableCounts)
        tables.push_back(entry.first);
    sort(tables.begin(), tables.end());

    // Build result
    vector<vector<string>> result;
    result.push_back({"Table"});
    result[0].insert(result[0].end(), foods.begin(), foods.end()); //initial index label

    for (int table : tables) { // iterativey build result from databsases and sorted content 
        vector<string> row{to_string(table)};
        auto& counts = tableCounts[table];
        for (auto& food : foods)
            row.push_back(to_string(counts[food]));
        result.push_back(row);
    }

    return result;
}

int main() {



// Example test case1 
    vector<vector<string>> orders1 = {
        {"David","3","Ceviche"},
        {"Corina","10","Beef Burrito"},
        {"David","3","Fried Chicken"},
        {"Carla","5","Water"},
        {"Carla","5","Ceviche"},
        {"Rous","3","Ceviche"}
    };

    vector<vector<string>> result1 = displayTable(orders1);
    cout << "Example 1 Output:\n";
    for (auto& row : result1) { //print in main dont sort in functions call
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i < row.size()-1 ? "," : "");
        }
        cout << endl;
    }

// Example test case2
    vector<vector<string>> orders2 = {
        {"James","12","Fried Chicken"},
        {"Ratesh","12","Fried Chicken"},
        {"Amadeus","12","Fried Chicken"},
        {"Adam","1","Canadian Waffles"},
        {"Brianna","1","Canadian Waffles"}
    };

    vector<vector<string>> result2 = displayTable(orders2);
    cout << "\nExample 2 Output:\n";
    for (auto& row : result2) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i < row.size()-1 ? "," : "");
        }
        cout << endl;
    }

    return 0;
}
