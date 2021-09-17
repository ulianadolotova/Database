#include "date.h"


//---------------------------------------------------------------------------------------------------

Date::Date() {

	year  = 0;
	month = 0;
	day   = 0;
}

Date::Date(std::istream& is) {

	const std::string init_string = "dummy";

	year  = ReadAndEnsureRightFormat(is, init_string);
	is.ignore(1);
	month = ReadAndEnsureRightFormat(is, init_string);
	is.ignore(1);
	day   = ReadAndEnsureRightFormat(is, init_string);

	if (is.peek() != ' ' && is.peek() != EOF) {

		throw std::runtime_error("Wrong date format: " + init_string);
	}

	EnsureCorrectValue(month, MIN_MONTH_SIZE, MAX_MONTH_SIZE, "Month");
	EnsureCorrectValue(day, MIN_DAY_SIZE, MAX_DAY_SIZE, "Day");

}


int Date::GetDay() const {

	return day;
}


int Date::GetMonth() const {

	return month;
}


int Date::GetYear() const {

	return year;
}


int Date::ReadAndEnsureRightFormat(std::istream& is, const std::string& init_string) {

	int number = 0;

	if (is >> number && (is.peek() == ' ' || is.peek() == '-' || is.peek() == EOF)) {

		return number;
	} 

	throw std::runtime_error("Wrong date format: " + init_string);
}


void Date::EnsureCorrectValue(int value, int min_value, int max_value, const std::string& str_name) {

	if (value >= min_value && value <= max_value) {

		return;

	}

	throw std::runtime_error(str_name + " value is invalid: " + std::to_string(value));
}


//----------------------------------------------------------------------------------------------------------

Date ParseDate(std::istream& is) {

	return Date(is);
}

//-----------------------------------------------------------------------------------------------------------



bool operator < (const Date& lhs, const Date& rhs) {

	if (lhs.GetYear() != rhs.GetYear()) {

		return lhs.GetYear() < rhs.GetYear();

	} else if (lhs.GetMonth() != rhs.GetMonth()) {

		return lhs.GetMonth() < rhs.GetMonth();

	} else {

		return lhs.GetDay() < rhs.GetDay();
	}
}


bool operator == (const Date& lhs, const Date& rhs) {

	return lhs.GetYear()  == rhs.GetYear() &&
		   lhs.GetMonth() == rhs.GetMonth() &&
		   lhs.GetDay()   == rhs.GetDay();
}


bool operator != (const Date& lhs, const Date& rhs) {

	return !(lhs == rhs);
}


bool operator > (const Date& lhs, const Date& rhs) {

	return !(lhs < rhs) && (lhs != rhs);
}


bool operator <= (const Date& lhs, const Date& rhs) {

	return (lhs < rhs) || (lhs == rhs); 
}


bool operator >= (const Date& lhs, const Date& rhs) {

	return (lhs > rhs) || (lhs == rhs); 
}


std::ostream& operator << (std::ostream& stream, const Date& obj) {

	stream << std::setfill('0');

	stream << std::setw(4) << obj.GetYear()  << "-"
			  	<< std::setw(2) << obj.GetMonth() << "-"
			  	<< std::setw(2) << obj.GetDay();

	return stream;
}


std::istream& operator >> (std::istream& stream, Date& obj) {

	std::string temp;

	stream >> temp;

	std::istringstream is;
	is.str(temp);

	obj = Date(is);

	return stream;
}
