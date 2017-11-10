//============================================================================
// Name        : Lab7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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


friend ostream& operator<<(ostream& os, const Book& book)
{
	os << book.title << " by " << book.author << endl;
	os << "$" << book.price << endl;
	os << "ISBN#:" << book.isbn << endl;
	return os;
}
//prints out a book to the designated stream in the following format

bool Book::operator==(const Book& book)
{
    return (title == book.title && author==book.author);
}
//compares two books to determine if they are the same book


bool Book::operator<(const Book& book)
{
	if(this->title.compare(book.title) == 0 && this->author.compare(book.author) == 0 && this->price == (book.price) && this->isbn == book.isbn )
		return false;
	else
	{
		if(this->title.compare(book.title) < 0)
			return true;
		else if(this->title.compare(book.title) > 0)
			return false;
		else
			if(this->author.compare(book.author) < 0)
				return true;
			else
				return false;
	}
}
//compares two books to determine if one comes before the other
//alphabetically by title and secondarily by author if the two
//books contain the same title
//returns false if the two books are the same


bool Book::operator>(const Book& book)
{
	if(this->title.compare(book.title) == 0 && this->author.compare(book.author) == 0 && this->price == book.price && this->isbn == book.isbn)
		return false;
	else 			// 3 cases, < , >, and =
	{
		if(this->title.compare(book.title) > 0)	// title is >
			return true;
		else if(this->title.compare(book.title) < 0)// title is <
			return false;
		else	// title is = then (check for author(2 cases))
			{
				if(this->author.compare(book.author) > 0)
					return true;
				else
					return false;
			}
	}
}
//compares two books to determine if one comes after the other
//alphabetically by title and secondarily by author if the two
//books contain the same title
//returns false if the two books are the same
