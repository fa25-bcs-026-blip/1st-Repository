
#include <iostream>
#include <cmath>

using namespace std;

const int CAPACITY = 20;

struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};

// This function adds a new value at the end of the list
bool insertEnd(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;

    list.data[list.size] = value;
    list.size++;

    return true;
}

// This function adds a value at the start of the list
bool insertAtBeginning(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;

    // Move all existing values one step to the right
    for (int i = list.size; i > 0; i--)
    {
        list.data[i] = list.data[i - 1];
    }

    list.data[0] = value;
    list.size++;

    return true;
}

// This function removes a value from the given position
bool deleteAtPosition(ArrayList &list, int position)
{
    if (position < 0 || position >= list.size)
        return false;

    // Shift the values left to fill the empty space
    for (int i = position; i < list.size - 1; i++)
    {
        list.data[i] = list.data[i + 1];
    }

    list.size--;

    return true;
}

// This function prints all the values in the list
void displayList(const ArrayList &list)
{
    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i] << " ";
    }

    cout << endl;
}

int main()
{
    ArrayList list;

    // These pointers will be used to find different values in the list
    int *ptr = list.data;
    int *minPtr = list.data;
    int *maxPtr = list.data;
    int *medianPtr = list.data;
    int *closestPtr = list.data;

    int sum = 0;
    int closestPosition;

    double generalAverage;
    double specialAverage;
    double averageDifference;
    double finalScore;

    // Adding the given values to the ArrayList
    insertEnd(list, 18);
    insertEnd(list, 7);
    insertEnd(list, 45);
    insertEnd(list, 11);
    insertEnd(list, 36);
    insertEnd(list, 26);
    insertEnd(list, 21);
    insertEnd(list, 13);
    insertEnd(list, 29);

    cout << "Initial ArrayList: ";
    displayList(list);

    // Starting from the first element to find min, max and sum
    ptr = list.data;
    minPtr = list.data;
    maxPtr = list.data;

    sum = 0;

    for (int i = 0; i < list.size; i++)
    {
        sum = sum + *ptr;

        // Check if the current value is smaller than the minimum
        if (*ptr < *minPtr)
        {
            minPtr = ptr;
        }

        // Check if the current value is bigger than the maximum
        if (*ptr > *maxPtr)
        {
            maxPtr = ptr;
        }

        ptr++;
    }

    cout << "Minimum Value: " << *minPtr << endl;
    cout << "Maximum Value: " << *maxPtr << endl;
    cout << "Sum: " << sum << endl;

    // Make a temporary copy of the list to find the median
    int temp[CAPACITY];

    for (int i = 0; i < list.size; i++)
    {
        temp[i] = list.data[i];
    }

    // Sorting the temporary array from smallest to largest
    for (int i = 0; i < list.size - 1; i++)
    {
        for (int j = 0; j < list.size - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int swapValue = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swapValue;
            }
        }
    }

    // Get the middle value after sorting
    int medianValue = temp[list.size / 2];

    // Find the actual median value in the original list
    medianPtr = list.data;

    for (int i = 0; i < list.size; i++)
    {
        if (*medianPtr == medianValue)
        {
            break;
        }

        medianPtr++;
    }

    cout << "Median Value: " << *medianPtr << endl;

    // Calculate the average of all values
    generalAverage = (double)sum / list.size;

    // Calculate the average of minimum, median and maximum
    specialAverage =
        (*minPtr + *medianPtr + *maxPtr) / 3.0;

    // Now find the value which is closest to the special average
    ptr = list.data;
    closestPtr = list.data;

    double smallestDistance =
        fabs(*ptr - specialAverage);

    for (int i = 0; i < list.size; i++)
    {
        double distance =
            fabs(*ptr - specialAverage);

        if (distance < smallestDistance)
        {
            smallestDistance = distance;
            closestPtr = ptr;
        }

        ptr++;
    }

    // Find the position of the closest value
    closestPosition = closestPtr - list.data;

    cout << "General Average: "
         << generalAverage << endl;

    cout << "Special Average: "
         << specialAverage << endl;

    cout << "Closest Value: "
         << *closestPtr << endl;

    cout << "Position of Closest Value: "
         << closestPosition << endl;

    // Find the difference between the two averages
    averageDifference =
        fabs(generalAverage - specialAverage);

    // Calculate the final score using the required formula
    finalScore =
        fabs(*closestPtr - generalAverage)
        + fabs(*closestPtr - specialAverage)
        + averageDifference;

    cout << "Difference Between Averages: "
         << averageDifference << endl;

    cout << "Final Score: "
         << finalScore << endl;

    // Remove the closest value from the list
    closestPosition = closestPtr - list.data;

    deleteAtPosition(list, closestPosition);

    cout << "ArrayList After Deletion: ";
    displayList(list);

    // Round the special average and add it at the beginning
    int roundedSpecialAverage =
        (int)round(specialAverage);

    insertAtBeginning(list, roundedSpecialAverage);

    cout << "Final ArrayList After Insertion: ";
    displayList(list);

    return 0;
}

