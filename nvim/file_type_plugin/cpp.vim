" ===C++向けの設定===
set makeprg=g++\ -std=c++17\ -Wall\ -Wextra\ -O2\ -o\ a.out\ %\ &&\ ./a.out
nnoremap <silent> <C-n> :cnext<CR>
nnoremap <silent> <C-p> :cprev<CR>
nnoremap <F5> :w<CR>:!./compile_run.sh %<CR>


