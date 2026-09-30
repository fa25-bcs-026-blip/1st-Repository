#include <iostream>
using namespace std;

struct ArrayList {
    int arr[100];
    int size = 0;

    void insertEnd(int val) {
        arr[size] = val;
        size++;
    }

    void display() {
        cout << "Array List: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int linearSearch(int target) {
        int i = 0;
        while (i < size) {
            if (arr[i] == target) {
                return i;
            }
            i++;
        }
        return -1;
    }
};

int main() {
    ArrayList list;
    int n, val, target;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        list.insertEnd(val);
    }

    list.display();

    cout << "Enter value to search: ";
    cin >> target;

    int index = list.linearSearch(target);
    if (index != -1) {
        cout << "Value found at index " << index << endl;
    } else {
        cout << "Value not found" << endl;
    }

    return 0;
}
