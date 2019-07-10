#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux__)
#include <sys/io.h>
#include <sys/stat.h>
#endif
using namespace std;
wchar_t *cpp[]={L"*.c",L"*.cpp",L"*.cc",L"*.cxx",L"*.h",L"*.hpp",L"*.hxx",L"*.hh"};
wchar_t *assembly[]={L"*.asm",L"*.s",L"*.inc"};
wchar_t *objc[]={L"*.m",L"*.mm",L"*.h"};
wchar_t *shell[]={L"*.sh",L"*.bash",L"*.zsh",L".bashrc"};
wchar_t *js[]={L"*.js"};
wchar_t *ts[]={L"*.ts"};
wchar_t *makefile[]={L"Makefile",L"GNUmakefile",L"*.mk"};
wchar_t *cmake[]={L"*.cmake",L"CMakeLists.txt"};
wchar_t *gitignore[]={L".gitignore"};
wchar_t *markdown[]={L"*.md",L"*.markdown",L".mdown"};
wchar_t *latex[]={L"*.tex"};
wchar_t *html[]={L"*.html",L"*.htm",L"*.xhtml"};
wchar_t *python[]={L"*.py"};
wchar_t *php[]={L"*.php"};
wchar_t *jsp[]={L"*.jsp"};
wchar_t *asp[]={L"*.asp",L"*.aspx"};
wchar_t *action_script[]={L"*.as"};
wchar_t *batchfile[]={L"*.bat",L"*.cmd"};
wchar_t *ruby[]={L"*.rb",L"*.ru"};
wchar_t *rust[]={L"*.rs"};
wchar_t *restructure_text[]={L"*.rst"};
wchar_t *ini[]={L"*.ini",L"*.cfg",L"*.conf",L"*.config"};
wchar_t *go[]={L"*.go"};
wchar_t *ada[]={L"*.ada"};
wchar_t *powershell[]={L"*.ps1"};
wchar_t *lua[]={L"*.lua"};
wchar_t *css[]={L"*.css"};
wchar_t *groovy[]={L"*.groovy"};
wchar_t *json[]={L"*.json"};
wchar_t *less[]={L"*.less"};
wchar_t *vue[]={L"*.vue"};
wchar_t *haskell[]={L"*.hs"};
wchar_t *vb[]={L"*.vb",L".vbs"};
wchar_t *jsx[]={L"*.jsx"};
wchar_t *csharp[]={L"*.cs"};
wchar_t *kotlin[]={L"*.kt"};
wchar_t *unreal_script[]={L".uc"};
wchar_t *yaml[]={L"*.yml"};
wchar_t *vim_script[]={L".vimrc"};
wchar_t *emacs[]={L".emacs"};
wchar_t *lisp[]={L"*.lisp",L"*.el"};
wchar_t *livescript[]={L"*.ls"};
wchar_t *d[]={L"*.d"};
wchar_t *java[]={L"*.java",L"*.jav"};
wchar_t *scala[]={L"*.scala"};
wchar_t *objsh[]={L"*.osh",L"*.objsh",L"*.oshc",L"*.oshed"};
wchar_t *vscode_ignore[]={L".vscodeignore"};
wchar_t *fsharp[]={L"*.fs"};
wchar_t *diff[]={L"*.diff"};
wchar_t *patch[]={L"*.patch"};
wchar_t *log[]={L"*.log"};
wchar_t *jinja[]={L"*.jinja"};
wchar_t *xml[]={L"*.xml"};

unsigned int current_lang_srcsize=0;
unsigned int current_lang_srclines=0;

wstring current_file_name;

int main(int argc,char *argv[])
{
    #ifdef __linux__
    printf("\033[94m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    #endif
    puts("Objective Shell Sources Statistical Tool");
    #ifdef __linux__
    printf("\033[33m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
    #endif
    puts("Copyright(C)2019 CodesBuilder");
    #ifdef __linux__
    #ifdef __linux__
    printf("\033[0m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    #endif
    puts("Statisticing...");
    #elif defined(_WIN32)||defined(_WIN64)
    HANDLE finddata_handle;
    WIN32_FIND_DATAW wfinddata;
    for(int i=0;i<7;i++)
    {
        if((finddata_handle=FindFirstFileW(cpp[i],&wfinddata))==INVALID_HANDLE_VALUE)
            continue;
        current_file_name=wfinddata.cFileName;
        HANDLE current_file_handle;
        if((current_file_handle=CreateFileW(current_file_name.c_str(),GENERIC_READ,NULL,NULL,OPEN_EXISTING,NULL,NULL))==INVALID_HANDLE_VALUE)
        {
            CloseHandle(current_file_handle);
            continue;
        }
    }
    #ifdef __linux__
    printf("\033[94m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    #endif
    printf("C++:");
    #endif
}