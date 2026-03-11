#include "Date.h"
#include <stdexcept>
#include <sstream>
Date::Date(){

    this->day=1;
    this->month=1;
    this->year=1970;
}
//Parameter
/**
 *
 * @param year
 * @param month
 * @param day
 */
Date::Date(int year,int month,int day){
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::Date(std::string formatted_date) {
    std::stringstream ss(formatted_date);
    std::string temp_day, temp_month, temp_year;
    std::getline(ss, temp_month, '/');
    std::getline(ss, temp_day, '/');
    std::getline(ss, temp_year, '/');
    setYear(stoi(temp_year));
    setMonth(stoi(temp_month));
    setDay(stoi(temp_day));

}

int Date::getDay() const{
    return day;
}
int Date::getMonth() const {
    return month;
}
int Date::getYear() const{
    return year;
}
void Date::setDate(int year,int month,int day){
    setYear(year);
    setMonth(month);
    setDay(day);
}
void Date::setDay(int day) {
    if (day < 1 || day > daysInMonth(this->year,this->month)){
        throw std::out_of_range("Invalid Day");
    }
    this-> day = day;
}
void Date::setMonth(int month) {
    if (month < 1 || month > 12){
        throw std::out_of_range("Invalid Month");
    }
    this-> month = month;
}
void Date::setYear(int year) {
    this->year=year;
}
int Date::daysInMonth(int year,int month){
    int days=0;
    switch (month){
        case 2:
            if(year % 400 ==0 ){days=29;}
            else if(year % 100 ==0) {days =28;}
            else if(year % 4 ==0) {days =29;}
            else {days =28;}
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days= 30;
            break;
        default:
            days=31;
    }
    return days;
}
bool Date::operator==(const Date &rhs) const{
    return  (this->getYear() == rhs.getYear() &&
             this->getMonth() == rhs.getMonth() &&
             this->getDay() == rhs.getDay() );
}
bool Date::operator!=(const Date &rhs)const{
    return !(*this ==rhs);
}
bool Date::operator<(const Date &rhs)const {

    if (this->getYear() < rhs.getYear()) { return true; } //less than
    else if (this->getYear() > rhs.getYear()) { return false; } //greater than

    else if (this->getMonth() < rhs.getMonth()) { return true; }
    else if (this->getMonth() > rhs.getMonth()) {return false;}

        //the year and months are the same
    else { return (this->getDay() < rhs.getDay()); }
}
bool Date::operator<=(const Date &rhs) const {
    return (*this < rhs || *this == rhs);
}

bool Date::operator>(const Date &rhs) const {
    return !(*this <=rhs);
}
bool Date::operator>=(const Date &rhs) const {
    return (*this > rhs);
}
std::string Date::toString()const{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << this->getMonth() << '/'
       << std::setw(2) << std::setfill('0') << this->getDay() << '/'
       << std::setw(4) << std::setfill('0') << this->getYear();
    return ss.str();
}
std::ostream& operator<<(std::ostream &out, const Date &rhs) {
    out << rhs.toString();
    return out;
}
