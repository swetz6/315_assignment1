#include "student.h"

float student::getTotal() {
    float total;
    for (int i = 0; i < studentBill.size(); i++) {
        total += studentBill[i].getAmount();
    }
    return total;
}

void student::printBill() {
    for (int i = 0; i < studentBill.size(); i++)
        std::cout << "Charge Type: " << studentBill[i].getType() << "\t" <<
        studentBill[i].getAmount() << '\n';
    std::cout << "Total is: " << student::calcAttempt();
}

bool student::entryInMonth(feePaymentEntry entry, boost::gregorian::date d){
    if((entry.getDate().month() == d.month()) && (entry.getDate().year() == d.year()))
        return true;
    else 
        return false;
}

boost::gregorian::date student::startOfNextMonth(boost::gregorian::date d){
    boost::gregorian::date eom = d.end_of_month();
    boost::gregorian::date_duration dur(1);
    boost::gregorian::date nextMonth = eom + dur;
    return nextMonth;
}

float student::calcAttempt(){
    boost::gregorian::date currentDate(student::firstEntryDate());
    boost::gregorian::date endDate(studentBill[student::numberEntries()-1].getDate());
    float monthTotal=0.0;
    float overallTotal=0.0;
    for(int index=0;index<student::numberEntries();){
        bool currentEntryInMonth = entryInMonth(studentBill[index],currentDate);
        if(currentEntryInMonth == true){
            monthTotal += studentBill[index].getAmount(); 
            index++;
        }
        else {
            currentDate = startOfNextMonth(currentDate);
            overallTotal = monthTotal+overallTotal+(overallTotal*.01);
            monthTotal=0.0;
        }
    }
    return (overallTotal=monthTotal+overallTotal+(overallTotal*.01));
}  
