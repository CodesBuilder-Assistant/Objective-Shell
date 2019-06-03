#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <io.h>
#elif defined(__linux)
#include <dirent.h>
#endif
using namespace std;
/*
* Detectable language list:
* C/C++
* Assembly
* Objective-C/C++
* Shell(sh,bash,zsh)
* JavaScript
* TypeScript
* Makefile
* CMake
* GitIgnore
* Markdown
* Latex
* HTML
*/
char *cpp[]={"*.c","*.cpp","*.cc","*.cxx","*.h","*.hpp","*.hxx","*.hh"};
char *assembly[]={"*.asm","*.s","*.inc"};
char *objc[]={"*.m","*.mm","*.h"};
char *shell[]={"*.sh","*.bash","*.zsh"};
char *js[]={"*.js"};
char *ts[]={"*.ts"};
char *makefile[]={"Makefile","GNUmakefile","*.mk"};
char *cmake[]={"*.cmake","CMakeLists.txt"};
char *gitignore[]={".gitignore"};
char *markdown[]={"*.md","*.markdown",".mdown"};
char *latex[]={"*.tex"};
char *html[]={"*.html","*.htm","*.xhtml"};
char *python[]={"*.py"};
char *php[]={"*.php"};
char *jsp[]={"*.jsp"};
char *asp[]={"*.asp","*.aspx"};
char *actionscript[]={"*.as"};
char *batch[]={"*.bat","*.cmd"};
char *ruby[]={"*.rb","*.ru"};
char *rust[]={"*.rs"};
char *restructure_text[]={"*.rst"};
//CRLF:MS-DOS/Windows newline.
#define CRLF "\r\n"
//LF:*nix newline.
#define LF "\n"
//CR:Macintosh newline.
#define CR "\r"
int main(int argc,char *argv[])
{
    if(argc>1)
    {

    }
}