/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_constants.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:43:56 by atrouill          #+#    #+#             */
/*   Updated: 2020/06/11 16:33:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONSTANTS_H
# define FT_PRINTF_CONSTANTS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

# define FLAG_0_PADDED	1
# define FLAG_L_PADDED  2
# define FLAG_PRECISION 4

# define CONV_CHAR      1
# define CONV_STR       2
# define CONV_PTR       4
# define CONV_INT       8
# define CONV_UNSIGNED  16
# define CONV_HEX       32
# define CONV_HEX_MAJ   64
# define PRINT_PERCENT  128

#endif
