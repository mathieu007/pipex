#Compiler and Linker
CC          	:= gcc

#The Target Binary Program
NAME			:= pipex
BONUS_NAME		:= pipex_bonus
COMMONS_NAME	:= commons

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR			:= src/pipex
FINDIR			:= src
BONUSDIR		:= src/bonus
COMMONSDIR		:= src/common
INCDIR			:= include
BUILDDIR		:= obj
BUILDDIR_BONUS	:= obj_bonus
BUILDDIR_COMMONS:= obj_common
TARGETDIR		:= 
SRCEXT			:= c
OBJEXT			:= o
LIBFT_DIR		:= libft
LIBFT_FILE		:= libft.a
LIBFT			:= $(LIBFT_DIR)/$(LIBFT_FILE)
INCLIBFTDEP 	:= -I$(LIBFT_DIR)/$(INCDIR)

#Flags, Libraries and Includes
CFLAGS      := -Wall -Wextra -Werror -g
LIB         := -L./$(LIBFT_DIR) -lm
# INC       := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)


SOURCES     :=  src/pipex/pipex.c	\

SRC_COMMONS :=	src/common/data.c	\
				src/common/error.c	\
				src/common/free.c	\
				src/common/process.c	\
				src/common/utils.c	\
				src/common/cmd_parse.c	\
				src/common/cmd_parse2.c	\
				src/common/fork.c	\
				src/common/open.c	\

BONUS_SRC   :=	src/bonus/get_next_line.c	\
				src/bonus/get_next_line_utils.c	\
				src/bonus/pipex_bonus.c	\

OBJECTS			:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT))) $(patsubst $(COMMONSDIR)/%,$(BUILDDIR_COMMONS)/%,$(SRC_COMMONS:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_BONUS	:= $(patsubst $(BONUSDIR)/%,$(BUILDDIR_BONUS)/%,$(BONUS_SRC:.$(SRCEXT)=.$(OBJEXT))) $(patsubst $(COMMONSDIR)/%,$(BUILDDIR_COMMONS)/%,$(SRC_COMMONS:.$(SRCEXT)=.$(OBJEXT)))

all: directories bonus $(NAME) $(BONUS_NAME)

#Remake
remake: cleaner all
	
directories:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR_BONUS)
	@mkdir -p $(BUILDDIR_COMMONS)

#Clean only Objecst
clean:
	@$(RM) -rf $(BUILDDIR)
	@$(RM) -rf $(BUILDDIR_BONUS)
	@$(RM) -rf $(BUILDDIR_COMMONS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)	

#Full Clean, Objects and Binaries
cleaner: clean
	@$(RM) -rf $(TARGETDIR)
	
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(LIBFT)
	
bonus: $(OBJECTS) $(OBJECTS_BONUS)

re:	fclean all

#Link
$(NAME): $(OBJECTS) 
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INCLIBFTDEP) $(INCDEP) -o $(NAME) $^ $(LIBFT)

$(BONUS_NAME): $(OBJECTS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INCLIBFTDEP) $(INCDEP) -o $(BONUS_NAME) $^ $(LIBFT)

$(BUILDDIR_COMMONS)/%.$(OBJEXT): $(COMMONSDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLIBFTDEP) $(INCDEP) -c -o $@ $<

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLIBFTDEP) $(INCDEP) -c -o $@ $<

$(BUILDDIR_BONUS)/%.$(OBJEXT): $(BONUSDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLIBFTDEP) $(INCDEP) -c -o $@ $<

.PHONY: bonus all remake clean cleaner resources