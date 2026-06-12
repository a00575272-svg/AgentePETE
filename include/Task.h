// Task.h
#pragma once
#include <string>
#include <vector>
#include "DayMonYear.h"

int nowDMY(now part);

class Task : public DayMonYear
{
private:
    std::string dayFileName;

public:
    // Private constructor for loading from file (no save)
    Task(int day, int month, int year,
        const std::string& title,
        const std::string& description,
        bool fromFile);


    Task(int day, int month, int year,
        const std::string& title,
        const std::string& description);

    void saveEntry();
    void taskDelet();

    static std::vector<Task> loadAllEntries();





private:
    std::string buildFileName();
};