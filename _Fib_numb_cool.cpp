//  Fib_numb_cool.cpp
//  A program to find the lowest number of unique fibonacci numebers that sum to any given natural number.
//  Execution time: very fast
//  Practical Uses: Not sure as of right now
//
//
//  Created by Nathan N. on 4/2/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    unsigned long int target = 1892181724129649417; // for fun, try 2997000102309100000 as target;
    unsigned long int start = 0;
    unsigned long int next = 1;
    unsigned long int fib_result = 0;
    vector<long> fib;
   
    while(fib_result < target) {
        fib_result = start + next;
        start = next;
        next = fib_result;
        fib.push_back(fib_result);
    }
    
    cout << endl << " ## The number " << target << " can be broken down into these fibonacci numbers:" << endl;
    
    long int comparisons = 0;
    unsigned long int check_sum = 0;
    unsigned long int left = target; // left over from each subtraction
    // loop thru all the numbers and find the biggest fib numbers we can subtract from target/left
    for(long int s = fib.size() - 1; s > -1; --s) {
        if(fib[s] > target) {
            continue;
        }
        else if(fib[s] <= left) {
            ++comparisons;
            left = left - fib[s];
            check_sum = check_sum + fib[s]; // for double checking to make sure the program out put is actually correct
            cout << fib[s] << endl;
            

        }
    }
    if(target == 0) {
        cout << 0 << endl;
    }
    // DOUBLE CHECK MECHANISM
    if(check_sum == target) {
        cout << "****************************" << endl;
        cout << "DOUBLE CHECK MECHANISM: PASS :)" << endl;
        cout << "Number of comparisons: about " << comparisons << endl;
        cout << "Number of multiplication computations: " << fib.size() << endl;
        return 0;
    }
    
    cout << "DOUBLE CHECK MECHANISM: FAIL :(" << endl;
    return 1;

}

/**
Max values you can try if you want:
20000000 // 20 million
1000000000 // 1 billion
2000000000 // 2bil (9th power)
200000000000 // 200 billion
20000000000000 // (13 power)
29970001023091
29970001023091000 // (17th power)
1892181724129649417 //  19th power (max)
 
** Below values do not work **
29970001023091000000 // (20th power)
29970001023091000000000
 
**/