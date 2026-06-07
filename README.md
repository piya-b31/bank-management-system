# 🏦 Bank Management System

A console-based Bank Management System built in **C++** using core Object-Oriented Programming principles. This project simulates real-world banking operations like account creation, deposits, withdrawals, and record management — with persistent file-based storage.

---

## 📌 Features

- **Open Account** — Register a new customer with personal details, account type (Saving/Current), and initial deposit
- **Deposit & Withdraw** — Perform transactions with minimum balance enforcement and penalty deduction
- **Check Balance** — View current account balance
- **Search Account** — Look up a customer record by name
- **Display All Records** — View all stored customer data
- **Remove Account** — Delete a customer account from records with confirmation prompt

---

## 🛠️ Tech Stack

| Component | Details |
|-----------|---------|
| Language | C++ |
| Concepts | OOP, Inheritance, File I/O, Vectors |
| Storage | Text file (`Customers_record.txt`) |
| IDE | Any C++ compiler (g++, VS Code, Dev-C++) |

---

## 🧱 Project Structure

```
BankManagementSystem/
│
├── main.cpp               # Main source file
├── Customers_record.txt   # Auto-generated customer data file
└── README.md
```

---

## 🏛️ Class Design

```
OpenAccount
    └── transaction        (inherits OpenAccount)
            └── ManageAcc  (inherits transaction)
```

| Class | Responsibility |
|-------|---------------|
| `OpenAccount` | Collects user info, generates account number, writes to file |
| `transaction` | Handles deposit, withdrawal, balance check |
| `ManageAcc` | Displays, searches, and removes customer records |

---

## ⚙️ How to Run

### 1. Clone the repository
```bash
git clone https://github.com/your-username/bank-management-system.git
cd bank-management-system
```

### 2. Compile
```bash
g++ main.cpp -o bank
```

### 3. Run
```bash
./bank        # Linux/Mac
bank.exe      # Windows
```

---

## 📋 Menu Overview

```
**** WELCOME TO BANK MANAGEMENT SYSTEM ****

Press 1 to Open Account
Press 2 to Search Account
Press 3 to Display Details
Press 4 to Remove an Account
Press 5 to Exit
```

### Account Types & Minimum Balance

| Account Type | Minimum Balance | Penalty if Below |
|-------------|----------------|-----------------|
| Saving      | ₹5,000         | ₹200            |
| Current     | ₹10,000        | ₹500            |

---

## 💡 Key Concepts Demonstrated

- **Multi-level Inheritance** — `OpenAccount → transaction → ManageAcc`
- **File Handling** — `fstream`, `ifstream`, `ofstream` for persistent storage
- **STL Vectors** — Used for filtering records during account removal
- **Input Validation** — Loops ensuring valid phone number, DOB, and deposit amount
- **Random Number Generation** — `mt19937` for unique 16-digit account numbers

---

## 👩‍💻 Author

**Piya Bharwani**  
BCA Student — Avantika University, Ujjain  
[LinkedIn](https://linkedin.com/in/piya-bharwani-9888a3305) | [GitHub](https://github.com/piya-b31)
