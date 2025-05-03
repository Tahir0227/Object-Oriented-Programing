#include<iostream>
using namespace std;
template <typename T>

T findMax(T a, T b){
	if(a>b)
		return a;
	else
		return b;
}

int main(){
	int x=5,y=10;
    double p=3.14,q=2.71;

    cout <<"Max of " <<x <<" and " <<y << " is: " <<findMax(x, y) <<endl;
    cout <<"Max of " <<p <<" and " <<q << " is: " <<findMax(p, q) <<endl;

    return 0;
}
