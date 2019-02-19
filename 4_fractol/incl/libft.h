/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:50:43 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 22:48:53 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define BUFF_SIZE 64

typedef	struct	s_bufs
{
	int			fd;
	char		*buf;
}				t_bufs;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnstr_fd(char const *s, size_t n, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

int				ft_gnl(int fd, char **line);
#endif
