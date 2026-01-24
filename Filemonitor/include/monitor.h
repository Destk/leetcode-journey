#ifndef MONITOR_H
#define MONITOR_H
#include "fileinfo.h"
#include <string>
class Monitor{
    private:
        std::string path{};
        Fileinfo prevresult{};
        int interval{};
        bool stop{true};
    public:
        Monitor(const std::string& p);
        Monitor();
        void setPath();
        std::string GetT() const;
        void SetI();
        void run();

};
#endif //MONITOR_H