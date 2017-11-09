
Lab 7: Hash Tables (100 pts)

Part 1: Complete the Book Class


Book.h and Book.cpp Files
Copy and paste the below code into a file named Book.h. Make sure this file is inside the same folder as your BST.h file in Eclipse.
Fill in the missing functions, using the concept of operator overloading.


#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <ostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
    unsigned isbn;

public:

/**Constructors*/
    Book();
    Book(string t, string a, double p, unsigned i);


    /**Access Functions*/
    string get_title();
    string get_author();
    unsigned get_isbn();
    double get_price();

    /**Manipulation Procedures*/
    void set_title(string t);
    void set_author(string a);
    void set_isbn(unsigned i);
    void set_price(double p);


/**Additional Functions*/

    friend ostream& operator<<(ostream& os, const Book& book);
    //prints out a book to the designated stream in the following format
    //<title> by <author>
    //$<price>
    //ISBN#: <isbn>
    //note that the << is required to be a friend function, not a member function
    //note2: do not print out the <> as part of the output

    bool operator==(const Book& book);
    //compares two books to determine if they are the same book

    bool operator<(const Book& book);
    //compares two books to determine if one comes before the other
    //alphabetically by title and secondarily by author if the two
    //books contain the same title
    //returns false if the two books are the same

    bool operator>(const Book& book);
    //compares two books to determine if one comes after the other
    //alphabetically by title and secondarily by author if the two
    //books contain the same title
    //returns false if the two books are the same

};


#endif /* BOOK_H_ */


Additionally, copy and paste the following code into a file named Book.cpp.
Please do not alter this file in any way or you may not receive credit for this Lab. You must only add to it.
You are required to implement the <, > and << functions.
For more information about operator overloading for the << function, see this article

#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book():title(""), author(""), price(0.0), isbn(0){};

Book::Book(string t, string a, double p, unsigned i) {
    title = t;
    author = a;
    price = p;
    isbn = i;
}

/**Access Functions*/

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

unsigned Book::get_isbn() {
    return isbn;
}

