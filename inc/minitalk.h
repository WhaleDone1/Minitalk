/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:04 by bcarpent          #+#    #+#             */
/*   Updated: 2024/05/06 13:20:05 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../Libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_data
{
	int		i;
	int		bit;
	int		pid;
	int		verif;
	int		c_pid;
	int		s_pid;
	int		str_len;
	char	*str;
	char	*p_str;
}					t_data;

#endif
