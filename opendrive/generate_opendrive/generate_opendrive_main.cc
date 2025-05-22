#include <iostream>

#include "sqlite3.h"
#include "tinyxml2.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <xml_file_path>" << std::endl;
    return 1;
  }

  tinyxml2::XMLDocument doc;
  if (doc.LoadFile(argv[1]) != tinyxml2::XML_SUCCESS) {
    std::cerr << "Failed to load xml file: " << argv[1] << std::endl;
    return 1;
  }
  doc.Print();
  std::cout << "Successfully loaded xml file: " << argv[1] << std::endl;

  sqlite3* db = nullptr;
  if (sqlite3_open("./data/example.sqlite", &db) != SQLITE_OK) {
    std::cerr << "Failed to open sqlite3 database" << std::endl;
    return 1;
  }
  sqlite3_stmt* stmt = nullptr;
  std::cout << "Print COMPANY table:" << std::endl;
  if (sqlite3_prepare_v2(db, "SELECT * FROM COMPANY", -1, &stmt, nullptr) ==
      SQLITE_OK) {
    while (sqlite3_step(stmt) == SQLITE_ROW) {
      const auto id = sqlite3_column_int(stmt, 0);
      const auto name = sqlite3_column_text(stmt, 1);
      const auto age = sqlite3_column_int(stmt, 2);
      const auto address = sqlite3_column_text(stmt, 3);
      const auto salary = sqlite3_column_double(stmt, 4);
      std::cout << "id: " << id << ", name: " << name << ", age: " << age
                << ", address: " << address << ", salary: " << salary
                << std::endl;
    }
    sqlite3_finalize(stmt);
  } else {
    std::cerr << "Failed to execute SELECT statement: SELECT * FROM COMPANY"
              << std::endl;
    return 1;
  }
  std::cout << "Print DEPARTMENT table:" << std::endl;
  if (sqlite3_prepare_v2(db, "SELECT * FROM DEPARTMENT", -1, &stmt, nullptr) ==
      SQLITE_OK) {
    while (sqlite3_step(stmt) == SQLITE_ROW) {
      const auto id = sqlite3_column_int(stmt, 0);
      const auto dept = sqlite3_column_text(stmt, 1);
      const auto emp_id = sqlite3_column_int(stmt, 2);
      std::cout << "id: " << id << ", dept: " << dept << ", emp_id: " << emp_id
                << std::endl;
    }
    sqlite3_finalize(stmt);
  } else {
    std::cerr << "Failed to execute SELECT statement: SELECT * FROM DEPARTMENT"
              << std::endl;
    return 1;
  }

  sqlite3_close(db);

  return 0;
}