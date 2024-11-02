/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:15:48 by cseriildii        #+#    #+#             */
/*   Updated: 2024/10/30 16:57:05 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdio>

void				add_contact(PhoneBook &myPhoneBook);
void				search_contact(PhoneBook &myPhoneBook);

const std::string 	get_data(const std::string& field);
int 				get_index(void);
const std::string	trim(const std::string& str);
bool				valid_phone_number(const std::string& phoneNumber);
int					ft_atoi(const std::string& num);

void				reopen_stdin();

#endif
