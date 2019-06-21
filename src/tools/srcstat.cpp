#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <io.h>
#elif defined(__linux)
#include <dirent.h>
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
char *batch[]={"*.bat","*.cmd"};
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
char *vb[]={"*.vb"};
char *vbs[]={"*.vbs"};
char *jsx[]={"*.jsx"};
char *csharp[]={"*.cs"};
char *kotlin[]={"*.kt"};
char *unreal_script[]={".uc"};
char *yaml[]={"*.yml"};
char *vim_script[]={".vimrc"};
char *emacs[]={".emacs"};
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
        for(int i=0;i<argc;i++)
            if(argv[i]=="-h")
            {
                puts("syntax:srcstat [options] [directory] ...");
                puts("options:");
                puts("-h                    Show this list");
                puts("-i [language] ...     Ignore a programming language");
                puts("-s [language] ...     Set a statistic programming languages");
                puts("-l [name] [filename]  Set a programming language's setting");
                puts("-lf [LF characters]   Set file line feed characters");
                puts("-f [format]           Set statistics output format");
            }
    }
}