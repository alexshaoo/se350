int main(int argc, char **argv) {
  if (argc != 2) {
    return -1;
  }
  remove(argv[1]);
  return 0;
}
