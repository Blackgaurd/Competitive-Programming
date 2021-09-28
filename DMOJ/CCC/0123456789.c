// CCC '02 J1 - 0123456789

int main() {
    switch (getchar()) {
        case '0':
            puts(
                " * * *\n*     *\n*     *\n*     *\n\n*     *\n*     *\n*     "
                "*\n * * *");
            break;
        case '1':
            puts("\n      *\n      *\n      *\n\n      *\n      *\n      *\n");
            break;
        case '2':
            puts(" * * *\n      *\n      *\n      *\n * * *\n*\n*\n*\n * * *");
            break;
        case '3':
            puts(
                " * * *\n      *\n      *\n      *\n * * *\n      *\n      *\n "
                "     *\n * * *");
            break;
        case '4':
            puts(
                "\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      "
                "*\n");
            break;
        case '5':
            puts(" * * *\n*\n*\n*\n * * *\n      *\n      *\n      *\n * * *");
            break;
        case '6':
            puts(" * * *\n*\n*\n*\n * * *\n*     *\n*     *\n*     *\n * * *");
            break;
        case '7':
            puts(
                " * * *\n      *\n      *\n      *\n\n      *\n      *\n      "
                "*\n");
            break;
        case '8':
            puts(
                " * * *\n*     *\n*     *\n*     *\n * * *\n*     *\n*     "
                "*\n*     *\n * * *");
            break;
        case '9':
            puts(
                " * * *\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n "
                "     *\n * * *");
            break;
    }

    return 0;
}