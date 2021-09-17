#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <cctype>


const int MAX_DAY_SIZE = 31;
const int MIN_DAY_SIZE = 1;
const int MAX_MONTH_SIZE = 12;
const int MIN_MONTH_SIZE = 1;


//-------------------------------------------------------------------------------------------------------


class Date {

public:

	Date();

	Date(std::istream& is);

	int GetDay() const;

	int GetMonth() const;

	int GetYear() const;

private:

	int year;
	int month;
	int day;


	int ReadAndEnsureRightFormat(std::istream& is, const std::string& init_string);

	void EnsureCorrectValue(int value, int min_value, int max_value, const std::string& str_name);

};


Date ParseDate(std::istream& is);


bool operator <  (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
bool operator >  (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs); 
bool operator >= (const Date& lhs, const Date& rhs);


std::ostream& operator << (std::ostream& stream, const Date& obj);


std::istream& operator >> (std::istream& stream, Date& obj);


//-------------------------------------------------------------------------------------------------------