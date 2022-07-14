#include<iostream>
#include<vector>
#include<time.h>
#include<conio.h>
#include<stdbool.h>
#include<windows.h>
#include<fstream>
using namespace std;

// Admin key 
const int admin_key = 45987;

// Helper
void space_provide();
void delay(int milli_seconds);



class Account{
    int acno;
    string holder_name;
    char type;
    int bal;
    int pin;
    public:

    void acccount_create(){
        cout<<endl<<endl<<endl<<endl;
        space_provide();
        cout<<"ENTER THE ACCOUNT NUMBER = ";
        cin>>acno;
        space_provide();
        cout<<"ENTER ACCOUNT HOLDER NAME = ";
        cin>>holder_name;
        space_provide();
        cout<<"ENTER TYPE OF ACCOUNT CURRENT(C) OR SAVINGS(S) = ";
        while(true){
            cin>>type;
            if(type=='c' || type =='C' || type=='s' || type=='S'){
                break;
            }
            else
            {
                space_provide();
                cout<<"PLEASE ENTER CORRECT TYPE OF ACCOUNT = ";
            }
        }
        type=toupper(type);
        space_provide();
        cout<<"ENTER ACCOUNT BALANCE (500>= FOR  SAVING AND 1000>= FOR CURRENT) = ";
        switch (type)
        {
            case 'S':
                while (true)
                {
                    cin>>bal;
                    if(bal>=500){
                        break;
                    }
                    else
                    {
                        space_provide();
                        cout<<"PLEASE ENTER BALANCE >=500 FOR SAVING ACCOUNT = ";
                    }
                }
                break;
        
            case 'C':
                while (true)
                {
                    cin>>bal;
                    if(bal>=1000){
                        break;
                    }
                    else
                    {
                        space_provide();
                        cout<<"PLEASE ENTER BALANCE >=1000 FOR CURRENT ACCOUNT = ";
                    }
                }
                break;
            
            default:
                break;
        }
        space_provide();
        cout<<"ENTER A FOUR DIGIT PIN = ";
        cin>>pin;
    }

    void print(){
        cout<<"ACCOUNT NUMBER = "<<acno<<endl;
        cout<<"ACCOUNT HOLDER NAME = "<<holder_name<<endl;
        cout<<"TYPE OF ACCOUNT = "<<type<<endl;
        cout<<"BALANCE = "<<bal<<endl;
    }

    bool anoComp(int num){
        if(num==acno){
            return true;
        }
        return false;
    }

    bool pinComp(int pinn){
        if(pinn==pin){
            return true;
        }
        return false;
    }

    void balChange(int n){
        int money;
        switch (n)
        {
        case 1:
            cout<<"ENTER THE AMOUNT TO DEPOSIT = ";
            cin>>money;
            bal+=money;
            break;
        case 2:
            cout<<"ENTER THE AMOUNT TO WITHDRAW = ";
            cin>>money;
            bal-=money;
        default:
            break;
        }
    }

    void modify(){
        cout<<"ENTER ACCOUNT HOLDER NAME = ";
        cin>>holder_name;
        cout<<"ENTER TYPE OF ACCOUNT CURRENT(C) OR SAVINGS(S) = ";
        while(true){
            cin>>type;
            if(type=='c' || type =='C' || type=='s' || type=='S'){
                break;
            }
            else{cout<<"PLEASE ENTER CORRECT TYPE OF ACCOUNT";}
        }
        type=toupper(type);
        cout<<"ENTER A FOUR DIGIT PIN";
        cin>>pin;
    }
};

int admin();
void start();
void choice(vector<Account>&acc);
bool welcome_screen();
int exitControl();
void write_account(vector<Account>&acc);
void deposit_withdraw(int num, int n, vector<Account>&acc);
bool pinVerify(int num, vector<Account>&acc);
void display_sp(int num, vector<Account>&acc);
void modify_account(int num, vector<Account>&acc);
void delete_account(int num, vector<Account>&acc);

int main(){ 
    vector<Account>acc;
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    system("color b0");
    int from_admin;
    // calling the function for all admin related stuff
    from_admin = admin();
    // If the admin key is entered wrong 4 times then program will close
    if (from_admin==-69)
    {
        return 0;
    }
    system("cls");
    system("color 18");
    fflush(stdin);
    while(true){
        if(welcome_screen()){
            int exit = exitControl();
            if(exit==-23451){
                continue;
            }
            break;
        }
        choice(acc);
    }
    return 0;
}



// Helper
void space_provide(){
    for (int i = 0; i < 64; i++)
    {
        cout<<" ";
    }
}

