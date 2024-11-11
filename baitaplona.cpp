#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void luatchoi() {
    cout << "*Luat choi : \n";
    cout << "-Chao mung ban den voi tro choi Puzzle! \n";
    cout << "-Tro choi nay yeu cau ban di chuyen o trong voi cac so ke voi o trong sao cho ma tran tro ve dang voi so bat dau la 1 và tang dan deu 1 don vi tu trai sang phai va o cuoi cung la o trong. \n";
    cout << "Chuc ban may man *=* \n";
    cout << endl;
}
void Swap(int* number_1, int* number_2) {
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}
void xaotron(int** a, int n) {
    srand(time(0));
    int k = 1;
    for (int i = 0; i < n; i++) {
        *(a + i) = new int[n];
        for (int j = 0; j < n; j++) {
            if (i == n - 1 && j == n - 1) {
                *(*(a + i) + j) = 0;
                continue;
            }
            *(*(a + i) + j) = k++;
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int hang = rand() % n;
            int cot = rand() % n;
            if ((hang != n - 1 || cot != n - 1) && (i != n - 1 || j != n - 1)) Swap((*(a + i) + j), (*(a + hang) + cot));
        }
    }
}
void in(int** a, int n) {
    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < n; j++) {
            if (*(*(a + i) + j) == 0) {
                cout << "   ";
                continue;
            }
            if (*(*(a + i) + j) < 10) cout << " " << *(*(a + i) + j) << " ";
            else cout << *(*(a + i) + j) << " ";
        }
    } cout << endl;
}
bool kiemtra(int** a, int n) {
    int k = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (*(*(a + i) + j) != k && (i != n - 1 || j != n - 1)) {
                return false;
            }
            k++;
        }
    }return true;
}
void choi(int** a, int n, int solantoida) {

    char s;
    int i = n - 1, j = n - 1;
    while (solantoida--) {
        cout << endl;
        cout << "Ban muon di chuyen trai(a) phai(d) len(w) xuong(s) : ";
        do {
            cin >> s;
            if (s != 'a' && s != 's' && s != 'd' && s != 'w') {
                cout << "Moi ban nhap lai!\n";
            }
        } while (s != 'a' && s != 's' && s != 'd' && s != 'w');
        if (s == 'a' && j - 1 >= 0) {
            Swap(*(a + i) + j, *(a + i) + j - 1);
            j = j - 1;
        }
        else if (s == 'd' && j + 1 < n) {
            Swap(*(a + i) + j, *(a + i) + j + 1);
            j = j + 1;
        }
        else if (s == 'w' && i - 1 >= 0) {
            Swap(*(a + i) + j, *(a + i - 1) + j);
            i = i - 1;
        }
        else if (s == 's' && i + 1 < n) {
            Swap(*(a + i) + j, *(a + i + 1) + j);
            i = i + 1;
        }
        in(a, n);
        if (kiemtra(a, n)) {
            cout << "Chuc mung ! Ban da thang tro choi! ";
            return;
        }
        cout << "So lan con lai de di chuyen la : " << solantoida << endl;

    }cout << "Ban da thua !";
}
void capphat(int**& a, int n) {
    a = new int* [n];
}
void thuhoi(int** a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}
int main() {
    cout << "================== CHAO MUNG BAN DEN VOI TRO CHOI ! ============================ \n";
    luatchoi();
    cout << "Nhap he ma tran ban muon choi (>=3) : ";
    int n;
    cin >> n;
    cout << "Nhap so lan toi da co the di chuyen : ";
    int solantoida;
    cin >> solantoida;
    int** a;
    capphat(a, n);
    xaotron(a, n);
    in(a, n);
    choi(a, n, solantoida);
    thuhoi(a, n);
    return 0;
}