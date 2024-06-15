#include <stdio.h>
#include <string.h>

typedef struct {
    char malop[10];
    char thu;
    char bd, kt;
    char diadiem[10];
    char magv[5][10];
} lop;

struct nodelh {
    lop lh;
    nodelh *next;
};
typedef struct nodelh *pnodelh;
typedef struct nodelh *lllop;

typedef struct {
    char mahp[10];
    char tenhp[50];
    lllop dslop;
} hocphan;

struct nodehp {
    hocphan hp;
    nodehp *next;
};
typedef struct nodehp *pnodehp;
typedef struct nodehp *llhp;

struct nodelk {
    pnodehp hp;
    char malop[10];
    nodelk *next;
};
typedef struct nodelk *pnodelk;
typedef struct nodelk *lllk;

typedef struct {
    char magv[10];
    char tengv[50];
    lllk lop;
} giangvien;

struct nodegv {
    giangvien gv;
    nodegv *next;
};
typedef struct nodegv *pnodegv;
typedef struct nodegv *llgv;

llhp hp;
llgv gv;

// Hàm tìm ki?m giáo viên theo mã
int tim_kiem_gv(llgv ds_gv, const char* magv) {
    pnodegv current_gv = ds_gv;
    while (current_gv != NULL) {
        if (strcmp(current_gv->gv.magv, magv) == 0) {
            printf("Teacher found:\n");
            printf("Teacher ID: %s\n", current_gv->gv.magv);
            printf("Teacher Name: %s\n", current_gv->gv.tengv);
            
            lllk current_lk = current_gv->gv.lop;
            while (current_lk != NULL) {
                printf("Course ID: %s, Class ID: %s\n", current_lk->hp->hp.mahp, current_lk->malop);
                current_lk = current_lk->next;
            }
            return 1; // Tìm th?y giáo viên
        }
        current_gv = current_gv->next;
    }
    printf("Teacher not found\n");
    return 0; // Không tìm th?y giáo viên
}

// Hàm s?a thông tin giáo viên
void sua_magv(llgv ds_gv, const char* old_magv, const char* new_magv, const char* new_name) {
    pnodegv current_gv = ds_gv;
    while (current_gv != NULL) {
        if (strcmp(current_gv->gv.magv, old_magv) == 0) {
            strcpy(current_gv->gv.magv, new_magv);
            strcpy(current_gv->gv.tengv, new_name);

            lllk current_lk = current_gv->gv.lop;
            while (current_lk != NULL) {
                pnodelh current_lh = current_lk->hp->hp.dslop;
                while (current_lh != NULL) {
                    for (int i = 0; i < 5; ++i) {
                        if (strcmp(current_lh->lh.magv[i], old_magv) == 0) {
                            strcpy(current_lh->lh.magv[i], new_magv);
                        }
                    }
                    current_lh = current_lh->next;
                }
                current_lk = current_lk->next;
            }
            printf("Updated teacher ID to %s and name to %s\n", new_magv, new_name);
            return;
        }
        current_gv = current_gv->next;
    }
    printf("Teacher not found\n");
}

int main() {
    
    // T?o l?p m?u
    lop lop1 = { "L01", '2', 8, 10, "Room101", { "GV01" } };
    pnodelh nodeLop1 = new nodelh;
    nodeLop1->lh = lop1;
    nodeLop1->next = NULL;
    
    // T?o h?c ph?n m?u
    hocphan hp1 = { "HP01", "Hoc Phan 1", nodeLop1 };
    pnodehp nodeHp1 = new nodehp;
    nodeHp1->hp = hp1;
    nodeHp1->next = NULL;

    // Liên k?t h?c ph?n v?i nodelk
    pnodelk nodeLk1 = new nodelk;
    strcpy(nodeLk1->malop, "L01");
    nodeLk1->hp = nodeHp1;
    nodeLk1->next = NULL;

    // T?o giáo viên m?u
    giangvien gv1 = { "GV01", "Nguyen Van A", nodeLk1 };
    pnodegv nodeGv1 = new nodegv;
    nodeGv1->gv = gv1;
    nodeGv1->next = NULL;

    // Danh sách liên k?t c?a giáo viên
    llgv ds_gv = nodeGv1;

    char searchMagv[10];
    char newMagv[10];
    char newName[50];
    int found = 0;

    // Tìm ki?m giáo viên cho d?n khi tìm th?y
    while (!found) {
        printf("Nhap ma giao vien can tim: ");
        scanf("%s", searchMagv);
        found = tim_kiem_gv(ds_gv, searchMagv);
        if (!found) {
            printf("Vui long nhap lai ma giao vien.\n");
        }
    }

    printf("Nhap ma giao vien moi: ");
    scanf("%s", newMagv);
    printf("Nhap ten giao vien moi: ");
    scanf(" %[^\n]", newName);

    // C?p nh?t mã giáo viên và tên giáo viên
    sua_magv(ds_gv, searchMagv, newMagv, newName);

    return 0;
}

