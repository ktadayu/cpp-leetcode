#!/bin/bash
# 使用: ./solve.sh 1 two_sum

set -e

NUM="0000${1:-$(date +%m%d)}"
NUM=${NUM: -4}
NAME=$2
FNAME="${DATE}_${NAME}.cpp"
FPROB="contest/${FNAME}"
IFILE="input/${DATE}_${NAME}.txt"

#0 上書きかどうか
if [[ -f "$FPROB" ]]; then
    echo "⚠️ すでに解答しています: $FPROB"
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
      echo "解き直しを保存しました。"
      exit 0
    fi
fi

# 1. コピー
cp tmpl.cpp main.cpp

# 2. 入力ファイルがなければ作成
if [ ! -f "$IFILE" ]; then
    touch "$IFILE"
    echo "# 入力例をここに書いてください" > "$IFILE"
fi

# 3. Vimを起動して main.cpp を開く
nvim main.cpp

# 4. 作業後、保存（上書き）
cp main.cpp "contest/${FNAME}"
echo "保存しました contest/${FNAME}"
