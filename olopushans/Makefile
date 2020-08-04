NAME = uls
 
CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = inc/uls.h
 
INCS = uls.h
 
SRC = src/main.c src/mx_ls_l.c src/mx_standart_ls_links.c src/mx_analiz_input.c src/mx_make_titi.c src/mx_output_mistake1.c src/mx_free_array2.c src/mx_print_table.c src/mx_write_zero.c src/mx_read_folder.c src/mx_free_list.c src/mx_analiz_input_second.c src/mx_output_mistake2.c src/mx_convert_to_hex.c src/mx_generate_input.c src/mx_ls_l2.c src/mx_print_colum.c src/mx_max_group.c src/mx_print_total_l.c src/mx_print_size_l.c src/mx_ls_m.c src/mx_print_m.c src/mx_print_table_s.c src/mx_ls_s.c src/mx_size_bytes.c src/mx_sorting.c src/mx_output_mistake3.c
 
SRCS = main.c mx_ls_l.c mx_standart_ls_links.c mx_analiz_input.c mx_make_titi.c mx_output_mistake1.c mx_free_array2.c mx_print_table.c mx_write_zero.c mx_read_folder.c mx_free_list.c mx_analiz_input_second.c mx_output_mistake2.c mx_convert_to_hex.c  mx_generate_input.c mx_ls_l2.c mx_print_colum.c mx_max_group.c mx_print_total_l.c mx_print_size_l.c mx_ls_m.c mx_print_m.c mx_print_table_s.c mx_ls_s.c mx_size_bytes.c mx_sorting.c mx_output_mistake3.c
 
LIB = libmx/libmx.a
 
LIBS = libmx.a
 
POBJS = main.o mx_ls_l.o mx_standart_ls_links.o mx_analiz_input.o mx_make_titi.o mx_output_mistake1.o mx_free_array2.o mx_print_table.o mx_write_zero.o mx_read_folder.o mx_free_list.o mx_analiz_input_second.o mx_output_mistake2.o mx_convert_to_hex.o mx_generate_input.o mx_ls_l2.o mx_print_colum.o mx_max_group.o mx_print_total_l.o mx_print_size_l.o mx_ls_m.o mx_print_m.o mx_print_table_s.o mx_ls_s.o mx_size_bytes.o mx_sorting.o mx_output_mistake3.o
 
LOBJS = mx_printchar.o mx_print_unicode.o mx_printstr.o mx_print_strarr.o mx_printint.o mx_pow.o mx_sqrt.o mx_nbr_to_hex.o mx_hex_to_nbr.o mx_itoa.o mx_foreach.o mx_binary_search.o mx_bubble_sort.o mx_quicksort.o mx_strlen.o mx_swap_char.o mx_str_reverse.o mx_strdel.o  mx_del_strarr.o mx_get_char_index.o mx_strdup.o mx_strndup.o mx_strcpy.o mx_strncpy.o mx_strcmp.o mx_strcat.o mx_strstr.o mx_get_substr_index.o mx_count_substr.o mx_count_words.o mx_strnew.o mx_strtrim.o mx_del_extra_spaces.o mx_strsplit.o mx_strjoin.o mx_file_to_str.o mx_read_line.o mx_replace_substr.o mx_memset.o mx_memcpy.o mx_memccpy.o mx_memcmp.o mx_memchr.o mx_memrchr.o mx_memmem.o mx_memmove.o mx_realloc.o mx_create_node.o mx_push_front.o mx_push_back.o mx_pop_front.o mx_pop_back.o mx_list_size.o mx_sort_list.o mx_isspace.o mx_def_end.o mx_def_start.o mx_isdigit.o mx_isalpha.o

POBJ = src/main.o src/mx_ls_l.o src/mx_standart_ls_links.o src/mx_analiz_input.o src/mx_make_titi.o src/mx_output_mistake1.o src/mx_free_array2.o src/mx_print_table.o src/mx_write_zero.o src/mx_read_folder.o src/mx_free_list.o src/mx_analiz_input_second.o src/mx_output_mistake2.o src/mx_convert_to_hex.o src/mx_generate_input.o src/mx_ls_l2.o src/mx_print_colum.o src/mx_max_group.o src/mx_print_total_l.o src/mx_print_size_l.o src/mx_ls_m.o src/mx_print_m.o src/mx_print_table_s.o src/mx_ls_s.o src/mx_size_bytes.o src/mx_sorting.o src/mx_output_mistake3.o

OBJ_DIR = obj
all: install clean

install: 
	@make -C libmx
	@cp $(SRC) .
	@cp $(INC) .
	@cp $(LIB) .
	@mkdir -p obj
	@clang $(CFLAG) -c $(SRCS)
	@cp $(POBJS) obj
	@clang $(CFLANG) -o $(NAME) $(POBJS) -L./libmx -lmx
	
uninstall: clean
	@rm -rf $(NAME)
	@make -sC libmx uninstall

clean:
	@rm -rf $(SRCS)
	@rm -rf $(INCS)
	@rm -rf $(LIBS)
	@rm -rf ./obj
	@rm -rf $(POBJS)
	@rm -rf $(LOBJS)
	@make -sC libmx clean
	@rm -rf libmx.a __.SYMDEF\ SORTED inc/libmx.h.gch

reinstall: uninstall install

