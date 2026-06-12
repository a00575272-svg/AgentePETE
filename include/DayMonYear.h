#pragma once

#include <iostream>
#include <chrono>
//#include <date/date.h>




class DayMonYear
{

public:
    static int defaultDay;

	int day;
	int month;
	int year;

	std::string titleTask;
	std::string descriptionTask;

public:


    DayMonYear(int,int,int,std::string,std::string);

    bool check() const;




 
    /// GettersAndSetters
    /// Format set/get + OriginalName beginig with capital letter+()
    /// Examle  day -> getDay()/setDay()
   
    

    std::string getTitleTask() {
        return titleTask;
    }

    std::string getDescriptionTask() {
        return descriptionTask;
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    // Setters
    void setDay(int d) {
        day = d;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }
    

protected:
    void setTitleTask(const std::string& title) {
        titleTask = title;
    }

    void setDescriptionTask(const std::string& description) {
        descriptionTask = description;
    }







};

