#include "object_detect.h"

#include <gtest/gtest.h>

TEST(IouTest, IntersectBbox) {
  BBox bbox1(0, 0, 10, 10);
  BBox bbox2(5, 5, 15, 15);
  double iou = Iou(bbox1, bbox2);
  EXPECT_NEAR(iou, 0.1748, 0.0001);
}

TEST(IouTest, NoIntersectBbox) {
  BBox bbox1(0, 0, 10, 10);
  BBox bbox2(11, 11, 21, 21);
  double iou = Iou(bbox1, bbox2);
  EXPECT_NEAR(iou, 0, 0.0001);
}