BANKING MANAGEMENT SYSTEM  (C++)
----------------------------------------------------------

It is A console-based Banking Management System developed using C++. This project allows users to manage customer accounts and perform basic banking operations such as deposits, withdrawals, fund transfers, and transaction history management.

The project demonstrates the practical implementation of Object-Oriented Programming (OOP), functions, vectors, conditional statements, loops, and file handling in C++.

* PROJECT OVERVIEW :
----------------------------------------------------

The Banking Management System is designed to simplify basic banking operations through a menu-driven interface.

Users can create customer accounts, view registered customers, check account details, deposit money, withdraw money, transfer funds between accounts, and view transaction history.

Customer information and transaction records are stored in a text file to maintain data between program executions.

* FEATURES :
--------------------------------------------------

The system provides the following functionalities:

1. Create Customer & Account

- Register a new customer.
- Generate a unique Customer ID.
- Generate an account number.
- Store customer details such as name and phone number.
- Set an opening account balance.

2. View All Customers

- Display all registered customers.
- Show Customer ID, name, account number, and balance.

3. View Account Details

- Search for an account using its account number.
- Display complete customer and account information.
- Check the available account balance.

4. Deposit Money

- Deposit money into an existing account.
- Automatically update the account balance.
- Record the deposit in transaction history.

5. Withdraw Money

- Withdraw money from an existing account.
- Validate the withdrawal amount.
- Check available balance.
- Update the account balance after withdrawal.

6. Transfer Funds

- Transfer money between two registered accounts.
- Validate sender and receiver accounts.
- Prevent transfers to the same account.
- Check sufficient balance before transferring.
- Update both account balances.
- Record transfer details.

7. View Transaction History

- Search transactions using an account number.
- Display transaction type.
- Display transaction amount.
- Display transaction details.

8. Exit

- Save the latest data.
- Exit the banking system safely.

* TECHNOLOGIES USED :
------------------------------------------

Technology| Purpose
C++| Core programming language
OOP| Classes and objects
STL Vector| Dynamic data storage
Functions| Modular programming
File Handling| Persistent data storage
iostream| Input and output operations
fstream| Reading and writing files
string| Handling customer information

* C++ CONCEPTS IMPLEMENTED :
------------------------------------------

This project helped me practise the following programming concepts:

- Classes and Objects
- Functions and Function Prototypes
- Encapsulation (basic class-based data organization)
- Vectors and Dynamic Arrays
- For Loops and Do-While Loops
- If-Else Statements
- Switch Statements
- String Handling
- File Handling
- Input and Output Operations
- Searching and Data Management

* PROJECT STRUCTURE :
------------------------------------------

Banking-Management-System/
│
├── project2.cpp
├── project2.exe
├── bankdata.txt
└── README.md

* FILE DESCRIPTION :
----------------------------------------------

- "project2.cpp" – Main C++ source code.
- "project2.exe" – Compiled executable file (Windows).
- "bankdata.txt" – Stores customer and transaction records.
- "README.md" – Project documentation.

* HOW TO RUN THE PROJECT :
------------------------------------------

Follow these steps to run the project:

1. Clone this repository or download the project files.
2. Open the project folder in Visual Studio Code.
3. Open the terminal.
4. Compile the C++ program using:

g++ project.cpp -o cgpa

5. Run the executable:

Windows:

.\cgpa.exe

Linux / macOS:

./cgpa

🖥️ Main Menu

The application provides the following menu:

========================================
       WELCOME TO APNA BANK
          BANKING SYSTEM
========================================

1. Create Customer and Account
2. View All Customers
3. View Account Details or Balance
4. Deposit Money
5. Withdraw Money
6. Transfer Funds
7. View Transaction History
8. Exit

Enter your choice :


* PROJECT STRUCTURE :
----------------------------------------------

Banking-Management-System/
│
├── Project2.cpp
│
├── README.md
│
├── Bankdata.txt
│
└── Images/
    │
    ├── Output1.png
    ├── Output2.png
    ├── Output3.png
    └── Output4.png


* LEARNING OUTCOMES :
---------------------------------------------

Through this project, I gained practical experience in:

Developing a menu-driven C++ application.
Understanding Object-Oriented Programming.
Managing customer records using vectors.
Implementing basic banking operations.
Maintaining transaction records.
Working with file handling for data persistence.
Improving logical thinking and problem-solving skills.
 
* DISCLAIMER :
------------------------------------------

This project is developed for educational and learning purpose.

It is a basic console based banking simulation and is not intended for handling real financial transactions or storing real banking information .

* Author :
------------------

 Sakshi Rathore
 B.Tech – Artificial Intelligence
 Jabalpur Engineering College (Madhya Pradesh)
 India

* Acknowledgement :
 ----------------------------

This project was developed as part of my C++ programming internship at CodeAlpha.

Thank you for visiting my repository!

If you find this project useful, feel free to give it a ⭐.