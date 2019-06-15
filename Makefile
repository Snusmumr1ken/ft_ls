##########################################################
#                                                        #
#             Makefile is created by anyvchyk            #
#                   for ft_ls project                    #
#                                                        #
##########################################################

#############           Varaibles            #############
#                                                        #
FILES = main help argument_parsing work_with_lists

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))

INC = -I ./includes
HEADER = ./includes/libls.h
LIBFT = ./my_libft/libft.a

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror
#                                                        #
##########################################################

#############              Rules             #############
#                                                        #
all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all clean fclean re

$(NAME): $(OBJ) $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): obj/%.o : src/%.c $(HEADER) $(LIBFT)
	@gcc -o $@ $(INC) -c $<

$(LIBFT):
	@make -C ./my_libft

libft_clean:
	@make -C ./my_libft clean

libft_fclean:
	@make -C ./my_libft fclean

clean: libft_clean
	@rm -rf $(OBJ)

fclean: libft_fclean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all
#                                                        #
##########################################################
