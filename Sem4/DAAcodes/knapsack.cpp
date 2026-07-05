#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
void knapsack(float weight[],float val[],int capacity){

}

int main(){
    int capacity, itemCount;
    std::cin >> itemCount;
    std::cin >> capacity;

    float weight[itemCount];
    float val[itemCount];
    for (int i = 0; i < itemCount; i++) {
        std::cin >> weight[i];
    }
    for (int i = 0; i < itemCount; i++) {
        std::cin >> val[i];
    }
    knapsack( weight,val, capacity);
}