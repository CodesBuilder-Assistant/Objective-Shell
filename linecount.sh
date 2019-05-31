# Please run in bash or git bash.
rm line.txt
find . -name "*.h" -or -name -or -name "*.c" -or -name "*.hpp" -or -name "*.cpp" |xargs grep -v "^$"|wc -l >> line.txt
