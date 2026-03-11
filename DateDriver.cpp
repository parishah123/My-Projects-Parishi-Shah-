#include <iostream>
#include "Date.h"

int main() {
    // Date Driver Code going here:
    Date* epoch =new Date();

    std::cout<<"Epoch should have a day of 1 and it is "<< epoch->getDay()<<std::endl;
    std::cout<<"Epoch should have a month of 1 and it is "<< epoch->getMonth()<<std::endl;
    std::cout<<"Epoch should have a year 1970 and it is "<< epoch->getYear()<<std::endl;

    std::cout<<std::endl;


    Date* independence =new Date(1776,7,4);
    std::cout<<"Independence should have a day of 4 and it is "<< independence->getDay()<<std::endl;
    std::cout<<"Independence should have a month of 7 and it is "<<independence->getMonth()<<std::endl;
    std::cout<<"Independence should have a year 1776 and it is "<< independence->getYear()<<std::endl;

    std::cout<<std::endl;


    Date* christmas =new Date(0,1,31);
    christmas->setYear(2025);
    christmas->setMonth(12);
    christmas -> setDay(25);


    std::cout<<"Christmas should have a day of 25 and it is "<< christmas->getDay()<<std::endl;
    std::cout<<"Christmas should have a month of 12 and it is "<< christmas->getMonth()<<std::endl;
    std::cout<<"Christmas should have a year 2025 and it is "<< christmas->getYear()<<std::endl;
    {
        Date *nope = new Date(2025,5,43);
    }

    try{
        Date *nope = new Date(2025,-9, 5);
    } catch(std:: out_of_range error) {
        std::cerr << "Failed to create date -9/5/2025 "<< error.what() << std::endl;
    }
     catch(std::out_of_range error){
        std::cerr<<"Failed to create date 5/43/2025 "<< error.what()<<std::endl;

    }

    Date *today =new Date(2025,9,9);
    Date *bestDayEver=new Date(2025,9,9);
    Date *suckyDay=new Date(2025,8,22);

    if( *today == *bestDayEver){
        std::cout<<"Today is the best day ever !"<<std::endl;
    } else{
        std::cout<<"Today is not the best day ever !"<<std::endl;
    }
    if( *today!= *bestDayEver){
        std::cout<<"Should see this !"<<std::endl;
    } else{
        std::cout<<"Should not see this !"<<std::endl;
    }
    if( *suckyDay < *today){
        std::cout<<"Glad it's over  !"<<std::endl;
    } else {
        std::cout<<"Great,still have a sucky day to look forward to."<<std::endl;
    }

    std::cout << "today should be 09/09/2025 and it is " << *today << std::endl;

    Date *firstDay = new Date("08/25/2025");

    std::cout << "First day should be 08/25/2025 and it is " << *firstDay << std::endl;
    std::cout << "Everything went great!" << std::endl;

    return 0;
}

