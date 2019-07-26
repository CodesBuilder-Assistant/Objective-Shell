#ifndef LANG_H
#include <wchar.h>
#include <memory.h>

enum language_id
{
    EN_US=0,
    ZH_HANS,
    ZH_HANT,
    AR,
    LANGID_END
};
const wchar_t *language_select_show[]={L"English",L"简体中文",L"繁體中文",L"العربية"};

const wchar_t installer_title_en_us[]=L"Objective Shell Installer";
const wchar_t installer_title_zh_hans[]=L"Objective Shell安装程序";
const wchar_t installer_title_zh_hant[]=L"Objective Shell安裝程式";
const wchar_t select_install_path_en_us[]=L"Install Path:";
const wchar_t select_install_path_zh_hans[]=L"安装目录:";
const wchar_t select_install_path_zh_hant[]=L"安裝目錄:";
const wchar_t select_modules_to_install_en_us[]=L"Select modules to install";
const wchar_t select_modules_to_install_zh_hans[]=L"选择要安装的组件";
const wchar_t select_modules_to_install_zh_hant[]=L"選擇要安裝的組件";
const wchar_t next_en_us[]=L"Next";
const wchar_t next_zh[]=L"下一步";
const wchar_t back_en_us[]=L"Back";
const wchar_t back_zh[]=L"返回";
const wchar_t cancel_en_us[]=L"Cancel";
const wchar_t cancel_zh[]=L"取消";
const wchar_t ok_en_us[]=L"OK";
const wchar_t ok_zh_hans[]=L"确定";
const wchar_t ok_zh_hant[]=L"確定";
const wchar_t yes_en_us[]=L"Yes";
const wchar_t yes_zh[]=L"是";
const wchar_t no_en_us[]=L"No";
const wchar_t no_zh[]=L"否";
const wchar_t installing_en_us[]=L"Installing...";
const wchar_t installing_zh_hans[]=L"安装中……";
const wchar_t installing_zh_hant[]=L"正在安裝……";
const wchar_t installation_completed_en_us[]=L"Installation Completed";
const wchar_t installation_completed_zh_hans[]=L"安装完成";
const wchar_t installation_completed_zh_hant[]=L"安裝完成";
const wchar_t installation_failed_en_us[]=L"Installation Failed";
const wchar_t installation_failed_zh_hans[]=L"安装失败";
const wchar_t installation_failed_zh_hant[]=L"安裝失敗";
const wchar_t errcode_en_us[]=L"Error Code:";
const wchar_t errcode_zh_hans[]=L"错误代码:";
const wchar_t errcode_zh_hant[]=L"錯誤代碼:";

wchar_t *installer_title;
wchar_t *select_install_path;
wchar_t *select_modules_to_install;
#endif