#include <iostream>
#include <string>

using namespace std;

struct rekening {
    string nama;
    string pinRekening;
    int saldo;
};

rekening maxRekening[5];
int availableRekening = 0;

void buatRekening() {
    if (availableRekening >= 5) {
        cout << "MOHON MAAF AKUN REKENING ANDA SUDAH MELEBIHI BATAS" << endl;
        return;
    }

    rekening newRekening;

    cout << "MASUKKAN NAMA : ";
    cin >> newRekening.nama;
    cout << "MASUKKAN PIN BARU : ";
    cin >> newRekening.pinRekening;

    newRekening.saldo = 0;

    maxRekening[availableRekening] = newRekening;
    availableRekening++;

    cout << "REKENING BARU BERHASIL DIBUAT!" << endl << endl;
}

int masukRekening() {
    string pin;

    cout << "MASUKKAN PIN REKENING : ";
    cin >> pin;

    for (int i = 0; i < availableRekening; i++) {
        if (maxRekening[i].pinRekening == pin) {
            cout << "SELAMAT DATANG TN/NY, " << maxRekening[i].nama << endl;
            return i;
        }
    }
    cout << "PIN YANG ANDA MASUKKAN SALAH" << endl;
    return -1;
    cout << endl;
}

void setorTunai(int index) {
    int uangSetor;

    cout << "MASUKKAN UANG YANG INGIN DIDEPOSIT PADA REKENING ANDA: ";
    cin >> uangSetor;

    cout << endl;

    if (uangSetor < 0) {
        cout << "JUMLAH SALDO YANG ANDA MASUKKAN TIDAK VALID" << endl << endl;
    } else {
        maxRekening[index].saldo += uangSetor;
        cout << "ANDA TELAH BERHASIL SETOR TUNAI PADA REKENING" << endl << endl;
        cout << "SALDO ANDA SAAT INI : RP. " << maxRekening[index].saldo << endl << endl;
    }
}

void tarikTunai(int index) {
    int uangTarik;

    cout << "MASUKKAN UANG YANG INGIN ANDA TARIK: ";
    cin >> uangTarik;

    cout << endl;

    if (uangTarik < 0) {
        cout << "JUMLAH SALDO YANG ANDA MASUKKAN TIDAK VALID" << endl;
    } else if (uangTarik > maxRekening[index].saldo) {
        cout << "SALDO ANDA KURANG" << endl;
    } else {
        maxRekening[index].saldo -= uangTarik;
        cout << "ANDA TELAH BERHASIL TARIK TUNAI PADA REKENING" << endl << endl;
        cout << "SALDO ANDA SAAT INI ADALAH: " << maxRekening[index].saldo << endl << endl;
    }
}

void cekSaldo(int index) {
    cout << "SALDO PADA REKENING ANDA SAAT INI : RP. " << maxRekening[index].saldo << endl;
}

void menuUtama() {
    int pilihan;
    bool keluar = false;

    do {
        cout << "========== MENU ==========" << endl;
        cout << "1. BUAT REKENING BARU" << endl;
        cout << "2. MASUK REKENING" << endl;
        cout << "3. BATAL" << endl;

        cout << "PILIH : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                buatRekening();
                break;

            case 2:
                int index;
                index = masukRekening();
                if (index != -1) {
                    int pilihRekening;
                    do {
                        cout << "========== MENU REKENING ==========" << endl;
                        cout << "1. CEK SALDO" << endl;
                        cout << "2. SETOR TUNAI" << endl;
                        cout << "3. TARIK TUNAI" << endl;
                        cout << "4. KELUAR PADA MENU AWAL" << endl << endl;

                        cout << "PILIH : ";
                        cin >> pilihRekening;

                        switch (pilihRekening) {
                            case 1:
                                cekSaldo(index);
                                break;

                            case 2:
                                setorTunai(index);
                                break;

                            case 3:
                                tarikTunai(index);
                                break;

                            case 4:
                                cout << "KEMBALI PADA MENU AWAL" << endl;
                                break;

                            default:
                                cout << "YANG ANDA PILIH TIDAK VALID" << endl;
                                break;
                        }
                    } while (pilihRekening != 4);
                }
                break;

            case 3:
                cout << "TERIMA KASIH SUDAH BERKUNJUNG" << endl;
                keluar = true;
                break;

            default:
                cout << "YANG ANDA PILIH TIDAK VALID" << endl;
                break;
        }
    } while (!keluar);
}

int main() {
    menuUtama();
    return 0;
}
