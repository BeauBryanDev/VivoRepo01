#include<iostream>
#include<climits>
#include<cstdio>

using namespace std;

uint greedyExchange(int coinValues[], int coinCount, int targetAmount) {
    if (targetAmount == 0)
        return 0;

    if (targetAmount < 0)
        return INT_MAX;

    int coins = INT_MAX;

    for (int i = 0; i < coinCount; i++) {
        
        int result = greedyExchange(coinValues, coinCount, targetAmount - coinValues[i]);

        if (result != INT_MAX)
            coins = min(coins, result + 1);
    }

    return coins;
}

int main(int argc, char const *argv[]) {
    int coinValues[] = {50, 25, 20, 10, 5, 2, 1};
    int coinCount = sizeof(coinValues) / sizeof(coinValues[0]);

    int targetAmount = 68;

    cout << "The minimum number of coins needed for " << targetAmount << " cents is: " 
         << greedyExchange(coinValues, coinCount, targetAmount) << endl;

    return 0;
}