/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:30:02 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/12 18:30:03 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <wchar.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# define BUFF_SIZE  10

typedef struct	s_type
{
	char			*flags;
	int				width;
	int				prec;
	char			*size;
	char			*arg;
	char			type;
	long long int	num;
	int				base;
	int				minus;
}				t_type;
typedef struct		s_list
{
    void			*content;
    size_t			content_size;
    struct s_list	*next;
}					t_list;

typedef struct		s_t
{
    int				fd;
    char			*line;
    size_t			next_line;
    size_t			i;
    size_t			last_size;
    struct s_t		*next;
}					t_t;


typedef struct	s_file
{
    int		fd;
    char	*buff;
    int		byte;
    int		eof;
    int     feof;
    int		len;
    int		current;
    int		error;
    char	*str;
}				t_file;

typedef struct	s_storage
{
    t_file **mass;
}				t_storage;
typedef    struct        s_gnl
{
    int                fd;
    char            *str;
    struct s_gnl    *next;
}                    t_gnl;
int				get_next_line(int fd, char **temp);
void			print_str(t_type *cons);
int				ft_printf(const char *restrict format, ...);
int				get_spec(char ch);
char			get_spec_init(char ch);
int				get_flag(char ch);
int				get_size(char ch);
int				size_cmp(char *temp, char *cons);
int				parse_arg(t_type *cons, va_list list, char *temp);
void			print_ch(char *temp, int *i);
int				parse_wildcard(char *str, t_type *cons, va_list list);
int				if_snumber(t_type *cons, va_list list);
int				if_unumber(t_type *cons, va_list list);
char			*itoa_base(unsigned long long int num, int base);
void			build_arg_num(t_type *cons);
void			parse_const(const char *str, t_type *cons,
				va_list list);
int				if_string(t_type *cons, va_list list);
int				if_number(t_type *cons, va_list list);
int				if_char(t_type *cons, va_list list);
int				is_unsigned(t_type *cons);
int				is_flag(char ch);
char			*to_bighex(char *width, t_type *cons);
void			check_null(long long int temp, t_type *cons);
int				parse_wdth_s(t_type *cons, va_list list);
void			parse_base(const char *str, t_type *cons);
void			build_arg_char(t_type *cons);
char			*to_char(wchar_t *str);
char			*ft_append(char *s1, char const *s2, size_t len, size_t len2);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *fist, const char *second, size_t count);
int				ft_strcmp(const char *first, const char *second);
char			*ft_strstr(const char *str, const char *substr);
char			*ft_strnstr(const char *str, const char *substr, size_t len);
char			*ft_strchr(const char *str, int ch);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strncpy(char *dest, const char *src, size_t num);
char			*ft_strcpy(char *dest, const char *src);
void			*ft_memchr(const void *arr, int c, size_t n);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
int				ft_memcmp(const void *buf1, const void *buf2, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memccpy(void *dest, const void *src, int ch, size_t len);
void			ft_bzero(void *s, size_t len);
void			*ft_memset(void *src, int ch, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd_end(t_list **alst, t_list *new);
char			*ft_renew(char *oldstr, size_t size);
char			*ft_redup(char *src, char *str);
void			ft_lstsort(t_list *lst, void (*f)(t_list *elem, t_list *elem2));

#endif
