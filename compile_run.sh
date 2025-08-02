#!/bin/bash

set -e  # コンパイルや実行で失敗したらスクリプトを止める

FILENAME=${1:-main.cpp}  # 引数でファイル名指定可。デフォルトは main.cpp
EXEC=./a.out

# コンパイル
g++ -std=c++17 -Wall -Wextra -O2 -I. "$FILENAME" -o "$EXEC"

# 入力が input/0001.txt にある場合は以下のように入力ファイル指定
if [[ -f input/$(basename "$FILENAME" .cpp).txt ]]; then
    "$EXEC" < input/$(basename "$FILENAME" .cpp).txt
else
    "$EXEC"
fi
