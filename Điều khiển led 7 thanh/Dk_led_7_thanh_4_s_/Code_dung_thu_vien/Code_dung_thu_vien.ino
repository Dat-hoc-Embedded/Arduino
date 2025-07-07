#include "SevSeg.h" //Thêm thư viện SevSeg vào.
 
//Tạo đối tượng led 7 đoạn
SevSeg myDisplay;
 
void setup()
{
 
    int displayType = COMMON_CATHODE; //Kiểu led chung cực dương(COMMON_ANODE) hay cực âm(COMMON_CATHODE)
 
    int digit1 = 9; //Pin chung nhóm 1
    int digit2 = 10; //Pin chung nhóm 2
    int digit3 = 11; //Pin chung nhóm 3
    int digit4 = 12; //Pin chung nhóm 4
 
    //Khai báo pin các nhánh của led đơn
    int segA = 2; //Nhánh led A
    int segB = 3; //Nhánh led B
    int segC = 4; //Nhánh led C
    int segD = 5; //Nhánh led D
    int segE = 6; //Nhánh led E
    int segF = 7; //Nhánh led F
    int segG = 8; //Nhánh led G
    int segDP = 13; //Dấu chấm
 
    int numberOfDigits = 4; //Số dấu chấm
 
    myDisplay.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP); //Thông báo thông tin về module
    myDisplay.SetBrightness(100); //Điều chỉnh độ sáng là 100%
}
 
void loop()
{
    myDisplay.DisplayString("abcd", 0b00001000); /* Thể hiện chữ AbcD ra bảng LED, và dãy số 0b00001000 là vị trí dấu chấm. 
                                                     Bạn hãy thử thay những số 0 bằng số 1 hoặc ngược lại để kiểm nghiệm*/
    delay(5000); //Chờ 5s
    myDisplay.DisplayString("11 3", 0b00000001); /*Thể hiện dãy "11 3" ra bảng led*/
}
