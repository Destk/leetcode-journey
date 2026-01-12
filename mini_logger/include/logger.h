#ifndef LOG_H
#define LOG_H
#include <fstream>
#include <string>

class logger{
    private:
        std::ofstream file;
    public:
        logger(const std::string& filename);
        void log(const std::string& message, const std::string& lvl);
        ~logger();
        
};

#endif // LOG_H