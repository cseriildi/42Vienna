#pragma once

#include <map>
#include <string>

typedef std::map<std::string, float> Database;
class BitcoinExchange {

public:
  static float getExchangeRate(const std::string &date);
  static void buy(const std::string &line);

private:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  static Database parseDatabase();

  static const char *_databaseFilename;
  static const Database _database;
};
