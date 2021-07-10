#include <stdio.h>

char col_2[6] = {'#','.','#','#','#'};
char col_3[6] = {'#','.','#','.','#'};
char col_4[6] = {'#','#','#','.','.'};
char col_7[6] = {'#','.','.','.','.'};
char col_59[6] = {'#','#','#','.','#'};
char col_068[6] = {'#','#','#','#','#'};

int n, w;
bool check_col(char* signal, int col, char* sample) {
    int i;
    for(i=0;i<5;i++)
    {
        if( signal[col] != sample[i] ) return false;
        col += w;
    }
    return true;
}

int digit(char* signal, int s_col, int e_col) {
    if( e_col - s_col == 2 ) return 1;
    if( check_col(signal, s_col+1, col_2) ) return 2;
    if( check_col(signal, s_col+1, col_3) ) return 3;
    if( check_col(signal, s_col+1, col_4) ) return 4;
    if( check_col(signal, s_col+1, col_7) ) return 7;
    
    if( check_col(signal, s_col+1, col_59) ) {
        return signal[w + s_col+3] != '#' ? 5 : 9;
    }
    
    if( signal[w*2 + s_col+2] == '.' ) return 0;
    if( signal[w + s_col+3] == '.' ) return 6;
    return 8;
}

bool is_blank(char* signal, int col) {
    int i;
    for( i=0;i<5;i++ ) {
        if( signal[col] != '.' ) return false;
        col += w;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    w = n / 5;
    
    char* signal = new char[n];
    scanf("%s", signal);
    
    int i, prev = -1;
    for(i=0;i<w;i++) {
        if( is_blank(signal, i) ) {
            if( i > prev+1 )
                printf("%d",digit(signal, prev, i));
            prev = i;
        }
    }
    
    if( w > prev+1 ) {
        printf("%d",digit(signal, prev, w));
    }
}