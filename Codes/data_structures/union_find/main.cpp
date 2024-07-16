#include "union_find.h"
#include <gtest/gtest.h>

TEST(UnionFindTest, BasicTest) {
  UnionFind uf(5);

  uf.unite(0, 1);
  uf.unite(2, 3);
  ASSERT_TRUE(uf.isConnected(0, 1));
  ASSERT_FALSE(uf.isConnected(0, 2));

  uf.unite(0, 2);
  ASSERT_TRUE(uf.isConnected(0, 3));
}

TEST(UnionFindTest, LargerSetTest) {
  UnionFind uf(10);

  for (int i = 0; i < 9; ++i) {
    uf.unite(i, i + 1);
  }

  ASSERT_TRUE(uf.isConnected(0, 9));
}

TEST(UnionFindTest, PathCompressionTest) {
  UnionFind uf(5);

  uf.unite(0, 1);
  uf.unite(1, 2);
  uf.unite(2, 3);
  uf.unite(3, 4);

  ASSERT_EQ(uf.find(0), uf.find(4));
}

TEST(UnionFindTest, UnionByRankTest) {
  UnionFind uf(7);

  uf.unite(0, 1);
  uf.unite(2, 3);
  uf.unite(4, 5);
  uf.unite(6, 0);
  uf.unite(4, 2);
  uf.unite(0, 2);

  ASSERT_TRUE(uf.isConnected(1, 5));
}