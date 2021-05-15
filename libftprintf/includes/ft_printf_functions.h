/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:45:53 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/25 15:33:11 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FUNCTIONS_H
# define FT_PRINTF_FUNCTIONS_H

/*
** BUFFER
*/
t_buffer	*init_buffer(t_buffer *buffer);
t_buffer	*check_data_len(t_buffer **buffer);
int			add_char_buffer(t_buffer **buff, char c);
int			add_str_buffer(t_buffer **buff, char *str);
int			add_char_last_pos_buffer(t_buffer **buff, char c);

/*
** PARSER
*/
t_parsing	*parse_format(const char **format, va_list *args);
void		parse_flags(const char **format, va_list *args, t_parsing *parsing);
void		parse_star(va_list *args, t_parsing *parsing);
void		parse_conv(char format, t_parsing *parsed);

/*
** UTILS
*/
t_parsing	*init_parsing_struct(t_parsing *parsed);
char		*add_char_to_str(char *str, char c);
char		*conv_to_hex(long nbr, char *hex);
int			conv_is_num(short	conv);
int			is_converter(char c);

/*
** TREAT CONV
*/
int			treat_conv(t_buffer **buffer, t_parsing *parsed, va_list *args);
int			call_conv(t_buffer **buffer, t_parsing *parsed, va_list *args);
int			call_flags(t_buffer **buffer, t_parsing *parsed);

/*
** CONVERSION
*/
int			conv_c(t_buffer **buffer, va_list *args);
int			conv_s(t_buffer **buffer, va_list *args);
int			conv_d(t_buffer **buffer, va_list *args);
int			conv_p(t_buffer **buffer, va_list *args);
int			conv_percent(t_buffer **buffer);
int			conv_u(t_buffer **buffer, va_list *args);
int			conv_x(t_buffer **buffer, va_list *args, char *hex);

/*
** FLAGS
*/
int			treat_precision(t_buffer **buffer, t_parsing *parsed);
int			precision_number(t_buffer **buffer, t_parsing *parsed);
int			precision_str(t_buffer **buffer, t_parsing *parsed);
int			treat_min_width(t_buffer **buffer, t_parsing *parsed);
int			treat_left_padded(t_buffer **buffer, t_parsing *parsed);
int			treat_zero_padded(t_buffer **buffer, t_parsing *parsed);

#endif
