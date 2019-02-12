# MY_LIBFT
My implementation of useful C functions.

#  list of functions:
int						ft_strlen(const char *str);

long long				ft_atoi(const char *str);

unsigned long long		ft_abs(long long nb);

int						ft_sqrt(int nb);

int						ft_strcmp(const char *s1, const char *s2);

int						get_next_line(const int fd, char **line);

int						ft_printf(const char *format, ...);

char					*ft_itoa_base_signed(long long value, int base);

char					*ft_itoa_base_unsigned(unsigned long long value, int base);
    
char					*ft_strcat(char *dest, const char *src);

char					*ft_strcpy(char *dest, const char *src);

char					*ft_strdup(const char *s);

char					*ft_strsub(char const *s, unsigned int start, size_t len);

char					*ft_strchr(const char *s, int c);

void					*ft_memcpy(void *dest, const void *src, size_t n);

void					*ft_memmove(void *dest, void *src, size_t n);

void					ft_strclr(char *s);



# Using

write make, then #include header from includes and compile with libft.a 
