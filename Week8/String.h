#include "iostream"
#include <cstring>

class String
{
private:
    size_t size;
    char *data;

public:
    String();                          //Част от Г4
    String(const String &);            //Част от Г4
    String &operator=(const String &); //Част от Г4
    String(size_t size);               //Задава начален размер на низа
    String(const char *data);          //Задава начална стойност на низа
    ~String();                         //Част от Г4

    String &concat(const String &);       //Конкатенира два низа (низ1 = "а", низ2 = "b", низ1.concat(низ2) = "ab")
    String *split(const char *delimiter); //Разделя низа по подаден символ или низ
	String generateStr(size_t&, int);
	int findWithIndex(int, const char*);
	friend size_t delimitersCounter(const String&, const char*);
    void reverse();                    //Обръща елементите на низа
    void clear();                      //Изчиства елементите на низа

    friend std::istream& operator>>(std::istream& in, String& other) {
        std::cout<<"Enter string length: ";
        in>>other.size;
        std::cout<<"\nEnter the string: ";
        in.getline(other.data, other.size);
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const String& other) {
		for (size_t i = 0; i < other.size; ++i){
			out << other.data[i];
		}
		return out;
	}
};

//String temp = "a b c"
//std::cout << temp;
//temp.split(" ") -> String[] result = ["a", "b", "c"];
//temp.split(" b ") -> String[] result = ["a", "c"];

String::String()
{
    this->size = 0;
    this->data = nullptr;
}
String::String(const String &other)
{
    this->size = other.size;
    this->data = new char[this->size];
    strcpy(this->data, other.data);
}
String &String::operator=(const String &other)
{
    if (this != &other)
    {
        this->size = other.size;
        delete[] this->data;
        this->data = new char[this->size];
        strcpy(this->data, other.data);
    }
    return *this;
}
String::String(size_t size)
{
    this->size = size;
    this->data = new char[this->size];
}
String::String(const char *data)
{
    this->size = strlen(data);
    this->data = new char[this->size];
    strcpy(this->data, data);
}
String::~String()
{
    delete[] this->data;
}

String &String::concat(const String &other)
{
    char *tmp = new char[this->size];
    strcpy(tmp, this->data);

    int i = strlen(tmp);
    int k = 0;

    this->size += other.size;

    delete[] this->data;
    this->data = new char[this->size];

    strcpy(this->data, tmp);

    for (i; i < this->size; i++)
    {
        this->data[i] = other.data[k];
        k++;
    }

    return *this;
}

// String *String::split(const char *delimiter)
// {
// }
//abcd -> dcba
void String::reverse()
{
    for (int i = 0; i < this->size / 2; i++)
    {
        std::swap(this->data[i], this->data[this->size - i - 1]);
    }
}

void String::clear()
{
}

String* String::split(const char* delimiter) // "c++#is#super"
{
    // "a#b#c" -> ["a", "b", "c"] if delimiter is "#"
	String* result = new String[delimitersCounter(*this, delimiter) + 1];
	
	size_t counter = 0;

	size_t i = 0;
	int currentIndex = this->findWithIndex(i, delimiter);

	while (currentIndex != -1) {
		result[counter++] = generateStr(i, currentIndex);

		i += strlen(delimiter);
		currentIndex = this->findWithIndex(i, delimiter);
	}

	result[counter] = generateStr(i, size);

	return result;
}

String String::generateStr(size_t &i, int endIndex) {
	String result;
	result.size = endIndex - i;
	result.data = new char[endIndex - i + 1];

	size_t counter = 0;
	for (i; i < endIndex; ++i)
	{
		result.data[counter++] = this->data[i];
	}
	result.data[counter] = '\0';

	return result;
}

size_t delimitersCounter(const String& str, const char* delimiter)
{
	size_t count = 0;
	for (size_t i = 0; i < str.size; ++i)
	{
		if (str.data[i] == delimiter[0]) {
			bool contains = true;
			for (size_t j = 1; delimiter[j]; ++j)
			{
				if (str.data[i + j] != delimiter[j]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				++count;
			}
		}
	}

	return count;
}

int String::findWithIndex(int index, const char* subString)
{
	for (size_t i = index; i < size; ++i)
	{
		if (data[i] == subString[0]) {
			bool contains = true;
			for (size_t j = 1; subString[j]; ++j)
			{
				if (data[i + j] != subString[j]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				return i;
			}
		}
	}
	return -1;
}