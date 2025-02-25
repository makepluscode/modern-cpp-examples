#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize a vector with some numbers
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Define a threshold value that we want to capture in lambda
    int threshold = 3;

    std::cout << "Numbers greater than " << threshold << ":\n";

    // Lambda function with capture
    // [threshold]: captures 'threshold' by value
    // (int n): parameter list, takes each number from vector
    auto check_threshold = [threshold](int n) {
        if (n > threshold) {
            std::cout << n << " is greater than " << threshold << std::endl;
        }
    };

    // Use for_each algorithm with our lambda function
    // This will apply the lambda to each element in the vector
    std::for_each(numbers.begin(), numbers.end(), check_threshold);

    return 0;
}