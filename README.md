# 🏦 Bank Management System (BMS)

A simple yet powerful **Bank Management System** built in **C++**, designed to simulate real-world banking operations such as account creation, deposits, withdrawals, user management, and currency exchange.  
This project follows Object-Oriented Programming (OOP) principles and focuses on clean code structure, modularity, and file-based data persistence.

---

## 🚀 Features

### 👤 Clients Management
- Add, update, find, and delete clients  
- Deposit and withdraw money  
- View total balances across all accounts  

### 🔐 User Management
- Add, update, and delete system users  
- Manage user permissions  
- Login and authentication system with user activity logs  
- Prevent self-deletion and “Admin” account removal  

### 💱 Currency Exchange
- View currency list and exchange rates  
- Currency conversion calculator  
- Update currency rates  

### 🧾 Transaction History
- Record and view transfer logs  
- Track deposits, withdrawals, and transfers between accounts  

### 🗂️ File-Based Storage
- All data (users, clients, currencies, logs) is stored in external files  
- Simulates a lightweight database system  

---

## 🧠 Technologies Used

- **Language:** C++  
- **Paradigm:** Object-Oriented Programming (OOP)  
- **Tools:** File I/O, Classes, Vectors, Static Methods, Validation Utilities  

---

## 📂 Project Structure
```
BMS/
│
├── Core/
│ ├── clsBankClient.h
│ ├── clsCurrency.h
│ ├── clsPerson.h
│ └── clsUser.h
│
├── Lib/
│ ├── clsDate.h
│ ├── clsInputValidate.h
│ ├── clsPeriod.h
│ ├── clsString.h
│ └── clsUtil.h
│
├── Screens/
│ ├── Client/
│ ├── Currencies/
│ └── User/
│
├── Global.h
└── main.cpp
```

---

## ⚙️ How to Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/SoufianeOuani/Bank-Management-Project.git


2. **Open in your IDE:**

Use Visual Studio, Code::Blocks, or any C++ IDE.

Set main.cpp as the startup file.

3. **Build & Run:**

Compile and run the project.

Follow on-screen menus to perform operations.

**🧩 Concepts Demonstrated**

Classes & Objects

Inheritance & Encapsulation

Static Methods

File Handling (read/write)

Input Validation

Data Structures (vectors)

Modular Programming

**🔒 Authentication System**

The system includes a simple login mechanism.

Default admin user:

Username: Admin

Password: Admin123

The Admin user cannot be deleted.

**📜 License**

This project is licensed under the MIT License
.

**👨‍💻 Author**

Soufiane Ouani
💡 Digital Development Student |
📧 ouanisoufiane@gmail.com


⭐ If you like this project, don’t forget to star it on GitHub!


---

