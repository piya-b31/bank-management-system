#include <iostream> // Input-output stream library
#include <string> // String manipulation library
#include <fstream> // File stream library
#include <random> // Random number generation library
#include <ctime> // Time manipulation library
#include <vector> // Vector library for dynamic arrays
using namespace std; // Using the standard namespace

class OpenAccount { // Class to manage opening bank accounts
public:
    int amount=0, amt=0, amtt=0, type; 
    string name, address, phnNo, dateOfBirth;
    long long accountNumber; 

    void openAcc() { // Function to open a bank account
        cin.ignore(); // Ignore any leftover characters in input buffer
        system("cls"); // Clear the screen
        cout << "\nEnter your name: "; 
        getline(cin, name); 

        cout << "Enter your Address: "; 
        getline(cin, address); 

        while (1) { // Loop to ensure valid date of birth input
            cout << "Enter your date of birth (DD/MM/YYYY): "; 
            cin >> dateOfBirth; 
            if (dateOfBirth.length() == 10) { 
                break; 
            } else {
                cout << "Enter valid Date of Birth!" << endl; 
            }
        }

        while (1) { // Loop to ensure valid phone number input
            cout << "Enter your Phone number: "; 
            cin >> phnNo; 
            if (phnNo.length() == 10) { 
                break; 
            } else {
                cout << "Enter valid phone number!" << endl; 
            }
        }
        
        cout<<"\nThank you for sharing your personal information with us!\n";
        
           
        do { // Loop to ensure valid account type input
             system("cls");
            cout << "\nWhich type of Account do you want? (1 for saving, 2 for current): "; 
            cin >> type; 
            switch (type) { // Switch statement to handle different account types
            case 1: // If saving account
                cout << "\n**You have to deposit a minimum amount of 5,000 to maintain your Saving account**" << endl; 
                while (1) { // Loop to ensure valid deposit amount input
                    cout << "\nPlease enter the amount to deposit: "; 
                    cin >> amt; 
                    if (amt < 5000) { // Check if deposit amount is less than minimum balance requirement
                        cout << "\nPlease deposit 5,000 or more to continue the process!" << endl; 
                    } else {
                        break; // Exit loop if valid deposit amount
                    }
                }
                break;

            case 2: // If current account
                cout << "\n**You have to deposit a minimum amount of 10,000 to maintain your Current account**" << endl; 
                while (1) { // Loop to ensure valid deposit amount input
                    cout << "\nPlease enter the amount to deposit: "; 
                    cin >> amt; 
                    if (amt < 10000) { // Check if deposit amount is less than minimum balance requirement
                        cout << "\nPlease deposit 10,000 or more to continue the process!" << endl; // Display error message for insufficient deposit amount
                    } else {
                        break; // Exit loop if valid deposit amount
                    }
                }
                break;
            default: // If invalid account type
                cout << "Enter valid choice!" << endl; 
                break;
            }
        } while (type != 2 && type != 1); // Continue loop until valid account type is chosen

        amount = amt; // Set account balance to deposited amount

        // Generate random account number
        random_device rd; 
        mt19937 gen(rd()); 
        uniform_int_distribution<long long> dis(1000000000000000, 9999999999999999); 
        accountNumber = dis(gen); 

        // Display account opening confirmation
        cout << "\nYour Account is successfully opened!!" << endl;
        cout << "........................................................" << endl;
        cout << "Your Account Number: " << accountNumber << endl;
        cout << "........................................................" << endl;
        cout << "Thank you for choosing our bank and opening an account with us!" << endl;

        ofstream file("Customers_record.txt", ios::app); // Open file to store customer records in append mode
        if (!file.is_open()) { // Check if file opening failed
            cout<<".................................."<<endl; 
            cerr << "Error: Unable to open file." << endl; 
            cout<<".................................."<<endl; 
            return; 
        }
        file // Write customer details to file
             << "Name: " << name << endl
             << "Address: " << address << endl
             << "Date of Birth: " << dateOfBirth << endl
             << "Phone No. : " << phnNo << endl
             << "Account Type: " << type << endl
             << "Balance Amount: " << amount << endl
             << "-----------------------------------------" << endl
             << "Account No. : " << accountNumber << endl
             << endl;
        file.close(); // Close file after writing
    }
};

