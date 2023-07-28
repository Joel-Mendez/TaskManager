#include "../headers/planner.h"
#include <iostream>
#include <algorithm>

// Constructor 
Planner::Planner(Database db){
    taskList = db.getAllTasks();
}

void Planner::Print(){
    std::cout<<"Task ID:"<<"\t"<<"Task Name:"<<std::endl;
    for (int n_task = 0; n_task < taskList.size(); n_task++) {
        std::cout << taskList[n_task].getID()<<"\t\t" << taskList[n_task].getName() << std::endl;
    }
}

std::vector<Task> Planner::getTaskList(){
    return taskList; 
}

void Planner::addTask(Task task){
    taskList.emplace_back(task);
}

void Planner::delTask(int ID){
    taskList.erase(std::remove_if(taskList.begin(), taskList.end(),
                               [ID](Task task) {
                                   return task.getID() == ID;
                               }),
                taskList.end());
}

