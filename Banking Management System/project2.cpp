# include <iostream>
# include <vector>
# include <string>
# include <iomanip>
# include <fstream>
# include <sstream>
using namespace std;

void createcustomer();
void viewcustomer();
void accountdetails();
void depositmoney();
void withdrawmoney();
void transferfunds();
void transactionhistory();
void loaddata();
void savedata() ;

int main() {

loaddata();
savedata();

cout<<"____________________________________________"<<endl;
cout<<"____________________________________________"<<endl;
cout<<endl;
cout<<"          WELCOME TO APNA BANK "            <<endl;
cout<<"            BANKING SYSTEM "                <<endl;

cout<<"____________________________________________"<<endl;
cout<<"____________________________________________"<<endl;


cout<<endl;
cout<<endl;

cout<<"========================================"<<endl;
cout<<"            MAIN MENU "    <<endl;
cout<<"========================================"<<endl;


int choice ;
do
{

    cout<<endl;
    cout<<endl;
   cout<<"\t 1.\t Create customer and account\n " ;
   cout<<"\t 2.\t View all customers\n ";
   cout<<"\t 3.\t View account details or balance\n ";
   cout<<"\t 4.\t Deposit money\n";
   cout<<"\t 5.\t Withdraw money\n";
   cout<<"\t 6.\t Transfer funds \n";
   cout<<"\t 7.\t View transaction history\n";
   cout<<"\t 8.\t exit\n";
   cout<<endl;
   cout<<endl;
   cout<<"\n Enter your choice :";
   cin>>choice ;

   switch(choice)
   {case 1 :
    createcustomer() ;
    break;

    case 2 :
    viewcustomer() ;
    break;

    case 3 :
    accountdetails() ;
    break;

    case 4 :
    depositmoney() ;
    break;

    case 5 :
    withdrawmoney() ;
    break;

    case 6 :
    transferfunds() ;
    break;

    case 7 :
    transactionhistory() ;
    break;

    case 8 :
    savedata() ;
    cout<<"\n Thank you for using Banking System!\n";
    break;

    default :
    cout<<"Invalid choice! Try again.";

}

} while (choice != 8);

}

class transaction 
{
public:
string type;
double amount;
string details;
};

class Customer 
{ 
  public:
  int customerId;
  string name ;
  string phone ;
  double balance ;
  int accountnumber;

  vector <transaction> transactions;

};


vector<Customer>customers;

int nextcustomerId = 111;
int nextaccountnumber = 10000011;


void createcustomer()
{
  Customer c;

  c.customerId = nextcustomerId++;
  c.accountnumber = nextaccountnumber++ ;

 cout<<"\n Enter Customer Name : ";
 cin.ignore();
 getline(cin , c.name ) ;

 cout<<"\n Enter phone Number : ";
 cin>> c.phone ; 

 cout<<"\n Enter opening Balance : ";
 cin>> c.balance ;

 customers.push_back(c);

 savedata();

 cout<<" \n CUSTOMER REGISTERED SUCCESSFULLY ";
cout<<endl;
cout<<endl;
cout<<"\n ____________________________________________\n";
cout<<"Customer ID :"<< c.customerId <<endl;
cout<<"Account number :"<< c.accountnumber <<endl;
cout<<"Customer Name :"<<c.name <<endl;
cout<<"opening Balance : Rs. "<<c.balance <<endl;
cout<<"_______________________________________________";
cout<<endl;
cout<<endl;
}

void viewcustomer(){
    if (customers.empty())
    {
        cout << "\nNo Customer Records Found!\n";
        return;
    }

    cout << "\n========== ALL REGISTERED CUSTOMERS ==========\n";

    for (int i = 0; i < customers.size(); i++)
    {
        cout << "\nCustomer " << i + 1 << endl;

        cout << "Customer ID: "
             << customers[i].customerId << endl;

        cout << "Customer Name: "
             << customers[i].name << endl;

        cout << "Account Number: "
             << customers[i].accountnumber << endl;

        cout << "Balance: Rs. "
             << customers[i].balance << endl;

          

        cout << "---------------------------------------\n";

        cout<<endl;
        cout<<endl;
    }
}

void accountdetails(){
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].accountnumber == accNo)
        {
            cout << "\n========== ACCOUNT DETAILS ==========\n";

            cout << "Customer ID: "
                 << customers[i].customerId << endl;

            cout << "Customer Name: "
                 << customers[i].name << endl;

            cout << "Phone Number: "
                 << customers[i].phone << endl;

            cout << "Account Number: "
                 << customers[i].accountnumber << endl;

            cout << "Available Balance: Rs. "
                 << customers[i].balance << endl;

            found = true;
            break;
            cout<<endl;
            cout<<endl;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }

    
}

