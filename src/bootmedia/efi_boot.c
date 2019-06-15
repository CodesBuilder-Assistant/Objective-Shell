#include <efi.h>
EFI_STATUS main(EFI_HANDLE ImageHandle,EFI_SYSTEM_TABLE SystemTable)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut,"Starting Objective Shell Boot Media...\n");
    return EFI_SUCCESS;
}
