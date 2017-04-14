/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:27:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 13:09:40 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define NO_EXIT 0
# define EXIT 1
# define NO_EXIT 0
# define UNDEFINED 0
# define MALLOC 1
# define INIT 2
# define OPEN 3
# define CLOSE 4
# define ARGUMENT 5
# define PARSING 6
# define EXTENSION 7

void			error_parse(char *file, char *error, int line);
void			error_extension(char *file, int close);
void			error_arg(int line, int arg, int close);
void			error(int error, int line, char *file, int close);
void			err(char *file, int line, char *message, int close);
#endif
