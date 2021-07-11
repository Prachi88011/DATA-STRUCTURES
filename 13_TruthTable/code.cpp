#include<iostream>
#include<set>
#include<stdio.h>
#include<iomanip>
using namespace std;
int exOR(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x XOR y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",i ^ j);
                cout<<"\n";

        }
    }
    return 0;
}
int conj(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x AND y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",i && j);
                cout<<"\n";

        }
    }
    return 0;
}
int disj(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x OR y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",i || j);
                cout<<"\n";

        }
    }
    return 0;
}
int cond(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x --> y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",!i || j);
                cout<<"\n";

        }
    }
    return 0;
}
int biCond(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x <--> y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",((!i || j) && (!j || i)));
                cout<<"\n";

        }
    }
    return 0;
}
int exNOR(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x XOR y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",!(i ^ j));
                cout<<"\n";

        }
    }
    return 0;
}
int neg(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(7)<<"x'\n";
    cout<<"   -------------\n";
    for(int i=0;i<=1;i++){
        cout<<setw(5)<<i<<setw(5)<<"|";
            cout<<"    ";
            printf("%d",!i);
            cout<<"\n";
    }
    return 0;

}
int nand(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x NAND y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",!(i && j));
                cout<<"\n";

        }
    }
    return 0;

}
int nor(){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x NOR y\n";
    cout<<"   -------------------------\n";
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
                cout<<setw(5)<<i<<setw(5)<<"|"<<setw(5)<<j<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",!(i || j));
                cout<<"\n";

        }
    }
    return 0;

}
int main(){
    conj();
    cout<<"\n\n";
    disj();
    cout<<"\n\n";
    exOR();
    cout<<"\n\n";
    cond();
    cout<<"\n\n";
    biCond();
    cout<<"\n\n";
    exNOR();
    cout<<"\n\n";
    neg();
    cout<<"\n\n";
    nand();
    cout<<"\n\n";
    nor();

}
