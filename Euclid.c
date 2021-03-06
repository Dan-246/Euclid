/*
    ユークリッドの互除法を用いて二数の最大公約数を求める
    例) 94,78
        94 = 78*1 + 16
        78 = 16*4 + 14
        16 = 14*1 + 2
        14 = 2*7 +0
        
        最大公約数：2

    [構想]
    1.2数：a,bを定義（自然数）
    2.a , bの大小を判断
    3.大きい数　＝　小さい数*商＋余り
    4.小さい数を大きい数に代入、余りを小さい数に代入
    5. 4と5をループ　（余りが0になるまで）
    6.最後の割る数が最大公約数

    3/20
    基礎を構築。しかし、whileのループの中に入れていないことが分かった。
    また、最大公約数の値にaが代入されている。whileの最後にaを代入しているから
    surplusが0になることはないのかも？

    4/6
    修正完了。最大公約数は正しく表示されている。また、互いに素である場合もうまく表示できた。
*/

#include <stdio.h>
int main(void){

    int a,b;
    int first_a, first_b;
    int gcd;       /*最大公約数*/
    int break_control;
    break_control = 0;  /*終了条件*/

    while(break_control == 0){
        printf("1つ目の整数値を入力してください\na:");
        scanf("%d",&a);
        printf("2つ目の整数値を入力してください\nb:");
        scanf("%d",&b);

        first_a = a;
        first_b = b;
            
        int surplus;
        if(a>b){        //bよりaが大きいとき（aをbで割るとき）
            surplus = a % b;
            while(surplus =! 0){
                surplus = a % b;
                a = b;
                if(surplus==0){
                    break;
                }
                b = surplus;
            }
            printf("最大公約数は%dです\n",b);
            if(b == 1){
                printf("2数 %d , %d は互いに素となります\n",first_a,first_b);
                printf("このプログラムを続行しますか？\n続行なら0終了なら1を入力してください : ");
                scanf("%d", &break_control);
            }
            else{
                printf("このプログラムを続行しますか？\n続行なら0終了なら1を入力してください : ");
                scanf("%d", &break_control);
            }
        }else{                  //bをaで割るとき
            surplus = b % a;
            while(surplus =! 0){
                surplus = b % a;
                b = a;
                if(surplus == 0){
                    break;
                }
                    a = surplus;
            }
            printf("最大公約数は%dです\n",b);
            if(a == 1){
                printf("2数 %d , %d は互いに素となります\n",first_a,first_b);
                printf("このプログラムを続行しますか？\n続行なら0終了なら1を入力してください : ");
                scanf("%d", &break_control);
            }
            else{
                printf("このプログラムを続行しますか？\n続行なら0終了なら1を入力してください : ");
                scanf("%d", &break_control);
            }
        }
    }    
    return 0;
}