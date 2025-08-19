#!/bin/bash
# 使用: try two_sum

set -e

NAME=$1
FNAME="${NAME}.cpp"
FPROB="samples/${FNAME}"

#0 上書きかどうか
if [[ -f "$FPROB" ]]; then
    echo "⚠️ すでに作成済です: $FPROB"
    echo -n "新規作成？ (y/n): "
    read yn
    if [[ "$yn" == "y" ]]; then
        cp tmpl.cpp main.cpp
        nvim main.cpp
        cp main.cpp "$FPROB"
        echo "編集のみ完了（上書きなし）"
        exit 0
    else
      nvim "$FPROB"
      echo "${FNAME}を保存しました。"
      exit 0
    fi
fi

# 1. コピー
cp tmpl.cpp main.cpp

# 2. Vimを起動して main.cpp を開く
nvim main.cpp

# 3. 作業後、保存（上書き）
cp main.cpp "samples/${FNAME}"
echo "保存しました samples/${FNAME}"
