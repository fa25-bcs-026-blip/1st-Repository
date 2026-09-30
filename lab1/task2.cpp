#include <iostream>
using namespace std;

struct ArrayList {
    int arr[100];
    int size = 0;

    void insertEnd(int val) {
        if (size >= 100) {
            cout << "List is full\n";
            return;
        }
        arr[size] = val;
        size++;
    }

    void insertStart(int val) {
        if (size >= 100) {
            cout << "List is full\n";
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
        size++;
    }

    void insertAfter(int target, int val) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Value not found\n";
            return;
        }
        for (int i = size; i > index + 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index + 1] = val;
        size++;
    }

    void insertBefore(int target, int val) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Value not found\n";
            return;
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        size++;
    }

    void display() {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }
        cout << "Array List: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteEnd() {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }
        size--;
    }

    void deleteStart() {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteSpecific(int val) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Value not found\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
};

int main() {
    ArrayList list;
    int choice, val, target;
    do {
        cout << "\n--- Array List Operations ---\n";
        cout << "1. Insert End\n2. Insert Start\n3. Insert After\n4. Insert Before\n";
        cout << "5. Display\n6. Delete End\n7. Delete Start\n8. Delete Specific\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            list.insertEnd(val);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            list.insertStart(val);
        } else if (choice == 3) {
            cout << "Enter target: ";
            cin >> target;
            cout << "Enter value: ";
            cin >> val;
            list.insertAfter(target, val);
        } else if (choice == 4) {
            cout << "Enter target: ";
            cin >> target;
            cout << "Enter value: ";
            cin >> val;
            list.insertBefore(target, val);
        } else if (choice == 5) {
            list.display();
        } else if (choice == 6) {
            list.deleteEnd();
        } else if (choice == 7) {
            list.deleteStart();
        } else if (choice == 8) {
            cout << "Enter value: ";
            cin >> val;
            list.deleteSpecific(val);
        }
    } while (choice != 9);

    return 0;
}
