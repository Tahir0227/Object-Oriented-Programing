#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileEncryptor{
	private:
    	string fileName;
    	int key;

	public:
    	FileEncryptor(string name, int k){
        	fileName = name;
        	key = k;
    	}

    	void encryptAndWrite(string msg){
        	ofstream file(fileName.c_str());
        	if (!file) {
            	cout << "Could not open file to write.\n";
            	return;
        	}
			
			int i;
        	for (i = 0; i < msg.length(); i++){
            	char c = msg[i];
            	if (c>='A' && c<='Z'){
                	c = (c-'A'+key) % 26 + 'A';
            	} 
				else if (c>='a' && c<='z'){
                	c = (c-'a'+key) % 26 + 'a';
            	}
            	msg[i]=c;
        	}

        	file <<msg;
        	file.close();
        	cout <<"Message encrypted and saved to file.\n";
    	}

    	void readAndDecrypt(){
        	ifstream file(fileName.c_str());
        	if (!file){
            	cout << "Could not open file to read.\n";
            	return;
        	}

        	string text;
        	getline(file, text);
        	file.close();

			int i;
        	for (i = 0; i < text.length(); i++){
            	char c = text[i];
            	if (c>='A' && c<='Z'){
                	c = (c-'A'-key+26) % 26 + 'A';
            	} else if (c>='a' && c<='z') {
                	c = (c-'a'-key+26) % 26 + 'a';
            	}
            	text[i]=c;
        	}

        	cout <<"Decrypted message: " <<text << endl;
    	}
};

int main() {
    FileEncryptor f1("data.txt",3);

    int choice;
    string input;

    cout << "1. Encrypt and Save\n2. Read and Decrypt\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice==1){
        cout << "Enter the message: ";
        getline(cin, input);
        f1.encryptAndWrite(input);
    } 
    
	else if (choice==2)
        f1.readAndDecrypt();
    
	else
        cout <<"Invalid option.\n";

    return 0;
}

