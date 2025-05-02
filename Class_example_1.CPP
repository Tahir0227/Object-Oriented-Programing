#include<iostream>
using namespace std;

class Bank{
	
	private:
		string accountHolder;
		int accountNumber;
		string accountType;
		double balance;
		
	public:
		
		void getAccountDetails(){
			cout<<"Account Details" <<endl;
			cout<<"Holder        :" <<accountHolder <<endl;
			cout<<"Account Number:" <<accountNumber <<endl;
			cout<<"Type          :" <<accountType <<endl;
			cout<<"Balance       :" <<balance <<endl <<endl;
			
		}
		
		void setAccountType(string newType){
			this->accountType = newType;
			cout<<"Updated Account Type to " <<accountType <<endl <<endl;
		}
		
		int deposit(double amount){
			this->balance = balance + amount;
			cout<<"Depositing :" <<amount <<endl;
			cout<<"New balence:" <<balance <<endl <<endl;
		}
		
		int withdraw(double amount){
			this->balance = balance - amount;
			cout<<"Withdrawing :" <<amount <<endl;
			cout<<"New balence :" <<balance <<endl <<endl;
		}
		
		Bank(){
			accountHolder="none";
			accountNumber=0;
			accountType="none";
			balance=0;
		}
		
		Bank(string AH, int AN, string AT, double B){
			accountHolder = AH;
			accountNumber = AN;
			accountType = AT;
			balance = B;
		}
};

int main(){
	
	Bank holder1("Tahir handimalik",1234567,"Savings",3000);
	holder1.getAccountDetails();
	holder1.deposit(3000);
	holder1.withdraw(1500);
	holder1.setAccountType("Current");
	cout<<"Final ";
	holder1.getAccountDetails();
	
	Bank holder2("Amar patil",98745561,"Current",8000);
	holder2.getAccountDetails();
	holder2.deposit(5000);
	holder2.withdraw(3500);
	holder2.setAccountType("Savings");
	cout<<"Final ";
	holder2.getAccountDetails();
}
