#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PHONG
{
	char ma_phong[6];
	float don_gia;
	int so_luong_giuong;
	int tinh_trang;
}PHONG;

void Nhap_thong_tin(PHONG &sv);
void Nhap_danh_sach_TS(PHONG sv[], int n);
void Xuat_thong_tin(PHONG &sv);
void Xuat_danh_sach_TS(PHONG sv[], int n);
void Phong_trong(PHONG ks[], int n);
void Tong_so_luong_giuong(PHONG ks[], int n);
void swap(PHONG &a, PHONG &b);
void SX_T_BY_DG(PHONG ks[], int &dau, int &cuoi);
void Danh_thu_hien_tai(PHONG ks[], int n);

int main()
{
	int soluong; 
	printf("Nhap so luong phong can nhap:  ");  scanf("%d", &soluong);
	PHONG ks[1000];
	Nhap_danh_sach_TS(ks, soluong);
	Xuat_danh_sach_TS(ks, soluong);
	Phong_trong(ks, soluong);
	Tong_so_luong_giuong(ks, soluong);
	int dau = 1, cuoi = soluong;
	SX_T_BY_DG(ks, dau, cuoi);
	printf("\nSap Xep Theo Don Gia\n");
	for(int i = 1; i<= cuoi; i++)
		Xuat_thong_tin(ks[i]);
	Danh_thu_hien_tai(ks, soluong);
}

void Nhap_thong_tin(PHONG &sv)
{
	printf("Nhap Ma Phong: "); fflush(stdin); gets(sv.ma_phong);
	printf("Nhap don gia: "); fflush(stdin); scanf("%f", &sv.don_gia);	
	printf("Nhap so luong giuong: "); fflush(stdin); scanf("%d", &sv.so_luong_giuong);
	printf("Nhap tinh trng: "); fflush(stdin); scanf("%d", &sv.tinh_trang);	
}
void Nhap_danh_sach_TS(PHONG sv[], int n)
{
	for(int i = 1; i <= n; i++)
		Nhap_thong_tin(sv[i]);	
}

void Xuat_thong_tin(PHONG &sv)
{
	printf("|\tMa Phong: %s ", sv.ma_phong); 
	printf("|\tDon Gia: %f  ", sv.don_gia); 
	printf("|\tSo Luong Phong: %d ", sv.so_luong_giuong);
	printf("|\tTinh Trang: %d \n", sv.tinh_trang);
}

void Xuat_danh_sach_TS(PHONG sv[], int n)
{
	printf("\n===============================Thong Tin Phong===============================\n");
	for(int i = 1; i <= n; i++)
		Xuat_thong_tin(sv[i]);	
}
void Phong_trong(PHONG ks[], int n)
{
	printf("\n<------------------------Cac Phong con trong--------------------> \n");
	int KT = 0;
	for(int i = 1; i <= n; i++)
		if(ks[i].tinh_trang == 0)
		{
			Xuat_thong_tin(ks[i]);
			KT++;
		}
	if(KT == 0)
		printf("\n => Het Phong !!");
}
void Tong_so_luong_giuong(PHONG ks[], int n)
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum += ks[i].so_luong_giuong;
	printf("\nTong so luong giuong la: %d\n", sum);
}
void swap(PHONG &a, PHONG &b)
{
	PHONG c = a;
	a = b;
	b = c;
}
void SX_T_BY_DG(PHONG ks[], int &dau, int &cuoi)
{
	int i, j;
    if(dau >= cuoi) return;
    PHONG x = ks[(dau+cuoi)/2];
    i = dau; j = cuoi;
    while(i <= j) {
        while(ks[i].don_gia < x.don_gia) i++;
        while(ks[j].don_gia > x.don_gia) j--;
            if(i <= j)
            {
                swap(ks[i], ks[j]);
                i++;    j--;
            }
    }
    SX_T_BY_DG(ks, dau, j);
	SX_T_BY_DG(ks, i, cuoi);
}
void Danh_thu_hien_tai(PHONG ks[], int n)
{
	int danh_thu = 0;
	for(int i = 1; i <= n; i++)
		if(ks[i].tinh_trang == 1)
			danh_thu += ks[i].don_gia;
	printf("\nDanh thu hien tai cua khach san: %d\n", danh_thu);
}
