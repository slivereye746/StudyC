#include <stdio.h>
#include <stdbool.h>

//Kiểm tra só nguyên tố
bool ktSoNguyenTo(int x){
    if (x<2)
    {
        /* code */
        return false;
    }
    else
    {
        /* code */
        for (int i = 2; i < x; i++)
        {
            /* code */
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }        
}

//Kiểm tra số hoàn hảo
bool ktSoHoanHao(int x){
    if (x<1)
    {
        /* code */
        return false;
    }
    else
    {
        /* code */
        int sum = 0;
        for (int i = 1; i < x; i++)
        {
            /* code */
            if (x % i == 0)
            {
                sum += i;
            }
        }
        if (sum == x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }        
}

//Kiểm tra số chính phương
bool ktSoChinhPhuong(int x){
    if (x<1)
    {
        /* code */
        return false;
    }
    else
    {
        /* code */
        for (int i = 1; i <= x; i++)
        {
            /* code */
            if (i * i == x)
            {
                return true;
            }
        }
        return false;
    }        
}

int main(){

    //Kiểm tra số
    int inputNum;
    printf("Nhap so bat ky: ");
    scanf("%d", &inputNum);
    bool check = ktSoNguyenTo(inputNum);
    if (check == true){
        printf("%d la so nguyen to!\n", inputNum);
    }
    else
    {
        printf("%d Khong phai la so nguyen to!\n", inputNum);
    }

    if (check == true)
    {
        /* code */
        printf("%d la so hoan hao!\n", inputNum);
    }
    else
    {
        /* code */
        printf("%d Khong phai la so hoan hao!\n", inputNum);
    }
    
    if (check == true)
    {
        /* code */
        printf("%d la so chinh phuong!\n", inputNum);
    }
    else
    {
        /* code */
        printf("%d Khong phai la so chinh phuong!\n", inputNum);
    }
    
    return 0;   
}

/**Nhập mảng đẻ quản lý dự án cntt gồm mã dự án int, teen char[200], địa điểm [300], kinh phí float
khai báo ngăn xếp, kiểm tra ngăn xếp rổng
viết hàm nhập dữ liệu cho ngăn xếp, show toàn bộ ngăn xếp
viết hàm hiển thị thông tin dự án có địa điểm ở Thuan Thanh
viết hàm main
**/
