//  Program9 track the number of comparisons performed by a sorting algorithm
//  Created by Minjing Liang on 10/24/20.
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
using namespace std;
class AbstractSort{    // base class
private:
    int comparisonCount; // number of comparison
protected:
    int compare(int x, int y){  //compare array elements function
        comparisonCount++;
        return (x-y);
    }
public:
    virtual void sort(int arr[],int size) = 0;  // virtual sort function
    int getComparisonCount(){                  // get number of comparison function
        return comparisonCount;
    }
    void resetComparisonCount(){               // reset count function
        comparisonCount = 0;
    }
};
class MaxSort : public AbstractSort{          // derived class
public:
    void sort(int arr[],int size){            // sorting funciton
        resetComparisonCount();
        for(int i = size-1; i >= 1; i--){
            int indexOfLargest = 0;
            for(int j = 1; j <= i; j++){
                if (compare(arr[j],arr[indexOfLargest])>0)
                    indexOfLargest = j;
            }
                    swap (arr[indexOfLargest],arr[i]);
        }
    }
};
int main() {
    const int MAX_NUM = 100;  //constant size variable
    int arr[MAX_NUM];         // int array
    int size;                 // int array size variable
    cout << "This program will keep track the number of comparisons performed by a sorting algorithm.\n";
    cout << "Enter a size for array less than 100: ";
    cin >> size;
    if (size > 100){  //valid input
        cout << "\nEnter a size for array less than 100: " << endl;
        exit(1);
    }
    srand(static_cast<int>(time(0))); // fill array with random number less than 1000
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 1000;
    }
    cout << "Array before sort\n";   // display array before sorting
    for (int i = 0; i < size; i++){
        cout << arr[i] << "   ";
    }
    MaxSort maxSort;  // create an object
    maxSort.sort(arr,size); // call sorting function
    cout << "\nArray after sort\n"; // display array after sortin
    for (int i = 0; i < size; i++){
        cout << arr[i] << "   ";
    }
    cout << "\nThe number of comparison for sorting the array is : ";
    cout << maxSort.getComparisonCount() <<endl; // call number of comparison function and display
    return 0;
}
