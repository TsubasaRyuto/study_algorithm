void trace(int A[], int digits) {
  for (int i = 0; i < digits; i ++) {
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}
