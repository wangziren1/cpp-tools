#include "object_detect.h"

cv::Mat Letterbox(cv::Mat& img, int dst_height, int dst_width, int stride) {
  int height = img.rows;
  int width = img.cols;
  double ratio = std::max(height / double(dst_height), 
                          width / double(dst_width));
  int new_height = int(std::round(height / ratio));
  int new_width = int(std::round(width / ratio));
  
  int dh = dst_height - new_height;
  int dw = dst_height - new_width;
  dh = dh % stride;
  dw = dw % stride;
  int top = 0, bottom = 0, left = 0, right = 0;
  if (dh % 2 == 0) {
    top = dh / 2;
    bottom = top;
  } else {
    top = dh / 2;
    bottom = top + 1;
  }
  if (dw % 2 == 0) {
    left = dw / 2;
    right = left;
  } else {
    left = dw / 2;
    right = left + 1;
  }
  
  cv::Mat img_resize;
  cv::resize(img, img_resize, cv::Size(new_width, new_height));
  cv::Mat img_pad;
  cv::copyMakeBorder(img_resize, img_pad, top, bottom, left, right,
                     cv::BORDER_CONSTANT, cv::Scalar(114, 114, 114));
  
  return img_pad;
}

// Compute iou between bbox1 and bbox2
// reference: https://zhuanlan.zhihu.com/p/473224484
double Iou(const BBox& bbox1, const BBox& bbox2) {
  int x1_inter = std::max(bbox1.x1, bbox2.x1);
  int y1_inter = std::max(bbox1.y1, bbox2.y1);
  int x2_inter = std::min(bbox1.x2, bbox2.x2);
  int y2_inter = std::min(bbox1.y2, bbox2.y2);

  int width_inter = x2_inter - x1_inter + 1;
  int height_inter = y2_inter - y1_inter + 1;
  if (width_inter <= 0 || height_inter <= 0)
    return 0;
  
  int area_inter = width_inter * height_inter;
  int area1 = (bbox1.x2 - bbox1.x1 + 1) * (bbox1.y2 - bbox1.y1 + 1);
  int area2 = (bbox2.x2 - bbox2.x1 + 1) * (bbox2.y2 - bbox2.y1 + 1);
  double iou = (double)area_inter / (area1 + area2 - area_inter);
  return iou;
}