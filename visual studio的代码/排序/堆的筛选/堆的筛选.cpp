void heapadjust(int r[], int s, int m)//��֪r[s]����������
{
	int rc = r[s];
	int j;
	for (j = 2 * s; j < m; j * =2)
	{
		if (r[j] < r[j + 1] && j < m) { j++; }
		if (rc > r[j]) { break; }
		r[s] = r[j]; s = j;
	}
	r[s] = rc;
}