void delay(int milli_seconds){  
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

bool welcome_screen()
{
    cout<<"\n\n\n\n\n\n\n\n\n";
    space_provide();
    cout<<"============================"<<endl;
    space_provide();
	cout<<"| - - - - - NAYA - - - - - |"<<endl;
    space_provide();
	cout<<"| - - - - - ATM - - - - - -|"<<endl;
    space_provide();
	cout<<"|- - MANAGEMENT SYSTEM - - |"<<endl;
    space_provide();
	cout<<"============================"<<endl;
	char a = 'A';
    space_provide();
    cout<<"PRESS ENTER TO GO ATM"<<endl;
    space_provide();
    cout<<"PRESS Q TO CLOSE THE ATM (ONLY FOR ADIMN)";
    fflush(stdin);
    while (a!='\n')
    {
        if(a=='Q' || a=='q'){
            return true;
        }
        scanf("%c", &a);
    }
    return false;
}

void choice(vector<Account>& acc){
    system("cls");
    printf("\n\n\n\n\n\n");
    space_provide();
    printf("    %c%c%c%c%c%c Please enter your choice.  %c%c%c%c%c%c\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254);
    int choose;
    int num;
    do
	{
		system("cls");
		cout<<"\n\n";
        cout<<"       ==========================================";
		cout<<"\n\n";
        cout<<"                  APNA ATM NAYA ATM";
        cout<<"\n\n";
        cout<<"       ==========================================";
		cout<<"\n\n\n\n";
        cout<<"     01. --> NEW ACCOUNT                    02. --> DEPOSIT AMOUNT";
		cout<<"\n\n";
        cout<<"     03. --> WITHDRAW AMOUNT                04. --> BALANCE ENQUIRY";
		cout<<"\n\n";
        cout<<"     05. --> CLOSE AN ACCOUNT               06. --> MODIFY AN ACCOUNT";
		cout<<"\n\n";
        cout<<"     07. --> EXIT";
		cout<<"\n\n";
        cout<<"------------------------------------------------------------------------";
		cout<<"\n\n";
        cout<<"     ---> SELECT YOUR OPTION(1-8) :- ";
		cin>>choose;
		system("cls");
		switch(choose)
		{
		case 1:
			write_account(acc);
			break;
		case 2:
            cout<<"\n\n\n\n\n\n\n\n\n\t          ==========================================";
            cout<<"\n\n\t                  ENTER THE ACCOUNT NUMBER ";
            cout<<"\n\n\t          ==========================================  :- ";
            cin>>num;
			deposit_withdraw(num, 1, acc);
			break;
		case 3:
            cout<<"\n\n\n\n\n\n\n\n\n\t          ==========================================";
            cout<<"\n\n\t                  ENTER THE ACCOUNT NUMBER ";
            cout<<"\n\n\t          ==========================================  :- ";
            cin>>num;
			deposit_withdraw(num, 2, acc);
			break;
		case 4:
            cout<<"\n\n\n\n\n\n\n\n\n\t          ==========================================";
            cout<<"\n\n\t                  ENTER THE ACCOUNT NUMBER ";
            cout<<"\n\n\t          ==========================================  :- ";
            cin>>num;
			display_sp(num, acc);
			break;
		case 5:
            cout<<"\n\n\n\n\n\n\n\n\n\t          ==========================================";
            cout<<"\n\n\t                  ENTER THE ACCOUNT NUMBER ";
            cout<<"\n\n\t          ==========================================  :- ";
            cin>>num;
			delete_account(num, acc);
			break;
		 case 6:
            cout<<"\n\n\n\n\n\n\n\n\n\t          ==========================================";
            cout<<"\n\n\t                  ENTER THE ACCOUNT NUMBER ";
            cout<<"\n\n\t          ==========================================  :- ";
            cin>>num;
			modify_account(num, acc);
			break;
		 case 7:
			cout<<"\n\n\tTHANK YOU FOR USING NAYA ATM";
			break;
		 default :
            continue;
		}
        fflush(stdin);
	}while(choose!=7);
    // Redirecting screen
        cout<<endl;
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
        system("color a0");
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        space_provide();
        cout<<"REDIRECTING";
        for (int i = 0; i < 4; i++)
        {
            printf(".");
            delay(300);
        }
        system("color 18");
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
}

void write_account(vector<Account>&acc){
    fflush(stdin);
    Account a1;
    a1.acccount_create();
    acc.push_back(a1);
    ofstream file_new_acc;
    file_new_acc.open("account.txt", ios::trunc);
    for (auto it = acc.begin(); it != acc.end(); it++){

        file_new_acc.write((char*)&*it, sizeof(a1));
        file_new_acc<<endl;

    }
    file_new_acc.close();
    cout<<"ACCOUNT ADDED"<<endl;
    cout<<"PRESS ENTER TO CONTINUE";
    fflush(stdin);
    char a = 'A';
    while (a!='\n')
    {
      scanf("%c", &a);
    }
}

void deposit_withdraw(int num, int n, vector<Account>&acc){

    auto it = acc.begin();
    for ( it = acc.begin(); it != acc.end(); it++){

        if(it->anoComp(num)){
            break;
        }
    }
    if(pinVerify(num, acc)){
        it->balChange(n);
        cout<<"TRANSACTION COMPLETE"<<endl;
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
    else
    {
        cout<<"WRONG PIN! PLEASE TRY AGAIN.";
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
    Account a1;
    ofstream file_new_acc;
    file_new_acc.open("account.txt", ios::trunc);
    for ( it = acc.begin(); it != acc.end(); it++){

        file_new_acc.write((char*)&*it, sizeof(a1));
        file_new_acc<<endl;

    }
    file_new_acc.close();
}

void display_sp(int num, vector<Account>&acc){

    auto it = acc.begin();
    for ( it = acc.begin(); it != acc.end(); it++){

        if(it->anoComp(num)){
            break;
        }
    }
    if(pinVerify(num, acc)){
        it->print();
        cout<<endl;
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
    else
    {
        cout<<"WRONG PIN! PLEASE TRY AGAIN.";
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
}

void modify_account(int num, vector<Account>&acc){
    auto it = acc.begin();
    for ( it = acc.begin(); it != acc.end(); it++){

        if(it->anoComp(num)){
            break;
        }
    }
    if(pinVerify(num, acc)){
        it->modify();
        cout<<"MODIFICATION COMPLETE"<<endl;
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
    else
    {
        cout<<"WRONG PIN! PLEASE TRY AGAIN.";
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
    Account a1;
    ofstream file_new_acc;
    file_new_acc.open("account.txt", ios::trunc);
    for ( it = acc.begin(); it != acc.end(); it++){

        file_new_acc.write((char*)&*it, sizeof(a1));
        file_new_acc<<endl;

    }
    file_new_acc.close();
}

void delete_account(int num, vector<Account>&acc){
    int index = -1;
    auto it = acc.begin();
    for ( it = acc.begin(); it != acc.end(); it++){
        index++;
        if(it->anoComp(num)){
            break;
        }
    }
    if(pinVerify(num, acc)){
        acc.erase(acc.begin()+index);
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
    else
    {
        cout<<"WRONG PIN! PLEASE TRY AGAIN.";
        cout<<"PRESS ENTER TO CONTINUE";
        fflush(stdin);
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
    }
    Account a1;
    ofstream file_new_acc;
    file_new_acc.open("account.txt", ios::trunc);
    for ( it = acc.begin(); it != acc.end(); it++){

        file_new_acc.write((char*)&*it, sizeof(a1));
        file_new_acc<<endl;

    }
    file_new_acc.close();
}

bool pinVerify(int num, vector<Account>&acc){
    int pin;
    bool fax=false;
    for (auto it = acc.begin(); it != acc.end(); it++){

        if(it->anoComp(num)){
            cout<<"ENTER PIN = ";
            cin>>pin;
            if(it->pinComp(pin)){
                fax=true;
                break;
            }
        }
    }
    return fax;
}

int exitControl(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    int key_entered;
    char a ='A';
    system("color 40");
    space_provide();
    printf("ENTER ADMIN KEY TO CLOSE ATM: ");
    cin>>key_entered;
    fflush(stdin);
    if(key_entered != admin_key)
    {  
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        space_provide();
        cout<<"KEY IS WRONG. YOU ARE NOT AUTHHORIZED TO CLOSE THE ATM."<<endl;
        space_provide();
        cout<<"PRESS ENTER TO CONTINUE";
        char a = 'A';
        while (a!='\n')
        {
            scanf("%c", &a);
        }
        // Redirecting screen
        system("color a0");
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        space_provide();
        cout<<"REDIRECTING";
        for (int i = 0; i < 4; i++)
        {
            printf(".");
            delay(300);
        }
        system("color 18");
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        return -23451;
    }
    else
    {
        return -7778;
    }
}

// To start the program and display instruction for admin.
int admin(){
    char a = 'A';
    space_provide();
    cout<<"Press Enter to start to the program";
    while (a!='\n')
    {
      scanf("%c", &a);
    }
    system("cls");
    printf("\n\n\n\n\n\n");
    space_provide();
    printf("    %c%c%c%c%c%c ADMIN  %c%c%c%c%c%c\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254);
    cout<<endl;
    space_provide();
    cout<<"Press Enter to continue";
    a = 'A';
    while (a!='\n')
    {
      scanf("%c", &a);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    int key_entered;
    space_provide();
    cout<<"Enter the admin key: ";
    scanf("%d", &key_entered);
    int count=0;
    while (key_entered != admin_key)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        if (count==3)
        {
            space_provide();
            cout<<"Entering the key wrong again will cause system to shut.\n";
        }
        if (count==4)
        {
            return -69;
        }    
        space_provide();
        cout<<"Wrong key! Please enter again: ";
        cin>>key_entered;
        count++;
    }
    return 1;
}