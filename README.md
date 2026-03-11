[comment]: <> (Do not remove this!)
![Points badge](../../raw/badges/.github/badges/points-bar.svg)

➡️ [Click here to view the autograder workflow](../../actions/workflows/classroom.yml)

# Customer Lab

## Why this Assignment Matters:
We'll use this assignment to review topics such as documenting, pointers, classes, objects, operator overloading and file I/O.  We'll be using the classes that we create in this lab for many of the upcoming labs.  If your OOP skills are rusty now is the time to brush up.  

In this lab, you will create two classes: `Date` and `Customer`. This assignment will focus on key Object-Oriented Programming concepts such as operator overloading, file I/O, and the use of pointers. The `Date` class will be developed together in class, and you will complete the `Customer` class on your own.

## Developing and testing:
I've included two test suites that you can use to check your work.  They labeled CustomerTests and DateTests and can run from within CLion.  These tests will tell you which methods of your code are passing and failing the tests that I wrote.  These tests will not check the readability of your code, the efficiency of your code or check for memory leaks, those parts will be hand graded.  You must also implement a DateDriver and CustomerDriver to test and demonstrate your Date and Customer Classes functionality.

I expect this assignment might easily be more than 1,000 lines of code with code, comments in the driver, header, and implementation files.  That is not going to be unusual for this class.  Start early and give yourself time.  

## Class Interfaces 
As with all assignments you will be given a list of public facing methods for your classes that you must implement.  How you implement the interface internally is up to you, but you must implement the public methods as described in this readMe.  This is the same way it will work when you join a coding team.  The lead programmer will assign you classes to write and dictate the interface so that all the coders on the team understand how to use your contributed code. 

There are 100 total points possible in this assignment.

60 points will be auto-graded, with the remaining 40 points given by Prof. Raupach after checking  that your code for all parts followed the good coding practices listed in the rubric and discussed in class.

## Grading rubric 100 points (60 auto-graded)

| Points | Requirements                             |
|--------|------------------------------------------|
| 30     | Date test suite. (auto graded)           |
| 10     | Date Driver  (manually graded)           |
| 30     | Customer test suite. (auto graded)       | 
| 10     | Customer Driver  (manually graded)       |                 
| 20     | Good coding practices. (manually graded) |

Note: You are allowed unlimited attempts ahead of the due date.
So, if you do not achieve full  points after your initial submissions, you may resubmit as many times as you want until you have reached the deadline or achieved the point total you want.

### Style and Efficiency Count

* Separate header (.h) and implementation (.cpp) files for all classes
* All variables should have self-commenting variable names.
* One statement per line, generally each line should also be less than 120 characters 
* Proper indenting and spacing
* Each function, class and method should have documenting comments.
* Good descriptive comments for tricky parts of the code.
* You need to make sure your efficiency is as good as the examples we review in class.
* A lack of coding errors like memory leaks

## Customer and Date Classes
![Customer and Date UML](images/Customers.png)


## Part 1 Date Class
We'll implement this one together in class as an example of how I like to have code written.  The Date class represents a calendar date.  In class, our example will have year, month and day properties but there are other solutions.  The Date class have two files Date.h for the class declaration and Date.cpp for the implementation. 

You'll also need to implement a DateDriver.cpp that demonstrates all the functions of the Date Class.  Don't wait until you're done with all the coding of the Date class to create this driver.  You should be using the driver to test each method as you're creating it.

The Date class should have the following methods making its public interface:
* Date(); -- Default Constructor, should set the date to epoc (January 1st 1970)
* Date(int year, int month, int day); -- Constructor that takes year, month and day arguments 
* Date(std::string formatted_date); -- Constructor that take a formatted string as m/d/y argument
* int getYear() const; -- Returns the year integer
* int getMonth() const; -- Returns the month integer
* int getDay() const; -- Returns the day integer
* string toString()  const; -- Returns a formatted () string of the date
* The ==, !=, <, <=, >, >= operators should be overloaded
* std::ostream & operator<< (std::ostream &out, const Date &date); -- should be created but not as part of the class itself

If a date is created that is not valid, 7/82/1960 for example, the Date class should throw a simple string exception "Out of Range". 

When you think you've implemented all the functions correctly you can run the DateTests and see if you pass all the tests that I wrote.  The results should display in the lower left corner of CLion.

![Showing dates test results](images/Date_test_results.png)

Be for moving on be sure to run your DateDriver, copy the output and paste it into the DriverOutput/DateDriverOutput.txt file, so I can see it when grading. 


## Part 2 Customer Class

Now it's time for you to implement a class on your own.  You are allowed to work with other, discuss ideas, but you ***must turn in your own work!*** A good rule of thumb if you're helping some on out is the person requesting help shows their code and the person helping never shows their code.  Put the work in on this one because we're going to be using it all semester long.  For example, we're going to create a Binary Search Tree in a future lab.  You're BST will be populated with customers from this lab.  

