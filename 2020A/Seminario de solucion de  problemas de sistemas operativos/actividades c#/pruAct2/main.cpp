#include <iostream>
#include <vector>
using namespace std;

int main() {

int tamLis = 0;
int totLotExa=tamLis/4;
int totLotRes=tamLis%4;
int catLotTot=totLotExa+totLotRes;
bool banCrearLot=false;
int totProEje=0;

if(totLotExa!=0)
  banCrearLot=true;

vector<int> lotAct, pro;

unsigned int i=0,k=0;
while(tamLis!=0){
     totProEje=0;
     if(banCrearLot){
        lotAct.clear();
        for(int j=0;j<4;j++){
           lotAct[j]=pro[i];
           i++;
           totProEje++;
        }
     } else{
        lotAct.clear();
        for(int j=0;j<tamLis;j++){
          lotAct[j]=pro[i];
          i++;
          totProEje++;
        }
     }

     /**k=0;
     while(k<lotAct.size()){

     }**/

     tamLis-=totProEje;
     totLotRes=tamLis%4;
     if(totLotRes!=0)
       banCrearLot=false;
     else
       banCrearLot=true;

     i++;
}




    return 0;
}
