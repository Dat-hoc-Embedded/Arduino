#include <SimpleKalmanFilter.h>
/*
 SimpleKalmanFilter(e_mea, e_est, q);
 e_mea: Mức độ không chắc chắn của phép đo (mong đợi vào phép đo) 
 e_est: Ước tính không chắc chắn (setup giống e_mea, thư viện sẽ tự hiệu chỉnh) 
 q: Phương sai - Khuyến nghị 0,001 - 1 (thường là 0,001), tùy vào dự án hiệu chỉnh cho phù hợp
 */
SimpleKalmanFilter locnhieu(2, 2, 0.01);

int bientro = A0; float gt_doc; float gt_filter;

void setup() 
{
  Serial.begin(9600);
  pinMode(bientro, INPUT);
}

void loop() 
{
  gt_doc = analogRead(bientro);
  
  gt_filter = locnhieu.updateEstimate(gt_doc);

  Serial.print("Đọc: "); 
  Serial.print(gt_doc);
  Serial.print("  Filter: "); 
  Serial.println(gt_filter);
  //delay(100);
}
