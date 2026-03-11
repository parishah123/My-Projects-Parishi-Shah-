#include <iostream>
#include <fstream>
#include<string>
#include "Customer.h"



    static const int CUSTOMER_SIZE = 100000;

    int main() {

        // create a new customer (pari)
        Customer *pari = new Customer();

        // set values for pari and print them
        pari->setCustomerID("1234");
        std::cout << pari->getCustomerID() << std::endl;

        pari->setFirstName("Parishi");
        std::cout << pari->getFirstName() << std::endl;

        pari->setLastName("Shah");
        std::cout << pari->getLastName() << std::endl;

        pari->setUserName("Shahp7368");
        std::cout << pari->getUserName() << std::endl;

        pari->setStreetAddress("Skyline Dr");
        std::cout << pari->getStreetAddress() << std::endl;

        pari->setCity("Milpitas");
        std::cout << pari->getCity() << std::endl;

        pari->setPostalCode("9807");
        std::cout << pari->getPostalCode() << std::endl;

        pari->setEmail("ppatelsth@gmail.com");
        std::cout << pari->getEmail() << std::endl;

        pari->setGender("Female");
        std::cout << pari->getGender() << std::endl;

        pari->setCompany("Meta");
        std::cout << pari->getCompany() << std::endl;

        pari->setJobTitle("Product Manager");
        std::cout << pari->getJobTitle() << std::endl;

        pari->setCustomerSince(Date("09/24/2022"));
        std::cout << pari->getCustomerSince() << std::endl;

        pari->setDateOfBirth(Date("09/3/2004"));
        std::cout << pari->getDateOfBirth() << std::endl;

        pari->setHouseholdIncome(int(100028));
        std::cout << pari->getHouseholdIncome() << std::endl;

        pari->setCreditScore(int(64752));
        std::cout << pari->getCreditScore() << std::endl;

        pari->setTotalSales(double(2774.262));
        std::cout << pari->getTotalSales() << std::endl << '\n';

        // create another customer (malav) using full constructor

        Customer* malav = new Customer("7480-HG0i186ci37", "mshahbet3h","Malav","Shah","1111 Twin Pines Alley","Louisville","CA","40266",
                                       "malavshah@seattletimes.com","Male","Google","Product Engineer",
                                       Date("12/30/1999"),"693-97-5541", Date("3/15/1957"),364713,639,424676.41);

// compare pari and malav by credit score
        Customer::setCompareWith(CreditScore);
        if(*pari == *malav){
            std::cout << "pari and malav credit scores are the same"<< std::endl;
        }
        if(*pari != *malav){
            std::cout << "pari and malav credit scores are not the same"<< std::endl;
        }
        if(*pari < *malav){
            std::cout << "pari has creditscore less than malav "<< std::endl;
        }
        if(*pari > *malav){
            std::cout << "pari has creditscore greater than malav"<< std::endl;
        }
        if(*pari <= *malav){
            std::cout << "pari has creditscore less than or equal to malav"<< std::endl;
        }
        if(*pari >= *malav){
            std::cout << "pari has creditscore greater than or equal to malav"<< std::endl;
        }
        std::cout << "\n";

        // compare by household income
        Customer::setCompareWith(HouseholdIncome );
        if(*pari == *malav){
            std::cout << "pari and malav income are the same"<< std::endl;
        }
        if(*pari != *malav){
            std::cout << "pari and malav income are not the same"<< std::endl;
        }
        if(*pari < *malav){
            std::cout << "pari has income less than malav "<< std::endl;
        }
        if(*pari > *malav){
            std::cout << "pari has income greater than malav"<< std::endl;
        }
        if(*pari <= *malav){
            std::cout << "pari has income less than or equal to malav"<< std::endl;
        }
        if(*pari >= *malav){
            std::cout << "pari has income greater than or equal to malav"<< std::endl;
        }
        std::cout << "\n";

        // compare by total sales
        Customer::setCompareWith(TotalSales  );
        if(*pari == *malav){
            std::cout << "pari and malav total sales are the same"<< std::endl;
        }
        if(*pari != *malav){
            std::cout << "pari and malav total sales are not the same"<< std::endl;
        }
        if(*pari < *malav){
            std::cout << "pari has total sales less than malav "<< std::endl;
        }
        if(*pari > *malav){
            std::cout << "pari has total sales greater than malav"<< std::endl;
        }
        if(*pari <= *malav){
            std::cout << "pari has total sales less than or equal to malav"<< std::endl;
        }
        if(*pari >= *malav){
            std::cout << "pari has total sales greater than or equal to malav"<< std::endl;
        }
        std::cout << "\n";

        // open customer file
        std::ifstream file("customer_data/Customer.txt"); //open file

        if (!file) {
            std::cerr << "Error,file could'nt open" << std::endl;
            return 1;
        }


        std::string line;
        std::getline(file, line);
        // first line has the column names

        // read customers into array
        Customer *arr = new Customer[CUSTOMER_SIZE]; //  reads 100000 lines
        int count = 0;

        while (count < CUSTOMER_SIZE && getline(file, line)) { //reads each line
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            Customer c(line); //makes customer from record
            arr[count] = c;
            count++;
        }

        // print first 100 customers
        for (int i = 0; i < 100; i++) {
            std::cout << arr[i] << "\n"; //uses toString()
        }

        // youngest
        Customer::setCompareWith(DateOfBirth);
        int young = 0;
        for (int i = 1; i < count; i++) {
            if (arr[i] > arr[young]) {
                young = i;
            }
        }
        std::cout << "\nyoungest: " << arr[young]
                  << " dob: " << arr[young].getDateOfBirth() << "\n";

        // least money spender
        Customer::setCompareWith(TotalSales);
        int least = 0;
        for (int i = 1; i < count; i++) {
            if (arr[i] < arr[CUSTOMER_SIZE]) {
             least=i;
            }
        }
        std::cout << "least money spender: " << arr[least]
                  << " sales: " << arr[least].getTotalSales() << "\n" << std::endl;
        delete[] arr;
        return 0;
    }