void depositmoney(){
    int accNo;
    double amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].accountnumber == accNo)
        {
            found = true;

            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "\nInvalid Amount!\n";
                return;
            }
            customers[i].balance += amount;

            customers[i].transactions.push_back(
                {"deposit", amount, "moneydeposited"}
            );

            cout<<"Total transactions : "<<customers[i].transactions.size()<<endl;

            savedata() ;

            cout << "\n========== DEPOSIT SUCCESSFUL ==========\n";

            cout << "Account Number: "
                 << customers[i].accountnumber << endl;

            cout << "Deposited Amount: Rs. "
                 << amount << endl;

            cout << "Updated Balance: Rs. "
                 << customers[i].balance << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void withdrawmoney(){
  int accNo;
    double amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].accountnumber == accNo)
        {
            found = true;

            cout << "Enter Amount to withdraw : ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "\nInvalid Amount!\n";
                return;
            }

            customers[i].balance -= amount;

            customers[i].transactions.push_back(
                {"withdrawal", amount, "moneywithdrawn"}
            );

            savedata();

            cout << "\n========== Withdrawal SUCCESSFUL ==========\n";

            cout << "Account Number: "
                 << customers[i].accountnumber << endl;

            cout << "Withdrawn Amount: Rs. "
                 << amount << endl;

            cout << "Current Balance: Rs. "
                 << customers[i].balance << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void transferfunds(){
    int senderAcc, receiverAcc;
    double amount;

    bool senderFound = false;
    bool receiverFound = false;

    int senderIndex = -1;
    int receiverIndex = -1;

    cout << "\nEnter Sender Account Number: ";
    cin >> senderAcc;

    cout << "\nEnter Receiver Account Number: ";
    cin >> receiverAcc;

    // Find sender and receiver accounts
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].accountnumber == senderAcc)
        {
            senderFound = true;
            senderIndex = i;
        }

        if (customers[i].accountnumber == receiverAcc)
        {
            receiverFound = true;
            receiverIndex = i;
        }
    }

    if (!senderFound)
    {
        cout << "\nSender Account Not Found!\n";
        return;
    }

    if (!receiverFound)
    {
        cout << "\nReceiver Account Not Found!\n";
        return;
    }

    if (senderIndex == receiverIndex)
    {
        cout << "\nCannot transfer money to the same account!\n";
        return;
    }

    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\nInvalid Amount!\n";
        return;
    }

    if (amount > customers[senderIndex].balance)
    {
        cout << "\nInsufficient Balance!\n";
        return;
    }

    // Transfer money
    customers[senderIndex].balance -= amount;
    customers[receiverIndex].balance += amount;

    customers[senderIndex].transactions.push_back(
    {"Transfer Sent", amount, "Money Transferred"}
);

customers[receiverIndex].transactions.push_back(
    {"Transfer Received", amount, "Money Received"}
);

    savedata() ;

    cout << "\n========== TRANSFER SUCCESSFUL ==========\n";

    cout << "Sender Account: "
         << senderAcc << endl;

    cout << "Receiver Account: "
         << receiverAcc << endl;

    cout << "Transferred Amount: Rs. "
         << amount << endl;

    cout << "Sender Remaining Balance: Rs. "
         << customers[senderIndex].balance << endl;

    cout << "Receiver Updated Balance: Rs. "
         << customers[receiverIndex].balance << endl;
}



void transactionhistory(){
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].accountnumber == accNo)
        {
            found = true;

            cout << "\n========== TRANSACTION HISTORY ==========\n";
            cout << "Account Number: " << accNo << endl;

            if (customers[i].transactions.empty())
            {
                cout << "\nNo Transactions Found!\n";
                return;
            }

            for (int j = 0; j < customers[i].transactions.size(); j++)
            {
                cout << "\nTransaction " << j + 1 << endl;
                cout << "Type: " << customers[i].transactions[j].type << endl;
                cout << "Amount: Rs. " << customers[i].transactions[j].amount << endl;
                cout << "Details: " << customers[i].transactions[j].details << endl;
                cout << "-----------------------------------\n";
                cout<<endl;
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void savedata()
{
    ofstream file("bankdata.txt");

    for (int i = 0; i < customers.size(); i++)
    {
        file << "C|" << customers[i].customerId << "|"
             << customers[i].name << "|"
             << customers[i].phone << "|"
             << customers[i].accountnumber << "|"
             << customers[i].balance << "|"
             << customers[i].transactions.size() << endl;

        for (int j = 0; j < customers[i].transactions.size(); j++)
        {
            file << "T|"
                 << customers[i].transactions[j].type << "|"
                 << customers[i].transactions[j].amount << "|"
                 << customers[i].transactions[j].details << endl;
        }
    }

    file.close();
}
void loaddata()
{
    ifstream file("bankdata.txt");

    if (!file){
        cout<<"error: could not open bankdata.txt"<<endl;
        return;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string marker, name, phone, account;
        string balance, id, count;

        if (!getline(ss, marker, '|')) continue;

        if (marker != "C")
            continue;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, phone, '|');
        getline(ss, account, '|');
        getline(ss, balance, '|');
        getline(ss, count, '|');

        Customer c;
        c.customerId = stoi(id);
        c.name = name;
        c.phone = phone;
        c.accountnumber = std::stoi(account);
        c.balance = stod(balance);
        int transactionCount = stoi(count);
        for (int j = 0; j < transactionCount; j++)
        {
            if (!getline(file, line))
                break;
            stringstream ts(line);
            string marker, type, amount, details;
            getline(ts, marker, '|');
            getline(ts, type, '|');
            getline(ts, amount, '|');
            getline(ts, details);
            if (marker == "T")
            {
                transaction t;
                t.type = type;
                t.amount = stod(amount);
                t.details = details;

                c.transactions.push_back(t);
            }
        }
        customers.push_back(c);
        if (c.customerId >= nextcustomerId)
            nextcustomerId = c.customerId + 1;
        int accNo = c.accountnumber ;
        if (accNo >= nextaccountnumber)
            nextaccountnumber = accNo + 1;
    }

    file.close();
}