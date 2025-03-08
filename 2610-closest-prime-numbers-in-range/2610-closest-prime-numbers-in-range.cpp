class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
    vector<int> primeNumbers;
    vector<int> res{-1, -1};

    // Store all the prime values from 0 till right
    // Using sieveOfEratosthenes method to find the prime numbers
    vector<bool> isPrime(right + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i <= right; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= right; j += i) {
                isPrime[j] = false;
            }
        }
    }

    //Stroing all the prime numbers in primeNumbers
    for(int i=left; i<=right; i++){
        if(isPrime[i]) primeNumbers.push_back(i);
    }

    //If size of primeNumbers is less then 2, then the output will be [-1, -1]
    //Even if there is 1 prime number between left & right, because res[1] - res[0] should still be minimized.
    if(primeNumbers.size()<2) return res;

    //If primeNumbers contains only 2 values, then no other combination exists
    if(primeNumbers.size()==2) return primeNumbers;

    //Check the minimum difference between 2 prime numbers
    int diff = INT_MAX;
    for(int i=0; i<primeNumbers.size()-1; i++){
        //We are checking primeNumbers[i+1]-primeNumbers[i]<diff
        //We are not checking primeNumbers[i+1]-primeNumbers[i]<=diff
        //because we need to return smallest value with minimum difference 
        if(primeNumbers[i+1]-primeNumbers[i]<diff){
            res[0] = primeNumbers[i];
            res[1] = primeNumbers[i+1];
            diff = res[1]-res[0];
        }
    }
    return res;
}
};