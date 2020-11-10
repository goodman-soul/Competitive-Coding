#!/bin/bash
# cppscript.sh
echo "Executing"
main_dir=$PWD
cpp_file=${main_dir##*/}
file_path="$main_dir/$cpp_file.cpp"
g++-9 -O2 -std=c++14 -Wall -Wextra -Wshadow -Wfatal-errors -Wl,-stack_size -Wl,256000000 -DLOCAL_DEFINE "$file_path"
obj_path="$main_dir/a.out"
for input in input*.txt
do
    if ! [ -s ${input} ]
    then
        echo -e "\033[31m\xE2\x9D\x97\xE2\x9D\x97 Empty file for ${input} \033[0m"
    else
        echo -e "\033[32mRunning for ${input} \033[0m"
        b=${input:5:1}
        temp_in="$main_dir/$input"
        temp_out="$main_dir/myOutput$b.txt"
        "$obj_path" <"$temp_in" >"$temp_out"

        cat "$temp_in"
        echo -e "=================================\n"
        echo -e "\033[32mOutput for ${input} \033[0m"
        cat "$temp_out"
        echo -e "=================================\n\n\n"
    fi
done

rm ./a.out
