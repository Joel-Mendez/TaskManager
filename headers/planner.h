#ifndef PLANNER_H
#define PLANNER_H

#include <string>
#include <vector>
#include "database.h"
#include "task.h"

class Planner {
    public:
        Planner(Database db); // Constructor
        void Print(); 
        void addTask(Task task);
        void delTask(int ID);
        std::vector<Task> getTaskList(); 
        // void editTask()
        // void setName(std::string name); // To edit task name

    private:
        std::vector<Task> taskList; //Task Name
        int selectedID; 
};

#endif // PLANNER_H