#include <iostream>
#include <cstring>

class Book{
private:
	char *author, *title;
	size_t pages, year;

public:
    //The big three = default constructor, copy constructor, operator=, destructor
    Book() {
        this->author = nullptr;
        this->title = nullptr;
        this->pages = 0;
        this->year = 0;
    }

    Book(const Book& other) {
        set_author(other.author);
        set_title(other.title);
        set_pages(other.pages);
        set_year(other.year);
    } 

    Book& operator=(const Book& other) {
        // 1. delete
        // 2. copy
        if (this != &other) {
            delete[] this->author;
            delete[] this->title;
            set_author(other.author);
            set_title(other.title);
            set_pages(other.pages);
            set_year(other.year);
        }

        return *this;
    }

    ~Book() {
        delete[] this->author;
        delete[] this->title;
    }

    Book(const char* author, const char* title, size_t pages, size_t year) {
        set_author(author);
        set_title(title);
        set_pages(pages);
        set_year(year);
    }

    
public:
//Setters / set methods
    void set_author(const char* author){
        this->author = new char[strlen(author) + 1];
        for(size_t i = 0; author[i]; ++i) {
            this->author[i] = author[i];
        } 
        this->author[strlen(author)] = '\0';
    } 

    void set_title(const char* title){
        this->title = new char[strlen(title) + 1];
        for(size_t i = 0; title[i]; ++i) {
            this->title[i] = title[i];
        } 
        this->title[strlen(title)] = '\0';
    } 

    void set_pages(int pages) {
        this->pages = pages;
    }

    void set_year(int year) {
        this->year = year;
    }

//Getters / get methods
    int getPages() const {
        return pages;
    }
    
    int getYear() const {
        return year;
    }

    char* getAuthor() const {
        return author;
    }

    char* getTitle() const {
        return title;
    }

    void print() const {
        std::cout<<"fhasdklf";
    }
};

int main() {
    Book a("dasj", "dfa", 0, 0);
    Book b = a;
    Book c;
    std::cout<<c.getYear()<<std::endl;
    c = a;

    a = a;

    return 0;
}
