#include "Prime.h"
#include <queue>
#include <unordered_set>
#include <cstdint>

int Prime::gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool Prime::IsACoprimeOf(int Value, int Coprime)
{
    return gcd(Value, Coprime) == 1;
}

//only good for small hamming number
uint64_t Prime::generateHammingNumbers(int n)
{
    std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> pq; // Min-heap priority queue
    std::unordered_set<uint64_t> seen; // To avoid duplicates

    pq.push(1); // The first Hamming number is 1
    seen.insert(1);

    uint64_t  answer;
    uint64_t factors[] = {2, 3, 5}; // The prime factors for Hamming numbers

    while (n--) {
        // Get the smallest element from the priority queue
        uint64_t current = pq.top();
        pq.pop();
        
        answer = current;
        //std::cout << current << " "; // Output the current smallest Hamming number
            
        // Generate new Hamming numbers by multiplying the current one by 2, 3, or 5
        for (int i = 0; i < 3; ++i) {
            uint64_t newNum = current * factors[i];
            if (seen.find(newNum) == seen.end()) { // If it's not already in the set
                pq.push(newNum);
                seen.insert(newNum);
            }
        }
    }
    //cout << endl;

    return answer;
}
