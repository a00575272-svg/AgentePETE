#include "Task.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <vector>
#include <filesystem>


enum class now
{
    Day,
    Month,
    Year
};

int nowDMY(now part)
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm local_tm{};
    localtime_s(&local_tm, &t);

    switch (part)
    {
    case now::Day:
        return local_tm.tm_mday;

    case now::Month:
        return local_tm.tm_mon + 1;

    case now::Year:
        return local_tm.tm_year + 1900;
    }

    return 0;
}

std::string Task::buildFileName()
{
    std::ostringstream oss;
    oss << "taskDir/"
        << std::setw(2) << std::setfill('0') << getDay()
        << "-"
        << std::setw(2) << std::setfill('0') << getMonth()
        << "-"
        << std::setw(4) << std::setfill('0') << (getYear())
        << ".txt";
    return oss.str();
}

Task::Task(int day, int month, int year,
    const std::string& title,
    const std::string& description)
    : DayMonYear(day, month, year, title, description)
{
    dayFileName = buildFileName();
    saveEntry();
}

void Task::saveEntry()
{
    std::fstream file(dayFileName, std::ios::out | std::ios::app);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << dayFileName << "\n";
        return;
    }

    file << getDay() << ","
        << getMonth() << ","
        << getYear() << ","
        << getTitleTask() << ","
        << getDescriptionTask() << "\n";

    file.close();
}


void Task::taskDelet()
{
    std::ostringstream target;
    target << getDay() << ","
        << getMonth() << ","
        << getYear() << ","
        << getTitleTask() << ","
        << getDescriptionTask() << "\n";
    std::string targetLine = target.str();

    std::ifstream fileIn(dayFileName);
    if (!fileIn.is_open())
    {
        std::cerr << "Error: could not open file " << dayFileName << "\n";
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(fileIn, line))
        lines.push_back(line + "\n");
    fileIn.close();

    bool found = false;
    for (auto it = lines.begin(); it != lines.end(); ++it)
    {
        if (!found && *it == targetLine)
        {
            lines.erase(it);
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cerr << "Entry not found in " << dayFileName << "\n";
        return;
    }

    std::ofstream fileOut(dayFileName, std::ios::out | std::ios::trunc);
    if (!fileOut.is_open())
    {
        std::cerr << "Error: could not rewrite file " << dayFileName << "\n";
        return;
    }

    for (const auto& l : lines)
        fileOut << l;

    fileOut.close();
}

// Private constructor - skips saveEntry()
Task::Task(int day, int month, int year,
    const std::string& title,
    const std::string& description,
    bool /*fromFile*/)
    : DayMonYear(day, month, year, title, description)
{
    dayFileName = buildFileName();
}

std::vector<Task> Task::loadAllEntries()
{
    std::vector<Task> entries;

    for (const auto& dirEntry : std::filesystem::directory_iterator("taskDir"))
    {
        if (dirEntry.path().extension() != ".txt")
            continue;

        std::ifstream file(dirEntry.path());
        if (!file.is_open())
        {
            std::cerr << "Could not open " << dirEntry.path() << "\n";
            continue;
        }

        std::string line;
        while (std::getline(file, line))
        {
            if (line.empty()) continue;

            std::istringstream ss(line);
            std::string dayStr, monthStr, yearStr, title, description;

            if (!std::getline(ss, dayStr, ',') ||
                !std::getline(ss, monthStr, ',') ||
                !std::getline(ss, yearStr, ',') ||
                !std::getline(ss, title, ',') ||
                !std::getline(ss, description))
            {
                std::cerr << "Malformed line skipped: " << line << "\n";
                continue;
            }

            try
            {
                int day = std::stoi(dayStr);
                int month = std::stoi(monthStr);
                int year = std::stoi(yearStr);
                entries.emplace_back(day, month, year, title, description, true);
            }
            catch (const std::exception& e)
            {
                std::cerr << "Parse error on line: " << line << " (" << e.what() << ")\n";
            }
        }

        file.close();
    }

    return entries;
}