double Book::get_price() {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/


bool Book::operator==(const Book& book) {
    return (title == book.title && author==book.author);
}
//To-do: Add <, > and << here

Catalogue.txt Text File
In Eclipse, right click the name of your project
Go to File-> New -> File and name your file catalogue.txt
Copy and paste the below contents into your text file
This will be the file you will use to populate your hash table
The Time in Between
Maria Duenas
9.86
4345344

Bleak House
Charles Dickens
8.99
3567897

Rebecca
Daphe Dumaurier
5.50
3242382

A Room with a View
E.M. Forster
7.50
1177889

Outlander
Diana Galbadon
19.95
5466565

Jane Eyre
Charlotte Bronte
7.90
2345674

The Hunger Games
Suzanne Collins
6.90
4232322

The Woman in White
Wilkie Collins
10.75
3256789

A Face like Glass
Frances Hardinge
15.95
4455443

Lady Audley's Secret
Mary Elizabeth Braddon
5.50
1212134

Agatha Christie
Murder on the Orient Express
2.99
9837583

Middlemarch
George Elliot
12.50
1256743

Our Souls at Night
Kent Haruf
11.99
7847489

Fangirl
Rainbow Rowell
10.79
2413725

Ramona Blue
Julie Murphy
9.99
9328311



Part 2: Write Your HashTable.cpp and HashTest.cpp Files

Hash Table Header File
Copy and paste the following code into a header file named HashTable.h
Please do not alter this file in any way or you may not receive credit for this lab
For this lab, you will implement each of the hash table functions whose prototypes are in HashTable.h.
Write these functions in a file named HashTable.cpp.
Please test each hash table function as you write it in a file named HashTest.cpp (which should include your main function).
Additionally, you will need to include your templated, doubly-linked List.h and the files Book.h and Book.cpp in the same project as your Hash Table.
To keep things simple, the size of the table is defined to be only 10 for this assignment. According to the rule of thumb defined in class, the size should be changed for your project to be roughly 2-3 times the number of projected entries to the table.
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include "List.h"
#include "Book.h"
using namespace std;

class HashTable {
public:
    /**Constructors*/

    HashTable(){}
    //constructor

    ~HashTable(){}
    //destructor


    /**Access Functions*/

    int hash(string key) const;
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    int countBucket(int index) const;
    //counts the number of Books at this index
    //returns the count
    //pre: 0<= index < SIZE

    int search(Book b) const;
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(Book b);
    //inserts a new book into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(Book b);
    //removes b from the table
    //calls the hash function on the key to determine
    //the correct bucket
    //pre: b is in the table

    /**Additional Functions*/

    void printBucket(ostream& out, int index) const;
    //Prints all the books at index
    //pre: 0<= index < SIZE
    //Should print according to the following formula:
    //Prints each book at that index in the format:
    //<title> by <author>
    //$<X.XX>
    //ISBN#: <isbn>
    //followed by a blank line

    void printTable(ostream& out) const;
    //Prints the first book at each index
    //along with a count of the total books
    //at each index by calling count_bucket
    //as a helper function
    //Prints in the format:
    //Books in the Catalogue:
    //<new line>
    //Group <bucket>
    //<title> by <author>
    //$<X.XX>
    //ISBN: <isbn>
    //+<number of elements at this index> -1 more similar book(s)
    //<new line><new line><new line>

private:
    static const int SIZE = 10;
    List<Book> Table[SIZE];
};

#endif /* HASHTABLE_H_ */




Hash Table Constructor and Destructor

The List constructor is already called inside of the HashTable.h, at the following line:
 List<Book> Table;
The List destructor will automatically be called once Table goes out of scope.

Calling the Hash Function

For the purposes of this assignment, we will be using the algorithm defined in class which sums the ASCII values of all the characters in the string key and scales the result to indices of the table.
You are welcome to use this or an alternate hash algorithm for your course project. However, please use the provided hash algorithm for this lab
The key that you should pass to the hash function is the Book's title concatenated with the Book's author. This key should provide enough unique information to differentiate among each book, even if the books have the same title or the same author. If both author and title are the same as another book's title and author, we can assume the book would be a duplicate entry in the table.


Adding Values to the Hash Table

The next step in the process is to be able to add a value to the hash table.
Since we are using the separate chaining approach to collisions, we are using an array of Lists to represent our table.
Each time we insert a new book into the table, we need to complete these steps:
Call the hash function to determine at which index or bucket to place the Book inside the table
Insert the Book at this index of the Table array.
Note that you need to call the correct function from the List class to insert this book onto the end of the chain of books.
Each time you insert a new book, it should be added onto the end of the chain. There is no additional sorting required (or needed).


Test Values for insert to be used in HashTest.cpp

You can test your insertData function by making the following function calls inside main of your HashTableTest.cpp:
      HashTable ht;
    Book pp("Pride and Prejudice", "Jane Austen", 1234567, 4.95);
    Book c("Contact", "Carl Sagan", 99993339, 9.95);
    Book hg("The Hunger Games", "Suzanne Collins", 12388888, 13.55);
    Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
    Book mhc("The Man in the High Castle", "Philip K Dick", 95959595, 15.95);
    Book bh("Bleak House", "Charles Dickens", 473890238, 8.00);

    ht.insert(pp);
    ht.insert(c);
    ht.insert(hg);
    ht.insert(mhc);
    ht.insert(bh);


Printing Using printBucket:

To verify your Hash Table functions are working properly, you need to be able to print the values contained in the Table.
Therefore, your next step - after writing insert - should be to write a print function.
There are two print functions you need to write for this lab; each one is used in a different way.
printBucket is used to display all of the values stored at a single bucket (a "row" in the table).
In contrast, printTable will display the first value stored at each index or bucket in the table (the "first column" in the table).
The printBucket function will allow us to dig more deeply into what is contained at a particular bucket.
You can think of printTable as providing a vertical cross section of values in the Table whereas printBucket gives us a horizontal cross section.
For example, a call to printBucket(9); in HashTest.cpp should display the following (assuming you have inserted the values provided above).


The Hunger Games by Suzanne Collins
$13.55
ISBN: 12388888


The Man in the High Castle by Philip K Dick
$15.95
ISBN: 95959595


Printing the Hash Table Using printTable

printTable displays the first value stored at each index in the table.
If you are following along with my example for HashTest.cpp, we want our printTable function to print the following to the console given the values we have already inserted:

Group 1
Bleak House by Charles Dickens
$8.00
ISBN: 473890238

+0 more similar book(s)


Group 3
Pride and Prejudice by Jane Austen
$4.95
ISBN: 1234567

+0 more similar book(s)


Group 5
Contact by Carl Sagan
$9.95
ISBN: 99993339

+0 more similar book(s)


Group 10
The Hunger Games by Suzanne Collins
$13.55
ISBN: 12388888

+1 more similar book(s)



In other words, for each bucket in the table, we are going to output the following to the console:
Group <index> + 1
<title> by <author>
$<X.XX>
ISBN : <isbn>
+<# books at that bucket -1> similar book(s)
__________________________________

Note that if the bucket contains no books, there will be no output for that bucket
Also, please note that there are no <> around the output. The <> are conventionally used to mean fill in the blank. You should get used to this convention as you will likely see it again in computer science.


Counting items at a bucket using the countBucket function

For this function, you will need to count the number of Books at a specific index or bucket.
Note that this function is a helper to printTable, which provides a tally of how many books are stored at each index as part of its output (see above).


Searching the Table

Our search function will search for a particular book to determine at which bucket it is stored in the Table.
Our first step will be to call the hash function to determine which index the book would be hashed to.
Next, you will need to search through the values at this bucket to determine if the book is stored at that bucket.
If you find the book, return the bucket or index.
If the book is not in the table, your function should return -1.
Note that you can use one of your List functions to complete this search. Which one would be more efficient?

Removing a Book from the Table

To remove a book, you will need to complete these steps:
Pass the book's title and author to the hash function to determine at which index this book is located.
Search for the book in the chain at that bucket
Once you have located it, call the appropriate List removal function to remove the book from that bucket .



Part 3: Write Catalogue.cpp (User Interface)

Working with the catalogue.txt file provided above, write a user interface that works like the example below.
This user interface must use a hash table into which you will insert the books from catalogue.txt to pre-populate the table.
Catalogue.cpp must contain a main function that offers a list of options to the user.
Option 1: Browse catalogue calls the printTable function to display a vertical cross section of records in the table
Option 2: Explore a book group (1-10) calls printBucket to display the records stored at a particular bucket. Note that the user will enter options 1-10, but the buckets (array indices) of your hash table are 0 - 9 so you will need to adjust the input by 1.
Option 3: Insert a new book calls the insert function
Option 4: Remove a book calls the remove function
Option 5: Search for a book calls the search function
Option 6: Exit, exits the program with a message "Happy Reading!"
After the user makes a selection, the menu should loop around again to allow the user to continue working with the hash table of books.
Please see the example output below for more information.


Your Output Must Work Identically to the Following:

Welcome to the Best Reads App!

What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 1
Books in the Catalogue:

Group 1
Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

+1 more similar book(s)


Group 3
Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

+0 more similar book(s)


Group 4
The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

+3 more similar book(s)


Group 5
Middlemarch by George Elliot
$12.50
ISBN#: 1256743

+0 more similar book(s)


Group 6
A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

+2 more similar book(s)


Group 7
The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789

+0 more similar book(s)


Group 10
A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

+2 more similar book(s)


What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 2

Enter the group number (1-10): 4

The books in this group are: 

1.The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

2.Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

3.Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

4.Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674


What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 3

Enter the title: Harry Potter
Enter the author: JK Rowling
Enter the price: 4.55
Enter the isbn: 432231

Harry Potter has been added to the catalogue
What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 1
Books in the Catalogue:

Group 1
Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

+1 more similar book(s)


Group 3
Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

+0 more similar book(s)


Group 4
The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

+3 more similar book(s)


Group 5
Middlemarch by George Elliot
$12.50
ISBN#: 1256743

+0 more similar book(s)


Group 6
A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

+2 more similar book(s)


Group 7
The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789

+0 more similar book(s)


Group 8
Harry Potter by JK Rowling
$4.55
ISBN#: 432231

+0 more similar book(s)


Group 10
A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

+2 more similar book(s)


What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 4

Enter the title of the book to remove: Harry Potter
Enter the author: JK Rowling

Harry Potter has been removed from the catalogue
What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 1
Books in the Catalogue:

Group 1
Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

+1 more similar book(s)


Group 3
Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

+0 more similar book(s)


Group 4
The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

+3 more similar book(s)


Group 5
Middlemarch by George Elliot
$12.50
ISBN#: 1256743

+0 more similar book(s)


Group 6
A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

+2 more similar book(s)


Group 7
The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789

+0 more similar book(s)


Group 10
A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

+2 more similar book(s)


What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 5


Enter the title of the book: Harry Potter
Enter the author: JK Rowling
Harry Potter is not in the catalogue.


What would you like to do?

1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit


Enter your choice: 6
Happy Reading!



What to Submit
Once you are certain your program is working as shown above, upload your files to Canvas under Lab 7.
You must submit the following files: Book.cpp, HashTable.cpp, HashTest.cpp, List.h, Catalogue.cpp
Please do not submit HashTable.h or Book.h or catalogue.txt as I will assume that these files are unaltered from the ones provided (no points if you alter these header files).
You will receive 10 points for a correct Book.cpp.
You will receive 60 points for a correct HashTable.cpp, along with a HashTest.cpp (-10 per incorrect function for a minimum of 0 points on this section)
You will receive 30 points for a correct Catalogue.cpp that works identically to the example above.
