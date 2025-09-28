#include <iostream>

std::string angkakekata(int x){
    std::string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
    std::string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas", "enam belas","tujuh belas","delapan belas","sembilan belas"};
    std::string puluhan[] = {"","","dua puluh","tiga puluh","empat puluh","lima puluh", "enam puluh","tujuh puluh", "delapan puluh", "sembilan puluh"};
    if (x >= 0 && x<=9){
        return satuan[x];
    }else if(x>=10 && x<=19){
        return belasan[x-10];
    }else if(x>=20 && x<=99){
        if(x%10==0){
            return puluhan[x/10];
    }    else {
        return puluhan[x/10]+" "+satuan[x%10];
    }  
        }else if(x == 100){
        return "seratus";
    }
}
    int main(){
        int n;
        std:: cout<<"Masukkan angka (0-100):";
        std::cin>> n;
        if(n>=0 && n<=100){ 
            std::string hasil = angkakekata(n);
            std::cout << n << "=" << hasil << std::endl;
        }
        return 0;

    }
