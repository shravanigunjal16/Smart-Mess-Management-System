#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
    string customer[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    // a) Customer Arrival
    void customerArrival(string name)
    {
        // Check if queue is full
        if ((rear + 1) % MAX == front)
        {
            cout << "Checkout queue is full!" << endl;
            return;
        }

        // First customer
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        customer[rear] = name;

        cout << name << " has joined the checkout queue." << endl;
    }

    // b) Customer Checkout
    void customerCheckout()
    {
        // Check if queue is empty
        if (front == -1)
        {
            cout << "No customers in the queue." << endl;
            return;
        }

        cout << customer[front]
             << " has completed checkout." << endl;

        // If only one customer is present
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    // d) View Customers
    void viewCustomers()
    {
        if (front == -1)
        {
            cout << "Checkout queue is empty." << endl;
            return;
        }

        cout << "\nCustomers in the queue:" << endl;

        int i = front;

        while (true)
        {
            cout << customer[i] << endl;

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }
    }

    // c) Close Checkout Counter
    void closeCounter()
    {
        if (front == -1)
        {
            cout << "Checkout counter is already empty." << endl;
        }
        else
        {
            cout << "\nClosing checkout counter..." << endl;
            cout << "Remaining customers in the queue:" << endl;

            viewCustomers();

            front = -1;
            rear = -1;

            cout << "Checkout counter closed successfully." << endl;
        }
    }
};

int main()
{
    CircularQueue q;
    int choice;
    string name;

    do
    {
        cout << "\n--- SUPERMARKET CHECKOUT SYSTEM ---" << endl;
        cout << "1. Customer Arrival" << endl;
        cout << "2. Customer Checkout" << endl;
        cout << "3. Close Checkout Counter" << endl;
        cout << "4. View Customers" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                q.customerArrival(name);
                break;

            case 2:
                q.customerCheckout();
                break;

            case 3:
                q.closeCounter();
                break;

            case 4:
                q.viewCustomers();
                break;

            case 5:
                cout << "Exiting the system..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}