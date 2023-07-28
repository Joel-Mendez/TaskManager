#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    public:
        Task(int id, std::string name); // Constructor

        int getID();
        std::string getName();
        void setName(std::string name); // To edit task name

    private:
        int task_id; //Task ID
        std::string task_name; //Task Name
};

#endif // TASK_H