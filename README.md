\# Movie Booking System



A console-based \*\*Movie Ticket Booking System\*\* developed in C using a \*\*Circular Queue\*\* data structure.



The application manages customer bookings, movie seat availability, ticket serving, queue operations, and bill generation.



\## Features



\* Book movie tickets

\* Manage customers using a circular queue

\* Generate unique booking IDs

\* Check available seats

\* View the next customer in the queue

\* Display all current bookings

\* Generate movie ticket bills

\* Calculate 18% GST

\* Support for multiple movies



\## Technologies Used



\* C Programming

\* Data Structures

\* Circular Queue

\* Structures

\* Arrays

\* String Handling

\* Functions

\* Console-based interface



\## Data Structure Used



\### Circular Queue



The project uses a \*\*Circular Queue\*\* to manage customer bookings.



The following queue operations are implemented:



\* \*\*Enqueue\*\* — Add a new customer booking

\* \*\*Dequeue\*\* — Serve the next customer

\* \*\*Peek\*\* — View the next customer

\* \*\*Display\*\* — Display all current bookings

\* \*\*isFull\*\* — Check whether the queue is full

\* \*\*isEmpty\*\* — Check whether the queue is empty



The circular queue allows the available array positions to be reused after customers are served.



\## Movies Available



| Movie    | Price per Ticket | Initial Seats |

| -------- | ---------------: | ------------: |

| Avengers |             ₹200 |             5 |

| Pathaan  |             ₹150 |             5 |



\## Project Structure



```text

Movie-Booking-System/

│

├── movie.c

├── .gitignore

└── README.md

```



\## How the Program Works



1\. The program initializes an empty circular queue.

2\. The user selects an operation from the menu.

3\. For a new booking, the customer provides their name, movie selection, and number of tickets.

4\. The system checks the available seats.

5\. If seats are available, the booking is added to the queue.

6\. Each booking receives a unique booking ID.

7\. When a customer is served, the booking is removed from the front of the queue.

8\. A bill is generated with the ticket cost and 18% GST.

9\. The user can view the next customer or display all current bookings.



\## How to Run



\### 1. Compile the program



Open a terminal inside the project directory and run:



```bash

gcc movie.c -o movie.exe

```



\### 2. Run the program



On Windows PowerShell:



```powershell

.\\movie.exe

```



\## Example



```text

\--- Movie Booking System ---

1\. Book Ticket

2\. Serve Customer (Generate Bill)

3\. View Next

4\. Display Bookings

5\. Exit



Enter choice: 1

Enter Name: Namita

Select Movie (1. Avengers, 2. Pathaan): 1

Enter number of tickets: 4



Booking added successfully! Booking ID: 1001

```



Displaying the bookings:



```text

\--- Current Bookings ---

ID:1001 | Namita | Avengers | 4 tickets | Amount: 800.00



\--- Seats Remaining ---

Avengers: 1

Pathaan: 5

```



\## Bill Generation



When a customer is served, the system generates a bill containing:



\* Booking ID

\* Customer name

\* Movie name

\* Number of tickets

\* Price per ticket

\* Subtotal

\* GST (18%)

\* Final amount



\## Learning Outcomes



This project demonstrates practical implementation of:



\* Circular Queue

\* FIFO (First In, First Out)

\* Structures in C

\* Arrays

\* Functions

\* String operations

\* Conditional statements

\* Menu-driven programming

\* Basic billing calculations



\## Future Improvements



Possible improvements include:



\* Add more movies

\* Increase seat capacity

\* Support multiple theatres or screens

\* Add date and show-time selection

\* Store bookings permanently using files

\* Add cancellation functionality

\* Add a graphical user interface

\* Improve input validation



\## Author



\*\*Namita Dave\*\*



Computer Engineering Student



