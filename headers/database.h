#ifndef DATABASE_H
#define DATABASE_H


#include <string>
#include <vector>
#include "sqlite3.h"
#include "task.h"
// #include "planner.h"

class Database{
    public:
        Database(std::string name); // Constructor
        ~Database(); //
        // void saveDatabase(Planner planner)
        void addTask(Task task); // Add task to database
        void clearTasks();
        void writeToDatabase(std::vector<Task> taskList);
        std::vector<Task> getAllTasks();

    

    private:
        sqlite3* db; //database pointer
};

#endif // DATABASE_H