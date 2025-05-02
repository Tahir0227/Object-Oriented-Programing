#include<iostream>
#include<cstring>
using namespace std;

class Book {
    private:
        char *title;
        char *auther_name;
        int page_count;
        bool format_type;
        char **chapter_pages;
        int chapter_count;

    public:
        void get_info() {
            cout << endl << endl;
            cout << "Book details\n";
            cout << "Title        :" << this->title << endl;
            cout << "Auther Name  :" << this->auther_name << endl;
            cout << "Format type  :" << this->format_type << endl;
            cout << "Page count   :" << this->page_count << endl;
            cout << "Chapter count:" << this->chapter_count << endl;
            cout << "Chapter pages:\n";
            for (int i = 0; i < 6; i++) {
                if (chapter_pages[i] != 0) {
                    cout << i + 1 << "=" << chapter_pages[i] << endl;
                }
            }
        }

        void change_chap_page_count(const char* new_chapter_pages[]) {
            for (int i = 0; i < 6; i++) {
                if (chapter_pages[i] != 0) {
                    delete chapter_pages[i];
                }
                chapter_pages[i] = new char[strlen(new_chapter_pages[i]) + 1];
                strcpy(chapter_pages[i], new_chapter_pages[i]);
            }
        }

        Book() {
            title = new char[1];
            auther_name = new char[1];
            page_count = 0;
            format_type = false;
            chapter_count = 0;
            chapter_pages = new char*[6];
            for (int i = 0; i < 6; i++) {
                chapter_pages[i] = 0;
            }
        }

        Book(const char* title, const char* auther_name, int page_count, bool format_type,
             int chapter_count, const char* chapter_pages[]) {
            this->title = new char[strlen(title)];
            strcpy(this->title, title);
            
            this->auther_name = new char[strlen(auther_name)];
            strcpy(this->auther_name, auther_name);
            
            this->page_count = page_count;
            this->format_type = format_type;
            this->chapter_count = chapter_count;
            this->chapter_pages = new char*[chapter_count];
            for (int i = 0; i < chapter_count; i++) {
                this->chapter_pages[i] = new char[strlen(chapter_pages[i]) + 1];
                
                strcpy(this->chapter_pages[i], chapter_pages[i]);
            }
        }

        Book(const Book &obj) {
            title = new char[strlen(obj.title)];
            strcpy(title, obj.title);
            
            auther_name = new char[strlen(obj.auther_name)];
            strcpy(auther_name, obj.auther_name);
            
            page_count = obj.page_count;
            format_type = obj.format_type;
            chapter_count = obj.chapter_count;
            chapter_pages = new char*[chapter_count];
            for (int i = 0; i < chapter_count; i++) {
                chapter_pages[i] = new char[strlen(obj.chapter_pages[i])];
                
                strcpy(chapter_pages[i], obj.chapter_pages[i]);
            }
        }

        ~Book() {
            delete[] title;
            delete[] auther_name;
            for (int i = 0; i < chapter_count; i++) {
                delete[] chapter_pages[i];
            }
            delete chapter_pages;
        }
};

int main() {
    const char* arr1[6] = {"1-50", "51-110", "111-170", "171-250", "251-300", "301-340"};
    
    Book b1("The God of Small Things", "Arundhati Roy", 340, true, 6, arr1);
    b1.get_info();

    Book b2(b1);
    b2.get_info();

    const char* arr2[6] = {"1-60", "61-120", "121-180", "181-260", "261-310", "311-340"};
    b2.change_chap_page_count(arr2);

    b1.get_info();
    b2.get_info();
}

