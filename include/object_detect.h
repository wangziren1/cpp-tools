#ifndef CPP_TOOLS_OBJECT_DETECT_H_
#define CPP_TOOLS_OBJECT_DETECT_H_

#include <opencv2/opencv.hpp>

struct BBox {
  BBox()=default;
  BBox(int x1, int y1, int x2, int y2, double conf_score=0.) 
      : x1(x1), y1(y1), x2(x2), y2(y2), conf_score(conf_score) {}
  int x1;
  int y1;
  int x2;
  int y2;
  float conf_score;
};

cv::Mat Letterbox(cv::Mat& img, int dst_height = 640, int dst_width = 640, 
                  int stride = 32);

double Iou(const BBox& bbox1, const BBox& bbox2);
#endif  // CPP_TOOLS_OBJECT_DETECT_H_