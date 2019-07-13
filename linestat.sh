find -name "*.h"\
 -or -name "*.c"\
 -or -name "*.hpp"\
 -or -name "*.cpp"\
 -or -name "*.asm"\
 -or -name "*.inc"\
 -or -name "*.cc"\
 -or -name "*.cxx"\
 -or -name "*.hh"\
 -or -name "*.hxx"\
 |xargs grep -v "^$"|wc --lines