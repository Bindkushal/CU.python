#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;

public:
    // Virtual destructor for proper cleanup of derived class objects
    virtual ~Publication() = default;

    // Virtual functions to be overridden by derived classes
    virtual void getdata() {
        std::cout << "Enter title: ";
        std::cin.ignore(); // To ignore any leftover newline character in the buffer
        std::getline(std::cin, title);
        std::cout << "Enter price: ";
        std::cin >> price;
    }

    virtual void putdata() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getdata() override {
        Publication::getdata(); // Call base class getdata
        std::cout << "Enter page count: ";
        std::cin >> pageCount;
    }

    void putdata() const override {
        Publication::putdata(); // Call base class putdata
        std::cout << "Page Count: " << pageCount << std::endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    void getdata() override {
        Publication::getdata(); // Call base class getdata
        std::cout << "Enter playing time (in minutes): ";
        std::cin >> playingTime;
    }

    void putdata() const override {
        Publication::putdata(); // Call base class putdata
        std::cout << "Playing Time: " << playingTime << " minutes" << std::endl;
    }
};

int main() {
    Publication* pubList[2]; // Array of pointers to Publication
    pubList[0] = new Book(); // Create a Book object
    pubList[1] = new Tape(); // Create a Tape object

    std::cout << "Enter details for book:" << std::endl;
    pubList[0]->getdata();
    std::cout << std::endl;

    std::cout << "Enter details for tape:" << std::endl;
    pubList[1]->getdata();
    std::cout << std::endl;

    std::cout << "Details of book:" << std::endl;
    pubList[0]->putdata();
    std::cout << std::endl;

    std::cout << "Details of tape:" << std::endl;
    pubList[1]->putdata();
    std::cout << std::endl;

    // Clean up dynamically allocated memory
    delete pubList[0];
    delete pubList[1];

    return 0;
} 