class transaction : public OpenAccount { // Class to manage transactions inheriting from OpenAccount
public:
    void deposit() { // Function to deposit amount
        cout << "\n\nEnter the amount you want to deposit: "; 
        cin >> amt; 
        if (amt < 0) { // Check if deposit amount is negative
            cout << "Enter a valid amount!" << endl; 
            return; 
        }
        amount += amt; // Add deposit amount to account balance
    }

    void withdraw() { // Function to withdraw amount
        cout << "\nEnter the amount you want to withdraw: "; 
        cin >> amtt; 
        if (amtt > amount) { // Check if withdrawal amount exceeds account balance
            cout << "Insufficient balance!" << endl; 
            return; 
        }
        amount -= amtt; // Deduct withdrawal amount from account balance
        if (type == 1 && amount < 5000) { // If saving account and balance falls below minimum balance
            cout << "Withdrawal amount exceeds limit. A 200 fee applies to withdrawals exceeding the limit." << endl; 
            amount-=200;
        } else if (type == 2 && amount < 10000) { // If current account and balance falls below minimum balance
            cout << "Withdrawal amount exceeds limit. A 500 fee applies to withdrawals exceeding the limit." << endl; 
            amount-=500;
        }
    }

    void balance() { 
        cout << "Your balance amount is: " << amount << endl; 
    }
};

class ManageAcc : public transaction { 
public:
    void display() { // Function to display customer records
        system("cls"); 
        int total;
        fstream file; 
        file.open("Customers_record.txt", ios::in); // Open file in input mode
        if (!file) { 
            cout<<"............................"<<endl; 
            cout << "There is no data" << endl; 
            cout<<"............................"<<endl; 
            file.close(); // Close file
        } else { 
            file >> accountNumber >> name >> phnNo >> address >> dateOfBirth >> amt >> amtt >> amount; 
            do { // Loop to read and display all records
                cout << "Name : " << name << endl; 
                cout << "Address : " << address << endl; 
                cout << "Phone No. : " << phnNo << endl; 
                cout << "Date of Birth : " << dateOfBirth << endl << endl; 
                cout << "Last Amount Deposited : " << amt << endl; 
                cout << "Last Amount Withdrawn : " << amtt << endl; 
                cout << "Balance Amount : " << amount << endl; 
                file >> accountNumber >> name >> phnNo >> address >> dateOfBirth >> amt >> amtt >> amount; 
                total++;
            } while (file.eof()); // Continue loop until end of file
            if (total == 0) { 
                cout<<"............................"<<endl; 
                cout << "There is no data" << endl; 
                cout<<"............................"<<endl; 
            }
        }
        file.close(); // Close file
    }

    void search() { // Function to search for a customer
        string searchName; 
        cin.ignore(); 
        system("cls"); 
        cout << "Enter the name of the customer you want to search: "; 
        getline(cin, searchName); 
        system("cls"); 
        ifstream file("Customers_record.txt"); // File stream object to read customer records
        if (!file.is_open()) { 
            cout << "Unable to open file!" << endl; 
            return; 
        }

        string line; 
        bool found = false; // Flag to indicate if customer is found
        while (getline(file, line)) { // Loop to read file line by line
            if (line.find("Name: " + searchName) != string::npos) { 
                // Extract and print customer information
                cout << "\nCustomer information found:\n\n"; 
                cout << line << endl; 
                for (int i = 0; i < 7; i++) { // Loop to print next 7 lines 
                    getline(file, line); 
                    cout << line << endl; 
                }
                found = true; 
                break; 
            }
        }

        if (!found) { 
            cout << "Customer with name '" << searchName << "' not found!" << endl;
        }

        file.close(); // Close file
    }

