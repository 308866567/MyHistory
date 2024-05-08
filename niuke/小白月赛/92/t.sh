#!/bin/bash
# 定义生成文件的函数
generate_files() {
    local start=6
    local end=8
    
    for ((i=$start; i<=$end; i++)); do
        cp /home/xiaobingdu/code/c++/tou.cpp  "0$i.cpp"
    done
}

echo "gogogo"
# 调用函数生成文件
generate_files "file" 5 "This is a test."