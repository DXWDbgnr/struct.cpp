#include <iostream>

struct ATM{

    std::string userName;
    int pin;
    int saldo;
    int pilihan;
};

void menuUtama(){
  std::cout << "===================================" << std::endl;
  std::cout << " SELAMAT DATANG DI ATM " << std::endl;
  std::cout << "===================================" << std::endl << std::endl;
  std::cout << " Silahkan pilih Transaksi yang ingin anda lakukan! " << std::endl << std::endl;
  std::cout << "===================================" << std::endl << std::endl;
  std::cout << " cek saldo   (1) " << std::endl;
  std::cout << " setor tunai (2) " << std::endl;
  std::cout << " Tarik Tunai (3) " << std::endl;
  std::cout << " Keluar      (4) " << std::endl << std::endl;
  std::cout << "===================================" << std::endl << std::endl;
  std::cout << " silahkan masukkan pilihan anda =  ";
}

bool autentikasiPin(ATM atm){
     int inputPIN;
     int maxPIN = 3;

     for (int i = 0; i < maxPIN; i++){
        std::cout << " Masukkan PIN anda! : ";
        std::cin >> inputPIN;

        if (inputPIN == atm.pin){
            return true;
        } else{
            std::cout << " PIN yang anda masukkan salah! kesempatan anda mencoba = " << (maxPIN -i -1) << std::endl;
        }
     }
     return false;
}

bool autentikasiUser(ATM atm){
     std::string inputUser;
     int maxUser= 3;

     for (int i = 0; i < maxUser; i++){
        std::cout << " Masukkan Username anda! : ";
        std::cin >> inputUser;

        if (inputUser == atm.userName){
            return true;
        } else{
            std::cout << " Username yang anda masukkan salah! kesempatan anda mencoba = " << (maxUser -i -1) << std::endl;
        }
     }
     return false;
}


int main(){

    ATM obj; 
    obj.userName = "agusdiatmika";
    obj.pin = 123456;
    obj.saldo = 00000000;
    int pilihan;
    
    if (!autentikasiUser(obj)){
    std::cout << " Anda telah memaukan Username yang salah sebanyak 3 kali, Kart anda di blokir" << std::endl;
    return 0;
 }
    if (!autentikasiPin(obj)){
    std::cout << " Anda telah memaukan PIN yang salah sebanyak 3 kali, Kart anda di blokir" << std::endl;
    return 0;
 }

do{

    menuUtama();
    std::cin >> pilihan;

    switch (pilihan){
    case 1:{
        std::cout << " Saldo Anda = Rp." << obj.saldo << std::endl;
        break;
        }
       

    case 2: {
    int setor;
    std::cout << " Masukkan Jumalah Uang, (Minimal 50000)!" << std::endl;
    std::cout << " Rp.";
    std::cin >> setor;
    if (setor >= 50000){
        obj.saldo += setor;
        std::cout << " Transaksi Berhasil! " << std::endl;
    }else{
        std::cout << " Anda Tidak Memenuhi Syarat Untuk Menyetor Tunai, Transaksi Gagal! " << std::endl;
    }
    break;
    }
    

    case 3:{
    int tarik;
    std::cout << " Masukkan Jumalah Uang! ";
    std::cout << " Rp.";
    std::cin >> tarik;
    if (tarik <= obj.saldo){
        obj.saldo -= tarik;
        std::cout << "Transaksi Berhasil! " << std::endl;
    }else{
        std::cout << " Saldo Anda Tidak Cukup, Transaksi Gagal! " << std::endl;
    }
    break;
    }

    case 4:{
        std::cout << "Terimakasih Telah Menggunakan Layanan Kami!" << std::endl;
        continue;
    default:
        std::cout << "Pilihan Tidak Tersedia, Coba Lagi!" << std::endl;
        break;
    }
}

} while(pilihan != 4);

std::cout << "===================================" << std::endl;
std::cout << "SELESAI!" << std::endl;
std::cout << "===================================" << std::endl;

return 0;
}