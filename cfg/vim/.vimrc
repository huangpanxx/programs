filetype plugin indent on
syntax on 
set nu
set sw=4
set nocp

"括号补全
:inoremap ( ()<ESC>i
:inoremap ) <c-r>=ClosePair(')')<CR>
:inoremap { {<CR>}<ESC>O
:inoremap } <c-r>=ClosePair('}')<CR>
:inoremap [ []<ESC>i
:inoremap ] <c-r>=ClosePair(']')<CR>
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
function! ClosePair(char)
 if getline('.')[col('.') - 1] == a:char
      return "\<Right>"
   else
      return a:char
   endif
endfunction



"移动到行首,
map <C-A> ^
"移动到行尾
map <C-E> $


"按Ctrl-B [保存],[编译],[运行] 当前文件
map <C-R> :call Compile()<CR>

func! Compile()
	if &filetype == 'c'
		exec "w"
		exec "! gcc % -o %< ; \ .\/%< ; rm -rf .\/%< && echo 运行完毕..."
	endif
	if &filetype == 'cpp'
		exec "w"
		exec "! g++ % -o %< ; \ .\/%< ; rm -rf .\/%< && echo 运行完毕..."
	endif
endfun

"按Ctrl-B [保存],[编译] 当前文件
map <C-B> :call Run()<CR>

func! Run()
	if &filetype == 'c'
		exec "w"
		exec "! gcc % -o %<; rm -rf .\/%<  && echo 编译完毕..."
	endif
	if &filetype == 'cpp'
		exec "w"
		exec "! g++ % -o %<; rm -rf .\/%< && echo 编译完毕..."
	endif
endfunc


