#include <iostream>
using namespace std;

const int N = 8; //クイーンの数
bool Board[N][N]; //チェス盤
int row[N]; //その行は襲撃されるか,クイーンの置いてある列を記録
bool col[N]; //その列は襲撃されるか
bool dpos[2*N]; //左下方向の列は襲撃されるか
bool dneg[2*N]; //右下方向の列は襲撃されるか

#define SAFE true
#define NOT_SAFE false

void PrintBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //クイーンが置かれている行が列と同じでなければ関数を抜ける(1行に2つ置けない)
            //ここで初期値として与えられたクイーンの盤以外表示されなくなる
            if(Board[i][j] == true){
                if(row[i] != j) return;
            }
        }
    }
    //ちゃんとした答え
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << (row[i] == j ? "Q" : ".");
        }
        cout << endl;
    }

}

void rec(int i){
    //N行目に来たらすべてのクイーンをおくことができたので出力
    if(i == N){
        PrintBoard();
        return;
    }

    for(int j = 0; j < N; j++){
        //i行j列目が襲撃されるならクイーンを置けない
        if( col[j] == NOT_SAFE or
            dpos[i + j] == NOT_SAFE or
            dneg[i - j + N - 1] == NOT_SAFE
        ) continue;

        //順番に置いていく
        row[i] = j;dneg[i - j + N - 1] = dpos[i+j] = col[j] = NOT_SAFE;
        //次の行を探す
        rec(i+1);
        //クイーンを取り除く
        row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = SAFE;
        
    }    
}

signed main(){
    for(int i = 0; i < N; i++){
        row[i] = -1;
        col[i] = SAFE;
        for(int j = 0; j < N; j++){
            Board[i][j] = false;
        }
    }
    for(int i = 0; i < 2 * N; i++)
        dneg[i] = dpos[i] = SAFE;


    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int r,c;
        cin >> r >> c;
        Board[r][c] = true;
    }

    rec(0);

    return 0;
}