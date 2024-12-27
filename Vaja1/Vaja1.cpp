// STACK and QUEUE

#include <iostream>
using namespace std;

void menu() {
    cout << "Stack - choices:" << endl;
    cout << "1) Add to stack" << endl;
    cout << "2) Read from stack" << endl;
    cout << "3) Print stack" << endl;
    cout << endl;
    cout << "Circular queue - choices:" << endl;
    cout << "4) Insert to queue" << endl;
    cout << "5) Read from queue" << endl;
    cout << "6) Print queue" << endl;
    cout << endl;
    cout << "7) End" << endl;
    cout << endl;
    cout << "Choice: ";
}

//FUNCTIONS FOR STACK
void push(int* stack, int& top, int max) {
    int i;
    cout << "Enter the number to be added to the stack: ";
    cin >> i;                                                       // random number, entered by user

    if (top == max) {                                               // if the index "top" is equal to the stack size, the stack is full 
        cout << "ERROR: Stack is full!" << endl;
        cout << endl;
    }
    else {
        stack[top] = i;                                             // put the number at the index "top" and increase the "top" by 1
        cout << "The following number was added to stack: " << i << endl;
        cout << endl;
        top++;
    }
}

void pop(int* stack, int& top) {
    if (top == 0) {                                                 // if the index "top" is equal to 0, it means that the stack is empty
        cout << "ERROR: Stack is empty!" << endl;
        cout << endl;
    }
    else {
        top--;                                                      //... otherwise, we print the last element in the stack and decrement the "top" by 1
        cout << "Last element in stack: " << stack[top] << endl;
        cout << endl;
    }
}

void print_stack(int* stack, int top) {
    cout << "Stack content: ";                                     // print everything on stack between indeces 0 and "top"
    for (int i = 0; i < top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
    cout << endl;
}


// FUNCTIONS FOR QUEUE
void insert_in_queue(int* queue, int& tail, int head, int maxi) {
    int i;
    cout << "Enter the number in the queue: ";
    cin >> i;

    // if "tail" is equal to the queue length, set it to zero, otherwise increment it by 1
    int tail_temporary = tail + 1;

    if (tail_temporary > maxi) {
        tail_temporary = 0;
    }

    if (tail_temporary == head) {
        cout << "ERROR: Queue is full!" << endl;
        cout << endl;
    }
    else {
        queue[tail] = i;                                             
        cout << "The following number was inserted into the queue: " << i << endl;
        cout << endl;
        tail = tail_temporary;                                          
    }
}

void read_queue(int* queue, int tail, int& head, int maxi) {
    if (tail == head) {                                            // if "head" and "tail" are at the same index, then the queue is empty
        cout << "ERROR: Queue is empty!" << endl;
        cout << endl;
    }
    else if (head == maxi) {                                      // if the "head" (i.e. the index of the first element) is equal to the length of the queue, we print the element at this index and set the "head" to index 0
        cout << "First element in the queue: " << queue[head] << endl;
        cout << endl;
        head = 0;
    }
    else {                                                        //... otherwise, we print the element at the "head" index and increase it by 1
        cout << "First element in the queue: " << queue[head] << endl;
        cout << endl;
        head++;
    }
}

void print_queue(int* queue, int tail, int& head, int maxi) {
    if (head == tail) {
        cout << "ERROR: Queue is empty!" << endl;
    }
    else {
        cout << "Queue content: ";
        if (head < tail) {                                            // if "head" is at a smaller index than "tail", we print the row from head to tail...
            for (int i = head; i < tail; i++)
                cout << queue[i] << " ";
            cout << endl;
        }
        else {                                                      // ... otherwise we print from "head" to "maxi", and then from 0 to "tail"
            for (int i = head; i <= maxi; i++)
                cout << queue[i] << " ";
            for (int j = 0; j < tail; j++)
                cout << queue[j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}



int main() {
    int choice;
    bool running = true;

    int stack_size = 0;
    int queue_size = 0;

    cout << "Enter stack size: ";
    cin >> stack_size;

    cout << "Enter queue size: ";
    cin >> queue_size;

    system("cls");

    int* stack = new int[stack_size];
    int top = 0;

    int* queue = new int[queue_size];
    int head = 0;
    int tail = 0;

    do {
        menu();
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            push(stack, top, stack_size);
            break;
        case 2:
            pop(stack, top);
            break;
        case 3:
            print_stack(stack, top);
            break;
        case 4:
            insert_in_queue(queue, tail, head, queue_size);
            break;
        case 5:
            read_queue(queue, tail, head, queue_size);
            break;
        case 6:
            print_queue(queue, tail, head, queue_size);
            break;
        case 7:
            running = false;
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }
    } while (running);

    return 0;
}



