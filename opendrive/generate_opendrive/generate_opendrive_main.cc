#include <iostream>

#include "tinyxml2.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <xml_file_path>" << std::endl;
        return 1;
    }

    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(argv[1])!= tinyxml2::XML_SUCCESS) {
        std::cerr << "Failed to load xml file: " << argv[1] << std::endl;
        return 1;
    }
    doc.Print();
    std::cout << "Successfully loaded xml file: " << argv[1] << std::endl;

    return 0;
}