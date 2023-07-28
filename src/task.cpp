#include "../headers/task.h"
#include <iostream>

// Constructor 
Task::Task(int id, std::string name){
    // std::cout<<"in task constructor... "<<std::endl;
    task_id = id; 
    task_name = name;
}

// Get Functions
int Task::getID(){
    return task_id; 
}

std::string Task::getName(){
    return task_name;
}

// Set Functions 
void Task::setName(std::string name){
    task_name = name; 
}; 
