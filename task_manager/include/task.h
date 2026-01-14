#ifndef TASK_H
#define TASK_H

#include <string>
    class Task{
        private:
            std::string name_{};
            std::string text_{};
            std::string comment_{};
            std::string deadline_{};
            int id_{};
            bool status_{};
        public:
            Task(int id,const std::string& name, const std::string& text, const std::string& deadline);
            void markDone();
            void addComment(const std::string& text);
            std::string getInfo() const;
            std::string getName() const;
            std::string getDeadline() const;
            bool isStatus() const;
            int getID() const;
    };
#endif //TASK_H