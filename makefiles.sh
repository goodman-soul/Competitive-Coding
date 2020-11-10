#!/bin/bash
# makefiles.sh

echo Creating File              : makefiles.sh

current_dir=$PWD
cpp_dir="$current_dir/"

len="$#"
files=0
count=0

for var in "$@"
do
    (( count++  ))
    if [[ $count = $# ]]; then
        files=$var
    elif [[ $count = $(($# - 1))  ]]; then
        cpp_dir+="$var"
    else
        cpp_dir+="$var "
    fi
done

mkdir "$cpp_dir"
echo "$cpp_dir"

cpp_file+="$cpp_dir/"
count=0
for var in "$@"
do
    (( count++  ))
    if [[ $count = $# ]]; then
        files=$var
    elif [[ $count = $(($# - 1))  ]]; then
        cpp_file+="$var"
    else
        cpp_file+="$var "
    fi
done

cpp_file+=".cpp"
touch "$cpp_file"

for i in $(seq 1 $files)
do
    touch "$cpp_dir/input$i.txt"
done
