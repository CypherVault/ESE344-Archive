#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int analyzePassword(const string& password) {
    int steps = 0; // tracker for peices that need updating
    int length = password.length();
    
    bool hasLower = false, hasUpper = false, hasDigit = false;
    bool hasRepeating = false;
    
    // Check character types
    for (size_t i = 0; i < length; i++) {
        if (islower(password[i])) hasLower = true;
        if (isupper(password[i])) hasUpper = true;
        if (isdigit(password[i])) hasDigit = true;
        
        // Check for repeating characters
        if (i >= 2) {
            if (password[i] == password[i-1] && password[i-1] == password[i-2]) {
                hasRepeating = true;
            }
        }
    }
    
    // Print status and count steps
    cout << "Requirements check: \n";
    
    // Length check
    if (length < 6) {
        cout << "- Length (6-20 chars): Fail (too short)\n";
        steps += 6 - length;  // Need to add characters
    }
    else if (length > 20) {
        cout << "- Length (6-20 chars): Fail (too long)\n";
        steps += length - 20;  // Need to remove characters
    }
    else {
        cout << "- Length (6-20 chars): Pass\n";
    }
    
    // Character type checks
    if (!hasLower) {
        cout << "- Lowercase letter: Fail\n";
        steps++;
    } else {
        cout << "- Lowercase letter: Pass\n";
    }
    
    if (!hasUpper) {
        cout << "- Uppercase letter: Fail\n";
        steps++;
    } else {
        cout << "- Uppercase letter: Pass\n";
    }
    
    if (!hasDigit) {
        cout << "- Digit: Fail\n";
        steps++;
    } else {
        cout << "- Digit: Pass\n";
    }
    
    if (hasRepeating) {
        cout << "- No triple repeating: Fail\n";
        steps++;
    } else {
        cout << "- No triple repeating: Pass\n";
    }
    
    return steps;
}

// Modified main function
int main() {
    vector<string> testCases = {
        "a",                    
        "aA1",                 
        "1337C0d3",           
        "abcdefghijklmnopqrstuvwxyz",
        "aaa",                
        "ABCD1234",          
        "abcd1234",          
        "ABCDabcd",          
        "aaa111",            
        "Password123",       
        "aaaAAA111",        
        ""                   
    };

    cout << "=== Strong Password Checker Demo ===" << endl << endl;

    for (size_t i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << (i + 1) << ":" << endl;
        cout << "-------------" << endl;
        cout << "Password: \"" << testCases[i] << "\"" << endl;
        cout << "Password length: " << testCases[i].length() << endl;
        
        // print the results of analyzing , and then the number of steps the funtion saw
        int minSteps = analyzePassword(testCases[i]);
        cout << "\nMinimum steps required: " << minSteps << endl << endl; 
        // this doesnt work perfect at the moment, it over or undercounts.
    }

    return 0;
}
