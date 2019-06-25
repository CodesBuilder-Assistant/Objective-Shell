#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <io.h>
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
char *vb[]={"*.vb"};
char *vbs[]={"*.vbs"};
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
char *sources_list[]={"sources.list"};

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
        return 0;
    }
    _finddata_t *current_info;
    unsigned long long srcline_sum=0;
    unsigned long long fsize_sum=0;
    intptr_t ret_int_ptr;
    for(int i=0;i<7;i++)
    {
        if((ret_int_ptr=_findfirst(cpp[i],current_info))==-1)
            continue;
        while(true)
        {
            #ifdef __linux
            struct _stat *current_file_stat;
            _stat(current_info->name,current_file_stat);
            fsize_sum+=current_file_stat->st_size;
            #endif
            FILE *current_file_ptr=fopen(current_info->name,"r");
            #if defined(_WIN32)||defined(_WIN64)
            fseek(current_file_ptr,0L,SEEK_END);
            fsize_sum+=ftell(current_file_ptr);
            #endif
            int current_char;
            #ifdef __linux
            while((current_char=fgetc(current_file_ptr))!=EOF)
                if(current_char=='\n')
                    srcline_sum++;
            #elif defined(_WIN32)||defined(_WIN64)
            while((current_char=fgetc(current_file_ptr))!=EOF)
                if(current_char=='\r')
                    if((current_char=getc(current_file_ptr))=='\n')
                        srcline_sum++;
                    else if(current_char==EOF)
                        break;
            #endif
            fclose(current_file_ptr);
            if(_findnext(ret_int_ptr,current_info)==-1)
                break;
        }
        printf("");
    }
}