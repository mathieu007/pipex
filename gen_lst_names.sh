#!/bin/bash
#the first arg
find * -type f -name "*.c" > gen_lst_names.txt
sed -i.bak "s/$(printf '\.c')/$(printf '\.c\t\n')\\\/g" gen_lst_names.txt
