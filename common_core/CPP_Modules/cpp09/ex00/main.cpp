#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char **argv) try {
void parseInput(const char *filename) {
  std::ifstream file(filename);

  if (argc != 2) {
    std::cout << "Usage: ./btc <filename>\n";
    return 1;
  }

  std::ifstream file(argv[1]);
  if (!file)
    throw std::runtime_error("Could not open file");

  std::string line;

  bool header_checked = false;
  while (std::getline(file, line) != 0) {
    if (!header_checked) {
      header_checked = true;
      if (line == "date | value")
        continue;
    }
    BitcoinExchange::buy(line);
  }
  file.close();
  return 0;

} catch (const std::exception &e) {
  std::cerr << "Error: " << e.what() << "\n";
  return 1;
} catch (...) {
  std::cerr << "Unknown error\n";
  return 1;
}
