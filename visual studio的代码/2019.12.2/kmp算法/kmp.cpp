int indexkmp(sstring.s, sstring.t, int pos)
{
	int i = pos;
	int j = 1;
	while (i < s.length&&j <= t.length)
	{
		if (j == 0 || s.ch[i] == t.ch[j])
		{
			i++; j++;
		}
		else { j = next[j]; }
	}
	if (j > t.length)return i - t.length;
	else return 0;
}