/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:38:21 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/10 21:53:35 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define TRUE 1
# define FALSE 0
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define INT_MIN_STR "-2147483648"
# define INT_MAX_STR "2147483647"

# define ABS(x) (x < 0 ? -(x) : (x))
# define SPACES1(x) (x == ' ' || x == '\t' || x == '\n')
# define SPACES2(x) (x == '\v' || x == '\r' || x == '\f')
# define ALLSPACES(x) (SPACES1(x) || SPACES2(x))
# define IS_UPPER(x) (x >= 65 && x <= 90 ? TRUE : FALSE)
# define IS_LOWER(x) (x >= 97 && x <= 122 ? TRUE : FALSE)
# define IS_DIGIT(x) (x >= 48 && x <= 57 ? TRUE : FALSE)
# define IS_ALPHA(x) ((IS_UPPER(x) || IS_LOWER(x)) ? TRUE : FALSE)
# define IS_ALNUM(x) ((IS_ALPHA(x) || IS_DIGIT(x)) ? TRUE : FALSE)
# define IS_PRINT(x) (x >= 32 && x <= 126 ? TRUE : FALSE)
# define IS_NONPRINT(x) ((x >= 0 && x <= 31) || x == 127 ? TRUE : FALSE)
# define IS_NEG(x) (x < 0 ? TRUE : FALSE)

# define FT_SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define SQR(x) (x * x)
/*
** Checks
*/
# define ERROR_CHECK(x) if (x) return (-1)
# define ZERO_CHECK(x) if (x) return (0)
# define NULL_CHECK(x) if (x) return (NULL)
# define BREAK_CHECK(x) if (x) break

#endif
