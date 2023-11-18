#include <limits.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "MarkDownEditor.h"
#include "MarkDownFile.h"

// using ::testing::_;
// using ::testing::AtLeast;
// using ::testing::Exactly;
// using ::testing::Return;
using namespace testing;
using namespace std;

TEST(RUNNABLE_TEST, RUNNABLE_TEST_LABEL)
{
  auto editor = MarkDownEditor(false);
  editor.exex_command("load ./tdd_test_file.md");
  editor.exex_command("exit");
  EXPECT_EQ(remove("./tdd_test_file.md"), 0);
}

TEST(DIRTY_TEST, DIRTY_TEST_LABEL)
{
  MarkDownFile file = MarkDownFile("./tdd_test_file.md");
  EXPECT_EQ(file.isDirty(), false);
  file.insertWord(1, "# 你好");
  EXPECT_EQ(file.isDirty(), true);
  file.save();
  EXPECT_EQ(file.isDirty(), false);
  EXPECT_EQ(remove("./tdd_test_file.md"), 0);
}

TEST(LIST_TEST, LIST_TEST_LABEL)
{
  MarkDownFile file = MarkDownFile("./tdd_test_file.md");
  stringstream ss;
  streambuf *buffer = cout.rdbuf(); // oldbuffer,STDOUT的缓冲区
  cout.rdbuf(ss.rdbuf());

  file.insertWord(1, "# 1");
  file.insertWord(2, "# 2");
  file.insertWord(3, "# 3");
  file.insertWord(4, "# 4");
  file.insertWord(5, "# 5");
  file.deleteLine(5);
  file.list();
  file.save();

  string s(ss.str());
  cout.rdbuf(buffer); // 重置，重新载入STDOUT的缓冲区
  EXPECT_EQ(s, string("# 1\n# 2\n# 3\n# 4\n"));
  EXPECT_EQ(remove("./tdd_test_file.md"), 0);
}