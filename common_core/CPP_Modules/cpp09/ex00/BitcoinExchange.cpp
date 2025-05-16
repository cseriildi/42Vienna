#include "../colors.hpp"

#include "BitcoinExchange.hpp"
#include "utils.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>

const char *BitcoinExchange::_databaseFilename = "data.csv";
const Database BitcoinExchange::_database = parseDatabase();

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {(void)other;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	(void)other;
	return *this;
}

//This should not throw
//The init of the static const database happens before the main
Database BitcoinExchange::parseDatabase()
{
	Database database;

	std::ifstream file(_databaseFilename);
	
	if (!file.is_open()) {
		std::cerr << "Could not open database file\n";
		return database;
	}

	std::string line;
	bool header_checked = false;

	while (std::getline(file, line) != 0)
	{
		if (!header_checked) {
			header_checked = true;
			if (line == "date,exchange_rate")
				continue;
		}

		std::istringstream iss(line);
		std::string date;
		std::string rateStr;

		std::getline(iss, date,  ',');
		std::getline(iss, rateStr);
		if (!is_valid_date(date) || !is_valid_value(rateStr)) {
			std::cerr << RED "Error during database parsing:\nInvalid database format, this line is ignored: " + line + RESET "\n";
			continue;
		}
		try {
			float rate = sto<float>(rateStr);
			if (rate < 0)
			{
				std::cerr << RED "Error during database parsing:\nRate can't be negative, this line is ignored: " + line + RESET "\n";
				continue;
			}
			database[date] = rate;
		}
		catch (const std::bad_cast &e){
			std::cerr << RED "Error during database parsing:\nInvalid rate, this line is ignored: " + line + RESET "\n";
			continue;
		}
	}

	file.close();
	return database;
}

float BitcoinExchange::getExchangeRate(const std::string &date)
{
	Database::const_iterator it = _database.lower_bound(date);
	if (it->first == date)
		return it->second;
	if (it == _database.begin())
		throw std::runtime_error("Date too early");
	
	return (--it)->second;
}

void BitcoinExchange::buy(const std::string& line)
{
	std::istringstream iss(line);
	std::string date;
	std::string valueStr;
	std::getline(iss, date, '|');
	std::getline(iss, valueStr);

	if (date.empty() || *(date.end() - 1) != ' ' || *valueStr.begin() != ' ' )
		throw std::runtime_error("Use \"date | value\" format");
	trim_values(date, valueStr);
	if (!is_valid_date(date))
		throw std::runtime_error("bad input => " + date);
	if (!is_valid_value(valueStr))
		throw std::runtime_error("bad input => " + valueStr);

	if (!is_less_than_1000(valueStr))
		throw std::runtime_error("too large a number => " + valueStr);
	
	try {
		float rate = sto<float>(valueStr);
		if (rate < 0)
			throw std::runtime_error("not a positive number => " + valueStr);
			
		std::cout << date << " => " << rate << " = " << rate * getExchangeRate(date) << "\n";
	}
	catch (const std::bad_cast &e){
		throw std::runtime_error("invalid rate => " + valueStr);
	}
}
