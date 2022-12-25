#include "gtest/gtest.h"

#include "leetcode.h"

TEST(test_algorithm, test_linked_list)
{
    EXPECT_EQ(1, 1);
}

TEST(test_binary_search, test_744)
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'j';

    char ret = nextGreatestLetter(letters, target);
    EXPECT_EQ(ret, 'c');
}

TEST(test_leetcode, test_k_mins)
{
    vector<int> data = {5, 4, 3, 1, 1, 0};
    vector<int> ret = find_k_mins(data, 3);
    vector<int> expect = {5, 3, 4};

    EXPECT_EQ(ret.size(), expect.size());
    for (size_t i = 0; i < ret.size(); ++i) {
        EXPECT_EQ(ret[i], expect[i]);
    }

    ret = find_k_mins(data, 7); /* expect beyong maximum list size */
    EXPECT_EQ(ret.size(), 6);
    expect = {5, 3, 4, 2, 1, 0};
    for (size_t i = 0; i < ret.size(); ++i) {
        EXPECT_EQ(ret[i], expect[i]);
    }
}