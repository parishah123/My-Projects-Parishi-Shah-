#include "Customer.h"
#include <stdexcept>
#include <sstream>

CustomerCompareOptions Customer::_compareWith = FullName; //default to fullname

std::string Customer::toString() const {
    // builds string
    return _first_name + " " + _last_name + " (" + _customer_id + ")";
}

// Default Constructor
Customer::Customer() {
    _customer_id = "";
    _username = "";
    _first_name = "";
    _last_name = "";
    _street_address = "";
    _city = "";
    _state = "";
    _postal_code = "";
    _email = "";
    _gender = "";
    _company = "";
    _job_title = "";
    _customer_since = Date();
    _social_security_number = "";
    _date_of_birth = Date();
    _household_income = int();
    _credit_score = int();
    _total_sales = double();
}

// Constructor with all params
Customer::Customer(std::string customer_id, std::string username, std::string first_name, std::string last_name,
                   std::string street_address, std::string city, std::string state, std::string postal_code,
                   std::string email, std::string gender, std::string company, std::string job_title, Date customer_since,
                   std::string social_security_number, Date date_of_birth, int household_income, int credit_score, double total_sales)
{
    _customer_id = customer_id;
    _username = username;
    _first_name = first_name;
    _last_name = last_name;
    _street_address = street_address;
    _city = city;
    _state = state;
    _postal_code = postal_code;
    _email = email;
    _gender = gender;
    _company = company;
    _job_title = job_title;
    _customer_since = Date(customer_since);
    _social_security_number = social_security_number;
    _date_of_birth = Date(date_of_birth);
    _household_income = int(household_income);
    _credit_score = int(credit_score);
    _total_sales = double(total_sales);
}

//Constructor with Record
// Split the string based on \t
// Save all elements in local variables
Customer::Customer(std::string record) {
    std::stringstream ss(record);

    //local variables
    std::string customer_id, username, first_name, last_name, street_address, city, state, postal_code, email, gender, company, job_title,
            customer_since, social_security_number, date_of_birth,household_income, credit_score, total_sales;

    std::getline(ss,customer_id,'\t');
    _customer_id = customer_id;

    std::getline(ss,username,'\t');
     _username = username;

    std::getline(ss,first_name,'\t');
    _first_name = first_name;

    std::getline(ss,last_name,'\t');
    _last_name=last_name;

    std::getline(ss,street_address,'\t');
    _street_address=street_address;

    std::getline(ss,city,'\t');
    _city=city;

    std::getline(ss,state,'\t');
    _state=state;

    std::getline(ss,postal_code,'\t');
    _postal_code=postal_code;

     std::getline(ss,email,'\t');
     _email=email;

    std::getline(ss,gender,'\t');
    _gender=gender;

    std::getline(ss,company,'\t');
    _company=company;

    std::getline(ss,job_title,'\t');
    _job_title=job_title;

    std::getline(ss,customer_since,'\t');
    _customer_since=Date(customer_since);

    std::getline(ss,social_security_number,'\t');
    _social_security_number=social_security_number;

    std::getline(ss,date_of_birth,'\t');
    _date_of_birth = Date(date_of_birth); // special case for date //

    std:: getline(ss,household_income,'\t');
    _household_income=std::stoi (household_income); //stoi → string → int

    std::getline(ss,credit_score,'\t');
    _credit_score=std::stoi(credit_score);

    std::getline(ss,total_sales,'\t');
    _total_sales=std::stod(total_sales);  //stod → string → double

}

//setUserName(username);setFirstName(first_name);setLastName(last_name );
//setStreetAddress(street_address);setCity(city );setState(state );
//setPostalCode(postal_code );setEmailAddress(email_address);setGender(gender);
//setCompany(company);setJobTitle(job_title);


std::string Customer::getCustomerID()const{
    return _customer_id;
}

std::string Customer::getUserName() const{
    return _username;
}
std::string Customer::getFirstName() const {
    return _first_name;
}
std::string Customer::getLastName() const{
    return _last_name;
}
std::string Customer::getStreetAddress()const{
    return _street_address;
}
std::string Customer::getCity()const{
    return _city;
}
std::string Customer::getState()const{
    return _state;
}
std::string Customer::getPostalCode()const{
    return _postal_code;
}
std::string Customer::getEmail()const{
    return _email;
}
std::string Customer::getGender()const{
    return _gender;
}
std::string Customer::getCompany()const{
    return _company;
}
std::string Customer::getJobTitle()const{
    return _job_title;
}
std::string Customer::getSocialSecurityNumber()const{
    return _social_security_number;
}
Date Customer::getCustomerSince()const{
    return  _customer_since;
}
Date Customer::getDateOfBirth()const{
    return _date_of_birth;
}
int Customer::getHouseholdIncome()const{
    return _household_income;
}
int Customer::getCreditScore()const{
    return _credit_score;
}
double Customer::getTotalSales()const{
    return _total_sales;
}

