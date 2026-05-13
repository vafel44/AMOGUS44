#include <iostream>
#include "Fraction.h"
#include "Vector3D.h"
#include "Matrix.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "  LABORATORNAYa RABOTA PO C++" << endl;
    cout << "  PEREGRUZKA OPERATOROV" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // ========== CHAST 1: DROBI ==========
    cout << "===== CHAST 1: RABOTA S DROBYAMI =====" << endl;
    try {
        Fraction a(1, 2);
        Fraction b(3, 4);
        
        cout << "Drob a = " << a << endl;
        cout << "Drob b = " << b << endl;
        
        Fraction c = a + b;
        cout << "a + b = " << c << endl;
        
        Fraction d = a - b;
        cout << "a - b = " << d << endl;
        
        Fraction e = a * b;
        cout << "a * b = " << e << endl;
        
        Fraction f = a / b;
        cout << "a / b = " << f << endl;
        
        cout << "a == b? " << (a == b ? "DA" : "NET") << endl;
        cout << "a < b? " << (a < b ? "DA" : "NET") << endl;
        
        Fraction g(6, 8);
        cout << "Sokrashenie 6/8 = " << g << endl;
        
        cout << "Decimalnoe znachenie a = " << a.toDouble() << endl;
        
    } catch (const exception& ex) {
        cout << "Oshibka v drobyah: " << ex.what() << endl;
    }
    
    cout << endl;
    cout << "Nazhmite Enter dlya prodolzheniya...";
    cin.get();
    cout << endl;
    
    // ========== CHAST 2: VEKTORY ==========
    cout << "===== CHAST 2: RABOTA S VEKTORAMI =====" << endl;
    try {
        Vector3D v1(1, 2, 3);
        Vector3D v2(4, 5, 6);
        
        cout << "Vektor v1 = ";
        v1.print();
        cout << endl;
        
        cout << "Vektor v2 = ";
        v2.print();
        cout << endl;
        
        Vector3D v3 = v1 + v2;
        cout << "v1 + v2 = ";
        v3.print();
        cout << endl;
        
        Vector3D v4 = v1 - v2;
        cout << "v1 - v2 = ";
        v4.print();
        cout << endl;
        
        double dot = v1 * v2;
        cout << "Skalyarnoe proizvedenie v1 * v2 = " << dot << endl;
        
        Vector3D v5 = v1 * 3;
        cout << "v1 * 3 = ";
        v5.print();
        cout << endl;
        
        cout << "Dlina vektora v1 = " << v1.length() << endl;
        
        ++v1;
        cout << "Posle ++v1 = ";
        v1.print();
        cout << endl;
        
        cout << "Dostup po indeksu: v2[0] = " << v2[0] << endl;
        cout << "Vsego sozdano vektorov: " << Vector3D::getVectorCount() << endl;
        
    } catch (const exception& ex) {
        cout << "Oshibka v vektorah: " << ex.what() << endl;
    }
    
    cout << endl;
    cout << "Nazhmite Enter dlya prodolzheniya...";
    cin.get();
    cout << endl;
    
    // ========== CHAST 3: MATRITSY (NE SHABLONNAYa) ==========
    cout << "===== CHAST 3: RABOTA S MATRITSAMI =====" << endl;
    try {
        // СОЗДАЁМ МАТРИЦЫ БЕЗ УГЛОВЫХ СКОБОК < > 
        Matrix m1(2, 2);   // НЕ пишем Matrix<int> - просто Matrix
        Matrix m2(2, 2);   // Matrix m2(2, 2) - правильно!
        
        cout << "Vvedite pervuyu matritsu 2x2 (4 celih chisla cherez probel):" << endl;
        cout << "Primer: 1 2 3 4" << endl;
        cin >> m1;
        
        cout << "Vvedite vtoruyu matritsu 2x2 (4 celih chisla cherez probel):" << endl;
        cin >> m2;
        
        cout << endl << "Pervaya matritsa:" << endl;
        cout << m1;
        
        cout << "Vtoraya matritsa:" << endl;
        cout << m2;
        
        Matrix m3 = m1 + m2;
        cout << "Summa matric:" << endl;
        cout << m3;
        
        Matrix m4 = m1 - m2;
        cout << "Raznost matric:" << endl;
        cout << m4;
        
        Matrix m5 = m1 * m2;
        cout << "Proizvedenie matric:" << endl;
        cout << m5;
        
        cout << "Opredelitel pervoy matricy: " << m1.determinant() << endl;
        
        Matrix m6 = m1.transpose();
        cout << "Transponirovannaya pervaya matritsa:" << endl;
        cout << m6;
        
        cout << "m1 == m2? " << (m1 == m2 ? "DA" : "NET") << endl;
        
        // Умножение на скаляр
        Matrix m7 = m1 * 2;
        cout << "Umnozhenie pervoy matricy na 2:" << endl;
        cout << m7;
        
        // ДЕМОНСТРАЦИЯ РАБОТЫ С БОЛЬШОЙ МАТРИЦЕЙ
        cout << "\nDemonstraciya raboty s matricey 3x3:" << endl;
        Matrix m8(3, 3);
        cout << "Vvedite matricu 3x3 (9 chisel):" << endl;
        cin >> m8;
        
        cout << "Vvedennaya matrica:" << endl;
        cout << m8;
        
        cout << "Opredelitel matricy 3x3: " << m8.determinant() << endl;
        
        Matrix m9 = m8.transpose();
        cout << "Transponirovannaya matrica:" << endl;
        cout << m9;
        
    } catch (const exception& ex) {
        cout << "Oshibka v matricah: " << ex.what() << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "PROGRAMMA ZAVERSHENA!" << endl;
    cout << "========================================" << endl;
    
    cin.get();
    cin.get();
    return 0;
} 