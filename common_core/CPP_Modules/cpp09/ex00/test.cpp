#include "BitcoinExchange.hpp"

void test(void) {
  BitcoinExchange::buy("2000-01-01 | 1");
  BitcoinExchange::buy("2025-06-30 | 1");
  BitcoinExchange::buy("2025-06-31 | 1");
  BitcoinExchange::buy("2024-02-29 | 1"); // %4=0, %100!=0,
  BitcoinExchange::buy("2021-02-29 | 1"); // %4!=0
  BitcoinExchange::buy("3000-02-29 | 1"); // %4=0, %100=0, %400!=0
  BitcoinExchange::buy("4000-02-29 | 1"); // %4=0, %100=0, %400=0

  BitcoinExchange::buy("2025-06-30| 1");
  BitcoinExchange::buy("2025-06-30 |1");
  BitcoinExchange::buy("2025-06-30 | 1 ");
  BitcoinExchange::buy(" 2025-06-30 | 1");
  BitcoinExchange::buy("2025-06-30 | 1 | 2");
  BitcoinExchange::buy("2025-06-30 ");

  BitcoinExchange::buy("2025-06-30 | 1.0.0");
  BitcoinExchange::buy("2025-06-30 | .1");
  BitcoinExchange::buy("2025-06-30 | 1.");
  BitcoinExchange::buy("2025-06-30 | -0.000000000000000000001");
  BitcoinExchange::buy("2025-06-30 | 1000");
  BitcoinExchange::buy("2025-06-30 | 1000.000000000000000000001");
  BitcoinExchange::buy("2025-06-30 | 1001");
}