void Customer:: setCustomerID(std::string customer_id){
    this->_customer_id=customer_id;
}

void Customer:: setUserName(std::string username){
    this->_username=username;
}

void Customer:: setFirstName(std::string first_name){
    this->_first_name=first_name;
}
void Customer:: setLastName(std::string last_name){
    this->_last_name=last_name;
}
void Customer:: setStreetAddress(std::string street_address){
    this->_street_address=street_address;
}
void Customer:: setCity(std::string city){
    this->_city=city;
}
void Customer:: setState(std::string state){
    this->_state=state;
}
void Customer:: setPostalCode(std::string postal_code){
    this->_postal_code=postal_code;
}
void Customer:: setEmail(std::string email){
    this->_email=email;
}
void Customer:: setGender(std::string gender){
    this->_gender=gender;
}
void Customer:: setCompany(std::string company){
    this->_company=company;
}
void Customer:: setJobTitle(std::string job_title){
    this->_job_title=job_title;
}
void Customer::setCustomerSince(Date customer_since){
    this->_customer_since=customer_since;
}
void Customer::setSocialSecurityNumber(std::string social_security_number){
    this->_social_security_number=social_security_number;
}
void Customer::setDateOfBirth(Date date_of_birth){
    this->_date_of_birth=date_of_birth;
}
void Customer::setHouseholdIncome (int household_income){
    this->_household_income=household_income;
}
void Customer::setCreditScore(int credit_score){
    this->_credit_score=credit_score;
}
void Customer::setTotalSales(double total_sales){
    this->_total_sales=total_sales;
}
CustomerCompareOptions Customer::getCompareWith() {
    return _compareWith;
}

void Customer::setCompareWith(CustomerCompareOptions code) {
    _compareWith = code;
}

bool Customer::operator<(const Customer& rhs) const {
    switch(_compareWith) {
        case CustomerSince:
            if (_customer_since < rhs._customer_since) {
                return true;
            } else {
                return false;
            }
            break;

        case DateOfBirth:
            if (_date_of_birth < rhs._date_of_birth) {
                return true;
            } else {
                return false;
            }
            break;

        case CreditScore:
            if (_credit_score < rhs._credit_score) {
                return true;
            } else {
                return false;
            }
            break;

        case HouseholdIncome:
            if (_household_income < rhs._household_income) {
                return true;
            } else {
                return false;
            }
            break;

        case CustomerID :
            return (_customer_id < rhs._customer_id);
        case TotalSales :
            return (_total_sales < rhs._total_sales);
        case UserName :
            return (_username < rhs._username);
        case FullName:
            std::string fullname= _last_name +" "+_first_name;
            std::string fullname2= rhs._last_name+" "+rhs._first_name;
            return fullname<fullname2;
    }
}
bool Customer::operator>(const Customer& rhs) const {
    switch (_compareWith) {
        case CustomerSince:
            return (_customer_since >rhs. _customer_since);
        case DateOfBirth:
            return (_date_of_birth >rhs. _date_of_birth);
        case CreditScore:
            return (_credit_score > rhs._credit_score);
        case HouseholdIncome:
            return (_household_income >rhs. _household_income);
        case CustomerID:
            return (_customer_id >rhs. _customer_id);
        case TotalSales:
            return (_total_sales >rhs. _total_sales);
        case UserName:
            return (_username > rhs._username);
        case FullName:
            std::string fullname= _last_name +" "+_first_name;
            std::string fullname2= rhs._last_name+" "+rhs._first_name;
            return fullname>fullname2;
    }
}

bool Customer::operator==(const Customer &rhs) const{
    switch(_compareWith){
        case CustomerSince:
            return (_customer_since == rhs._customer_since);
        case DateOfBirth:
            return (_date_of_birth == rhs._date_of_birth);
        case CreditScore:
            return (_credit_score == rhs._credit_score);
        case HouseholdIncome:
            return (_household_income == rhs._household_income);
        case CustomerID:
            return (_customer_id == rhs._customer_id);
        case TotalSales:
            return (_total_sales == rhs._total_sales);
        case UserName:
            return (_username == rhs._username);
        case FullName:
            std::string fullname= _last_name +" "+_first_name;
            std::string fullname2= rhs._last_name+" "+rhs._first_name;
            return fullname==fullname2;
    }
}
bool Customer::operator!=(const Customer &rhs)const{
    return !(*this == rhs);
}
bool Customer::operator<=(const Customer &rhs) const {
    return (*this == rhs || *this < rhs);
}

bool Customer::operator>=(const Customer &rhs) const {
    return !(*this<rhs);
}

    std::ostream& operator<<(std::ostream& out, const Customer& c) {
        out << c.toString();  // call your string method
        return out;
    }

