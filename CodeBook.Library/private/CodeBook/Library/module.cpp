#include <CodeBook/Library/module.hpp>

#include <Windows.h>

BOOLEAN WINAPI DllMain(IN HINSTANCE hDllHandle, IN DWORD nReason, IN LPVOID Reserved)
{
   BOOLEAN bSuccess = TRUE;

   switch (nReason)
   {
      case DLL_PROCESS_ATTACH:
         break;
      case DLL_PROCESS_DETACH:
         break;
      case DLL_THREAD_ATTACH:
         break;
      case DLL_THREAD_DETACH:
         break;
   }

   return bSuccess;
}

namespace CodeBook {
namespace Library {

CODE_BOOK_x_LIBRARY_x_API std::string GetVersion()
{
   return "CodeBook.Library (v0.0.1)";
}

}   // namespace Library
}   // namespace CodeBook
