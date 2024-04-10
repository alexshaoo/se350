FILE* f = fopen("file.txt", "r");
int file_desc = fileno(f);
int result = flock(file_desc, LOCK_EX);