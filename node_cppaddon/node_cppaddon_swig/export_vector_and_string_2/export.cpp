#include "export.h"
#include <iostream>
std::vector<std::string> show(const std::vector<std::string>& a) {
    for (std::vector<std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
        std::cout << "at CPP:" <<*it << std::endl;
    }
    return a;
}
