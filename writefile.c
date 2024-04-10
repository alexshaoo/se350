void write_points_to_file(point *p, FILE f) {
  while (p != NULL) {
    fprintf(f, "%d, %d, %d\n", p->x, p->y, p->z);
    p = p->next;
  }
}

int main(int argc, char **argv) {
  FILE *fp;
  int i, isquared;

  fp = fopen("results.dat", "r");
  if (fp == NULL) {
    return -1;
  }

  while (fscanf(fp, "%d %d\n", &i, &isquared) == 2) {
    printf("i: %d,  isquared: %\n", i, isquared);
  }

  fclose(fp);
  return 0;
}
