#include<iostream>
using namespace std;

class Person{
	protected:
		string name;
		int age;
	
	public:
		Person(string n, int a) : name(n), age(a) {}
		
		virtual void display_deatails(){
			cout << "Name        :" <<name <<endl;
			cout << "Age         :" <<age <<endl;
		}
		
};

class Student : virtual public Person{
	protected:
		int rollNumber;
		string branch;
		int marks;
	
	public:
		Student(string n, int a, int r, string b, float m) : Person(n, a), rollNumber(r), branch(b), marks(m) {}
		
		int calculateCGPA(){
			return marks / 10;
		}
		
		virtual void display_deatails(){
			Person::display_deatails();
			cout << "Roll number :" <<rollNumber <<endl;
			cout << "Branch      :" <<branch <<endl;
			cout << "Marks       :" <<marks <<endl <<endl;
		}
		friend class Administration;
};

class Faculty : virtual  public Person{
	protected:
		int facultyID;
		string department;
		int salary;
	
	public:
		Faculty(string n, int a, int fID, string d, float s) : Person(n, a), facultyID(fID), department(d), salary(s) {}
		
		virtual void display_deatails(){
			Person::display_deatails();
			cout << "Faculty ID. :" <<facultyID <<endl;
			cout << "Department  :" <<department <<endl;
			cout << "Salary      :" <<salary <<endl <<endl;
		}
		friend class Administration;
};

class TeachingAssistant : public Student,public Faculty{
	public:
		TeachingAssistant(string n, int a, int r, string b, float m, int fID, string d, float s)
		: Person(n, a), Student(n, a, r, b, m), Faculty(n, a, fID, d, s) {}
		
		void display_deatails(){
			Person::display_deatails();
			cout << "Roll Number: " << rollNumber <<endl;
			cout << "Branch     : " << branch <<endl;
			cout << "Faculty ID : " << facultyID <<endl;
			cout << "Department : " << department <<endl;
			cout << "Salary     :" << salary << endl <<endl;
		}
};

class Administration{
	public:
		static void showDetails(const Student &s, const Faculty &f){
        cout << "Administration Friend Function:\n";
        cout << "Student " << s.name << " from " << s.branch << " scored " << s.marks << " marks." <<endl;
        cout << "Faculty " << f.name << " teaches " << f.department <<endl <<endl;
    }
};


int main(){
	
	Student s1("Tahir Handimalik",20,034,"AIML",87);
	cout <<"Student Details:-" <<endl;
	s1.display_deatails();
	
	Faculty f1("Rohan Patil",27,015,"CSE",65000);
	cout <<"Faculty Details:-" <<endl;	
	f1.display_deatails();
	
	TeachingAssistant t1("Uday Patil",32,012,"AIML",90,05,"CSE",45000);
	cout <<"Teaching Assistant Details:-" <<endl;
	t1.display_deatails();
	
	Administration::showDetails(s1, f1);
    return 0;
	
}
