#include <iostream>
#include <string>
#include "headers/task.h"
#include "headers/database.h"
#include "headers/planner.h"

// using namespace std;

int main() {
    std::cout << "Howdy!" << std::endl;
    std::cout << std::endl;

    // Opening Database
    Database db("todo.db");

    // Initializing Variables
    Planner abby(db);
    char user_input; 

    while (true) {

        // Get user input
        std::cout << "How can I help you today?"<<std::endl;
        std::cout << "c - create new task" << std::endl; // move instruction prompt to separate function
        std::cout << "d - delete task " << std::endl;
        std::cout << "e - edit task " << std::endl;
        std::cout << "l - list tasks "<< std::endl;
        std::cout << "x - exit app " << std::endl;
        std::cout << std::endl;
        std::cin >> user_input;

        // Executing User Input
        if (user_input == 'c') {
            // Create Task
            std::string task_name;
            std::cout << "Enter the task name: "<<std::endl;
            std::cin >> task_name;
            Task task(1,task_name);
            std::cout<<std::endl;
            abby.addTask(task);

        } else if (user_input == 'd') {
            // Delete Task
            int task_id;
            std::cout << "Enter the task ID to delete: "<<std::endl;
            std::cin >> task_id;
            abby.delTask(task_id);// Delete from planner
        } else if (user_input == 'e') {
            // Edit Task
            int task_id;
            std::cout << "Enter the task ID to edit: "<<std::endl;
            std::cin >> task_id;
            // // string task_edit, task_change;
            // cout << "Enter the attribute to edit: ";
            // // cin >> task_edit;
            // cout << "Enter the new value: ";
            // cin >> task_change;
            // edit_task(task_id, task_edit, task_change);
        } else if (user_input == 'l') {
            // List Tasks
            std::cout << "List of Tasks ..." << std::endl;
            abby.Print();
            std::cout << std::endl;
        } else if (user_input == 'x') {
            // Exit app
            std::cout << "Exiting app..." << std::endl;
            // db.clearTasks();
            // db.writeToDatabase(abby.getTaskList());
            break;
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    return 0;
}
