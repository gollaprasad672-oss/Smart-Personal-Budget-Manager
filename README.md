# Smart-Personal-Budget-Manager

This is a Smart Personal Budget Manager which effectively stores the user's daily expenses. The user can view their daily expenses, a monthly summary, and the categories in which money was spent. This enables users to ensure money is effectively used for daily necessities and allows them to reduce their spending effectively.  



## Features  
> Add an expense with date, category, amount, and a short description.

> View all expenses in a simple table with IDs.

> Monthly summary with totals and a highest-spend category.
## Requirements
GCC or any C compiler.
## Build
gcc finance_tracker.c -o finance_tracker
## Run
Linux/macOS:  

 ./finance_tracker  
 
Windows:  

.\finance_tracker.exe  

An expenses.txt file is created in the same folder after your first saved expense. Back it up if you need to preserve history.

# Finance Tracker  

A simple command-line finance tracker written in C that allows you to track income and expenses.

## Features  

Add income transactions  

Add expense transactions  

View current balance (income - expenses)  

View all transactions  

Simple numeric menu navigation
## Compilation
To compile the program, use:

gcc finance_tracker.c -o finance_tracker  

Or on Windows with MinGW:  

gcc finance_tracker.c -o finance_tracker.exe
## Usage
Run the compiled program:

./finance_tracker  

or on Windows:

finance_tracker.exe  

Then use the numeric menu to navigate:  


1 - Add Income  

2 - Add Expense  

3 - View Balance  

4 - View All Transactions  

5 - Exit
## Notes
Transactions are stored in memory and will be lost when the program exits  

Maximum of 100 transactions per session  

All amounts must be positive numbers
