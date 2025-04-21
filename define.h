/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:53:16 by lagea             #+#    #+#             */
/*   Updated: 2025/04/21 15:06:16 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DEFINE_H__
# define __DEFINE_H__

# define BUFFER_SIZE 10000
# define ERROR_PRINTF "ft_printf: works for stdout and stderr only, 1 or 2"

// Fucntion macros
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define DIFF(x, y) ABS((x) - (y))
# define SIGN(x) ((x) < 0 ? -1 : (x) > 0 ? 1 : 0)
# define IS_EVEN(x) ((x) % 2 == 0 ? 1 : 0)
# define IS_ODD(x) ((x) % 2 != 0 ? 1 : 0)
# define RAD_TO_DEG(x) ((x) * 180.0 / M_PI)
# define DEG_TO_RAD(x) ((x) * M_PI / 180.0)
# define SWAP(a, b) { \
    __typeof__(a) tmp = a; \
    a = b; \
    b = tmp; \
}
# define FREE(ptr) { \
    free(ptr); \
    ptr = NULL; \
}
 
#endif