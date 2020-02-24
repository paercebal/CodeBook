#include <CodeBook/LibraryTesting/main.hpp>

#include <CodeBook/Library/module.hpp>

#include <iostream>

#include <gtest/gtest.h>

int main(int argc, char * argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(CodeBook_LibraryTesting, GetVersion)
{
   EXPECT_EQ("CodeBook.Library (v0.0.1)", CodeBook::Library::GetVersion());
}

namespace CodeBook {
namespace LibraryTesting {

}   // namespace LibraryTesting
}   // namespace CodeBook
