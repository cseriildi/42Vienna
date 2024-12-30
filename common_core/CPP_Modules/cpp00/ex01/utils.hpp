#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>
#include <cstdio>

std::wstring 	get_data(const std::wstring& field);
int 			get_index(void);
std::wstring	trim(const std::wstring& str);
bool			valid_phone_number(const std::wstring& phoneNumber);
int				ft_atoi(const std::wstring& num);
void			reopen_stdin();
std::wstring	ft_itoa(int n);
void			print_field(const std::wstring& field, int len);
bool			has_emoji(const std::wstring& str);

#endif
