#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
#include <iomanip>

/**
// A Class to represent a calendar date
*/

class Date{
private:
    int day;
    int month;
    int year;

    int daysInMonth(int year,int month);
public:
    Date();  // Default Construtor sets the date to 1/1/1970

    /**
     *
	  @param year date year
	  @param month date month
	  @param day date day
     */

    Date( int year,int month,int day);

    /**
	  date formated as 'MM/DD/YYYY'
	  @param formatted_date
     */
     Date(std::string fromatted_date);

      /**
	  @return year
     */

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    /**
     *
	  @return the date formated in MM/DD/YYYY
     */
        std::string toString() const;

     /**
	 Sets the day
	  @param day
     */
    void setDay (int day);
    void setMonth (int month);
    void setYear (int year);
    void setDate(int year, int month,int day);

    bool operator==(const Date &rhs) const;
    bool operator!=(const Date &rhs) const;
    bool operator<(const Date &rhs) const;
    bool operator>(const Date &rhs) const;
    bool operator<=(const Date &rhs) const;
    bool operator>=(const Date &rhs) const;

};

std::ostream& operator<<(std::ostream &out, const Date &rhs); //operator overloading

#endif //DATE_H
