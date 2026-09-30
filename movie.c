#include <stdio.h>
#include <string.h>

#define MAX 5

// Structure for Customer
struct Customer {
    int bookingID;
    char name[50];
    char movie[20];
    int tickets;
    float pricePerTicket;
    float totalAmount;
};

// Queue structure
struct Queue {
    struct Customer arr[MAX];
    int front, rear;
};

// Global booking ID generator
int bookingCounter = 1001;

// Initialize Queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if Queue is Full (Circular Queue)
int isFull(struct Queue *q) {
    return ((q->front == 0 && q->rear == MAX - 1) ||
            (q->rear == (q->front - 1 + MAX) % MAX));
}

// Check if Queue is Empty
int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

// Enqueue (Add booking)
void enqueue(struct Queue *q, struct Customer c) {
    if (isFull(q)) {
        printf("Queue is Full! Cannot add more bookings.\n");
        return;
    }

    if (q->front == -1) {
        q->front = q->rear = 0;
    }
    else if (q->rear == MAX - 1 && q->front != 0) {
        q->rear = 0;
    }
    else {
        q->rear++;
    }

    q->arr[q->rear] = c;
    printf("Booking added successfully! Booking ID: %d\n", c.bookingID);
}

// Print Bill
void printBill(struct Customer c) {
    float gst = (c.totalAmount * 18) / 100;
    float finalAmount = c.totalAmount + gst;

    printf("\n========= MOVIE TICKET BILL =========\n");
    printf("Booking ID     : %d\n", c.bookingID);
    printf("Customer Name  : %s\n", c.name);
    printf("Movie Name     : %s\n", c.movie);
    printf("Tickets        : %d\n", c.tickets);
    printf("Price/Ticket   : %.2f\n", c.pricePerTicket);
    printf("Subtotal       : %.2f\n", c.totalAmount);
    printf("GST (18%%)      : %.2f\n", gst);
    printf("Total Amount   : %.2f\n", finalAmount);
    printf("====================================\n");
}

// Dequeue (Serve customer)
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No customers in queue to serve.\n");
        return;
    }

    printf("\nTicket issued to %s for movie %s\n",
           q->arr[q->front].name, q->arr[q->front].movie);

    // Print bill
    printBill(q->arr[q->front]);

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else if (q->front == MAX - 1) {
        q->front = 0;
    }
    else {
        q->front++;
    }
}

// Peek (View next customer)
void peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Next Customer in Line: %s (Booking ID: %d)\n",
           q->arr[q->front].name, q->arr[q->front].bookingID);
}

// Display all bookings
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    printf("\n--- Current Bookings ---\n");

    int i = q->front;

    if (q->rear >= q->front) {
        while (i <= q->rear) {
            printf("ID:%d | %s | %s | %d tickets | Amount: %.2f\n",
                   q->arr[i].bookingID, q->arr[i].name, q->arr[i].movie,
                   q->arr[i].tickets, q->arr[i].totalAmount);
            i++;
        }
    }
    else {
        while (i < MAX) {
            printf("ID:%d | %s | %s | %d tickets | Amount: %.2f\n",
                   q->arr[i].bookingID, q->arr[i].name, q->arr[i].movie,
                   q->arr[i].tickets, q->arr[i].totalAmount);
            i++;
        }

        i = 0;
        while (i <= q->rear) {
            printf("ID:%d | %s | %s | %d tickets | Amount: %.2f\n",
                   q->arr[i].bookingID, q->arr[i].name, q->arr[i].movie,
                   q->arr[i].tickets, q->arr[i].totalAmount);
            i++;
        }
    }
}

// Main Program
int main() {
    struct Queue q;
    initQueue(&q);

    int choice;
    struct Customer c;

    int avengersSeats = 5;
    int pathaanSeats = 5;

    do {
        printf("\n--- Movie Booking System ---\n");
        printf("1. Book Ticket\n");
        printf("2. Serve Customer (Generate Bill)\n");
        printf("3. View Next\n");
        printf("4. Display Bookings\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                c.bookingID = bookingCounter++;

                printf("Enter Name: ");
                scanf("%s", c.name);

                int m;
                printf("Select Movie (1. Avengers, 2. Pathaan): ");
                scanf("%d", &m);

                if (m == 1) {
                    strcpy(c.movie, "Avengers");
                    c.pricePerTicket = 200;
                }
                else if (m == 2) {
                    strcpy(c.movie, "Pathaan");
                    c.pricePerTicket = 150;
                }
                else {
                    printf("Invalid movie choice.\n");
                    break;
                }

                printf("Enter number of tickets: ");
                scanf("%d", &c.tickets);

                c.totalAmount = c.tickets * c.pricePerTicket;

                if (strcmp(c.movie, "Avengers") == 0) {
                    if (c.tickets <= avengersSeats) {
                        avengersSeats -= c.tickets;
                        enqueue(&q, c);
                    } else {
                        printf("Not enough seats! Only %d left.\n", avengersSeats);
                    }
                }
                else if (strcmp(c.movie, "Pathaan") == 0) {
                    if (c.tickets <= pathaanSeats) {
                        pathaanSeats -= c.tickets;
                        enqueue(&q, c);
                    } else {
                        printf("Not enough seats! Only %d left.\n", pathaanSeats);
                    }
                }
                break;
            }

            case 2:
                dequeue(&q);
                break;

            case 3:
                peek(&q);
                break;

            case 4:
                display(&q);
                printf("\n--- Seats Remaining ---\n");
                printf("Avengers: %d\n", avengersSeats);
                printf("Pathaan: %d\n", pathaanSeats);
                break;

            case 5:
                printf("Exiting system...\n");
                break;

            default:
                printf("Please select 1-5.\n");
        }

    } while (choice != 5);

    return 0;
}