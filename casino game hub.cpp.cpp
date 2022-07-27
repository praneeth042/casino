#include <bits/stdc++.h>

struct NUMBER{
    int firstnumber,secondnumber,sum,thirdnumber;
};
void firstcard(int firstnumber,int secondnumber,int thirdnumber,int sum){
    std::cout<<"  \n\n\n";
    std::cout<<sum<<"\n\n";
    std::cout<<"   First Card   "<<firstnumber<<"\n\n";
    std::cout<<"   Second Card  "<<secondnumber<<"\n\n";
    std::cout<<"   Extra Card   "<<thirdnumber<<"\n\n";
    std::cout<<"\n";

}
void secondcard(int firstnumber,int secondnumber,int sum){
    std::cout<<"\n\n\n"<<sum<<"\n\n";
    std::cout<<"This Is a Natural Win 8/9\n";
    std::cout<<"First Card"<<firstnumber<<"\n\n";
    std::cout<<"Second Card"<<secondnumber<<"\n\n";
}
bool restart(char a,long money){
    if(money>0){
        if(a=='Y'||a=='y')return true;
        else if(a=='n'||a=='N'){
            std::cout<<"THANK YOU FOR PLAYING...";
            return false;
        }
    }
    else{
        std::cout<<"Insufficient cash!!!!!....";
        return false;
    }
}
int winnerdecln(int bankercard,int playercard){
    if(bankercard>playercard){
        std::cout<<"\nBANKER WIN,";
        return 1;
    }
    else if(bankercard<playercard){
        std::cout<<"\nPLAYER WIN,";
        return 2;

    }
    else if(bankercard==playercard){
        std::cout<<"\n DRAWWW...,";
        return 3;
    }
}
int winner(int wnr,int dec,int bet){
    if(wnr==dec){std::cout<<"YOU WIN!!!!!\nCONGRATULATIONS\n";return bet;}
    if(wnr==3){std::cout<<"TIED!!\n";return 0;}
    else{
        std::cout<<"YOU LOST!\nBETTER LUCK NEXT TIME!!\n\n";bet*=-1;return bet;
    }
}
int main(){
    system("Color 2F");
    srand(time(NULL));
    std::string name;
    int bet,dec,wnr,prize;
    char a;
    bool q=true;
    int cash=10000;
    std::cout<<"\nPLEASE ENTER YOUR CARD TO START\n";
    std::cout<<"ENTER YOUR NAME:";
    getline(std::cin,name);
    std::cout<<"WELCOME TO DALLAS CASINO CLUB\n";
    do{
        std::cout<<"current balance"<<cash<<"\n"<<"1-BANKER\n2-PLAYER\n"<<"CHOOSE YOUR BET   ";
        while(!(std::cin>>dec)||(dec<1||dec>2)){
            std::cin.clear();
            std::cout<<"\nCHOOSE YOUR BET \n1-BANKER\n2-PLAYER\n";
        }
        do{
            std::cout<<"PLACE YOUR BET:";std::cin>>bet;

        }
        while(bet>cash);

        std::cout<<"\n\nBANKER'S CARD =\n";

        struct NUMBER banker;
        banker.firstnumber=rand()%10 + 1;
        banker.secondnumber=rand()%10 + 1;
        banker.sum=banker.firstnumber+banker.secondnumber;
        banker.sum=banker.sum % 10;

        if(banker.sum!=9 && banker.sum!=8){
            banker.thirdnumber=rand() % 10 +1;
            banker.sum+=banker.thirdnumber;
            banker.sum=banker.sum % 10;
            firstcard(banker.firstnumber,banker.secondnumber,banker.thirdnumber,banker.sum);
        }
        else{
            secondcard(banker.firstnumber,banker.secondnumber,banker.sum);
        }
        std::cout<<"\n\n"<<"PLAYER'S CARD"<<"=\n";
        struct NUMBER player;
        player.firstnumber=rand() % 10 +1;
        player.secondnumber=rand() % 10 +1;
        player.sum=player.firstnumber+player.secondnumber;
        player.sum=player.sum % 10;

        if(player.sum!=9 && player.sum !=8){
            player.thirdnumber=rand() % 10 + 1;
            player.sum+=player.thirdnumber;
            player.sum=player.sum%10;
            firstcard(player.firstnumber,player.secondnumber,player.thirdnumber,player.sum);
        }
        else{
            secondcard(player.firstnumber,player.secondnumber,player.sum);
        }
        wnr=winnerdecln(banker.sum,player.sum);
        prize=winner(wnr,dec,bet);
        cash+=prize;
        std::cout<<"CURRENT POOL"<<cash<<std::endl;

        std::cout<<"WANT TO PLAY AGAIN-Y/N ";std::cin>>a;
        q=restart(a,cash);
    }while(q!=false);
}