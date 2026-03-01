#ifndef SCAN_H
#define SCAN_H
#include <string>
class Scanner{

private:
    const inline static int t{10};
public:
    bool checkPort(const std::string& ip, int port);
};

#endif //SCAN_H