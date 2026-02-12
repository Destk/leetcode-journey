#ifndef SCAN_H
#define SCAN_H

#include <string>
class Scanner{
    public:
        bool checkPort(const std::string& ip, int port);
};
#endif //SCAN_H