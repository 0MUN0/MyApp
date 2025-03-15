#include <iostream>
using namespace std;

struct Date
{
    short days;
    short month;
    short year;
} ;

short ReadInt(string massege)
{
short Month;
cout <<"\n"<<massege;
cin >> Month;
return Month;
}

bool isLeapYear(short Year)
    {

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

short NumberOfDaysInAMonth(short Month, short Year)
    {

    if (Month < 1 || Month>12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :days[Month - 1];
    }



Date ReadDate ()
{
    Date date ;
    date.year = ReadInt("Enter year ");
    date.month = ReadInt("Enter month ");
    date.days = ReadInt("Enter days ");
    cout<<"\n\n" ;
    return date ;
}

bool islastMonthAtYear(Date date)
{
    return date.month == 12 ;
}

bool isLastDayAtMonth(Date date)
{
    return date.days == NumberOfDaysInAMonth(date.month,date.year) ;
}

Date incrreseOneDay(Date date)
{
    if(isLastDayAtMonth(date))
    {
        date.days = 1 ;
        date.month++ ;

        if(date.month == 13)
        {

            date.month = 1 ;   
            date.year ++ ;   
        
        }

    }
    else
        date.days ++ ;
    
        return date ;
}

int main()
{
    Date date ;
    
    date = ReadDate() ;
    date = incrreseOneDay(date) ;

    cout<<date.days<<"/"<<date.month<<"/"<<date.year ;

}