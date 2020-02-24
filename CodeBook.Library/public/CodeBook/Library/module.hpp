#ifndef CODE_BOOK_x_LIBRARY_x_MODULE_x_HPP
#define CODE_BOOK_x_LIBRARY_x_MODULE_x_HPP

#include <string>

// clang-format off
#if defined(CODE_BOOK_x_LIBRARY_x_EXPORTS)
#define CODE_BOOK_x_LIBRARY_x_API         __declspec(dllexport)
#else
#pragma comment(lib, "CodeBook.Library.lib")
#define CODE_BOOK_x_LIBRARY_x_API         __declspec(dllimport)
#endif
// clang-format on

namespace CodeBook {
namespace Library {

CODE_BOOK_x_LIBRARY_x_API std::string GetVersion();

}   // namespace Library
}   // namespace CodeBook

#endif   // CODE_BOOK_x_LIBRARY_x_MODULE_x_HPP
