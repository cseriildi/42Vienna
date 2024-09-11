/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:15:48 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/11 19:21:48 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void				add_contact(PhoneBook &myPhoneBook);
void				search_contact(PhoneBook &myPhoneBook);

const std::string 	get_data(const std::string& field);
int 				get_index(void);
const std::string	trim(const std::string& str);
bool				valid_phone_number(const std::string& phoneNumber);
int					ft_atoi(const std::string& num);

#endif