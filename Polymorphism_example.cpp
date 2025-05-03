#include<iostream>
using namespace std;

class Bank{
		
	public:
		
		void deposit(int amt){
			cout << "Depositing Rs." <<amt <<" in cash" <<endl; 
		}
		
		void deposit(double amt){
			cout << "Depositing Rs." <<amt <<" in digital payment" <<endl;
		}
		
		void deposit(string upiID, int amt){
			cout << "Depositing Rs." <<amt <<" using UPI (" <<upiID << ")"<<endl <<endl;
		}
};

class Account{
	private:
		int account_no;
		int balance;
		
	public:
		Account(int ac, int bal){
			account_no = ac;
			balance = bal;
		}
		
		void show_detail(){
			cout << "Account No :" <<account_no <<endl;
			cout << "Balance    :" <<balance <<endl <<endl;
		}
		
		void operator +(Account& obj){
			int transfer_amt = 2000;
			cout <<"Transferring " <<transfer_amt <<" from account " <<account_no <<" to account" <<obj.account_no <<endl;
			balance -=  transfer_amt;
			obj.balance += transfer_amt;
		}
		
		void operator -(int withdraw_amt){
			
			cout <<"Withdrawing " << withdraw_amt <<" from Account " <<account_no <<endl;
			balance = balance - withdraw_amt;
		}
};

int main(){
	
	Bank b1;
	b1.deposit(2000);
	b1.deposit(3400.50);
	b1.deposit("tahir0@icici", 4000);
	
	Account a1(001,5000) , a2(002,3000);
	a1.show_detail();
	a2.show_detail();
	
	a1 + a2;
	a1.show_detail();
	a2.show_detail();
	
	a1 - 3000;
	a1.show_detail();
	
	return 0;
}
