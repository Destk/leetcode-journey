#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <fstream>
#include "task.h"
class Manager{
    private:
        int nextid{1};
        std::vector<Task> tasks{};
        Task* findTask(int id);
    public:
    Manager();
    ~Manager();
    void addTask(const std::string&  name, const std::string& text, const std::string& date);
    void removeTask(int id);
    void markTaskDone(int id);
    void listAll() const;
    void saveToFile(const std::string& filename);
    void addCommentToTask(int id, const std::string& comment);
};
#endif //MANAGER_H