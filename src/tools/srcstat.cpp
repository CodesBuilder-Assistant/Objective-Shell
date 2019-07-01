#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux)
#include <sys/io.h>
#include <sys/stat.h>
#endif
using namespace std;
char *cpp[]={"*.c","*.cpp","*.cc","*.cxx","*.h","*.hpp","*.hxx","*.hh"};
char *assembly[]={"*.asm","*.s","*.inc"};
char *objc[]={"*.m","*.mm","*.h"};
char *shell[]={"*.sh","*.bash","*.zsh",".bashrc"};
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
char *action_script[]={"*.as"};
char *batchfile[]={"*.bat","*.cmd"};
char *ruby[]={"*.rb","*.ru"};
char *rust[]={"*.rs"};
char *restructure_text[]={"*.rst"};
char *ini[]={"*.ini","*.cfg","*.conf","*.config"};
char *go[]={"*.go"};
char *ada[]={"*.ada"};
char *powershell[]={"*.ps1"};
char *lua[]={"*.lua"};
char *css[]={"*.css"};
char *groovy[]={"*.groovy"};
char *json[]={"*.json"};
char *less[]={"*.less"};
char *vue[]={"*.vue"};
char *haskell[]={"*.hs"};
char *vb[]={"*.vb",".vbs"};
char *jsx[]={"*.jsx"};
char *csharp[]={"*.cs"};
char *kotlin[]={"*.kt"};
char *unreal_script[]={".uc"};
char *yaml[]={"*.yml"};
char *vim_script[]={".vimrc"};
char *emacs[]={".emacs"};
char *lisp[]={"*.lisp","*.el"};
char *livescript[]={"*.ls"};
char *d[]={"*.d"};
char *java[]={"*.java","*.jav"};
char *scala[]={"*.scala"};
char *objsh[]={"*.osh","*.objsh","*.oshc","*.oshed"};
char *vscode_ignore[]={".vscodeignore"};
char *fsharp[]={"*.fs"};
char *diff[]={"*.diff"};
char *patch[]={"*.patch"};
char *log[]={"*.log"};
char *jinja[]={"*.jinja"};
char *xml[]={"*.xml"};

int main(int argc,char *argv[])
{
    #ifdef __linux
    printf("\033[94m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY)
    #endif
    puts("Objective Shell Sources Statistical Tool");
    #ifdef __linux
    printf("\033[33m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
    #endif
    puts("Copyright(C)2019 CodesBuilder");
    #ifdef __linux
    #elif defined(_WIN32)||defined(_WIN64)
    HANDLE finddata;
    finddata=FindFIrstFile();
    #endif
}