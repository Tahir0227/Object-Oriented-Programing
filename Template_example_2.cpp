#include<iostream>
using namespace std;

template <typename T>

class Calculator{
	private:
		T n1;
		T n2;
		
	public:
		Calculator(T a , T b){
			n1=a;
			n2=b;
		}
		
		T addition(){
			return n1 + n2;
		}
		
		T subtraction(){
			return n1 - n2;
		}
		
		T multiplication(){
			return n1 * n2;
		}
		
		T division(){
			return n1 / n2;
		}
		
};

int main(){
	Calculator<int> c1(8,19);
	cout <<"Integer operation : 8 + 19 =" <<c1.addition() <<endl;
	
	
	Calculator<int> c2(10.19 , 6.78);
	cout <<"Float operation : 10.19 * 6.78 =" <<c2.multiplication() <<endl;	
	
	return 0;
}
