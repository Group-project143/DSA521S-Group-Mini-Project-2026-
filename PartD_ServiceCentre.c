#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE 100

struct Student {
    int studentNumber;
    char name[50];
    char serviceType[50];
    int serviceTime;
};

struct Node {
    struct Student data;
    struct Node *next;
};
struct Node *head = NULL;

struct Student queue[MAX_QUEUE];
int front = 0;
int rear = -1;
int queueSize = 0;

void enqueue(struct Student student)
{
    if (queueSize == MAX_QUEUE)
    {
        printf("Queue is full.\n");
        return;
    }

    rear = (rear + 1) % MAX_QUEUE;
    queue[rear] = student;
    queueSize++;

    printf("%s has joined the queue.\n", student.name);
}

struct Student dequeue()
{
    struct Student emptystudent = {0};

    if (queueSize == 0)
    {
        printf("Queue is empty.\n");
        return emptystudent;
    }

    struct Student servedStudent = queue[front];
    front = (front + 1) % MAX_QUEUE;
    queueSize--;

    printf("%s has been served and removed from the queue.\n", servedStudent.name);
    return servedStudent;
}
struct Student peek()
{
    struct Student emptystudent = {0};

    if (queueSize == 0)
    {
        printf("Queue is empty.\n");
        return emptystudent;
    }

    return queue[front];
}

void displayQueue()
{
    if (queueSize == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("\n===== WAITING QUEUE =====\n");
    
    int index = front;
    
    for (int i = 0; i < queueSize; i++)
    {
        printf("%d. %d | %s | %s | %d minutes\n",
                i + 1,
                queue[index].studentNumber,
                queue[index].name,
                queue[index].serviceType,
                queue[index].serviceTime);

        index = (index + 1) % MAX_QUEUE;
    }   

    printf("=========================\n");
}

void insertRecord(struct Student student)
{
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = student;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}
void displayRecords()
{
    if (head == NULL)
    {
        printf("No student service records.\n");
        return;
    }

    printf("\n===== STUDENT SERVICE RECORDS =====\n");

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d | %s | %s | %d minutes\n",
               temp->data.studentNumber,
               temp->data.name,
               temp->data.serviceType,
               temp->data.serviceTime);

        temp = temp->next;
    }

    printf("===================================\n");
}
void searchRecord(int studentNumber)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data.studentNumber == studentNumber)
        {
            printf("\nStudent found:\n");
            printf("Student Number: %d\n", temp->data.studentNumber);
            printf("Name: %s\n", temp->data.name);
            printf("Service Type: %s\n", temp->data.serviceType);
            printf("Service Time: %d minutes\n",
                   temp->data.serviceTime);

            return;
        }

        temp = temp->next;
    }

    printf("Student not found.\n");
}

