/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:15:48 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/07 15:48:09 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "PhoneBook.hpp"
#include <string>
#include <cstdio>

void			add_contact(PhoneBook &myPhoneBook);
void			search_contact(PhoneBook &myPhoneBook);
std::string 	get_data(const std::string& field);
int 			get_index(void);
std::string		trim(const std::string& str);
bool			valid_phone_number(const std::string& phoneNumber);
int				ft_atoi(const std::string& num);
void			reopen_stdin();

#endif
