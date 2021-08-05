void get_next(sstring.t, int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < t.length)
	{
		if (j == 0 || t.ch[i] == t.ch[j]) { i++; j++; next[i] = j;}
		else 
		{
			j = next[j];
        }
}