void deleteRecord(int studentNumber)
{
    if (head == NULL)
    {
        printf("No student service records.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *previous = NULL;

    while (temp != NULL &&
           temp->data.studentNumber != studentNumber)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student not found.\n");
        return;
    }

    if (previous == NULL)
    {
        head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    printf("%s's service record has been deleted.\n",
           temp->data.name);

    free(temp);
}
void displayDailyStatistics()
{
    int serviceTimes[] = {12, 5, 8, 4, 15, 11};

    int numberOfStudents = 6;
    int totalServiceTime = 0;
    int highestServiceTime = serviceTimes[0];
    int lowestServiceTime = serviceTimes[0];
    int longerThanTen = 0;

    for (int i = 0; i < numberOfStudents; i++)
    {
        totalServiceTime += serviceTimes[i];

        if (serviceTimes[i] > highestServiceTime)
        {
            highestServiceTime = serviceTimes[i];
        }

        if (serviceTimes[i] < lowestServiceTime)
        {
            lowestServiceTime = serviceTimes[i];
        }

        if (serviceTimes[i] > 10)
        {
            longerThanTen++;
        }
    }

    float averageServiceTime =
        (float) totalServiceTime / numberOfStudents;

    printf("\n===== DAILY STATISTICS =====\n");
    printf("Number of Students Served: %d\n", numberOfStudents);
    printf("Total Service Time: %d minutes\n", totalServiceTime);
    printf("Average Service Time: %.2f minutes\n", averageServiceTime);
    printf("Highest Service Time: %d minutes\n", highestServiceTime);
    printf("Lowest Service Time: %d minutes\n", lowestServiceTime);
    printf("Services Longer Than 10 Minutes: %d\n", longerThanTen);
    printf("============================\n");
}
void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        if (smallestIndex != i)
        {
            int temp = array[i];
            array[i] = array[smallestIndex];
            array[smallestIndex] = temp;
        }
    }
}
void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}
void merge(int array[], int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int leftArray[leftSize];
    int rightArray[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;

            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(array, low, high);

        quickSort(array, low, pivotIndex - 1);

        quickSort(array, pivotIndex + 1, high);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       NUST SERVICE CENTRE\n");
        printf("====================================\n");
        printf("1. Add Student to Queue\n");
        printf("2. Serve Next Student\n");
        printf("3. View Waiting Queue\n");
        printf("4. Add Service Record\n");
        printf("5. Search Service Record\n");
        printf("6. Delete Service Record\n");
        printf("7. Display All Service Records\n");
        printf("8. View Daily Statistics\n");
        printf("9. Sort Service Times\n");
        printf("0. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
           
            case 1:
            {
                struct Student newStudent;

                printf("\n===== ADD STUDENT TO QUEUE =====\n");

                printf("Enter Student Number: ");
                scanf("%d", &newStudent.studentNumber);

                printf("Enter Name: ");
                scanf(" %49[^\n]", newStudent.name);

                printf("Enter Service Type: ");
                scanf(" %49[^\n]", newStudent.serviceType);

                printf("Enter Service Time (minutes): ");
                scanf("%d", &newStudent.serviceTime);

                enqueue(newStudent);

                break;
            }

            case 2:
            {
                printf("\n===== SERVE NEXT STUDENT =====\n");

                struct Student servedStudent = dequeue();

                if (servedStudent.studentNumber != 0)
                {
                    printf("Student served successfully.\n");
                }

                break;
            }

            case 3:
            {
                displayQueue();
                break;
            }

            case 4:
            {
                struct Student record;

                printf("\n===== ADD SERVICE RECORD =====\n");

                printf("Enter Student Number: ");
                scanf("%d", &record.studentNumber);

                printf("Enter Name: ");
                scanf(" %49[^\n]", record.name);

                printf("Enter Service Type: ");
                scanf(" %49[^\n]", record.serviceType);

                printf("Enter Service Time (minutes): ");
                scanf("%d", &record.serviceTime);

                insertRecord(record);

                printf("Service record added successfully.\n");

                break;
            }

            case 5:
            {
                int studentNumber;

                printf("\n===== SEARCH SERVICE RECORD =====\n");

                printf("Enter Student Number: ");
                scanf("%d", &studentNumber);

                searchRecord(studentNumber);

                break;
            }

            case 6:
            {
                int studentNumber;

                printf("\n===== DELETE SERVICE RECORD =====\n");

                printf("Enter Student Number: ");
                scanf("%d", &studentNumber);

                deleteRecord(studentNumber);

                break;
            }

            case 7:
            {
                displayRecords();
                break;
            }

            case 8:
            {
                displayDailyStatistics();
                break;
            }

            case 9:
            {
                int sortChoice;

                printf("\n===== SORT SERVICE TIMES =====\n");
                printf("1. Selection Sort\n");
                printf("2. Insertion Sort\n");
                printf("3. Merge Sort\n");
                printf("4. Quick Sort\n");

                printf("Choose Sorting Algorithm: ");
                scanf("%d", &sortChoice);

                int serviceTimes[] =
                    {17, 5, 23, 8, 14, 3, 11, 20, 6, 9};

                int size = 10;

                printf("\nBefore Sorting:\n");

                for (int i = 0; i < size; i++)
                {
                    printf("%d ", serviceTimes[i]);
                }

                printf("\n");

                switch (sortChoice)
                {
                    case 1:
                        selectionSort(serviceTimes, size);
                        printf("\nSelection Sort selected.\n");
                        break;

                    case 2:
                        insertionSort(serviceTimes, size);
                        printf("\nInsertion Sort selected.\n");
                        break;

                    case 3:
                        mergeSort(serviceTimes, 0, size - 1);
                        printf("\nMerge Sort selected.\n");
                        break;

                    case 4:
                        quickSort(serviceTimes, 0, size - 1);
                        printf("\nQuick Sort selected.\n");
                        break;

                    default:
                        printf("\nInvalid sorting option.\n");
                        break;
                }

                if (sortChoice >= 1 && sortChoice <= 4)
                {
                    printf("\nAfter Sorting:\n");

                    for (int i = 0; i < size; i++)
                    {
                        printf("%d ", serviceTimes[i]);
                    }

                    printf("\n");
                }

                break;
            }

            case 0:
            {
                printf("\nExiting NUST Service Centre System...\n");
                printf("Thank you.\n");
                break;
            }

            default:
            {
                printf("\nInvalid option. Please try again.\n");
                break;
            }
        }

    } while (choice != 0);

    return 0;
} 