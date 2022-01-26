void red () {
  printf("\033[1;31m");
}

void green() {
  printf("\033[1;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

void clear() {
  printf("\e[1;1H\e[2J");
}

void highlight(char* str){
    yellow();
    printf("%s", str);
    reset();
}

