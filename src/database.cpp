#include "../headers/database.h"
#include <iostream>
#include <typeinfo>
// Constructor 
Database::Database(std::string name){
    // Building SQL Database
    int rc = sqlite3_open(name.c_str(), &db); 
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    }

    // Initializing Table if empty // Change if including more attributes
    std::string createTableQuery = "CREATE TABLE IF NOT EXISTS todo ("
                                   "id INTEGER PRIMARY KEY,"
                                   "name TEXT"
                                   ");";

    rc = sqlite3_exec(db, createTableQuery.c_str(), 0, 0, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
    }

}

// Deconstructor 
Database::~Database() {
    // Close SQL Database
    int rc = sqlite3_close(db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error closing database: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Task Related Functions 
// void Database::addTask(Task task){
//     std::string query = "INSERT INTO todo (name) VALUES (?)"; // Initializing query //Change to include more attributes
//     sqlite3_stmt* stmt; // Statement pointer

//     int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
//     if (rc != SQLITE_OK) {
//         std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
//         return;
//     }

//     // Bind parameters (id and name) to the statement ///Change to include more attributes
//     // sqlite3_bind_int(stmt, 1, task.getID());
//     sqlite3_bind_text(stmt, 1, task.getName().c_str(), -1, SQLITE_STATIC);

//     // Execute the statement
//     rc = sqlite3_step(stmt);
//     if (rc != SQLITE_DONE) {
//         std::cerr << "Error executing SQL statement: " << sqlite3_errmsg(db) << std::endl;
//     }

//     // Finalize the statement
//     sqlite3_finalize(stmt);
// }

void Database::writeToDatabase(std::vector<Task> taskList){
    for(Task task : taskList){
        std::cout<<task.getName()<<std::endl;
        std::string query = "INSERT INTO todo (name) VALUES (?)"; // Initializing query //Change to include more attributes
        sqlite3_stmt* stmt; // Statement pointer

        int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        // Bind parameters (id and name) to the statement ///Change to include more attributes
        // sqlite3_bind_int(stmt, 1, task.getID());
        sqlite3_bind_text(stmt, 1, task.getName().c_str(), -1, SQLITE_STATIC);

        // Execute the statement
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            std::cerr << "Error executing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        }

        // Finalize the statement
        sqlite3_finalize(stmt);
    }    
}   

std::vector<Task> Database::getAllTasks() {
    std::vector<Task> tasks;
    std::vector<int> ID; 
    std::string query = "SELECT id, name FROM todo"; // Query to select all tasks

    sqlite3_stmt* stmt; // Statement Ptr to iterate over rows
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        return tasks;
    }

    // Iterating over rows
    while (sqlite3_step(stmt) == SQLITE_ROW) { 
        // Retrieving Task attributes from row n
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* char_name = sqlite3_column_text(stmt, 1);
        std::string str_name = reinterpret_cast<const char*>(char_name);
        Task task(id,str_name); // Recreating task
        tasks.emplace_back(task); // Add the Task to the vector
    }
    sqlite3_finalize(stmt);
    return tasks;
}

void Database::clearTasks() {
    std::string query = "DELETE FROM todo"; // SQL query to delete all rows from the table

    char* errorMessage;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "Error deleting records from the database: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
}

// void Database::delTask(int id){

// }

// std::vector Database::getTasks(){

// }