In this part you're going to implement a Customer Class for a company. If you open the customer_data/Customer.txt file you'll see a huge file of tab separated values(tsv) records of customer data.  In a tab separated file the fields are separated by tabs (\t) and the records are separated by new lines (\n).  You are going to use that data to create customer objects from your customer class.  The file has the following fields, you'll most likely want to make properties of your class to match:

* customer_id
* username
* first_name
* last_name
* street_address
* city
* state
* postal_code
* email_address
* gender
* company
* job_title
* customer_since
* social_security_number
* date_of_birth
* household_income
* credit_score
* total_sales

Notice the customer_since and date_of_birth fields, seems like a good place utilize aggregation with our new Date class.  
The Customer Class should be implemented in two files Customer.h and Customer.cpp just like the Date class.  The public interface for this class should be made up of the methods:

*It seems like a lot but notice that most are simple getters and setters.*

#### Constructors 
* Customer()
* Customer(string customer_id, string username, string first_name, string last_name, string street_address,
  string city, string state, string postalCode, string email, string gender, string company, string job_title,
  Date customer_since, string social_security_number, Date date_of_birth, int household_income,
  int credit_score, double total_sales); 
* Customer(string record);

#### Getters and Setters
* void setCustomerID(string customer_id);
* string getCustomerID();
* string getUserName();
* void setUserName(string username);
* string getFirstName() const;
* void setFirstName(string first_name);
* string getLastName() const;
* void setLastName(string last_name);
* string getStreetAddress() const;
* void setStreetAddress(string street_address);
* string getCity() const;
* void setCity(string city);
* string getState() const;
* void setState(string state);
* string getPostalCode() const;
* void setPostalCode(string postal_code);
* string getEmail() const;
* void setEmail(string email);
* string getGender() const;
* void setGender(string gender);
* string getCompany() const;
* void setCompany(string company);
* string getJobTitle() const;
* void setJobTitle(string job_title);
* void setSocialSecurityNumber(string social_security_number);
* string getSocialSecurityNumber();
* Date getCustomerSince() const;
* void setCustomerSince(Date customer_since);
* Date getDateOfBirth() const;
* void setDateOfBirth(Date date_of_birth);
* int getHouseholdIncome() const;
* void setHouseholdIncome(int household_income);
* int getCreditScore() const;
* void setCreditScore(int credit_score);
* double getTotalSales() const;
* void setTotalSales(double total_sales);



#### Static Methods (See notes below)
* static CustomerCompareOptions getCompareWith();
* static void setCompareWith(CustomerCompareOptions code);

#### Stringify
* string toString() const; -- should return a string in the format "firstName lastName (customerID)".  Used by the file stream operator. 

#### Operator Overloading
* The ==, !=, <, <=, >, >= operators should be overloaded

#### stream operator overloading 
* std::ostream & operator<< (std::ostream &out, const Customer &customer); -- should be created but not as part of the class itself

***Note: CustomerCompareOptions and the ==, !=, <, <=, >, >= operators***
Our Customer Class is going to have something a little extra, so we can have more fun later in the semester.  We're going to be able to change the property that the comparison operators use to compare in other words we're going to be able to change how the comparison operator works at runtime. 


For example the code:
```c++
    // Jenna has been a customer since 10/27/2008 and has a credit score of 671
    // Elmer has been a customer since 6/19/1999 and has a credit score of 476
    
    Customer::setCompareWith(CustomerSince);

    if (jenna < elmer) {
        cout << "Jenna has been a customer longer" << endl;
    } else {
        cout << "Elmer has been a customer longer" << endl;
    }

    Customer::setCompareWith(CreditScore);

    if (jenna < elmer) {
        cout << "Elmer has a better credit" << endl;
    } else {
        cout << "Jenna has a better credit" << endl;
    }
```
Outputs:
```text
Elmer has been a customer longer
Jenna has better credit
```

Declare this enum at the top of the Customer.h file above the class declaration: 
```c++
enum CustomerCompareOptions { FullName, UserName, CustomerID,CustomerSince, DateOfBirth, CreditScore, HouseholdIncome, TotalSales};
```
This will allow us to use nice readable names when switching the compare operators. If no comparison option is set default to FullName.


## Customer Driver


The CustomerDriver.cpp should demonstrate all the functionality of the customer class. In it needs load all 100,000 customer records into a dynamic array (but start small while you're developing, like 100).  No vectors, sorry.

Then demonstrate a "find maximum algorithm" with the DateOfBirth to find the youngest customer, and a "find minimum algorithm" to find the customer that has spent the least.  If there is more than one result just be sure to return one of them, for example if the youngest customer turns out to have the same birthdate as another customer just be sure to print one of them. 

When you're done you can run the CustomerTests to see if you pass the automated tests. Be sure to copy the output from your driver to the CustomerDriverOutput.txt file.  
