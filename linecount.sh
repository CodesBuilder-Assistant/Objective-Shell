# Please run in bash or git bash.
find . -name "*.h" -or -name -or -name "*.c" -or -name "*.hpp" -or -name "*.cpp" |xargs grep -v "^$"|wc -l
