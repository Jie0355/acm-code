// @description 快读快写
using ValueType = int;
ValueType read() {
    ValueType x = 0, np = 1;
    char c = getchar();
    if (c == '-') {
        np = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * np;
}
void write(ValueType x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}