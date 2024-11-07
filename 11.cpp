#include <iostream>
using namespace std;

struct Ngay {
    int ngay;  
    int thang; 
    int nam;   
};

struct SinhVien {
    char maSV[8];     
    char hoTen[50];  
    char gioiTinh[10]; 
    Ngay ngaySinh;   
    char diaChi[100];  
    char lop[12];      
    char khoa[7];      
};
// Cấu trúc lưu thông tin của một sinh viên.

void nhapChuoi(char chuoi[], int doDaiToiDa) {
    //Hàm nhập chuỗi
    cin.ignore();
    for (int i = 0; i < doDaiToiDa; i++) {
        char c = cin.get();
        if (c == '\n') { 
            chuoi[i] = '\0'; 
            break;
        }
        chuoi[i] = c; 
    }
}
//Hàm nhập chuỗi

void nhapSinhVien(SinhVien &sv) {
    cout << "Nhap ma sinh vien (toi da 7 ky tu): ";
    nhapChuoi(sv.maSV, 8);  
    
    cout << "Nhap ho ten sinh vien (toi da 49 ky tu): ";
    nhapChuoi(sv.hoTen, 50);  

    cout << "Nhap gioi tinh (toi da 9 ky tu): ";
    nhapChuoi(sv.gioiTinh, 10);  

    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;  

    cout << "Nhap dia chi (toi da 99 ky tu): ";
    nhapChuoi(sv.diaChi, 100);  

    cout << "Nhap lop (toi da 11 ky tu): ";
    nhapChuoi(sv.lop, 12);  

    cout << "Nhap khoa (toi da 6 ky tu): ";
    nhapChuoi(sv.khoa, 7);  
}
//Hàm nhập thông tin sinh viên
void inSinhVien(SinhVien sv) {
    cout << "Ma SV: " << sv.maSV << endl;
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Gioi tinh: " << sv.gioiTinh << endl;
    cout << "Ngay sinh: " << sv.ngaySinh.ngay << "/" << sv.ngaySinh.thang << "/" << sv.ngaySinh.nam << endl;
    cout << "Dia chi: " << sv.diaChi << endl;
    cout << "Lop: " << sv.lop << endl;
    cout << "Khoa: " << sv.khoa << endl;
}

//So sánh hai ngày sinh
bool soSanhNgay(Ngay a, Ngay b) {
    return a.ngay == b.ngay && a.thang == b.thang && a.nam == b.nam;
}
// Hàm so sánh ngày sinh của hai sinh viên.

void timSinhVienCungNgaySinh(SinhVien ds[], int soLuong, Ngay ngaySinh) {
    bool timThay = false;  //Đánh dấu xem có tìm thấy sinh viên nào không
    for (int i = 0; i < soLuong; i++) {
        if (soSanhNgay(ds[i].ngaySinh, ngaySinh)) {  //Kiểm tra nếu ngày sinh trùng khớp
            inSinhVien(ds[i]);  
            timThay = true;    
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien cung ngay sinh!" << endl;
    }
}
//Hàm tìm kiếm sinh viên có cùng ngày sinh.

void xoaSinhVienCungNgaySinh(SinhVien ds[], int &soLuong, Ngay ngaySinh) {
    for (int i = 0; i < soLuong; i++) {
        if (soSanhNgay(ds[i].ngaySinh, ngaySinh)) {  
            for (int j = i; j < soLuong - 1; j++) {
                ds[j] = ds[j + 1];  
            }
            soLuong--;  
            i--;  
        }
    }
}
//Hàm xóa tất cả sinh viên có cùng ngày sinh.
int main() {
    int soLuong;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;  
    
    SinhVien ds[100];  //Tạo mảng chứa tối đa 100 sinh viên

    //Nhập thông tin cho các sinh viên
    for (int i = 0; i < soLuong; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        nhapSinhVien(ds[i]);  
    }

    //Tìm sinh viên theo ngày sinh
    Ngay ngaySinh;
    cout << "Nhap ngay sinh can tim (ngay thang nam): ";
    cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam; 
    
    cout << "\nDanh sach sinh vien cung ngay sinh:" << endl;
    timSinhVienCungNgaySinh(ds, soLuong, ngaySinh);  

    cout << "\nXoa sinh vien cung ngay sinh." << endl;
    xoaSinhVienCungNgaySinh(ds, soLuong, ngaySinh);

    cout << "\nDanh sach sinh vien sau khi xoa:" << endl;
    for (int i = 0; i < soLuong; i++) {
        inSinhVien(ds[i]);

    return 0;  
}
