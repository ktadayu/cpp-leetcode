let mapleader = " "
let maplocalleader = ","

"Editor-Settings{{{
" Encoding{{{
" Use utf-8 to overall encoding.
set encoding=utf-8
scriptencoding utf-8

" Use utf-8 when file write.
set fileencoding=utf-8

" Use file encodings when loaded.
set fileencodings=utf-8,sjis,iso-2022-jp,euc-jp
" }}}

" Automatic line feed code recognition.
set fileformats=unix,dos

"ウインドウ移動
nnoremap <silent> <C-h> <C-w>h
nnoremap <silent> <C-j> <C-w>j
nnoremap <silent> <C-k> <C-w>k
nnoremap <silent> <C-l> <C-w>l
inoremap <silent> <C-h> <Esc><C-w>h
inoremap <silent> <C-j> <Esc><C-w>j
inoremap <silent> <C-k> <Esc><C-w>k
inoremap <silent> <C-l> <Esc><C-w>l
tnoremap <silent> <C-h> <C-\><C-n><C-w>h
tnoremap <silent> <C-j> <C-\><C-n><C-w>j
tnoremap <silent> <C-k> <C-\><C-n><C-w>k
tnoremap <silent> <C-l> <C-\><C-n><C-w>l


" 全角スペースにシンタックスハイライトをかける
augroup highlightIdegraphicSpace
  autocmd!
  autocmd Colorscheme * highlight IdeographicSpace term=underline ctermbg=DarkGreen guibg=DarkGreen
  autocmd VimEnter,WinEnter * match IdeographicSpace /　/
augroup END


" VSCodeっぽく
set timeoutlen=300
set ttimeoutlen=50
nnoremap <Esc>j :m .+1<CR>==
nnoremap <Esc>k :m .-2<CR>==
inoremap <Esc>j <Esc>:m .+1<CR>==
inoremap <Esc>k <Esc>:m .-2<CR>==
             
" i to nをesc以外で
inoremap jk <Esc>

" visualで選択行をインデント
vnoremap <Tab> >gv
vnoremap <S-Tab> <gv


" 編集中ファイル名の表示
set title 
" 行番号を表示
set number
" 現在の行を強調表示
set cursorline

set smartindent
set virtualedit=onemore

set laststatus=2
" コマンドラインの補完
set wildmode=list:longest

" Tab系
" 不可視文字を可視化(タブが「▸-」と表示される)
set list listchars=tab:\▸\-
" Tab文字を半角スペースにする
set expandtab
" 行頭以外のTab文字の表示幅（スペースいくつ分）
set tabstop=2
" 行頭でのTab文字の表示幅
set shiftwidth=2
" normalでtabでインデント
nnoremap <Tab> ^i<Tab><Esc>
nnoremap <S-Tab> ^"_x
" 空白を表示
set list listchars=tab:\▸\-

"カーソル
set ruler

" 検索系
" 検索文字列が小文字の場合は大文字小文字を区別なく検索する
set ignorecase
" 検索文字列に大文字が含まれている場合は区別して検索する
set smartcase
" 検索文字列入力時に順次対象文字列にヒットさせる
set incsearch
" 検索時に最後まで行ったら最初に戻る
set wrapscan
" 検索語をハイライト表示
set hlsearch
" ESC連打でハイライト解除
nmap <Esc><Esc> :nohlsearch<CR><Esc>

colorscheme desert


