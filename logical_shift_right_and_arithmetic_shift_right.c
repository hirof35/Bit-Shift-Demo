#include <stdio.h>
#include <limits.h>

// 2進数を表示するヘルパー関数
void print_bits(int n) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

// 1. 論理シフトの実装（符号付き整数対応：常に0埋め）
int logical_shift_right(int value, int shift) {
    // 一度符号なしにキャストすることで、強制的に論理シフト（0埋め）にする
    unsigned int temp = (unsigned int)value;
    return (int)(temp >> shift);
}

// 2. 算術シフトの実装（符号付き整数対応：符号ビット維持）
int arithmetic_shift_right(int value, int shift) {
    // 通常の符号付き右シフト（多くの環境で算術シフトになる）
    // ※より厳密・安全に行う場合は、負数の場合のオーバーフローやパディングに注意します
    return value >> shift;
}

int main() {
    // 負の数（例: -16）
    // 32bit環境の2進数: 11111111 11111111 11111111 11110000
    int val = -16; 

    printf("元データ:      ");
    print_bits(val);
    printf("値: %d\n\n", val);

    // 2ビット右シフト
    int shift_amount = 2;

    // 論理シフトの結果
    int l_result = logical_shift_right(val, shift_amount);
    printf("論理シフト後:  ");
    print_bits(l_result);
    printf("値: %d (上位に0が埋まるため正の大きな数になる)\n\n", l_result);

    // 算術シフトの結果
    int a_result = arithmetic_shift_right(val, shift_amount);
    printf("算術シフト後:  ");
    print_bits(a_result);
    printf("値: %d (符号が維持される)\n", a_result);

    return 0;
}
