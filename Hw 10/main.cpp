#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

double divide(int num, int den) {
    if (den == 0) {
        throw invalid_argument("Can't divide by zero!");
    }
    double divided = num/den;
    return divided;
}

int accessArray(int arr[], int size, int idx) {
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range!");
    }
    return arr[idx];
}

void nestedFunction() {
    throw runtime_error("Something went wrong in nestedFunction.");
}

void outerFunction() {
    try {
        nestedFunction();
    } catch (const runtime_error& e) {
        cerr << "Caught it in outerFunction: " << e.what() << endl;
        throw;
    }
}

int main() {
    try {
        int num, den;
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;

        try {
            double res = divide(num, den);
            cout << "Result: " << res << endl;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }

        int size;
        cout << "Enter array size: ";
        cin >> size;

        int* arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1;
        }

        int idx;
        cout << "Enter index to access: ";
        cin >> idx;

        try {
            int val = accessArray(arr, size, idx);
            cout << "Value at index " << idx << ": " << val << endl;
        } catch (const out_of_range& e) {
            cerr << "Error: " << e.what() << endl;
        }


        try {
            outerFunction();
        } catch (const runtime_error& e) {
            cerr << "Caught it again in main: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}
