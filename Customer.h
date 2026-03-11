#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <ostream>
#include "Date.h"
/**
 * Enum to represent different options for comparing customers
 */
using std::string;
enum CustomerCompareOptions {
    FullName, // 0
    UserName,   //1
    CustomerID,  //2
    CustomerSince,  //3
    DateOfBirth,        //4
    CreditScore,    //5
    HouseholdIncome, //6
    TotalSales   //7
};
/**
 * A class to represent a Customer
 */

class Customer{
private:
    static CustomerCompareOptions _compareWith;

    std::string _customer_id;
    std::string _username;
    std::string _first_name;
    std::string _last_name;
    std::string _street_address;
    std::string _city;
    std::string _state;
    std::string _postal_code;
    std::string _email;
    std::string _gender;
    std::string _company;
    std::string _job_title;
    std::string _social_security_number;
    Date _customer_since;
    Date _date_of_birth;
    int _household_income;
    int _credit_score;
    double _total_sales;

public:
    /**
     * Get the comparison option currently used
     * @return CustomerCompareOptions
     */
    static CustomerCompareOptions getCompareWith();
    /**
   * Set the comparison option
   * @param code comparison option
   */
    static void setCompareWith(CustomerCompareOptions code);
    /**
     * Convert the customer object into a string (summary format)
     * @return string representation
     */
    std::string toString() const;   //to prints the object ,but it does'nt print everything
    /**
    * Default constructor
    * Initializes everything to empty/zero
    */
    Customer (); //constructor 1 //set everything to emty

    Customer(std::string customer_id, std::string username, std::string first_name, std::string last_name,
             std::string street_address, std::string city, std::string state, std::string postalCode,
             std::string email, std::string gender, std::string company, std::string job_title, Date customer_since,
             std::string social_security_number, Date date_of_birth, int household_income, int credit_score, double total_sales); //constructor 2 it takes feild values as parameters

    /**
* Constructor to build a Customer from a record line
* Splits the record string using tabs
* @param record tab-delimited string
*/
    Customer(std::string record); //constructor 3 //it splits the record using tabs and creates the object

    // ----------- SETTERS & GETTERS -----------

    void setCustomerID(std::string customer_id);
    std::string getCustomerID()const;

    void setUserName(std::string username);
    std::string getUserName() const;

    void setFirstName(std::string first_name);
    std::string getFirstName() const;

    void setLastName(std::string last_name);
    std::string getLastName()const;

    void setStreetAddress(std::string street_address);
    std::string getStreetAddress()const;

    void setCity(std::string city);
    std::string getCity()const;

    void setState(std::string state);
    std::string getState()const;

    void setPostalCode(std::string postal_code);
    std::string getPostalCode()const;

    void setEmail(std::string email);
    std::string getEmail()const;

    void setGender(std::string gender);
    std::string getGender()const;

    void setCompany(std::string company);
    std::string getCompany()const;

    void setJobTitle(std::string job_title);
    std::string getJobTitle()const;

    void setSocialSecurityNumber(std::string social_security_number);
    std::string getSocialSecurityNumber()const;

    void setCustomerSince(Date customer_since);
    Date getCustomerSince()const;

    void setDateOfBirth(Date date_of_birth );
    Date getDateOfBirth()const;

    void setHouseholdIncome(int household_income);
    int getHouseholdIncome() const;

    void setCreditScore(int credit_score);
    int getCreditScore()const;

    void setTotalSales(double total_sales);
    double getTotalSales()const;

    bool operator==(const Customer &rhs) const;
    bool operator!=(const Customer &rhs) const;
    bool operator<(const Customer &rhs) const;
    bool operator>(const Customer &rhs) const;
    bool operator<=(const Customer &rhs) const;
    bool operator>=(const Customer &rhs) const;
/**
 * Overloaded << operator for printing customer
 * @param out output stream
 * @param c customer object
 * @return ostream reference
 */

};
std::ostream& operator<<(std::ostream& out, const Customer& c);
#endif //CUSTOMER_H

