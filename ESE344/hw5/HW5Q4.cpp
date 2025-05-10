#include <iostream>
#include <cstring>

//extra credit Number 1 leetcode attempt

// Function to count char freq
void countChars(const char* s, int* count) 
{ //as long as it isnt a null character loop through the whole passed string and for that index increment for each appearance 
    for (int i = 0; s[i] != '\0'; i++) {
        count[(int)s[i]]++;
    }
}

// Function to build the palindrome string
void buildPalindrome(const int* count, char* palindrome, int len) {
    int left = 0;
    int right = len - 1;
    char center = 0;

    for (int i = 0; i < 128; i++) {
        int pairs = count[i] / 2; // grab teh counted letters at the end indexes, and place them into plaindrome string
        for (int j = 0; j < pairs; j++) {
            palindrome[left++] = (char)i;
            palindrome[right--] = (char)i;
        }
        // if non mod 2, we can grab the absoluete center and place that off count character from before
        if (count[i] % 2 == 1 && center == 0) {
            center = (char)i;
        }
    }
    // Place the center character if there is an odd-count character
    if (center != 0) {
        palindrome[left] = center;
    }
    palindrome[len] = '\0'; // Null-terminate the string for C complicance
}

int main() {
    const char* s = "abccccdd"; // example from pdf hw assignment
    int count[128] = {0}; //preallocated memory to hold up to 128 letters of frequyency logging

   // count char freq
    countChars(s, count);


    //deal with precounting the palindrome to build the string later on 
    // palindrome length
    int length = 0;
    for (int i = 0; i < 128; i++) {
        length += (count[i] / 2) * 2;
    }
    // If any odd-count character exists, we can put one in the center
    if (length < (int)strlen(s)) {
        length++;
    }

    // build palindrome string for output 
    char palindrome[101]; // again were assuming lenth, string is <= 100 chars
    buildPalindrome(count, palindrome, length);

    // print results
    std::cout << "Longest palindrome length: " << length << std::endl;
    std::cout << "(There can be multiple answers given the string provided. on my machine for this example it outputs ccdadcc.) \n\nThe longest palindrome that this program has calculated is: " << palindrome << std::endl;

    return 0;
}
