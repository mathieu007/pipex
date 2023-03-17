/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:03:23 by math              #+#    #+#             */
/*   Updated: 2023/03/16 08:20:25 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# define MAX_PARAMS_DATA 1000
# define TEMP_SORT_DATA 1000000
# define FIXED_DATA_SIZE 1000000
# define TEMP_MAX_GROUP_BY_DATA 10000
# define TEMP_MAX_GROUP_BY_CLAUSES 100

# include "libft.h"
# include "lst.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_lst
{
	int32_t		_capacity;
	int32_t		_count;
	int32_t		_size;
	int32_t		_offset;
	void		*(*_alloc)(struct s_lst *lst, size_t size_in_byte);
	bool		_is_static;
	void		*(*_free)(struct s_lst *lst);
	void		*(*_free_data)(void *data);
	uint8_t		*data;
}				t_lst;

typedef struct s_group_by
{
	int32_t		_array_length;
	int32_t		_group_count;
	t_lst		**data;
	t_lst		*positions;
}				t_group_by;

typedef enum e_type
{
	T_STRUCT,
	T_LST,
	T_LST_STRING,
	T_STRING
}				t_type;

typedef struct s_params
{
	int64_t		_data;
	uint64_t	_udata;
	int32_t		_elem_size;
	bool		_is_ptr;
	bool		_is_signed;
}				t_params;

void			*p_uchar(uint8_t p);
void			*p_char(int8_t p);
void			*p_uint(uint32_t p);
void			*p_int(int32_t p);
void			*p_ulong(uint64_t p);
void			*p_long(int64_t p);
void			*p_ushort(uint16_t p);
void			*p_short(int16_t p);
void			*p_bool(bool p);

int8_t			to_char(void *p);
uint8_t			to_uchar(void *p);
int16_t			to_short(void *p);
uint16_t		to_ushort(void *p);
uint32_t		to_uint(void *p);
int64_t			to_long(void *p);
uint64_t		to_ulong(void *p);
char			*to_str(void *p);

bool			initialize(void);

t_lst			*lst_new_temp(int32_t array_size,
					int32_t size_of_elem);
t_lst			*lst_new_fixed(int32_t array_size,
					int32_t size_of_elem);
t_lst			*lst_new(int32_t array_elem_count,
					int32_t size_of_inner_elem);
t_lst			*lst_new_static(void *data, int32_t max_capacity,
					size_t size_of_elem);

int32_t			lst_filter_index_of(t_lst *lst, bool (*conds)(void *item,
						void *values), void *values);
t_lst			*lst_replace(t_lst *lst, int32_t index, void *ptr);
t_lst			*lst_add(t_lst *lst, void *ptr);
t_lst			*lst_insert(t_lst *lst, int32_t index, void *item);
t_lst			*lst_remove_at(t_lst *lst, int32_t index);
t_lst			*lst_rotate_left(t_lst *lst, int32_t elem_count);
t_lst			*lst_rotate_right(t_lst *lst, int32_t elem_count);
void			*lst_to_array_fixed(t_lst *lst);
void			*lst_to_array_temp(t_lst *lst);
void			*lst_to_array_static(t_lst *lst, void *dst);
void			*lst_to_array(t_lst *lst);
void			*lst_last(t_lst *lst);
void			*lst_first(t_lst *lst);

int32_t			lst_filter_last_index_of(t_lst *lst,
					bool (*conditions)(void *item,
						void *values),
					void *values);

void			*lst_filter_last(t_lst *lst, bool (*conditions)(t_lst *lst,
						int32_t index, void *values), void *values);
int64_t			lst_filter_sum(t_lst *lst, int64_t (*select)(t_lst *lst,
						int32_t index));
int64_t			lst_filter_avg(t_lst *lst, int64_t (*select)(t_lst *lst,
						int32_t index));
void			*lst_filter_first(t_lst *lst, bool (*conditions)(t_lst *lst,
						int32_t index, void *val), void *val);
void			*lst_filter_min(t_lst *lst, int32_t (*comparer)(t_lst *lst,
						int32_t index, int32_t prev));
int32_t			lst_filter_min_index(t_lst *lst,
					int32_t (*comparer)(t_lst *lst, int32_t index,
						int32_t prev));
int32_t			lst_filter_count(t_lst *lst, bool (*filter)(void *item1,
						void *values), void *values);
void			*lst_filter_max(t_lst *lst, void *(*comparer)(void *item1,
						void *item2));
int32_t			lst_filter_max_index(t_lst *lst,
					void *(*comparer)(void *first, void *second));
bool			lst_sequence_equal(t_lst *lst,
					t_lst *to_compare);
bool			lst_sequence_equal_ptr(t_lst *lst,
					bool (*comparer)(t_lst *lst, int32_t index,
						t_lst *to_compare),
					t_lst *to_compare);
int32_t			*lst_sel_int_to_array_temp(t_lst *lst,
					int32_t (*select)(t_lst *lst,
						int32_t index));
t_lst			*lst_select_int(t_lst *lst,
					int32_t (*select)(void *item));
t_lst			*lst_select(t_lst *lst,
					void *(*select)(void *item),
					size_t size_of_elem);
const void		*lst_get_array(t_lst *lst);
int32_t			*lst_sel_int_to_array_fixed(t_lst *lst,
					int32_t (*select)(t_lst *lst,
						int32_t index));
t_lst			*lst_select_to_lst_temp_pool(t_lst *lst,
					void *(*select)(t_lst *lst, int32_t index),
					size_t size_of_elem);
void			*lst_filter_get_next(t_lst *lst,
					bool (*conditions)(t_lst *lst, int32_t index,
						void *values),
					void *values,
					int32_t start_index);
void			*lst_filter_get_nth(t_lst *lst,
					bool (*conditions)(t_lst *lst, int32_t index,
						void *values),
					void *values,
					int32_t nth_item);
t_lst			*lst_order_by(t_lst *lst, int32_t (*comparer)(t_lst *lst,
						int32_t index, int32_t prev));
t_lst			*lst_filter_range(t_lst *lst, int32_t start_index,
					int32_t count);
t_lst			*lst_filter_range_temp(t_lst *lst, int32_t start_index,
					int32_t count);
t_lst			*lst_filter_range_fixed(t_lst *lst, int32_t start_index,
					int32_t count);

void			*lst_free(t_lst *lst);
void			lst_swap(t_lst *lst, int32_t index, int32_t index2,
					int32_t elem_count);

t_lst			*_internal_resize_temp(t_lst *lst, int32_t elem_count);
t_lst			*_internal_resize(t_lst *lst, int32_t elem_count);
t_lst			*_internal_resize_insert(t_lst *lst, int index,
					int32_t elem_count);
t_lst			*_internal_resize_insert_temp(t_lst *lst, int32_t index,
					int32_t elem_count_to_insert);
t_group_by		*_internal_group_by_resize_temp(t_group_by *grp,
					int32_t group_count_to_add);

uint8_t			*lst_data(t_lst *lst, int32_t index);
void			*lst_get(t_lst *lst, int32_t index);
void			**lst_addr_ptr(t_lst *lst, int32_t index);
void			*lst_addr(t_lst *lst, int32_t index);
uint8_t			*temp_sort_pool(int32_t size_in_bytes);

t_lst			*lst_copy(t_lst *lst);
t_lst			*lst_copy_fixed(t_lst *lst);
t_lst			*lst_copy_temp(t_lst *lst);
t_lst			**group_by_data_pool(int32_t num_group);
t_group_by		*group_by_clause_pool(void);
t_group_by		*_lst_group_by_new_temp(int32_t group_count);
t_group_by		*_lst_group_by_add_temp(t_group_by *grp, t_lst *lst);
t_lst			*lst_group_by_get_at(t_group_by *grp, int32_t index);
t_group_by		*lst_group_by(t_lst *lst, bool (*comparer)(t_lst *lst,
						int32_t index, int32_t prev_index));
int32_t			lst_filter_index_of_start_at(t_lst *lst,
					bool (*conditions)(t_lst *lst,
						int32_t index,
						void *values),
					int32_t start_index,
					void *values);
int32_t			lst_get_int(t_lst *lst, int32_t index);
int32_t			*lst_addr_int_ptr(t_lst *lst, int32_t index);
t_lst			*lst_add_int(t_lst *lst, int32_t value);
t_lst			*lst_reverse_select(t_lst *lst,
					void *(*select)(t_lst *lst,
						int32_t index));
int32_t			*lst_reverse_select_int(t_lst *lst,
					int32_t (*select)(t_lst *lst,
						int32_t index));
bool			*lst_int_to_bool_array(t_lst *lst, int32_t len, bool reverse);
t_lst			*lst_filter_exclude(t_lst *lst, t_lst *exclude_indices);
t_lst			*lst_filter_exclude_temp(t_lst *lst,
					t_lst *exclude_indices);
t_lst			*lst_filter_exclude_fixed(t_lst *lst,
					t_lst *exclude_indices);

t_lst			*lst_rev_to_lst_fixed(t_lst *lst);
t_lst			*lst_reverse(t_lst *lst);

t_lst			*lst_filter_fixed(t_lst *lst, bool (*match_item)(t_lst *lst,
						int32_t index, void *values), void *values);
t_lst			*lst_filter_temp(t_lst *lst, bool (*match_item)(t_lst *lst,
						int32_t index, void *values), void *values);
t_lst			*lst_filter(t_lst *lst, bool (*match_item)(void *item,
						void *values), void *values);
t_lst			*_internal_resize_insert_pool(t_lst *lst,
					int32_t index,
					int32_t elem_count_to_insert);
bool			_lst_can_add(t_lst *lst, int32_t elem_count);
int32_t			_lst_offset(t_lst *lst, int32_t index);
void			*_lst_addr_offset(t_lst *lst, int32_t offset);
int32_t			_lst_offset_mid(t_lst *lst, int32_t offset);
int32_t			_lst_index_mid(t_lst *lst, int32_t offset);
void			*_lst_addr_mid(t_lst *lst, int32_t offset);

void			*p_values(size_t size);
void			*inc_ptr(void *p, size_t byte_size);
t_lst			*lst_filter_include(t_lst *lst, t_lst *include_indices);
const int32_t	*lst_get_int_array(t_lst *lst);
int32_t			*lst_to_int_array_temp(t_lst *lst);
t_lst			*lst_insert_int(t_lst *lst, int32_t index, int32_t item);
int32_t			to_int(void *p);

void			*_malloc(t_lst *lst, size_t size);
void			*_alloc_static(t_lst *lst, size_t size);
void			*_alloc_temp(t_lst *lst, size_t size);
void			*_alloc_fixed(t_lst *lst, size_t size);

void			*_free_malloc(t_lst *lst);
void			*_free_fixed(t_lst *lst);
void			*_free_temp(t_lst *lst);
void			*_free_static(t_lst *lst);

void			*_free_data_malloc(void *data);
void			*_free_data_fixed(void *data);
void			*_free_data_temp(void *data);
void			*_free_data_static(void *data);

t_lst			*lst_copy_data(t_lst *src, t_lst *dst);
t_lst			*lst_reset(t_lst *lst);
int32_t			lst_get_alloc_size(t_lst *lst);
void			*lst_new_item(void *static_data, int32_t index,
					size_t size_of_elem);
t_lst			*lst_copy_static(t_lst *lst, void *data,
					int32_t data_elem_count);
t_lst			*lst_reverse_int(t_lst *lst);
void			*copy_temp(void *obj, size_t size_in_bytes);
int32_t			*to_ints(void *p);
void			*p_int2(int32_t value, int32_t value2);
t_lst			*lst_filter_indices(t_lst *lst,
					bool (*match_item)(void *item, void *values),
					void *values);
t_lst			*lst_remove_at_end(t_lst *lst, int32_t count);
void			*lst_free_to_array(t_lst *lst);
bool			ft_streq(const char *s1, const char *compare);

#endif
