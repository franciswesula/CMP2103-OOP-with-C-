#include <iostream>
#include <vector>

using namespace std;

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    cout << "Enter a credit card number as a long integer: ";
    cin >> cardNumber;

    if (isValid(cardNumber)) {
        cout << cardNumber << " is valid" << endl;
    } else {
        cout << cardNumber << " is invalid" << endl;
    }

    return 0;
}

bool isValid(long long number) {
    int size = getSize(number);
    
    // Rule: Must have between 13 and 16 digits
    if (size < 13 || size > 16) {
        return false;
    }

    // Rule: Must start with 4, 5, 37, or 6
    bool hasValidPrefix = prefixMatched(number, 4) ||
                          prefixMatched(number, 5) ||
                          prefixMatched(number, 37) ||
                          prefixMatched(number, 6);

    if (!hasValidPrefix) {
        return false;
    }

    // Rule: Luhn check (Mod 10)
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    
    return (totalSum % 10 == 0);
}

// Get the result from Step 2 (Double every second digit from right to left)
int sumOfDoubleEvenPlace(long long number) {
    vector<int> digits;
    
    // Extract digits right-to-left into a vector
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    
    int sum = 0;
    // Even places from right to left (1st, 3rd, 5th, etc., in 1-based indexing) 
    // corresponds to index 1, 3, 5, etc., in 0-based vector indexing.
    for (size_t i = 1; i < digits.size(); i += 2) {
        sum += getDigit(digits[i] * 2);
    }
    
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number % 10) + (number / 10);
}

// Return sum of odd place digits in number
int sumOfOddPlace(long long number) {
    vector<int> digits;
    
    // Extract digits right-to-left into a vector
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    
    int sum = 0;
    // Odd places from right to left (0th, 2nd, 4th, etc., in 1-based indexing)
    // corresponds to index 0, 2, 4, etc., in 0-based vector indexing.
    for (size_t i = 0; i < digits.size(); i += 2) {
        sum += digits[i];
    }
    
    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    return getPrefix(number, getSize(d)) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    vector<int> digits;
    while (d > 0) {
        digits.push_back(d % 10);
        d /= 10;
    }
    return digits.size();
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    if (size < k) {
        return number;
    }
    
    long long result = number;
    // To get the first 'k' digits, we trim off the remaining (size - k) digits from the right.
    for (int i = 0; i < size - k; ++i) {
        result /= 10;
    }
    
    return result;
}