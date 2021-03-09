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

// Да се напише клас Library, който да има масив от книги и адрес

// Класът да има

template <typename T>
void swap(T& first, T& second);

class Library {
private:
	Book* books;
	char* address;
    size_t numberOfBooks;

public:
// Голяма четворка
    Library() {
		this->books = nullptr;
		this->address = nullptr;
	}

    Library(const Library& library) {
        delete[] this->books;
		delete[] this->address;

		this->books = new Book[library.numberOfBooks];
		for (int i = 0; i < library.numberOfBooks; i++) {
			this->books[i] = library.books[i];
		}

		this->address = new char[strlen(library.address) + 1];
		for (int i = 0; library.address[i] != '\0'; i++) {
			this->address[i] = library.address[i];
		}
		this->address[strlen(library.address)] = '\0';
    }

    Library& operator=(const Library& library) {
        if (&library != this) {
			delete[] this->books;
			delete[] this->address;

			this->books = new Book[library.numberOfBooks];
			for (int i = 0; i < library.numberOfBooks; i++) {
				this->books[i] = library.books[i];
			}

			this->address = new char[strlen(library.address) + 1];
			for (int i = 0; library.address[i] != '\0'; i++) {
				this->address[i] = library.address[i];
			}
			this->address[strlen(library.address)] = '\0';
		}

		return *this;
	}

    ~Library() {
		delete[] books;
        delete[] address;
	}

// Гетъри
    Book* getBooks() const{
		return this->books;
	}

    char* getAddress() const{
		return this->address;
	}

// Метод sort_by_bookSize()
    void sort_by_BookSize()
    {
		for (int i = 0; i < numberOfBooks - 1; ++i)
        {
			for (int j = 0; j < numberOfBooks - i - 1; ++j)
            {
                if(books[j].getPages() > books[j+1].getPages())
                {
                    swap(books[j], books[j+1]);
                }
            }
		}
	}

// Метод sort_alphabetical_order()
// Метод за принтиране на масива от книги
};


template <typename T>
void swap(T& first, T& second)
{
    T helper = first;
    first = second;
    second = helper;
}


int main() {
    std::cout << "Test " << std::endl;

//    l1 = l1
//    ^     ^
//   this  library

    return 0;
}
