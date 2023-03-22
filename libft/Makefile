NAME = libft.a

SRC	=	src/alloc_pool/data_pool.c	\
		src/ft_atoi.c	\
		src/ft_atoi_long.c	\
		src/ft_bzero.c	\
		src/ft_calloc.c	\
		src/ft_exponent.c	\
		src/ft_strchrlast.c	\
		src/ft_isalnum.c	\
		src/ft_isalpha.c	\
		src/ft_isascii.c	\
		src/ft_isdigit.c	\
		src/ft_isprint.c	\
		src/ft_itoa.c	\
		src/ft_itoa_temp.c	\
		src/ft_log2_64.c	\
		src/ft_max.c	\
		src/ft_memchr.c	\
		src/ft_memcmp.c	\
		src/ft_memcpy.c	\
		src/ft_memmove.c	\
		src/ft_memset.c	\
		src/ft_min.c	\
		src/ft_putchar_fd.c	\
		src/ft_putendl_fd.c	\
		src/ft_putnbr_fd.c	\
		src/ft_putstr.c	\
		src/ft_putstr_fd.c	\
		src/ft_split.c	\
		src/ft_split_many.c	\
		src/ft_split_many_temp.c	\
		src/ft_split_temp.c	\
		src/ft_strchr.c	\
		src/ft_strdup.c	\
		src/ft_strcpy.c	\
		src/ft_striteri.c	\
		src/ft_strjoin.c	\
		src/ft_strjoin_temp.c	\
		src/ft_strstarwith.c	\
		src/ft_streq.c	\
		src/ft_strlcat.c	\
		src/ft_strlcpy.c	\
		src/ft_strncpy.c	\
		src/ft_strlen.c	\
		src/ft_strmapi.c	\
		src/ft_strncmp.c	\
		src/ft_strnstr.c	\
		src/ft_strrchr.c	\
		src/ft_strtrim.c	\
		src/ft_substr.c	\
		src/ft_tolower.c	\
		src/ft_toupper.c	\
		src/ft_replace_temp.c	\
		src/ft_substr_temp.c	\
		src/ft_count_char.c	\
		src/memory/memory_pool.c	\
		src/memory/memory_pool_resize.c	\
		src/temp_pool.c	\

SRC_BONUS =	src/bonus/ft_lstadd_back.c	\
			src/bonus/ft_lstadd_front.c	\
			src/bonus/ft_lstclear.c	\
			src/bonus/ft_lstdelone.c	\
			src/bonus/ft_lstiter.c	\
			src/bonus/ft_lstlast.c	\
			src/bonus/ft_lstmap.c	\
			src/bonus/ft_lstnew.c	\
			src/bonus/ft_lstsize.c	\
			
SRC_LST =	src/lst/_lst_group_by_add.c	\
			src/lst/_lst_group_by_internal.c	\
			src/lst/_lst_group_by_new.c	\
			src/lst/func/inc_ptr.c	\
			src/lst/func/params1.c	\
			src/lst/func/params2.c	\
			src/lst/func/to_char.c	\
			src/lst/func/to_int.c	\
			src/lst/func/to_long.c	\
			src/lst/func/to_short.c	\
			src/lst/func/to_str.c	\
			src/lst/internal/lst_free_data_internal.c	\
			src/lst/internal/lst_free_internal.c	\
			src/lst/internal/lst_new_internal.c	\
			src/lst/lst_add.c	\
			src/lst/lst_copy.c	\
			src/lst/lst_filter.c	\
			src/lst/lst_filter_avg.c	\
			src/lst/lst_filter_count.c	\
			src/lst/lst_filter_exclude.c	\
			src/lst/lst_filter_first.c	\
			src/lst/lst_filter_get_next.c	\
			src/lst/lst_filter_get_nth.c	\
			src/lst/lst_filter_include.c	\
			src/lst/lst_filter_index_of.c	\
			src/lst/lst_filter_indices.c	\
			src/lst/lst_filter_last.c	\
			src/lst/lst_filter_max.c	\
			src/lst/lst_filter_min.c	\
			src/lst/lst_filter_range.c	\
			src/lst/lst_filter_sum.c	\
			src/lst/lst_firts.c	\
			src/lst/lst_free.c	\
			src/lst/lst_get.c	\
			src/lst/lst_get2.c	\
			src/lst/lst_get_alloc_size.c	\
			src/lst/lst_group_by.c	\
			src/lst/lst_group_by_get.c	\
			src/lst/lst_insert.c	\
			src/lst/lst_int_to_bool_array.c	\
			src/lst/lst_last.c	\
			src/lst/lst_new.c	\
			src/lst/lst_new_item.c	\
			src/lst/lst_order_by.c	\
			src/lst/lst_remove.c	\
			src/lst/lst_replace.c	\
			src/lst/lst_reset.c	\
			src/lst/lst_reverse.c	\
			src/lst/lst_reverse_select.c	\
			src/lst/lst_rotate.c	\
			src/lst/lst_select.c	\
			src/lst/lst_sequence_equal.c	\
			src/lst/lst_swap.c	\
			src/lst/lst_to_array.c	\
			src/lst/lst_to_array2.c	\
			src/lst/lst_utils_internal.c	\
			src/lst/lst_utils_internal2.c	\
			src/lst/utils.c	\

LST_SRCDIR		= src/lst
BONUS_SRCDIR	= src/bonus
SRCDIR			= src
INCDIR			= include
BUILDDIR		= obj
BUILDDIR_LST	= obj_lst
BUILDDIR_BONUS	= obj_bonus
TARGETDIR		= bin
SRCEXT			= c
OBJEXT			= o

OBJS 		= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRC:.$(SRCEXT)=.$(OBJEXT)))
OBJS_BONUS	= $(patsubst $(BONUS_SRCDIR)/%,$(BUILDDIR_BONUS)/%,$(SRC_BONUS:.$(SRCEXT)=.$(OBJEXT)))
LST_OBJS	= $(patsubst $(LST_SRCDIR)/%,$(BUILDDIR_LST)/%,$(SRC_LST:.$(SRCEXT)=.$(OBJEXT)))

CC		= gcc
INCDEP	= -I$(INCDIR)
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf
AR		= ar crs

all: directories $(NAME) bonus lst

directories:
	mkdir -p $(TARGETDIR)
	mkdir -p $(BUILDDIR)
	mkdir -p $(BUILDDIR_LST)
	mkdir -p $(BUILDDIR_BONUS)

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^
	
lst: $(LST_OBJS)
	$(AR) $(NAME) $^

clean:
	$(RM) -rf $(BUILDDIR)
	$(RM) -rf $(BUILDDIR_LST)
	$(RM) -rf $(BUILDDIR_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

$(LST_OBJS): $(BUILDDIR_LST)/%.o: $(LST_SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCDEP) -c $< -o $@

$(OBJS_BONUS): $(BUILDDIR_BONUS)/%.o: $(BONUS_SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCDEP) -c $< -o $@ 

$(OBJS): $(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCDEP) -c $< -o $@

$(NAME): $(OBJS) $(LST_OBJS) $(BONUS_OBJS)
	@$(AR) $@ $^

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(AR) $@ $<

$(BUILDDIR_LST)/%.$(OBJEXT): $(LST_SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(AR) $@ $<
	
$(BUILDDIR_BONUS)/%.$(OBJEXT): $(BONUS_SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(AR) $@ $<

.PHONY: bonus lst all clean fclean re
