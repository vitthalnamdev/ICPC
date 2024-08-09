#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <algorithm>

int main() {
    const size_t arraySize = 100000;
    const uint64_t minValue = 1;
    const uint64_t maxValue = 1000000;
    std::cout<<1<<std::endl;
	std::cout<<arraySize<<std::endl;
    // Create a random number generator
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937_64 eng(rd()); // Seed the generator
    std::uniform_int_distribution<uint64_t> distr(minValue, maxValue);

    // Create a set to store unique numbers
    std::unordered_set<uint64_t> uniqueNumbers;

    // Generate unique random numbers
    while (uniqueNumbers.size() < arraySize) {
        uniqueNumbers.insert(distr(eng));   
    }

    // Transfer unique numbers to a vector
    std::vector<uint64_t> array(uniqueNumbers.begin(), uniqueNumbers.end());

    // Output the first 10 elements to verify
     
    for (size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
