"nvimtree無効化
let g:loaded_netrw = 1
let g:loaded_netrwPlugin = 1

" エディタ基本設定
runtime! conf/basic.vim
" ファイルタイプ別のローカル設定
runtime! file_type_plugin/cpp.vim

" python
let g:python3_host_prog = expand('~/.venvs/nvim/bin/python')

" ===プラグイン===
if &compatible
 set nocompatible
endif
" Add the dein installation directory into runtimepath
set runtimepath+=~/.cache/dein/repos/github.com/Shougo/dein.vim

if dein#load_state('~/.cache/dein')
 call dein#begin('~/.cache/dein')
 call dein#add('~/.cache/dein/repos/github.com/Shougo/dein.vim')
 "call dein#add('Shougo/deoplete.nvim')
 call dein#add('jiangmiao/auto-pairs')
 call dein#add('tpope/vim-surround')
 call dein#add('neoclide/coc.nvim', {'merged': 0, 'rev': 'release'})
 call dein#add('nvim-tree/nvim-tree.lua')
 call dein#add('nvim-tree/nvim-wev-devicons')
 call dein#add('nvim-lualine/lualine.nvim')
 call dein#add('nvim-telescope/telescope.nvim', {'rev': '0.1.x'})
 if !has('nvim')
   call dein#add('roxma/nvim-yarp')
   call dein#add('roxma/vim-hug-neovim-rpc')
 endif
 call dein#end()
 call dein#save_state()
endif

filetype plugin indent on
syntax enable

" 保存時フォーマット
autocmd BufWritePre *.cpp,*.h,*.hpp,*.cc,*.c ClangFormat
command! -range=% ClangFormat execute '<line1>,<line2>!clang-format'

"coc
set statusline^=%{coc#status()}

"nvimtree
nnoremap <C-n> :NvimTreeToggle<CR>
