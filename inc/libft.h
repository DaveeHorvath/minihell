/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:47:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/19 22:29:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# ifndef DEBUG_MSG
#  define DEBUG_MSG 0
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775807
# endif

# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif

# define DEBUGFD 2
# define GCRESET "\e[0m"
# define GCGEN "\e[1mGC: "
# define GCCLEAN "\e[1;36mGC: clean: "
# define GCALLOC "\e[1;34mGC: alloc: "
# define GCOBJ "\e[1;34mGC: obj: "
# define GCSWEEP "\e[1;35mGC: sweep: "
# define GCPUSH "\e[1;32mGC: push: "
# define GCPOP "\e[1;31mGC: pop: "

# define GC_START 256 
# define STACK_MAX 2048
# define E_STACKOF 23
# define E_STACKUF 24

typedef struct s_list
{
	void			*blk;
	size_t			*size;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_obj
{
	unsigned char	marked;
	size_t			blksize;
	void			*blk;
	struct s_obj	*next;
}	t_obj;

typedef struct s_vm
{
	void	*stack[STACK_MAX];
	size_t	stacksize;
	size_t	maxobjs;
	size_t	objs;
	t_obj	*head;
}	t_vm;

// is
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isspace(int c);
int		ft_isinteger(char *n);

// put
void	ft_debugmsg(char *pfx, char *f, ...);
void	ft_debugnbr(long n);
void	ft_debugunbr(unsigned long n);
void	ft_debugxnbr(unsigned long n, char f);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(const char *s, int fd);
int		ft_putendl_fd(const char *s, int fd);
int		ft_putnbr_fd(int n, int fd, int *flags);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putxnbr_fd(unsigned long n, int fd, int upper);

// to
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
long	ft_atol(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);

// nbr
size_t	ft_intlen(int n);
size_t	ft_uintlen(unsigned int n);
size_t	ft_hexlen(unsigned long n);

// str
size_t	ft_strlen(const char *s);
size_t	ft_wordcount(const char *s);
size_t	ft_strclen(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	**ft_splitstrs(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strsjoin(char const *s1, char const *s2, char sep);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strremove(const char *s, const char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strupper(char *s);
char	*ft_strlower(char *s);
char	*ft_strrev(char *s);
int		ft_contains(const char *s, char c);
int		ft_strequals(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// mem
void	ft_free(void *ptr);
void	ft_bzero(void *s, size_t n);
void	*ft_alloc(size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// lst
t_list	*ft_lstnew(void *blk);
t_list	*ft_lstdup(t_list *node);
t_list	*ft_lstpop(t_list *node);
t_list	*ft_lstpush(t_list *node);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_front(t_list **list, t_list *node);
void	ft_lstadd_back(t_list **list, t_list *node);
void	ft_lstrmnode(t_list **list, t_list *node);
void	ft_lstpushall(t_list *list);;
void	ft_lstpopall(t_list *list);

// printf
void	ft_pfsetfd(int fd);
int		ft_pfgetfd(void);
int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);
int		ft_printformat(const char **f, va_list args);
int		ft_putarg(const char **f, va_list args);
int		ft_putc(va_list args, int *flags, char format);
int		ft_putd(va_list args, int *flags);
int		ft_putu(va_list args, int *flags);
int		ft_puts(va_list args, int *flags);
int		ft_putx(va_list args, int *flags, char format);
int		ft_putp(va_list args, int *flags);
int		putpadding(int spaces, char c, int *sign, int *flags);

// gnl
char	*get_next_line(int fd);
char	*bufshift(char *buf, char *src, size_t n);
char	*bufcopy(char *buf, char **out);

// gc

/// blk
size_t	ft_getblksize(void *blk);
void	*ft_register(void *blk);

/// obj
t_obj	*ft_getobj(void *blk);
t_obj	*ft_newobj(t_vm *vm, size_t n);
void	ft_unmarkall(t_vm *vm);
void	ft_markall(t_vm *vm);

/// pop
void	*ft_pop(void);
void	ft_popall(void);
void	ft_popblk(void *blk);
void	ft_popn(size_t blks);

/// push
void	*ft_push(void *blk);
void	*ft_pusharr(void *arr);
void	ft_pushn(size_t blks, ...);

/// utils
t_vm	*ft_getvm(void);
void	ft_sweep(t_vm *vm);
void	ft_clean(void);
void	ft_exit(int estat);
int		ft_return(int rval);

#endif