    bool removeAccount() { // Function to remove a customer account
        string nameToRemove; 
        system("cls"); 
        cout << "Enter the name of the customer account to remove: "; 
        cin.ignore(); 
        getline(cin, nameToRemove); 
        
            ifstream inputFile("Customers_record.txt"); 
        string line; 
        bool found = false; // Flag to indicate if account is found
        vector<string> linesToKeep; // Vector to store lines to keep

        while (getline(inputFile, line)) { // Loop to read file line by line
            if (line.find("Name: " + nameToRemove) == string::npos) { // Check if line does not contain the name to remove
                linesToKeep.push_back(line); // Add line to vector (keeping lines to keep)
            } else { // If line contains the name to remove
                found = true; // Set flag to indicate account found
                // Skip lines containing account information (approximately 7 lines)
                for (int i = 0; i < 7; ++i) { // Loop to skip next 7 lines
                    getline(inputFile, line); // Read and discard next line
                }
            }
        }

        inputFile.close(); // Close input file

        if (!found) { 
            cout << "Customer with name '" << name << "' not found for removal." << endl; 
            return false; 
        }
        cout << "\nDo you really want to remove this Account?(1 for Yes, 2 for No)\n ";
        int ans;
        cin>>ans;
        if(ans==1){
        // Overwrite the original file content with filtered data
        ofstream outputFile("Customers_record.txt", ios::trunc); // Open file in truncate mode to clear existing content
        if (!outputFile.is_open()) { 
            cerr << "Error: Unable to open file for account removal." << endl; 
            return false; 
        }

        for (const string& line : linesToKeep) { 
            outputFile << line << endl; 
        }

        outputFile.close(); // Close output file

        cout << "Account successfully removed." << endl; 
    }
        else{
            cout<<"\nThank you for being with us!\n";
        }
        return true; 
    }
        
};

int main() { // Main function
    cout << "\n\t\t**** WELCOME TO BANK MANAGEMENT SYSTEM ****" << endl; 
    int choice; 
    ManageAcc l; 
    int ch; // Variable to store main menu choice
    do { // Loop to display main menu
        cout << "\nPress 1 to Open Account" << endl; 
        cout << "Press 2 to Search Account" << endl; 
        cout << "Press 3 to Display Details" << endl; 
        cout << "Press 4 to Remove an Account" << endl; 
        cout << "Press 5 to Exit" << endl; 
        cout << "\nEnter your choice: "; 
        cin >> ch; 
        switch (ch) { // Switch statement to handle user choice
         case 1: 
            system("cls");
            l.openAcc(); 
           
            do { // Loop to display account operation menu
                cout << "\n1. Deposit Amount"; 
                cout << "\n2. Withdraw Amount"; 
                cout << "\n3. Check balance"; 
                cout << "\n4. Exit"; 
                cout << "\nEnter your choice: "; 

                cin >> choice; 
                system("cls"); 
                switch (choice) { // Switch statement to handle user choice
                case 1: 
                    l.deposit(); 
                    break;
                case 2: 
                    l.withdraw(); 
                    break;
                case 3: 
                    l.balance(); 
                    break;
                case 4: 
                    exit; 
                }
            } while (choice != 4); // Continue loop until user chooses to exit
            break;

        case 2: 
            l.search(); 
            break;
        case 3: 
            l.display(); 
            break;
        case 4: 
            system("cls"); 
            l.removeAccount(); 
            break;
        case 5: 
            cout << "Exiting..." << endl; 
            break;
        default:
            cout << "Invalid choice!" << endl; 
            break;
        }
    } while (ch != 5); // Continue loop until user chooses to exit

    return 0; // Return 0 to indicate successful program execution
}