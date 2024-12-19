#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Initialize the two maps
    map<int, int> numbers1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    map<int, int> numbers2 = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}, {6, 60}, {7, 70}, {8, 80}, {9, 90}};

   
    map<int, string> intermediate;

    //just needed chat to show me how to create iterating copies of my original two maps
    map<int, int>::iterator int1 = numbers1.begin();
    map<int, int>::iterator int2 = numbers2.begin();

    while (int1 != numbers1.end() && int2 != numbers2.end()) {
        intermediate[int1->first] = to_string(int1->second) + ", " + to_string(int2->second);
        ++int1;
        ++int2;
    }

    
    cout << "Intermediate map: ";
    for (const auto& pair : intermediate) {
        cout << pair.first << ": " << pair.second << " ";
    }
    cout << endl;

    return 0;
}
