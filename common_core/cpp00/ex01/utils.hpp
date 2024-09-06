/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:15:48 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/06 16:02:34 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "PhoneBook.hpp"
#include <cctype>

void		add_contact(PhoneBook &my_phonebook);
void		search_contact(PhoneBook &my_phonebook);

std::string get_data(std::string field);
int 		get_index(void);
std::string	trim(std::string str);
bool		valid_phone_number(std::string phone_number);

#endif